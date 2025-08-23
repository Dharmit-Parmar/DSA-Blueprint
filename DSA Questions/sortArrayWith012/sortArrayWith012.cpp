#include <iostream>
#include <string>
#include <vector>
using namespace std;

void swap(int& a , int &b){
    int temp;
    temp = a;
    a = b ;
    b = temp;

}

int main() {
    int arr[10] = { 2, 1, 0, 1, 2, 0, 2, 1, 0, 1};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    cout << "Original Array: ";
    for(int i = 0 ; i < size ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;


    // sorting start here
    for(int i = 0 ; i<size ; i++)
    {
        for(int  j = i ; j < size ; j++)
        {
            if(arr[i] > arr[j])
            {
                swap(arr[i] , arr[j]);
            }
        }
    }


    cout << "Sorted Array: ";
    for(int i = 0 ; i < size ; i++)
    {
        cout << arr[i] << " ";
    }   
    cout << endl;
    return 0;
}