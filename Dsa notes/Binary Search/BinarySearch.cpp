#include <iostream>
#include <string>
using namespace std;

int BinarySearch(int arr[] , int n , int key)
{
    int s = 0 ;
    int e = n-1;

    int mid = (s+e)/2;

    while (s<=e)
    {
        if(arr[mid] == key)
        {
            return mid;
        }
        else if(arr[mid] < key)
        {
            s = mid +1;
        }
        else{
            e = mid -1;
        }
        mid = (s+e)/2;
    }
    

}


int main() {
       int arr[] = {1, 2, 2, 3, 5, 7,8,9,10};
       int size = sizeof(arr) / sizeof(arr[0]);
       int key = 9;
    cout << BinarySearch(arr,size  ,key);
    
    return 0;
}