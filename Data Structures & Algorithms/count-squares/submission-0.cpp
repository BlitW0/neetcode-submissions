class CountSquares {
    typedef pair <int, int> pi;
    map <pi, int> pts;
public:
    CountSquares() {}
    
    void add(vector<int> point) {
        pts[{point[0], point[1]}] += 1;
    }
    
    int count(vector<int> point) {
        int px = point[0], py = point[1], ans = 0;
        for (auto& [key, val] : pts) {
            auto [x, y] = key;
            if (x == px) {
                int a = abs(y - py); // length of square
                if (a == 0) continue; // same point square size 0

                // try to make square using pts on left or right parallel
                for (int d = -1; d <= 1; d++)
                    if (d) {
                        pi p1 = {x + d*a, y}, p2 = {x + d*a, py};
                        if (pts.contains(p1) and pts.contains(p2))
                            ans += val * pts[p1] * pts[p2]; // all combs
                    }
            }
        }
        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */