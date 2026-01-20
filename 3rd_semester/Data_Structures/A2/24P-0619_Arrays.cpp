#include<iostream>
using namespace std;
class Arr{
private:
    int *data,size,capacity;
    int index, val;


    bool isEmpty() {
        if(size == -1) return true;
        else return false;
    }

    bool isFull() {
        if(size == capacity - 1) return true;
        else return false;
    }

    int insertion(int index, int value) {
        if ( *(data + index) != 0 ){
            for (int i=size; i>=index; i--)
                *(data +i+1) = *(data +i);
        }else if ( (index != 0) && (*(data + index-1) == 0) ){ // (index != 0) to stop accessing the location data[-1].
            index = size + 1;
            cout<<"\n to maintain linearity/sequence in the list changing index to: "<<index;
        }
        *(data + index) = value;
        ++size;
        return index;
    }

    int deletion(int index) {
        int value = *(data + index);
        *(data + index) =  0;      // hypothetical deletion: using zero as a sentinel number, showing absence of data.
        for (int i=index; i<size; i++)
            *(data + i) = *(data +i+1);
        *(data + size) = 0; //to remove copy of the data from the last location.
        --size;
        return value;
    }

    int search(int value,int searchType){
        int index = -1;
        if (!searchType){
            for (int i=0; i<=size; i++)
                if (*(data+i) == value) return i;
        }
        else{
            int low=0, high=size,mid=0;
            while (low <= high){
                mid = (low + high)/2;
                if (*(data + mid) == value) return mid;
                else if (*(data + mid)<value) low = mid + 1;
                else high = mid - 1;
            }
        }
        return index;
    }

    int findMinimum(int startingLocation){
        int index = startingLocation, smallest = *(data+startingLocation);
        for (int i = startingLocation + 1; i<=size; i++){
            if (*(data + i)<smallest){
                smallest = *(data + i);
                index = i;
            }
        }
        return index; // returns index of smallest value in the list under consideration.
    }

    int findMaximum(int startingLocation){
        int index = startingLocation, largest = *(data+startingLocation);
        for (int i = startingLocation + 1; i<=size; i++){
            if (*(data + i)>largest){
                largest = *(data + i);
                index = i;
            }
        }
        return index; // returns index of largest value in the list under consideration.
    }

    void swap(int &a, int &b){
        int temp = a;
        a = b;
        b = temp;
    }

    void sort(int order){
        int index = -1;
        if (!order){
            for(int i=0; i<size; i++){
                index = findMinimum(i);
                swap(*(data + index),*(data + i));
            }
        }else{
            for (int i=0; i<size; i++){
                index = findMaximum(i);
                swap(*(data + index),*(data + i));
            }
        }
    }

    // Majority elements
    int majorityElement() {
        if(isEmpty()) return -1;

        // Boyer-Moore Voting algorithm
        int candidate = *(data + 0);
        int counter = 1;

        // Find candidates

        for(int i = 1; i<= size; i++) {
            if(counter == 0) {
                candidate =  *(data + i);
                counter = 1;
            } else if(*(data + i) == candidate) counter++;
            else counter--;
        }
        return candidate;
    }

    int subArraySum(int k) {
        if(isEmpty()) return 0;

        int count = 0;

        for(int i = 0; i <= size ; i++) {
            int currSum = 0;
            for(int j = i; j <= size; j++) {
                currSum += *(data + j);

                if(currSum == k) count++;
            }
        }
        return count;
    }

    int longestSubArray(int k) {
        if(isEmpty()) return 0;

        int maxLength = 0;

        for(int i = 0; i<= size ; i++) {
            int currSum = 0;
            for(int j = i;  j<= size ; j++) {
                currSum += *(data + j);

                if(currSum <= k) {
                    int currLength = j - i + 1;
                    if(currLength > maxLength) maxLength = currLength;
                }
            }
        }
        return maxLength;
    }

public:
    Arr(int cap) : size(-1), capacity(cap) {
        data = new int[capacity];
    }

