#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>

using namespace std;

// Fixed limit for simplicity
const int MAX_STUDENTS = 100;

// Function to log errors
void logError(const string &message) {
    ofstream errorFile("errors.txt", ios::app);
    if (errorFile.is_open()) {
        errorFile << "Error: " << message << endl;
        errorFile.close();
    }
}

// Function to validate a single record
bool validateRecord(const string &line, int &id, string &name, int marks[]) {
    size_t pos = 0, prev_pos = 0;
    int count = 0;

    try {
        while ((pos = line.find(',', prev_pos)) != string::npos) {
            string value = line.substr(prev_pos, pos - prev_pos);
            count++;
            if (count == 1) {
                id = stoi(value);
            } else if (count == 2) {
                name = value;
            } else if (count >= 3 && count <= 7) {
                int mark = stoi(value);
                if (mark < 0 || mark > 100) return false;
                marks[count - 3] = mark;
            }
            prev_pos = pos + 1;
        }

        // Process the last value
        if (count == 7) {
            int mark = stoi(line.substr(prev_pos));
            if (mark < 0 || mark > 100) return false;
            marks[4] = mark;
        } else {
            return false;
        }
    } catch (...) {
        return false;
    }

    return count == 7;
}

// Function to calculate grade
string calculateGrade(double average) {
    if (average >= 95) return "A+";
    if (average >= 85) return "A";
    if (average >= 75) return "B";
    if (average >= 65) return "C";
    if (average >= 50) return "D";
    return "F";
}

// Function to process the input file
void processFile(const string &inputFile, const string &outputFile) {
    ifstream inFile(inputFile);
    ofstream outFile(outputFile);

    if (!inFile.is_open()) {
        logError("File not found: " + inputFile);
        return;
    }

    if (!outFile.is_open()) {
        logError("Failed to open output file: " + outputFile);
        return;
    }

    // Prepare to store data in arrays
    int totalStudents = 0;
    int ids[MAX_STUDENTS];
    string names[MAX_STUDENTS];
    int marks[MAX_STUDENTS][5];
    int totals[MAX_STUDENTS];
    string grades[MAX_STUDENTS];
    double averages[MAX_STUDENTS];

    string line;
    while (getline(inFile, line) && totalStudents < MAX_STUDENTS) {
        int id, marksArray[5];
        string name;

        if (validateRecord(line, id, name, marksArray)) {
            int sum = 0;
            for (int i = 0; i < 5; i++) {
                sum += marksArray[i];
            }
            double avg = sum / 5.0;
            string grade = calculateGrade(avg);

            // Store data into arrays
            ids[totalStudents] = id;
            names[totalStudents] = name;
            for (int i = 0; i < 5; i++) {
                marks[totalStudents][i] = marksArray[i];
            }
            totals[totalStudents] = sum;
            averages[totalStudents] = avg;
            grades[totalStudents] = grade;

            totalStudents++;
        } else {
            logError("Invalid record: " + line);
        }
    }
    inFile.close();

    // Manually sort based on total marks descending and by name alphabetically in case of tie
    for (int i = 0; i < totalStudents - 1; i++) {
        for (int j = i + 1; j < totalStudents; j++) {
            if (totals[j] > totals[i] || (totals[j] == totals[i] && names[j] < names[i])) {
                // Swap logic
                swap(ids[i], ids[j]);
                swap(names[i], names[j]);
                for (int k = 0; k < 5; k++) {
                    swap(marks[i][k], marks[j][k]);
                }
                swap(totals[i], totals[j]);
                swap(averages[i], averages[j]);
                swap(grades[i], grades[j]);
            }
        }
    }

    // Write sorted data to the output file
    outFile << "Rank,ID,Name,Marks1,Marks2,Marks3,Marks4,Marks5,Total,Average,Grade\n";

    for (int i = 0; i < totalStudents; i++) {
        outFile << i + 1 << "," << ids[i] << "," << names[i] << ",";
        for (int j = 0; j < 5; j++) {
            outFile << marks[i][j] << (j < 4 ? "," : "");
        }
        outFile << "," << totals[i] << "," << fixed << setprecision(2) << averages[i] << "," << grades[i] << endl;
    }

    outFile.close();
}

// Function to search for a student
void searchStudent(const string &file, const string &query) {
    ifstream inFile(file);
    if (!inFile.is_open()) {
        logError("File not found: " + file);
        return;
    }

    string line;
    bool found = false;
    while (getline(inFile, line)) {
        if (line.find(query) != string::npos) {
            cout << line << endl;
            found = true;
        }
    }
    if (!found) cout << "Student not found." << endl;
    inFile.close();
}

// Main function
int main() {
    string inputFile = "students.txt";
    string outputFile = "processed_students.txt";

    processFile(inputFile, outputFile);

    string query;
    cout << "Enter student ID or name to search: ";
    cin >> query;

    searchStudent(outputFile, query);

    return 0;
}
