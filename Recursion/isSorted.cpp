Method 1:

#include<iostream>
using namespace std;

bool isSorted(int arr[], int size) {
    // Base case
    if(size == 0 || size == 1 ) {
        return true;
    }

    if(arr[0] > arr[1])
        return false;
    else {
        bool remainingPart = isSorted(arr + 1, size - 1 );
        return remainingPart;
    }
}

int main() {
    int arr[5] = {2,4,9,9,9};
    int size = 5;

    bool ans = isSorted(arr, size);

    if(ans){
        cout << "Array is sorted " << endl;
    }
    else {
        cout << "Array is not sorted " << endl;
    }

    return 0;
}

--------------------------------------------------------------------------------------------------------------

Method 2:
#include <iostream>
using namespace std;

bool ifSorted(int arr[], int n, int count=0) {
    // Base case
    if(count == n - 1) return true;

    if(arr[count] > arr[count + 1]) return false;

    return ifSorted(arr, n, count + 1);
}

int main() {
    int arr[] = {2,4,6,8,10};
    int n = sizeof(arr)/sizeof(arr[0]);

    if(ifSorted(arr, n)) cout << "Sorted";
    else cout << "Not sorted";
}
