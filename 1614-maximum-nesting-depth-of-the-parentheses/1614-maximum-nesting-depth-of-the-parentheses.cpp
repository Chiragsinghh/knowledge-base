class Solution {
public:
    int maxDepth(string s) {
        unordered_map<char,int>mp;
        int count =0;

        stack<char>p;
        int ans = INT_MIN;

        for(char a :s){
            if(a=='('){
                p.push(a);
                count++;
                ans = max(ans,count);

            }
            if(a==')'){
                p.pop();
                count--;
            }

        }

        return ans==INT_MIN?0:ans;
    }
};