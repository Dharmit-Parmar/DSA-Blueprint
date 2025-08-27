#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main() {
    
    int arr[10] = {1, -3, 2, -2, 5, -1, 4, -7, 0, 8};
    int size = sizeof(arr)/sizeof(arr[0]);

    // after sorting all the element automatic came to left

    cout << "Original Array: ";
    for(int i = 0 ; i < size ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;


    int index = 0 ;
    for(int i = 0 ; i<size ; i++)
    {
        if(arr[i] < 0)
        {
            swap(arr[i] , arr[index]);
            index ++;
        }
         
    }


    cout << "final Array: ";
    for(int i = 0 ; i < size ; i++)
    {
        cout << arr[i] << " ";
    }   
    cout << endl;
    return 0;
}