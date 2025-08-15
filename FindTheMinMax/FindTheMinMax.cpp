#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr)/sizeof(arr[0]);
    int min  , max = 0;

    for(int i = 0 ; i <10 ; i++)
    {
        if(min > arr[i])
        {
            min = arr[i];
        }
        if(max < arr[i])
        {
            max = arr[i];
        }
    }

    cout << "Minimum Value: " << min << endl;
    cout << "Maximum Value: " << max << endl;


    return 0;
}