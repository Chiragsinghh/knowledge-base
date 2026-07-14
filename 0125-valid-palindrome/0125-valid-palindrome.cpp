class Solution {
public:
    bool isPalindrome(string s) {
        for(int i=0;i<s.size();i++){
            if(s[i]>='A' && s[i]<='Z'){
                s[i]=s[i]+32;
            }
        }

        string a;

        for(auto ch:s){
            if(ch>='a' && ch<='z'){
                a.push_back(ch);
            }else if(ch>='0' && ch<='9'){
                a.push_back(ch);
            }
        }

        string b =a; 
        reverse(a.begin(),a.end());

        if(a==b){
            return true;
        }
        return false;
    }
};