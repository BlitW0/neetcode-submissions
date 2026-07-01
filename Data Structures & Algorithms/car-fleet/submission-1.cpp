class Solution {
public:
    typedef pair <int, int> pi;

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        
        vector <pi> cars(n);
        for (int i = 0; i < n; i++)
            cars[i] = {position[i], speed[i]};
        sort(cars.rbegin(), cars.rend());

        stack <pi> fl;
        for (auto p : cars) {
            if (fl.empty()) {
                fl.push(p);
                continue;
            }

            pi nxt = fl.top();
            int nsp = nxt.second, npos = nxt.first;
            int sp = p.second, pos = p.first;

            // compare time to reach target = (target - pos) / speed
            // with the top of stack (car leading next fleet)
            // if p takes more time than stack top (fleet leader)
            // create new fleet with leader as p
            if ( (target - pos)*nsp > (target - npos)*sp )
                fl.push(p);
        }

        return fl.size();
    }
};
