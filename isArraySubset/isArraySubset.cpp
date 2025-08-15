//Find whether an array is a subset of another array



#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int firstApproch(int a[], int b[], int sa, int sb);
int finalApproch(int a[], int b[], int sa, int sb);

int main()
{
    int A[] = {5, 1, 3, 4, 2};
    int B[] = {4, 2, 5};
    int C[] = {5, 8, 3};
    int sizeA = sizeof(A) / sizeof(A[0]);
    int sizeB = sizeof(B) / sizeof(B[0]);
    int sizeC = sizeof(C) / sizeof(C[0]);

    firstApproch(A, B, sizeA, sizeB);
    firstApproch(A, C, sizeA, sizeC);
    finalApproch(A, B, sizeA, sizeB);
    finalApproch(A, C, sizeA, sizeC);
    return 0;
}

int firstApproch(int a[], int b[], int sa, int sb)
{
    sort(a, a + sa);
    sort(b, b + sb);

    int count = 0;
    for (int i = 0; i < sa; i++)
    {
        for (int j = 0; j < sb; j++)
        {
            if (a[i] == b[j])
            {
                count++;
            }
            if (i == j)
            {
                break;
            }
        }
    }

    if (count == sb)
    {
        cout << "B is subset of A" << endl;
    }
    else
    {
        cout << "B is not subset of A" << endl;
    }
    return 0;
}

int finalApproch(int a[], int b[], int sa, int sb)
{
    sort(a, a + sa);
    sort(b, b + sb);
    int i = 0, j = 0, count = 0;
    while (i < sa && j < sb)
    {
        if (a[i] == b[j])
        {
            i++;
            j++;
            count++;
        }
        else if (a[i] < b[j])
        {
            i++;
        }
        else
        {
            cout << "the element is not subset of the parent" << endl;
            return -1;
        }
    }
    if (count == sb)
    {
        cout << "the element is subset of parent" << endl;
    }
    else
    {
        cout << "the element is not subset of parent" << endl;
    }
    return 0;
}
