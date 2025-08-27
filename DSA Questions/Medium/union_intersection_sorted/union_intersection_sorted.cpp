#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void findIntersection(int arr1[], int n1, int arr2[], int n2)
{
    sort(arr1, arr1 + n1);
    sort(arr2, arr2 + n2);

    int result[min(n1, n2)];
    int k = 0;

    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (arr1[i] == arr2[j])
        {

            result[k++] = arr1[i];

            i++;
            j++;
        }
        else if (arr1[i] < arr2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    cout << " The intersection is : \n"
         << endl;
    for (int i = 0; i < k; i++)
    {
        cout << result[i] << " ";
    }
}

void findUnion(int arr1[], int n1, int arr2[], int n2)
{
    sort(arr1, arr1 + n1);
    sort(arr2, arr2 + n2);

    int result[max(n1, n2)];
    int k = 0;
    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if(arr1[i] == arr2[j])
        {
            result = arr1[i];
        }
       
    }

    cout << " The union is : \n"
         << endl;
    for (int i = 0; i < k; i++)
    {
        cout << result[i] << " ";
    }
}
int main()
{
    int arr1[] = {1, 4, 5,5, 6};
    int arr2[] = {1,2,2, 3, 5, 7};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);

    findIntersection(arr1, n, arr2, m);
    findUnion(arr1, n, arr2, m);
    return 0;
}