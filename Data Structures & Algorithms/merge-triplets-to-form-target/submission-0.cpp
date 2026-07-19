class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool a = 0, b = 0, c = 0;
        int tx = target[0], ty = target[1], tz = target[2];

        for (auto& t : triplets) {
            int x = t[0], y = t[1], z = t[2];
            if (x == tx and y <= ty and z <= tz) a = 1;
            if (x <= tx and y == ty and z <= tz) b = 1;
            if (x <= tx and y <= ty and z == tz) c = 1;
        }

        return a and b and c;
    }
};