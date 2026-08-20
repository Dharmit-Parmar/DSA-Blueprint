class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int totalTime = 0;
        int prev = 0;

        for (int i = 0; i < requests.size(); i++) {
            totalTime += abs(requests[i] - prev);
            prev = requests[i];
        }

        return totalTime;
    }
};