#include<bits/stdc++.h>
using namespace std;

class EmailNotification {
public:
    void send(const string& message) {
        cout << "Sending an Email notification: " << message << endl;
    }
};

class NotificationService {
public:
    void sendNotification(const string& type, const string& message) {
        if (type == "EMAIL") {
            EmailNotification email;
            email.send(message);
        }
        // } else if (type == "SMS") {
        //     SMSNotification sms;
        //     sms.send(message);
        // } else if (type == "Push") {
        //     PushNotification push;
        //     push.send(message);
        // } else if (type == "Slack") {
        //     SlackNotification slack;
        //     slack.send(message);
        // } else if (type == "WhatsApp") {
        //     WhatsAppNotification wa;
        //     wa.send(message);
        // }
    }
};



int main() {
    NotificationService service;

    service.sendNotification("EMAIL", "Welcome to our platform!");
    // service.sendNotification("SMS", "Your OTP is 1234");
    // service.sendNotification("Push", "You have a new notification");
    // service.sendNotification("Slack", "A new task has been assigned");
    // service.sendNotification("WhatsApp", "Hello! How are you?");

    return 0;
}