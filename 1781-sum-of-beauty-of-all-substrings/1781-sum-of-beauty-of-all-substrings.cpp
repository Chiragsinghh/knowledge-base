class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int cnt[26] = {0};

            for (int j = i; j < n; j++) {
                cnt[s[j] - 'a']++;

                int mx = 0;
                int mn = INT_MAX;

                for (int k = 0; k < 26; k++) {
                    if (cnt[k] > 0) {
                        mx = max(mx, cnt[k]);
                        mn = min(mn, cnt[k]);
                    }
                }

                ans += mx - mn;
            }
        }

        return ans;
    }
};