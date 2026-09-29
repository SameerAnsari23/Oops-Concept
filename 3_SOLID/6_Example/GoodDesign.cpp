#include <bits/stdc++.h>
using namespace std;

// ======================================================
// Food Item
// ======================================================
class FoodItem {
public:
    string name;
    double price;
    FoodItem(string name, double price) {
        this->name = name;
        this->price = price;
    }
};


// ======================================================
// Food Order
// ======================================================
class FoodOrder {
private:
    vector<FoodItem*> items;
public:
    void addItem(FoodItem* item) {
        items.push_back(item);
    }

    double calculateTotal() {
        double total = 0;
        for (auto item : items) {
            total += item->price;
        }
        return total;
    }

    const vector<FoodItem*>& getItems() const {
        return items;
    }
};


// ======================================================
// Payment Abstraction
// ======================================================
class Payment {
public:
    virtual void pay(double amount) = 0;
    virtual ~Payment() {}
};


// ======================================================
// Payment Implementations
// ======================================================
class UPIPayment : public Payment {
public:
    void pay(double amount) override {
        cout << "Payment of Rs " << amount << " done using UPI" << endl;
    }
};

class CardPayment : public Payment {
public:
    void pay(double amount) override {
        cout << "Payment of Rs " << amount << " done using Card" << endl;
    }
};

class CashPayment : public Payment {
public:
    void pay(double amount) override {
        cout << "Payment of Rs " << amount << " done using Cash" << endl;
    }
};


// ======================================================
// Notification Abstraction
// ======================================================
class Notification {
public:
    virtual void send(string message) = 0;
    virtual ~Notification() {}
};

// ======================================================
// Notification Implementations
// ======================================================
class EmailNotification : public Notification {
public:
    void send(string message) override {
        cout << "Email: " << message << endl;
    }
};

class SMSNotification : public Notification {
public:
    void send(string message) override {
        cout << "SMS: " << message << endl;
    }
};


// ======================================================
// Repository Abstraction
// ======================================================
class OrderRepository {
public:
    virtual void save(const FoodOrder& order) = 0;
    virtual ~OrderRepository() {}
};


// ======================================================
// Repository Implementation
// ======================================================
class MySQLOrderRepository : public OrderRepository {
public:
    void save(const FoodOrder& order) override {
        cout << "Order saved to MySQL" << endl;
    }
};


// ======================================================
// Invoice Printer
// ======================================================
class InvoicePrinter {
public:
    void print(const FoodOrder& order) {
        cout << "\n---------- INVOICE ----------" << endl;

        for (auto item : order.getItems()) {
            cout << item->name << " : Rs " << item->price << endl;
        }

        cout << "Total: Rs " << order.calculateTotal() << endl;
    }
};


// ======================================================
// Order Service
// ======================================================
class OrderService {
private:
    Payment& payment;
    Notification& notification;
    OrderRepository& repository;
public:
    OrderService(Payment& payment, Notification& notification, OrderRepository& repository)
        : payment(payment),
          notification(notification),
          repository(repository) {
    }

    void placeOrder(FoodOrder& order) {
        double total = order.calculateTotal();
        payment.pay(total);
        repository.save(order);
        notification.send("Your order has been placed successfully.");
    }
};


// ======================================================
// Main
// ======================================================
int main() {
    FoodItem pizza("Pizza", 300);
    FoodItem burger("Burger", 150);

    FoodOrder order;
    order.addItem(&pizza);
    order.addItem(&burger);

    UPIPayment payment;
    EmailNotification notification;
    MySQLOrderRepository repository;
    InvoicePrinter printer;
    printer.print(order);

    OrderService service(payment, notification, repository);
    service.placeOrder(order);

    return 0;
}