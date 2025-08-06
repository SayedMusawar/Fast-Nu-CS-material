#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_STUDENTS = 100;
const int MAX_NAME_LENGTH = 50;

// Function to calculate grade based on average marks
char calculateGrade(float average) {
    if (average >= 95) return 'A' + '+';  // Simulating 'A+'
    else if (average >= 85) return 'A';
    else if (average >= 75) return 'B';
    else if (average >= 65) return 'C';
    else if (average >= 50) return 'D';
    else return 'F';
}

// Function to log errors with timestamps
void logError(ofstream &errorFile, const char *message) {
    time_t now = time(0);
    char *dt = ctime(&now); // Get current time
    dt[strlen(dt) - 1] = '\0'; // Remove newline character
    errorFile << "[" << dt << "] " << message << endl;
}

// Inline string-to-integer conversion logic
int convertStringToInt(const char *token) {
    int number = 0;
    int index = 0;

    // Handle negative numbers
    if (token[index] == '-') {
        index++;
    }

    // Convert string to integer
    while (token[index] != '\0') {
        if (token[index] >= '0' && token[index] <= '9') {
            number = number * 10 + (token[index] - '0');
        } else {
            return 0; // Return 0 for invalid characters
        }
        index++;
    }

    return number;
}

// Function to read and validate data from the file
int readData(ifstream &inputFile, int IDs[], char Names[][MAX_NAME_LENGTH], int Marks[][5], int TotalMarks[], float AverageMarks[], char Grades[], ofstream &errorFile) {
    char line[200];
    int studentCount = 0;

    while (inputFile.getline(line, 200)) {
        char *token = strtok(line, ",");
        if (token == nullptr) {
            logError(errorFile, "Invalid line format.");
            continue;
        }

        // Parse ID
        int currentID = convertStringToInt(token);

        // Check for duplicate IDs
        bool duplicateID = false;
        for (int i = 0; i < studentCount; i++) {
            if (IDs[i] == currentID) {
                duplicateID = true;
                break;
            }
        }

        if (duplicateID) {
            logError(errorFile, "Duplicate ID found.");
            continue;
        }

        IDs[studentCount] = currentID;

        // Parse Name
        token = strtok(nullptr, ",");
        if (token == nullptr) {
            logError(errorFile, "Invalid line format.");
            continue;
        }
        strncpy(Names[studentCount], token, MAX_NAME_LENGTH);

        // Parse Marks
        bool validMarks = true;
        TotalMarks[studentCount] = 0;

        for (int i = 0; i < 5; i++) {
            token = strtok(nullptr, ",");
            if (token == nullptr) {
                logError(errorFile, "Invalid marks format.");
                validMarks = false;
                break;
            }
            Marks[studentCount][i] = convertStringToInt(token);
            if (Marks[studentCount][i] < 0 || Marks[studentCount][i] > 100) {
                logError(errorFile, "Marks out of range.");
                validMarks = false;
                break;
            }
            TotalMarks[studentCount] += Marks[studentCount][i];
        }

        if (!validMarks) continue;

        // Calculate average and grade
        AverageMarks[studentCount] = TotalMarks[studentCount] / 5.0;
        Grades[studentCount] = calculateGrade(AverageMarks[studentCount]);
        studentCount++;
    }

    return studentCount;
}

// Function to sort students by rank (total marks, then name alphabetically)
void rankStudents(int studentCount, int IDs[], char Names[][MAX_NAME_LENGTH], int Marks[][5], int TotalMarks[], float AverageMarks[], char Grades[]) {
    for (int i = 0; i < studentCount - 1; i++) {
        for (int j = i + 1; j < studentCount; j++) {
            if (TotalMarks[j] > TotalMarks[i] || (TotalMarks[j] == TotalMarks[i] && strcmp(Names[j], Names[i]) < 0)) {
                // Swap everything for students i and j
                swap(IDs[i], IDs[j]);
                swap(TotalMarks[i], TotalMarks[j]);
                swap(AverageMarks[i], AverageMarks[j]);
                swap(Grades[i], Grades[j]);
                for (int k = 0; k < 5; k++) swap(Marks[i][k], Marks[j][k]);
                char temp[MAX_NAME_LENGTH];
                strcpy(temp, Names[i]);
                strcpy(Names[i], Names[j]);
                strcpy(Names[j], temp);
            }
        }
    }
}

// Function to write processed data to a file
void writeProcessedData(ofstream &processedFile, int studentCount, int IDs[], char Names[][MAX_NAME_LENGTH], int Marks[][5], int TotalMarks[], float AverageMarks[], char Grades[]) {
    processedFile << "Rank, ID, Name, Marks1, Marks2, Marks3, Marks4, Marks5, Total, Average, Grade\n";
    for (int i = 0; i < studentCount; i++) {
        processedFile << i + 1 << ", " << IDs[i] << ", " << Names[i];
        for (int j = 0; j < 5; j++) {
            processedFile << ", " << Marks[i][j];
        }
        processedFile << ", " << TotalMarks[i] << ", " << AverageMarks[i]
                      << ", " << Grades[i] << endl;
    }
}

// Function to search for a student by ID or name
void searchStudent(int studentCount, int IDs[], char Names[][MAX_NAME_LENGTH], int Marks[][5], int TotalMarks[], float AverageMarks[], char Grades[]) {
    cout << "Enter ID or Name to search: ";
    char query[50];
    cin.ignore();
    cin.getline(query, 50);

    bool found = false;
    for (int i = 0; i < studentCount; i++) {
        if (atoi(query) == IDs[i] || strcmp(query, Names[i]) == 0) {
            cout << "ID: " << IDs[i] << ", Name: " << Names[i] << ", Marks: ";
            for (int j = 0; j < 5; j++) {
                cout << Marks[i][j] << " ";
            }
            cout << ", Total: " << TotalMarks[i] << ", Average: " << AverageMarks[i]
                 << ", Grade: " << Grades[i] << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No student found with the given ID or name.\n";
    }
}

// Main function
int main() {
    ifstream inputFile("students.txt");
    ofstream processedFile("processed_students.txt");
    ofstream errorFile("errors.txt");

    if (!inputFile.is_open()) {
        cerr << "Error: Could not open input file.\n";
        return 1;
    }

    if (!processedFile.is_open() || !errorFile.is_open()) {
        cerr << "Error: Could not open output files.\n";
        return 1;
    }

    int IDs[MAX_STUDENTS];
    char Names[MAX_STUDENTS][MAX_NAME_LENGTH];
    int Marks[MAX_STUDENTS][5];
    int TotalMarks[MAX_STUDENTS];
    float AverageMarks[MAX_STUDENTS];
    char Grades[MAX_STUDENTS];
// Task 1: Reading and parsing data
    int studentCount = readData(inputFile, IDs, Names, Marks, TotalMarks, AverageMarks, Grades, errorFile);
    // Task 2: Rank students:
    rankStudents(studentCount, IDs, Names, Marks, TotalMarks, AverageMarks, Grades);
    // Task 4:
    writeProcessedData(processedFile, studentCount, IDs, Names, Marks, TotalMarks, AverageMarks, Grades);

    inputFile.close();
    processedFile.close();
    errorFile.close();

    return 0;
}