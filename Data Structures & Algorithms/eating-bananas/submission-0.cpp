class Solution {
public:
    typedef long long ll;

    ll numHours(vector<int>& piles, int k) {
        ll hrs = 0;
        for (int x : piles) {
            hrs += x/k + (x % k != 0);
        }
        return hrs;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        ll lo = 1, hi = 1e18, mid, ans = 1e18;

        while (lo <= hi) {
            mid = (hi + lo) >> 1;
            ll hrs = numHours(piles, mid);

            if (hrs > h) lo = mid + 1;
            else {
                ans = mid;
                hi = mid - 1;
            }
        }

        return ans;
    }
};