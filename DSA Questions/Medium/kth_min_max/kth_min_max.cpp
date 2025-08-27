#include <iostream>
#include <string>
#include<algorithm>
using namespace std;

int main() {
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k =0;

    sort(arr , arr+n);
    cout << "Enter the K term" << endl;
    cin >> k ; 

    cout << "K max term is "  << arr[n-k] << endl;
    cout << "K min term is " << arr[k-1] << endl ; 

    return 0;
}

// finding k min and max term is easy
// you just have to sort the array and then starting terms are min terms
// ending terms are max terms