    void insertion() {
        if(isFull()) {
            cout<<"Overflow!!!"<<endl;
            return;
        }
        cout<<"Enter the index in which you want to enter the value (must start index from 1)"<<endl;
        cin >> index;
        index--;
        if(index < 0) {
            cout<<"Invalid index!...  Index must be greater than 0"<<endl;
            return;
        } else if(index >= capacity) {
            cout<<"Index must be less than "<<capacity<<". Couldn't add the value"<<endl;
            return;
        }
        cout<<"Enter the value you want to add"<<endl;
        cin >> val;
        insertion(val,index);
    }

    void deletion() {
        if ( isEmpty() ) return;
        int index = -1,value=0, choice=0;
        cout<<"\n\n enter choice for deletion: ( 1 by index ) or ( 2 by value ) = ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"\n enter index [0 to "<<size<<"] = "; cin>>index;
                if ( index<0 || index>size ) {
                        cout <<"\n invalid index";
                        return;
                }
                value = deletion(index);
                break;
            case 2:
                cout<<"\n enter value for deletion: "; cin>>value;
                index = search(value,0); // passing zero for linear search
                if (index == -1) cout<<"\n value not present in array. "; return;
                value = deletion(index);
                break;
            default:
                cout<<"\n invalid choice, try again! "; return;
        }
        cout<<"\n value: "<<value<<" successfully deleted from index"<<index<<", new size of array =  "<<size+1;
    }

    void search() {
        if (isEmpty()) return;
        int value = 0, searchType=0;
        cout<<"\n enter value for searching = "; cin>>value;
        cout<<"\n enter type of search: 0 for Linear Search, 1 for Binary Search = "; cin>>searchType;
        if (searchType){
            cout<<"\n sorting data in ascending for binary search (original indexes changed) ";
            sort(0); //we used zero for ascending order sorting in our logic.
        }
        int index = search(value,searchType);
        (index == -1) ? cout<<"\n\t value not found" : cout<<"\n\t value found at index = "<<index;
    }

    void display() {
        if (isEmpty()) return;
        cout<<"\n values in array = ";
        for (int i=0; i<=size; i++) cout<<*(data + i)<<" ";
    }

    void sort() {
        if (isEmpty()) return;
        int order = 0;
        cout<<"\n Enter 0 for Ascending Order, 1 for Descending Order = ";
        cin>>order;
        sort(order);
        if (!order) cout<<"\n data successfully sorted in Ascending Order";
        else cout<<"\n data successfully sorted in Descending Order";
    }

    // Q1 Remove Duplicates
    void removeDuplicates() {
        if(isEmpty()) {
            cout<<"Array is empty"<<endl;
            return;
        }
        int index = 0;
        for(int i = 1; i<= size; i++) {
            if(*(data + i) != *(data + index)) {
                index++;
                *(data+ index) = *(data + i);
            }
        }
        size = index;
    }
    
    // Q2 Longest Consecutive Sequence
    int longestConsecutive() {
        if(isEmpty()) {
            cout<<"Array is empty"<<endl;
            return 0;
        }
        // Sort the array in ascending order;
        sort(0);

        int longest = 1;
        int curr = 1;

        for(int i = 0; i< size ;i++) {
            if (*(data + i) == *(data + i -1)) continue; //Skip the duplicates

            // Check if consecutive
            if(*(data + i) == *(data + i -1) + 1) curr++;
            else {
                longest = max(longest, curr);
                curr = 1;
            }
        }

        longest = max(longest, curr);

        return longest;
    }

    // Q3 Find Triplets
    void findTriplets() {
        if(size > 2) {
            cout<<"Not enough elements"<<endl;
            return;
        }
        // Sort in ascending order
        sort(0);

        for(int i =0; i<= size - 2; i++) {
            // Avoid duplicates
            if(i >0 && *(data + i) == *(data + i -1)) continue;

            int left = i + 1;
            int right = size;
            while(left < right) {
                int sum = *(data + i) + *(data + left) + *(data + right);

                if(sum == 0) {
                    cout<<"["<<*(data + i)<<","<<*(data + left) <<", "<<*(data + right)<<"]"<<endl;

                    //  move left pointer to next new value
                    int lastLeft = *(data + left);
                    while(left < right && *(data + left) == lastLeft) left++;

                    // move right pointer to next new value
                    int lastRight = *(data + right);
                    while(left < right && *(data+right) == lastRight) right--;
                } else if(sum < 0) left++;
                else right--;
            }
        }
    }

    // Q4 move Zeroes
    void moveZeroes() {
        if(isEmpty()) {
            cout<<"Array is empty"<<endl;
            return;
        }
        int pos = 0;

        for(int i = 0;i <= size; i++) {
            if(*(data + i) != 0) {
                *(data + pos) = *(data+i);
                pos++;
            }
        }
        while(pos <= size) {
            *(data + pos) = 0;
            pos++;
        }
    }

    // Q5 Majority elements that appears more than n/2 times
    void findMajority() {
        if(isEmpty()) {
            cout<<"Array is empty"<<endl;
            return;
        }
        int majority = majorityElement();
        cout<<"Majority element is: "<<majority<<endl;
    }

    // Q6 Subarray sum equals to k
    void subArrSum() {
        if(isEmpty()) {
            cout<<"Array is empty"<<endl;
            return;
        }

        int k = 0;
        
        for(int i = 0; i <= size; i++) {
            int currSum = 0;
            for(int j = i; j <= size ; j++) {
                currSum += *(data + j);

                if(currSum == k) {
                    cout<<"[";
                    for(int k = i;i<= j; i++) {
                        cout<<*(data + k);
                        if(k < j) cout<<", ";
                    }
                    cout<<"] (indices "<<i<<"-"<< j<<")"<<endl;
                }
            }
        }
    }

    // Q7 Find length of longest array whose sum is equal to k
    void longestSubArray() {
        if(isEmpty()) {
            cout<<"Array is empty"<<endl;
            return;
        }
        int k = 0;
        cout<<"Enter the target sum "; cin >> k;

        int maxLength = longestSubArray(k);

        if(maxLength > 0) {
            for(int i = 0; i <= size; i++) {
                int currSum = 0;

                for(int j = i; j <= size ; j++) {
                    currSum += *(data + j);

                    if(currSum <= k && (j - i +1) == maxLength) {
                        cout<<"[";
                        for(int k = i; k<= j; k++) {
                            cout<<*(data + k);
                            if(k < j) cout<<", ";
                            cout<<"] (indices"<<i<<"-"<<j<<", sum = "<<currSum<<")"<<endl;
                        }
                    }
                }
            }
        }
    }
};
void displayMenu() {
    cout<<"===== ARRAY LIST MENU ====="<<endl;
    cout<<"1. Insert a value in the list"<<endl;
    cout<<"2. Delete a value from the list"<<endl;
    cout<<"3. Search a value in the list"<<endl;
    cout<<"4. Find Minimum"<<endl;
    cout<<"5. Find Maximum"<<endl;
    cout<<"6. Remove Duplicates from the list"<<endl;
    cout<<"7. Longest Consecutive Sequence"<<endl;
    cout<<"8. Find Triplets that sum to 0"<<endl;
    cout<<"9. Move zeros to the end of array"<<endl;
    cout<<"10. Majority elements that appears more than /2 times"<<endl;
    cout<<"11. Find the subarray whose sum is equal to k"<<endl;
    cout<<"12. Find length of longest array whose sum is equal to k"<<endl;
    cout<<"13. Display values"<<endl;
    cout<<"0. Exit"<<endl;
}
int main() {
    Arr a(20);

    a.removeDuplicates();
    a.display();

    return 0;
}