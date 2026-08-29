class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        for (auto const e : asteroids) {
            if (s.empty()) {
                s.push(e);
                continue;
            }

            // If stack top is moving left (< 0) and e is moving right (> 0),
            // they are moving away from each other — no collision.
            if (s.top() < 0 && e > 0) {
                s.push(e);
                continue;
            }

            // check the direction (same sign means same direction, no
            // collision)
            if (signbit(s.top()) == signbit(e)) {
                s.push(e);
                continue;
            }

            bool destroyed = false;
            while (!s.empty() && s.top() > 0 && e < 0 &&
                   abs(s.top()) < abs(e)) {
                s.pop();
            }

            // if stack top is greater now then e should destroy
            if (!s.empty() && s.top() > 0 && e < 0) {
                if (abs(s.top()) == abs(e)) {
                    s.pop();
                }
                destroyed = true;
            }

            // if still remains the rock then push it
            if (!destroyed) {
                s.push(e);
            }
        }

        vector<int> res(s.size());
        for (int i = s.size() - 1; i >= 0; --i) {
            res[i] = s.top();
            s.pop();
        }
        return res;
    }
};