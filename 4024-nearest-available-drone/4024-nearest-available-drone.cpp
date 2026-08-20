class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int n = drones.size() ;
        int closDrone = -1;
        int minDistance = INT_MAX;
        for(int i{0} ; i<n ; i++)
        {
            int x = drones[i][0];
            int y = drones[i][1];
            int r = drones[i][2];

            int d = abs(x-target[0]) + abs(y-target[1]);
            if(d<minDistance && d <= r)
            {
                minDistance = d;
                closDrone = i;
            }
        }

        return closDrone;
    }
};