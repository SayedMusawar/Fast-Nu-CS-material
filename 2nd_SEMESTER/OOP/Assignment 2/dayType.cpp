#include<iostream>
using namespace std;

// Class to represent a day of the week and perform operations on it
class dayType {
    private:
        string* day; // Dynamically allocated string to store the day (e.g., "Sun")
        const string daysInWeek[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"}; // Array of days for reference
    public:
        // Default constructor: Initializes day to "Sun"
        dayType() {
            day = new string("Sun");
        }

        // Parameterized constructor: Initializes day to the given string
        dayType(string d) {
            day = new string(d);
        }

        // Copy constructor: Creates a deep copy of another dayType object
        dayType(const dayType& d) {
            day = new string(*(d.day));
        }

        // Destructor: Deallocates the dynamically allocated day
        ~dayType() {
            delete day;
        }    

        // Sets the day to the given string
        void setDay(string d) {
            *day = d;
        }

        // Returns the current day
        string getDay() {
            return *day;
        }

        // Prints the current day
        void printDay() {
            cout << "Day is: " << *day << endl;
        }

        // Returns the next day in the week
        string nextDay() {
            for(int i = 0; i < 7; i++) {
                if(daysInWeek[i] == *day) return daysInWeek[(i+1) % 7];
            }
            return "NOT_FOUND"; // In case the day is not found
        }

        // Returns the previous day in the week
        string previousDay() {
            for(int i = 0; i < 7; i++) {
                if(daysInWeek[i] == *day) return daysInWeek[(i + 6) % 7];
            }
            return "NOT_FOUND"; // In case the day is not found
        }

        // Calculates and returns the day after adding n days
        string requiredDay(int n) {
            for(int i = 0; i < 7; i++) {
                if(daysInWeek[i] == *day) return daysInWeek[(i + n) % 7];
            }
            return "NOT_FOUND"; // In case the day is not found
        }
};

// Main function: Menu-driven program to test the dayType class
int main() {
    dayType *day = new dayType(); // Dynamically allocate a dayType object
    int choice, numDays;
    string dayInput;
    
    // Menu loop to perform operations
    do {
        cout << "\nMenu:\n";
        cout << "1. Set the day\n";
        cout << "2. Print the day\n";
        cout << "3. Get the day\n";
        cout << "4. Get the next day\n";
        cout << "5. Get the previous day\n";
        cout << "6. Calculate day after adding days\n";
        cout << "7. Copy object and print\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: // Set the day
                cout << "Enter day (Sun, Mon, Tue, etc.): ";
                cin >> dayInput;
                day->setDay(dayInput);
                break;
            case 2: // Print the day
                day->printDay();
                break;
            case 3: // Get and display the day
                cout << "Current day is: " << day->getDay() << endl;
                break;
            case 4: // Get and display the next day
                cout << "Next day is: " << day->nextDay() << endl;
                break;
            case 5: // Get and display the previous day
                cout << "Previous day is: " << day->previousDay() << endl;
                break;
            case 6: // Calculate and display the day after adding days
                cout << "Enter number of days to add: ";
                cin >> numDays;
                cout << "Day after adding " << numDays << " days: " 
                     << day->requiredDay(numDays) << endl;
                break;
            case 7: { // Create a copy of the object and print it
                dayType copyday(*day);
                cout << " copied object: ";
                copyday.printDay();
            }
            break;
            case 8: // Exit the program
                cout << "Exiting program.\n";
                break;
            default: // Handle invalid input
                cout << "Invalid choice. Try again.\n";
            break;
        }
    } while (choice != 8);

    delete day; // Deallocate the dynamically allocated object
    return 0;
}