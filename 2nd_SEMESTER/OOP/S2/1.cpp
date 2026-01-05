#include <iostream>
using namespace std;

// Base class for mammals
class Mammal {
public:
    void makeSound() {
        cout << "Mammal sound: Bark" << endl;
    }
};

// Base class for birds
class Bird {
public:
    void makeSound() {
        cout << "Bird sound: Chirp" << endl;
    }
};

// Base class for movement
class Movement {
public:
    void move() {
        cout << "Animal is moving..." << endl;
    }
};

// Derived class from Mammal, Bird and Movement
class AnimalType : public Mammal, public Bird, public Movement {
public:
    // Mammal::makeSound();
    void makeSound() {
        Mammal::makeSound();
        Bird::makeSound();
    }
};

int main() {
    AnimalType animal;

    animal.move();        // Calls overridden move() in AnimalType
    animal.makeSound();   // Calls overridden makeSound() in AnimalType

    return 0;
}
