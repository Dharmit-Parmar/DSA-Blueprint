#include <iostream>
#include <string>
#include<vector>
using namespace std;

int maxSum(vector<int>a)
{
       int currsum = a[0];   // start with first element
    int maxsum = a[0];    // global max also starts with first

    for (int i = 1; i < a.size(); i++) {
        // Either extend previous subarray OR start fresh from a[i]
        currsum = max(a[i], currsum + a[i]);
        maxsum = max(maxsum, currsum);
    }
    return maxsum ; 
    
}


int main() {
     vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};

     cout << "maxsum is : " << maxSum(nums) << endl; 
    
    return 0;
}