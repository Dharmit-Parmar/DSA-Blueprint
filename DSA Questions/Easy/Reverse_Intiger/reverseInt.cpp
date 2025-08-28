#include <iostream>
#include <string>
using namespace std;

// here is the leetcode solution
class Solution
{
public:
    int reverse(int x)
    {
        int result = 0;
        // here imaginge x is 234
        // now we take the

        while (x != 0)
        {
            int digit = x % 10;
            x = x / 10;
            // this is to check the overflow means the value dont get outof bound
            // if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > 7))
            //     return 0;
            // if (result < INT_MIN / 10 || (result == INT_MIN / 10 && digit < -8))
            //     return 0;

            result = result * 10 + digit;
        }
        return result;
    }
};

int main()
{

    return 0;
}