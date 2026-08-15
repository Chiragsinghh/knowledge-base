class Solution {
public:
    string reverseWords(string s) {
        int i=0;
        int j= s.size()-1;
        string ans ="";

        stack<string>a;

        while(s[i]==' ' && i<s.size()){
            i++;
        }
        while(s[j]==' ' && j>=0){
            j--;
        }

        while (i <= j) {
            string temp = "";
            while (i <= j && s[i] != ' ') {
                temp.push_back(s[i]);
                i++;
            }
            if (!temp.empty()) {
                a.push(temp);
            }
            while (i <= j && s[i] == ' ') {
                i++;
            }
        }

        while(!a.empty()){
            ans = ans + a.top();
            a.pop();
            if(!a.empty()){
                ans = ans +" ";
            }
        }

        return ans;


    }
};