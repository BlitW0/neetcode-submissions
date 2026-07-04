class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() < t.length())
            return "";

        unordered_map <char, int> cnt, cnt2;
        for (char c : t)
            cnt[c]++;
        
        auto checkless = [&cnt, &cnt2]() {
            for (auto p : cnt)
                if (cnt2[p.first] < p.second)
                    return false;
            return true;
        };
        
        int st = 0, en = 0, n = s.length(), i = -1, mlen = INT_MAX;
        while (st <= en and en < n) {
            cnt2[s[en]]++;
            // check if all t chars have suff count
            if (not checkless()) {
                en++;
                continue;
            }
            // move st to remove non-t chars and extra t chars
            while (st <= en and
                    (not cnt.contains(s[st])
                        or cnt2[s[st]] > cnt[s[st]])) {
                            cnt2[s[st++]]--;
                    }

            int len = en - st + 1;
            // found, store start idx and len
            if (len < mlen)
                mlen = len, i = st;
            
            // move both, check for new substrings
            cnt2[s[st++]]--, en++;
        }

        if (i == -1) return "";
        return s.substr(i, mlen);
    }
};