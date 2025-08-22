#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void findSum(int arr[], int size, int n) {
    sort(arr, arr + size);

    for (int i = 0; i < size - 2; i++) {
        int j = i +1;
        int k = size - 1; 

        while (j < k) {
            int currentSum = arr[i] + arr[j] + arr[k];

            if (currentSum == n) {
                cout << "the pair is: " << arr[i] << " " << arr[j] << " " << arr[k] << endl;
                j++;
                k--;
            } else if (currentSum < n) {
                j++;
            } else {
                k--;
            }
        }
    }
}

int main() {
    int arr[11] = {12, 3, 4, 1, 6, 9, 15, 7, 8, 2,0};
    int size = sizeof(arr) / sizeof(arr[0]);
    findSum(arr, size, 12);

    return 0;
}