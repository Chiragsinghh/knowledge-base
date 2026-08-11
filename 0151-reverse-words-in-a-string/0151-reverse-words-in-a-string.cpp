class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        stack<string> a;

        int i = 0;
        int n = s.size();

        // Skip leading spaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        while (i < n) {
            string curr = "";

            // Build one word
            while (i < n && s[i] != ' ') {
                curr.push_back(s[i]);
                i++;
            }

            if (!curr.empty()) {
                a.push(curr);
            }

            // Skip multiple spaces
            while (i < n && s[i] == ' ') {
                i++;
            }
        }

        // Pop words in reverse order
        while (!a.empty()) {
            ans += a.top();
            a.pop();

            if (!a.empty()) {
                ans += " ";
            }
        }

        return ans;
    }
};