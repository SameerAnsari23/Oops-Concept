#include <iostream>
#include <string>

using namespace std;

// Step 1: Common interface
class INotification {
public:
    virtual void send(const string& message) = 0;
    virtual ~INotification() = default; // Essential for safe deletion through base pointer
};

// Step 2: Email notification
class EmailNotification : public INotification {
public:
    void send(const string& message) override {
        cout << "Sending an Email notification: " << message << endl;
    }
};

// Step 3: SMS notification
class SMSNotification : public INotification {
public:
    void send(const string& message) override {
        cout << "Sending an SMS notification: " << message << endl;
    }
};

// Step 4: Push notification
class PushNotification : public INotification {
public:
    void send(const string& message) override {
        cout << "Sending a Push notification: " << message << endl;
    }
};

// Step 5: Simple Factory returning a raw pointer
class NotificationFactory {
public:
    static INotification* createNotification(const string& type) {
        if (type == "EMAIL") {
            return new EmailNotification();
        }
        else if (type == "SMS") {
            return new SMSNotification();
        }
        else if (type == "PUSH") {
            return new PushNotification();
        }

        return nullptr;
    }
};

// Step 6: Notification Service managing creation and cleanup
class NotificationService {
public:
    void sendNotification(const string& type, const string& message) {
        INotification* notification = NotificationFactory::createNotification(type);

        if (notification != nullptr) {
            notification->send(message);
            delete notification; // Clean up allocated memory
        }
        else {
            cout << "Invalid notification type!" << endl;
        }
    }
};

// Step 7: Main function
int main() {
    NotificationService service;

    service.sendNotification("EMAIL", "Welcome to our platform!");
    service.sendNotification("SMS", "Your OTP is 1234");
    service.sendNotification("PUSH", "You have a new notification");
    service.sendNotification("WHATSAPP", "Hello! How are you?");

    return 0;
}