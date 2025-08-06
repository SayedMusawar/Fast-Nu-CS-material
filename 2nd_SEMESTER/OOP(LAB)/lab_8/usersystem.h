#include <iostream>
#include <cstring>

class UserSystem {
private:
    char* username;
    static int count;

public:
    UserSystem(const char* name);
    
    ~UserSystem();
    
    UserSystem(const UserSystem& other);                  

    UserSystem(const UserSystem& other, bool deepCopy);
    
    static void displayCount();
    
    void displayUserName() const;
};