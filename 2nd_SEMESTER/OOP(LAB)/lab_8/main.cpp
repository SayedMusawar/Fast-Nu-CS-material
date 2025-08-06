#include "UserSystem.h"
using namespace std;

int main() {
    UserSystem user1("Musawar");
    user1.displayUserName();

    UserSystem user2("Ali");
    user2.displayUserName();
    UserSystem::displayCount();

    UserSystem user3 = user1;    
    user3.displayUserName();

    UserSystem user4(user2, true);  
    user4.displayUserName();

    UserSystem::displayCount();

    {
        UserSystem user5("Shah");
        UserSystem::displayCount();
    }

    UserSystem::displayCount();

    return 0;
}