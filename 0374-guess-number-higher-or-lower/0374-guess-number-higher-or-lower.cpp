/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int s{0}, e{n};

        while (s <= e) {
            int m = (s + (e - s) / 2);
            int res = guess(m);

            if (res == 0) {
                return m;
            } else if (res < 0) {
                e = m - 1;
            } else {
                s = m + 1;
            }
        }

        return -1;
    }
};