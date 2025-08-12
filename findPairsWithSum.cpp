#include <iostream>
#include <string>
#include <vector>
using namespace std;

// here is applying broot force method to find pairs with sum
void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
void brootForceSum(int arr[], int size, int n)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (n == (arr[i] + arr[j]))
            {
                cout << "Your number of pairs are : " << " ";
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
                int temp;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
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
                cout << "Your number of pairs are : " << " ";
                cout << arr[i] << " " << arr[j] << endl;
            }
        }
    }
}

void finalApproch(int arr[], int size, int n)
{
    int i = 0, j = 0;
    // for (int i = 0; i < size; i++)
    // {
    //     for (int j = i + 1; j < size; j++)
    //     {

    //         if (arr[i] > arr[j])
    //         {
    //             int temp;
    //             temp = arr[i];
    //             arr[i] = arr[j];
    //             arr[j] = temp;
    //         }
    //     }
    // }
    while (i != size && j != size)
    {
        if (arr[i] > arr[j])
        {
            swap(arr[i], arr[j]);
           
        }
         if(j ==size -1)
            {
                i++;
                j = i ;
                continue;
            }
            j++;
    }

    i = size - 1, j = 0;
    while (i > j)
    {

        if ((arr[i] + arr[j]) > n)
        {
            i--;
        }
        else if ((arr[i] + arr[j]) < n)
        {
            j++;
        }
        else if ((arr[i] + arr[j]) == n)
        {

            cout << "The pairs are : " << arr[i] << " " << arr[j] << endl;
            cout << "The pairs are : " << arr[j] << " " << arr[i] << endl;
            i--;
            j++;
        }
    }
     
}

int main()
{
    int arr[11] = {10,7,2,3,1,5,8,9,4,0,6};
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