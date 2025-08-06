#include "UserSystem.h"
using namespace std;
int UserSystem::count = 0;

UserSystem::UserSystem(const char* name) {
    username = new char[strlen(name) + 1];
    strcpy(username, name);
    count++;
    cout << "User registered: " << username << " . Total users: " << count << endl;
}

UserSystem::~UserSystem() {
    count--;
    cout << "User logged out: " << username << ". Total users: " << count << endl;
    delete[] username;
}

UserSystem::UserSystem(const UserSystem& other) {
    username = other.username;
    count++;
    cout << "Shallow copy created for: " << username << ". Total users are: " << count << endl;
}

UserSystem::UserSystem(const UserSystem& other, bool deepCopy) {
    if (deepCopy) {
        username = new char[strlen(other.username) + 1];
        strcpy(username, other.username);
        count++;
        cout << "Deep copy create for: " << username << " .Total users are: " << count << endl;
    } else {
        username = other.username;
        count++;
        cout << "Shallow copy created for: " << username << ". Total users are: " << count << endl;
    }
}

void UserSystem::displayCount() {
    cout << "Current registered users are: " << count << endl;
}

void UserSystem::displayUserName() const {
    cout << "Username: " << username << endl;
}