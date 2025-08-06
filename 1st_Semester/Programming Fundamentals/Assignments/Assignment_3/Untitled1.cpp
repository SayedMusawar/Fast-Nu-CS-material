#include <iostream>
using namespace std;

int main() {
		freopen("1.in","r",stdin);
    int t; // Number of test cases
    cin >> t;

    while (t--) {
        int n; // Number of stars
        cin >> n;

        int arr[100]; // Static array for energy levels
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int operations = 0; // Count of operations

        // Repeat until all energy levels are equal
        while (n > 1) {
            bool allEqual = true;
            
            // Check if all elements are equal
            for (int i = 0; i < n; i++) {
                if (arr[i] != arr[0]) { // Compare with the first element
                    allEqual = false;
                    break;
                }
            }

            if (allEqual) break; // Exit if all stars have equal energy

            // Find the first adjacent pair to remove
            for (int i = 0; i < n; i++) {
                int next = (i + 1) % n; // Next element index (circular behavior)

                if (arr[i] <= arr[next]) {
                    // Remove the star at index `next`
                    for (int j = next; j < n - 1; j++) {
                        arr[j] = arr[j + 1];
                    }
                    n--; // Decrease the size of the array
                    operations++; // Increment operations
                    break; // Restart checking from the beginning
                }
            }
        }

        cout << operations << endl; // Output result for the test case
    }

    return 0;
}
