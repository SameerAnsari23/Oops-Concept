// The Factory Method Design Pattern defines a method for creating objects but lets subclasses decide which concrete object to create.

#include <iostream>
#include <string>

using namespace std;

// Step 1: Common notification interface
class INotification {
public:
    virtual void send(const string& message) = 0;

    virtual ~INotification() = default;
};

// Step 2: Email notification
class EmailNotification : public INotification {
public:
    void send(const string& message) override {
        cout << "Sending an Email notification: "
             << message << endl;
    }
};

// Step 3: SMS notification
class SMSNotification : public INotification {
public:
    void send(const string& message) override {
        cout << "Sending an SMS notification: "
             << message << endl;
    }
};

// Step 4: Push notification
class PushNotification : public INotification {
public:
    void send(const string& message) override {
        cout << "Sending a Push notification: "
             << message << endl;
    }
};

// Step 5: Abstract factory
class NotificationFactory {
public:
    virtual INotification* createNotification() = 0;

    virtual ~NotificationFactory() = default;
};

// Step 6: Email factory
class EmailNotificationFactory : public NotificationFactory {
public:
    INotification* createNotification() override {
        return new EmailNotification();
    }
};

// Step 7: SMS factory
class SMSNotificationFactory : public NotificationFactory {
public:
    INotification* createNotification() override {
        return new SMSNotification();
    }
};

// Step 8: Push factory
class PushNotificationFactory : public NotificationFactory {
public:
    INotification* createNotification() override {
        return new PushNotification();
    }
};

// Step 9: Notification service
class NotificationService {
public:
    void sendNotification(NotificationFactory& factory,const string& message) {
        INotification* notification = factory.createNotification();

        if (notification != nullptr) {
            notification->send(message);
            delete notification;
        }
        else {
            cout << "Notification creation failed!" << endl;
        }
    }
};

// Step 10: Main function
int main() {
    NotificationService service;

    EmailNotificationFactory emailFactory;
    SMSNotificationFactory smsFactory;
    PushNotificationFactory pushFactory;

    service.sendNotification(emailFactory, "Welcome to our platform!");
    service.sendNotification(smsFactory, "Your OTP is 1234");
    service.sendNotification(pushFactory, "You have a new notification");

    return 0;
}