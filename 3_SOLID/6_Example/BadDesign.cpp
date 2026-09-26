#include<bits/stdc++.h>
using namespace std;

class FoodItem {
    public:
    string name;
    double price;
    FoodItem (string name, double price) {
        this->name = name;
        this->price = price;
    }
};


class FoodOrder{
    vector<FoodItem*> items;

    public:
    void addItem(FoodItem* item) {
        items.push_back(item);
    }

    double calculateTotal() {
        double total = 0;
        for(auto it: items) {
            total += it->price;
        }
        return total;
    }

    void payementMethod(string type) {
        double price = calculateTotal();
        if (type == "cash") {
            cout << "Payment of " << price << " is done using cash method" << endl;
        }
        else if (type == "upi") {
            cout << "Payment of " << price << " is done using upi method" << endl;
        }
        else if (type == "card") {
            cout << "Payment of " << price << " is done using card method" << endl;
        }
    }

    void notification(string type) {
        if (type == "mail") {
            cout << "We are notifying you on mail" << endl;
        }
        else if (type == "sms") {
            cout << "We are notifying you on sms" << endl;
        }
        else if (type == "WhatsApp") {
            cout << "We are notifying you on whatsapp" << endl;
        }
    }

    void saveToDatabase() {
        for (auto it : items) {
            cout << "-" << it->name << endl;
        }
        cout << "Saved to our database" << endl;
    }

    void invoice() {
        cout << "Item Name       item Price" << endl;
        for (auto it : items) {
            cout << "-" << it->name << "          " << it->price << endl;
        }
        cout << "Total price: " << calculateTotal() << endl;
    }
};


int main() {
    FoodItem pizza("Pizza", 100);
    FoodItem burger("Burger", 50);

    FoodOrder zomato;
    zomato.addItem(&pizza);
    zomato.addItem(&burger);
    zomato.payementMethod("upi");
    zomato.notification("sms");
    zomato.notification("mail");
    zomato.notification("WhatsApp");
    zomato.saveToDatabase();
    zomato.invoice();

    return 0;
}