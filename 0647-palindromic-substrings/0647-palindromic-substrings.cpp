class Solution {
public:
    int check(string& s,int i,int j){
        int c=0;
        while(i>=0 && j<s.size()){
            if(s[i]==s[j]){
                c++;
                i--;
                j++;
            }else{
                break;
            }
        }
        return c;
    }
    int countSubstrings(string s) {
        int ans =0;
        for(int i=0;i<s.size();i++){
            ans+=check(s,i,i);
            ans+=check(s,i,i+1);
        }
        return ans;
    }
};