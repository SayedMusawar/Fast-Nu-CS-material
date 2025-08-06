#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

// User class to manage user information
class User {
private:
    string userID;
    string username;
    string password;
    static int totalUsers; // Static member to track total users

public:
    // Default constructor
    User() : userID("N/A"), username("N/A"), password("N/A") {
        totalUsers++;
    }

    // Parameterized constructor
    User(string id, string name, string pwd) 
        : userID(id), username(name), password(pwd) {
        totalUsers++;
    }

    // Destructor
    ~User() {
        cout << "User " << username << " logged out." << endl;
        totalUsers--;
    }

    // Public methods for data hiding
    void setPassword(string pwd) {
        password = pwd;
    }

    // Const member function
    string getUsername() const {
        return username;
    }

    string getUserID() const {
        return userID;
    }

    bool authenticate(string pwd) const {
        return password == pwd;
    }

    // Static member function
    static int getTotalUsers() {
        return totalUsers;
    }
};

// Initialize static member
int User::totalUsers = 0;

// Message class to manage individual messages
class Message {
private:
    string senderID;
    string receiverID;
    string content;
    time_t timestamp;
    static int totalMessages; // Static member to track total messages

public:
    // Parameterized constructor
    Message(string sender, string receiver, string msg) 
        : senderID(sender), receiverID(receiver), content(msg) {
        timestamp = time(nullptr);
        totalMessages++;
    }

    // Destructor
    ~Message() {
        cout << "Message from " << senderID << " to " << receiverID << " deleted." << endl;
    }

    // Const member functions
    string getSenderID() const {
        return senderID;
    }

    string getReceiverID() const {
        return receiverID;
    }

    string getContent() const {
        return content;
    }

    string getTimestamp() const {
        return ctime(&timestamp);
    }

    // Static member function
    static int getTotalMessages() {
        return totalMessages;
    }
};

// Initialize static member
int Message::totalMessages = 0;

// ChatSession class to manage the chat system
class ChatSession {
private:
    vector<User*> users; // List of users (dynamically allocated)
    vector<Message*> messages; // List of messages (dynamically allocated)

public:
    // Default constructor
    ChatSession() {}

    // Destructor to clean up dynamically allocated memory
    ~ChatSession() {
        for (User* user : users) {
            delete user;
        }
        for (Message* msg : messages) {
            delete msg;
        }
        cout << "Chat session ended." << endl;
    }

    // Add a user to the session
    void addUser(string id, string name, string pwd) {
        users.push_back(new User(id, name, pwd));
        cout << "User " << name << " added." << endl;
    }

    // Authenticate a user
    User* login(string id, string pwd) {
        for (User* user : users) {
            if (user->getUserID() == id && user->authenticate(pwd)) {
                cout << "User " << user->getUsername() << " logged in." << endl;
                return user;
            }
        }
        cout << "Invalid user ID or password." << endl;
        return nullptr;
    }

    // Send a message
    void sendMessage(string senderID, string receiverID, string content) {
        bool receiverExists = false;
        for (User* user : users) {
            if (user->getUserID() == receiverID) {
                receiverExists = true;
                break;
            }
        }
        if (!receiverExists) {
            cout << "Receiver does not exist." << endl;
            return;
        }
        messages.push_back(new Message(senderID, receiverID, content));
        cout << "Message sent from " << senderID << " to " << receiverID << endl;
    }

    // Display chat history for a user
    void displayChatHistory(string userID) const {
        cout << "Chat history for user " << userID << ":" << endl;
        for (const Message* msg : messages) {
            if (msg->getSenderID() == userID || msg->getReceiverID() == userID) {
                cout << "From " << msg->getSenderID() << " to " << msg->getReceiverID() 
                     << " at " << msg->getTimestamp() << "Message: " << msg->getContent() << endl;
            }
        }
    }
};

// Main program with console-based interface
int main() {
    ChatSession chat;

    // Add some users
    chat.addUser("U001", "Alice", "pass123");
    chat.addUser("U002", "Bob", "pass456");

    // Log in as Alice
    User* alice = chat.login("U001", "pass123");
    if (alice) {
        // Send a message from Alice to Bob
        chat.sendMessage(alice->getUserID(), "U002", "Hello, Bob! How are you?");
    }

    // Log in as Bob
    User* bob = chat.login("U002", "pass456");
    if (bob) {
        // Send a message from Bob to Alice
        chat.sendMessage(bob->getUserID(), "U001", "Hi, Alice! I'm doing great, thanks!");
    }

    // Display chat history for Alice
    if (alice) {
        chat.displayChatHistory(alice->getUserID());
    }

    // Display total users and messages
    cout << "Total users: " << User::getTotalUsers() << endl;
    cout << "Total messages: " << Message::getTotalMessages() << endl;

    return 0;
}