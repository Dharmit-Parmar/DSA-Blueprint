class Solution {
public:
    /**
     * @brief Determines whether a given integer is a valid perfect square.
     *
     * METHODOLOGY:
     * We use a binary search approach within the range [0, num]. For each mid
     * value, we compute its square (cast to long long to prevent integer
     * overflow) and compare it with the target number. If the square matches
     * the target, we return true. If it is smaller, we search the right half;
     * otherwise, we search the left half.
     *
     * COMPLEXITY:
     * - Time Complexity: O(log n), where n is the input integer, because the
     * search space is halved in each iteration.
     * - Space Complexity: O(1), as we only use a few variables for pointers and
     * state.
     */
    bool isPerfectSquare(int num) {
        int s{0}, e{num};
        while (s <= e) {
            int mid = (s + (e - s) / 2);
            long long square = (long long)mid * mid;
            if (square == num)
                return true;
            else if (square < num)
                s = mid + 1;
            else
                e = mid - 1;
        }

        return false;
    }
};