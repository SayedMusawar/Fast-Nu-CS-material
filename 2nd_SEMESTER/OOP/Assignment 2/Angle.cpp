#include<iostream>
using namespace std;

// Class to represent an angle in degrees, minutes, and direction (latitude or longitude)
class Angle {
    private:
        int* degrees; // Dynamically allocated integer for degrees
        float* minutes; // Dynamically allocated float for minutes
        char direction; // Direction (N, S, E, W)
    public:
        // Three-argument constructor: Initializes degrees, minutes, and direction
        Angle(int deg, float min, char dir) {
            degrees = new int(deg);
            minutes = new float(min);
            direction = dir;
        }

        // Copy constructor: Creates a deep copy of another Angle object
        Angle(const Angle& a) {
            degrees = new int(*a.degrees);
            minutes = new float(*a.minutes);
            direction = a.direction;
        }

        // Function to get angle values from the user
        void getAngle() {
            cout << "Enter degrees: ";
            cin >> *degrees;
            cout << "Enter minutes: ";
            cin >> *minutes;
            cout << "Enter direction (N, S, E, W): ";
            cin >> direction;
        }

        // Function to display the angle in the format degrees°minutes' direction
        void showAngle() {
            cout << *degrees << "\xF8" << *minutes << "' " << direction << endl;
        }

        // Destructor: Deallocates dynamically allocated members
        ~Angle() {
            delete degrees;
            delete minutes;
        }
};

// Function to dynamically allocate an Angle object
Angle* DynamicAngle(int deg, float min, char dir) {
    return new Angle(deg, min, dir);
}

// Main function: Tests the Angle class with predefined and user-input angles
int main() {
    Angle angle1(149, 34.8, 'W'); // Create an angle using the constructor

    cout << "1st angle is: ";
    angle1.showAngle(); // Display the first angle

    Angle angle2 = angle1; // Create a copy of angle1
    cout << "Duplicate angle: ";
    angle2.showAngle(); // Display the copied angle

    Angle* angle3 = DynamicAngle(17, 31.5, 'S'); // Dynamically allocate an angle
    cout << "Dynamic angle: ";
    angle3->showAngle(); // Display the dynamically allocated angle

    char choice;
    // Loop to allow the user to input and display angles
    do {
        Angle userAngle(0, 0.0, 'N'); // Create a temporary angle object
        userAngle.getAngle(); // Get angle values from the user
        cout << "You entered: ";
        userAngle.showAngle(); // Display the user-entered angle

        cout << "Do you want to enter another angle? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    delete angle3; // Deallocate the dynamically allocated angle
    return 0;
}