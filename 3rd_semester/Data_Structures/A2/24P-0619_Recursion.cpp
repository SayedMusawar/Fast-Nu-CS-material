#include <iostream>
#include <cstring>
using namespace std;

// Q1 Print all subsets of a given set
void printSubsetResult(int subset[], int subsetSize) {
    cout << "{";
    for (int i = 0; i < subsetSize; ++i) {
        cout << subset[i];
        if (i + 1 < subsetSize) cout << ",";
    }
    cout << "}" << endl;
}

void generateSubsets(int arr[], int n, int idx, int subset[], int subsetSize) {
    if (idx == n) {
        printSubsetResult(subset, subsetSize);
        return;
    }
    // Exclude current element
    generateSubsets(arr, n, idx + 1, subset, subsetSize);

    // Include current element
    subset[subsetSize] = arr[idx];
    generateSubsets(arr, n, idx + 1, subset, subsetSize + 1);
}

//Q2: Generate All Permutations of a String
void swapChars(char &a, char &b) {
    char t = a; a = b; b = t;
}

void permuteString(char str[], int l, int r) {
    if (l == r) {
        cout << str << endl;
        return;
    }
    for (int i = l; i <= r; ++i) {
        swapChars(str[l], str[i]);
        permuteString(str, l + 1, r);
        swapChars(str[l], str[i]); // backtrack
    }
}

// Q3: Subset Sum Problem (determine if subset sums to target)
bool subsetSumExistsHelper(int arr[], int n, int idx, int target, int chosen[], int chosenSize) {
    if (target == 0) {
        // print one valid subset
        cout << "Found subset: {";
        for (int i = 0; i < chosenSize; ++i) {
            cout << chosen[i];
            if (i + 1 < chosenSize) cout << ",";
        }
        cout << "}" << endl;
        return true;
    }
    if (idx >= n) return false;
    if (target < 0) return false;

    // Include current
    chosen[chosenSize] = arr[idx];
    if (subsetSumExistsHelper(arr, n, idx + 1, target - arr[idx], chosen, chosenSize + 1)) return true;

    // Exclude current
    if (subsetSumExistsHelper(arr, n, idx + 1, target, chosen, chosenSize)) return true;

    return false;
}

bool subsetSumExists(int arr[], int n, int target) {
    int chosen[100];
    return subsetSumExistsHelper(arr, n, 0, target, chosen, 0);
}

// Q4: Fibonacci Sequence (print first n Fibonacci numbers)
int fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fib(n - 1) + fib(n - 2);
}

// print first n Fibonacci numbers using recursion (prints in order)
void printFibSequence(int n) {
    if (n <= 0) return;
    if (n == 1) {
        cout << 0;
        return;
    }
    // Recursively print first n-1, then print element n-1
    printFibSequence(n - 1);
    cout << " " << fib(n - 1);
}

// Q5: Reverse a String (using recursion)
void reverseStringRec(char s[], int l, int r) {
    if (l >= r) return;
    swapChars(s[l], s[r]);
    reverseStringRec(s, l + 1, r - 1);
}

// Q6a: Find the Power (x^n) using recursion (fast exponentiation)
long long powerRec(long long x, long long n) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        long long half = powerRec(x, n / 2);
        return half * half;
    } else {
        return x * powerRec(x, n - 1);
    }
}

// Q6b: Count Digits of a Number (recursively)
int countDigitsRec(long long num) {
    if (num < 0) num = -num; // handle negative
    if (num < 10) return 1;
    return 1 + countDigitsRec(num / 10);
}

// Q7: Binary Search using Recursion
int binarySearchRec(int arr[], int l, int r, int target) {
    if (l > r) return -1;
    int mid = l + (r - l) / 2;
    if (arr[mid] == target) return mid;
    else if (arr[mid] > target) return binarySearchRec(arr, l, mid - 1, target);
    else return binarySearchRec(arr, mid + 1, r, target);
}

// Q8: Find Maximum Element in Array (using recursion)
int findMaxRec(int arr[], int n) {
    if (n == 1) return arr[0];
    int maxOfRest = findMaxRec(arr, n - 1);
    return (arr[n - 1] > maxOfRest) ? arr[n - 1] : maxOfRest;
}

// Q9: Count Occurrences of a Number in Array (recursively)
int countOccurrencesRec(int arr[], int n, int idx, int target) {
    if (idx == n) return 0;
    int add = (arr[idx] == target) ? 1 : 0;
    return add + countOccurrencesRec(arr, n, idx + 1, target);
}

// Q10: Reverse an Array using Recursion
void reverseArrayRec(int arr[], int l, int r) {
    if (l >= r) return;
    int t = arr[l]; arr[l] = arr[r]; arr[r] = t;
    reverseArrayRec(arr, l + 1, r - 1);
}
int main() {
    cout << "--- Problem 1: All Subsets (Power Set) ---" << endl;
    int set1[] = {1,2,3};
    int n1 = 3;
    int subset[10];
    generateSubsets(set1, n1, 0, subset, 0);
    cout << endl;

    cout << "--- Problem 2: Permutations of a String ---" << endl;
    char s2[] = "ABC"; // make sure it's modifiable
    permuteString(s2, 0, (int)strlen(s2) - 1);
    cout << endl;

    cout << "--- Problem 3: Subset Sum Problem ---" << endl;
    int arr3[] = {3,34,4,12,5,2};
    int n3 = 6;
    int target3 = 9;
    bool exists = subsetSumExists(arr3, n3, target3);
    cout << "Subset sum exists: " << (exists ? "true" : "false") << endl;
    cout << endl;

    cout << "--- Problem 4: Fibonacci Sequence ---" << endl;
    int fn = 5;
    printFibSequence(fn);
    cout << endl << endl;

    cout << "--- Problem 5: Reverse a String ---" << endl;
    char s5[] = "hello";
    reverseStringRec(s5, 0, (int)strlen(s5) - 1);
    cout << s5 << endl << endl;

    cout << "--- Problem 6a: Power (x^n) ---" << endl;
    long long x = 2;
    long long p = 5;
    cout << x << "^" << p << " = " << powerRec(x, p) << endl << endl;

    cout << "--- Problem 6b: Count Digits of a Number ---" << endl;
    long long num6 = 12345;
    cout << "Digits in " << num6 << " = " << countDigitsRec(num6) << endl << endl;

    cout << "--- Problem 7: Binary Search (Recursion) ---" << endl;
    int arr7[] = {1,2,3,4,5,6};
    int idx7 = binarySearchRec(arr7, 0, 5, 4);
    if (idx7 >= 0) cout << "Found at index " << idx7 << endl; else cout << "Not found" << endl;
    cout << endl;

    cout << "--- Problem 8: Find Maximum Element in Array ---" << endl;
    int arr8[] = {3,9,1,7,5};
    cout << "Maximum = " << findMaxRec(arr8, 5) << endl << endl;

    cout << "--- Problem 9: Count Occurrences of a Number in Array ---" << endl;
    int arr9[] = {1,2,3,2,4,2};
    cout << "Occurrences of 2 = " << countOccurrencesRec(arr9, 6, 0, 2) << endl << endl;

    cout << "--- Problem 10: Reverse an Array using Recursion ---" << endl;
    int arr10[] = {1,2,3,4,5};
    reverseArrayRec(arr10, 0, 4);
    cout << "Reversed array: ";
    for (int i = 0; i < 5; ++i) cout << arr10[i] << (i+1<5? ",":"");
    cout << endl << endl;

    return 0;
}
