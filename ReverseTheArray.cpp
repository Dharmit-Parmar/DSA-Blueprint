#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr)/sizeof(arr[0]);
    int reverseArr[10];
    cout << "Original Array: ";
    for(int i = 0 ; i < 10 ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    for(int i = 0 ; i < size ; i++)
    {
        reverseArr[i] = arr[size - i - 1];
    }

    cout << "\nReversed Array: ";
    for(int i = 0 ; i < size ; i++)
    {
        cout << reverseArr[i] << " ";
    }
    
    return 0;
}