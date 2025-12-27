#include <iostream>
#include <algorithm>

using namespace std;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void brootForceSum(int arr[], int size, int n)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (n == (arr[i] + arr[j]))
            {
                cout << arr[i] << " " << arr[j] << endl;
            }
        }
    }
}

void afterSotingTheArr(int arr[], int size, int n)
{
    int theNearestIndex;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(&arr[i], &arr[j]);
            }
            if (arr[j] <= n)
            {
                theNearestIndex = j;
            }
        }
    }

    for (int i = theNearestIndex; i > 0; i--)
    {
        for (int j = 0; j < theNearestIndex; j++)
        {
            if (n == (arr[i] + arr[j]))
            {
                cout << arr[i] << " " << arr[j] << endl;
            }
        }
    }
}

void finalApproch(int arr[], int size, int n)
{
    sort(arr, arr + size);
    int left = 0;
    int right = size - 1;

    while (left < right)
    {
        int sum = arr[left] + arr[right];
        if (sum == n)
        {
            cout << arr[left] << " " << arr[right] << endl;
            left++;
            right--;
        }
        else if (sum < n)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
}

int main()
{
    int arr[11] = {10, 7, 2, 3, 1, 5, 8, 9, 4, 0, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    int n;
    cout << "Enter the number : ";
    cin >> n;

    cout << "This one is Brootforce approch : " << endl;
    brootForceSum(arr, size, n);

    cout << "\n This one is Brootforse but after sorting with new algorithem : " << endl;
    afterSotingTheArr(arr, size, n);

    cout << "\n The final approch is : " << endl;
    finalApproch(arr, size, n);
    return 0;
}