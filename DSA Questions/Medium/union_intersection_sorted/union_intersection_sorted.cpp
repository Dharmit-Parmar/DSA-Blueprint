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
    cout << " The intersection is :" << endl;
    for (int i = 0; i < k; i++)
    {
        cout << result[i] << " ";
    }
}

void findUnion(int arr1[], int n1, int arr2[], int n2)
{
    sort(arr1, arr1 + n1);
    sort(arr2, arr2 + n2);

    int result[n1 + n2];
    int k = 0;

    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (arr1[i] == arr2[j])
        {
           
            if (k == 0 || result[k - 1] != arr1[i])
                result[k++] = arr1[i];
            i++;
            j++;
        }
        else if (arr1[i] < arr2[j])
        {
            if (k == 0 || result[k - 1] != arr1[i])
                result[k++] = arr1[i];
            i++;
        }
        else
        {
            if (k == 0 || result[k - 1] != arr2[j])
                result[k++] = arr2[j];
            j++;
        }
    }
 
    while (i < n1)
    {
        if (k == 0 || result[k - 1] != arr1[i])
            result[k++] = arr1[i];
        i++;
    }

    
    while (j < n2)
    {
        if (k == 0 || result[k - 1] != arr2[j])
            result[k++] = arr2[j];
        j++;
    }

    cout << "\nThe union is:\n";
    for (int x = 0; x < k; x++)
        cout << result[x] << " ";
    cout << endl;




    
    // Your original idea:
    // You wanted to handle duplicates by comparing the current element with the previous
    // in the same array like:
    //    if(arr1[i] == arr1[i-1]) { ... } 
    //    if(arr2[j] == arr2[j-1]) { ... }
    // And if duplicate found, you wanted to store the element from the other array.
    //
    // Why this is wrong:
    // 1. When i=0 or j=0, arr1[i-1] or arr2[j-1] becomes arr1[-1]/arr2[-1] → out-of-bounds access.
    // 2. Using --i or --j in condition (like arr1[--i]) modifies the pointer before comparison.
    //    This can cause wrong comparisons, duplicate insertions, or infinite loops.
    // 3. Your loop condition was while(i < n1 || j < n2) → OR allows one array to finish,
    //    but inside you still access both arrays → out-of-bounds risk.
    // 4. Union logic got mixed: sometimes you inserted elements from both arrays even when
    //    they are duplicates or not in order.
    //
    // Correct idea:
    // - Check the **last inserted element in the result array** instead of moving back pointers.
    // - Use while(i < n1 && j < n2) for traversal.
    // - After main loop, add remaining elements from both arrays with the same duplicate check.
}


int main()
{
    int arr1[] = {1, 4, 5, 5, 6};
    int arr2[] = {1, 2, 2, 3, 5, 7};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);

    findIntersection(arr1, n, arr2, m);
    findUnion(arr1, n, arr2, m);
    return 0;
}