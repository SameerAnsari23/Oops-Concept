#include <iostream>
#include <string>
#include <memory>

using namespace std;

// Step 1: Product interfaces
class INotification {
public:
    virtual void send(const string& message) = 0;
    virtual ~INotification() = default;
};

class INotificationConfig {
public:
    virtual void configure() = 0;
    virtual ~INotificationConfig() = default;
};

// Step 2: Standard notification products
class StandardEmailNotification : public INotification {
public:
    void send(const string& message) override {
        cout << "Standard Email: " << message << endl;
    }
};

class StandardSMSNotification : public INotification {
public:
    void send(const string& message) override {
        cout << "Standard SMS: " << message << endl;
    }
};

// Step 3: Standard configuration products
class StandardEmailConfig : public INotificationConfig {
public:
    void configure() override {
        cout << "Configuring Standard Email" << endl;
    }
};

class StandardSMSConfig : public INotificationConfig {
public:
    void configure() override {
        cout << "Configuring Standard SMS" << endl;
    }
};

// Step 4: Premium notification products
class PremiumEmailNotification : public INotification {
public:
    void send(const string& message) override {
        cout << "Premium Email: " << message << endl;
    }
};

class PremiumSMSNotification : public INotification {
public:
    void send(const string& message) override {
        cout << "Premium SMS: " << message << endl;
    }
};

// Step 5: Premium configuration products
class PremiumEmailConfig : public INotificationConfig {
public:
    void configure() override {
        cout << "Configuring Premium Email" << endl;
    }
};

class PremiumSMSConfig : public INotificationConfig {
public:
    void configure() override {
        cout << "Configuring Premium SMS" << endl;
    }
};

// Step 6: Abstract Factory
class INotificationFactory {
public:
    virtual INotification* createEmail() = 0;
    virtual INotification* createSMS() = 0;

    virtual INotificationConfig* createEmailConfig() = 0;
    virtual INotificationConfig* createSMSConfig() = 0;

    virtual ~INotificationFactory() = default;
};

// Step 7: Standard Factory
class StandardNotificationFactory : public INotificationFactory {
public:
    INotification* createEmail() override {
        return new StandardEmailNotification();
    }

    INotification* createSMS() override {
        return new StandardSMSNotification();
    }

    INotificationConfig* createEmailConfig() override {
        return new StandardEmailConfig();
    }

    INotificationConfig* createSMSConfig() override {
        return new StandardSMSConfig();
    }
};

// Step 8: Premium Factory
class PremiumNotificationFactory : public INotificationFactory {
public:
    INotification* createEmail() override {
        return new PremiumEmailNotification();
    }

    INotification* createSMS() override {
        return new PremiumSMSNotification();
    }

    INotificationConfig* createEmailConfig() override {
        return new PremiumEmailConfig();
    }

    INotificationConfig* createSMSConfig() override {
        return new PremiumSMSConfig();
    }
};

// Step 9: Notification Service
class NotificationService {
public:
    void sendEmail(
        INotificationFactory& factory,
        const string& message
    ) {
        unique_ptr<INotification> email(factory.createEmail());

        unique_ptr<INotificationConfig> config(
            factory.createEmailConfig()
        );

        config->configure();
        email->send(message);
    }

    void sendSMS(
        INotificationFactory& factory,
        const string& message
    ) {
        unique_ptr<INotification> sms(factory.createSMS());

        unique_ptr<INotificationConfig> config(
            factory.createSMSConfig()
        );

        config->configure();
        sms->send(message);
    }
};

// Step 10: Main function
int main() {
    NotificationService service;

    StandardNotificationFactory standardFactory;
    PremiumNotificationFactory premiumFactory;

    cout << "--- Standard Notifications ---" << endl;

    service.sendEmail(standardFactory, "Welcome to our platform!");
    service.sendSMS(standardFactory, "Your OTP is 1234");

    cout << "\n--- Premium Notifications ---" << endl;
    service.sendEmail(premiumFactory, "Welcome to our platform!");
    service.sendSMS(premiumFactory, "Your OTP is 1234");

    return 0;
}