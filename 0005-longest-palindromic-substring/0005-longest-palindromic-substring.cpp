class Solution {
public:
    string ans ="";
    int maxlen =0;
    void expand(int i,int j,string& s){
        while(i>=0 && j<s.size() && s[i]==s[j]){
            int len= j-i+1;
            if(len>maxlen){
                maxlen=len;
                ans = s.substr(i,j-i+1);
            }
            i--;
            j++;
        }
    }
    string longestPalindrome(string s) {
        for(int i=0;i<s.size();i++){
            expand(i,i,s);
            expand(i,i+1,s);
        }

        return ans;
    }
};