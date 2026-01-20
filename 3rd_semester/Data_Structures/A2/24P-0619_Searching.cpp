#include <iostream>
using namespace std;
void display() {
    cout<<"===== Searching Algorithms ====="<<endl;
    cout<<"1. Linear Search"<<endl;
    cout<<"2. Binary Search"<<endl;

}
void linearSearch() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements:\n";
    for(int i = 0; i < n; i++) cin >> arr[i];

    int target;
    cout << "Enter value to search: ";
    cin >> target;

    bool found = false;
    int index = -1;

    for(int i = 0; i < n; i++) {
        if(arr[i] == target) {
            found = true;
            index = i;
            break;
        }
    }

    if(found) cout << "Element found at index " << index;
    else cout << "Not Found";
}
void binarySearch() {
    int n, target;
    int low = 0;
    int high  = n -1;
    int arr[n];
    bool found = false;
    int index = -1;

    cout << "Enter size of sorted array: ";
    cin >> n;
    cout << "Enter " << n << " sorted elements:\n";
    for(int i = 0; i < n; i++) cin >> arr[i];
    cout << "Enter target value: ";
    cin >> target;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] == target) {
            found = true;
            index = mid;
            break;
        }
        else if(target < arr[mid]) high = mid - 1;
        else low = mid + 1;
    }

    if(found) cout << "Found at index " << index;
    else cout << "Not Found";
}
int binarySearch(int arr[], int low, int high, int target) {
    if(low > high) return -1;

    int mid = (low + high) / 2;

    // If element found
    if(arr[mid] == target) return mid;

    // Search left half
    if(target < arr[mid]) return binarySearch(arr, low, mid - 1, target);

    // Search right half
    return binarySearch(arr, mid + 1, high, target);
}

int main() {
    display();
    int choice; cin >> choice;
    do {
        switch(choice) {
            case 1:
                linearSearch();
            break;
            case 2:
                binarySearch();
            break;
            case 3:
                int n;
                cout << "Enter size of sorted array: ";
                cin >> n;
                int arr[n];
                cout << "Enter " << n << " sorted elements:\n";
                for(int i = 0; i < n; i++) cin >> arr[i];
                int target;
                cout << "Enter target value: ";
                cin >> target;
                int result = binarySearch(arr, 0, n - 1, target);
                if(result != -1) cout << "Found at index " << result;
                else cout << "Not Found";
        }
    } while(choice != 0);

    return 0;
}
