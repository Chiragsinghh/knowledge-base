class Solution {
public:
    int maxDepth(string s) {
        int ans =0;
        int temp =0;


        for(char a:s){
            if(a=='('){
                temp++;
            }else if(a==')'){
                temp--;
            }
            ans = max(temp,ans);

        }

        return ans;
    }
};