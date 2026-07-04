class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() < t.length())
            return "";

        vector <int> cnt(128, 0), cnt2(128, 0);
        for (char c : t)
            cnt[c]++;
        
        auto checkless = [&cnt, &cnt2]() {
            for (int i = 0; i < 128; i++)
                if (cnt[i] and cnt2[i] < cnt[i])
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
            char cst = s[st];
            while ( st <= en and
                    (not cnt[cst] or cnt2[cst] > cnt[cst]) ) {
                            cnt2[cst]--;
                            cst = s[++st];
                    }

            int len = en - st + 1;
            // found, store start idx and len if less than prev min
            if (len < mlen)
                mlen = len, i = st;
            
            // move both, check for new substrings
            cnt2[s[st++]]--, en++;
        }

        if (i == -1) return "";
        return s.substr(i, mlen);
    }
};