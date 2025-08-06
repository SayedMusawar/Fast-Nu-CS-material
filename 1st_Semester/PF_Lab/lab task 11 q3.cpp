#include <iostream>
using namespace std;

int main() {
    string password;
    cout << "Enter the password: ";
    getline(cin, password);

    int score = 0;
    bool special_symbol = false, digit = false, letter = false, cap_letter = false;

    for (int i = 0; i < password.length(); i++) {
        char ch = password[i];

        if ((ch >= 33 && ch <= 47) || (ch >= 58 && ch <= 64) || (ch >= 91 && ch <= 96) || (ch >= 123 && ch <= 126)) {
            special_symbol = true;
        }

        if (ch >= '0' && ch <= '9') {
            digit = true;
        }

        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            letter = true;
        }

        if (ch >= 'A' && ch <= 'Z') {
            cap_letter = true;
        }
    }

    if (special_symbol) score++;
    if (digit) score++;
    if (letter) score++;
    if (password.length() > 6) score++;
    if (cap_letter) score++;

    if (score >= 5) {
        cout << "Strong password" << endl;
    } else {
        cout << "Weak password" << endl;
    }

    return 0;
}
