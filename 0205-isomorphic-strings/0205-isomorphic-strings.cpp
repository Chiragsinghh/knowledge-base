class Solution {
public:

    string normalise(string &s){
        string a="";
        unordered_map<char, char> code;
        
        char j='a';
        for(int i=0;i<s.length();i++){
            if(code.find(s[i])==code.end()){
            code[s[i]]=j;
            j++;
            }
        }
        for(int i=0;i<s.length();i++){
            a.push_back(code[s[i]]);
        }
        return a;

    }

    bool isIsomorphic(string& s,string& t) {
    

        return normalise(s)==normalise(t);
        return false;
    }
};