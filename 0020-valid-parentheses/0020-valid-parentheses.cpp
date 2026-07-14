class Solution {
public:
    bool isValid(string s) {
        stack<char>q;

        for(auto ch:s){
            if(ch=='(' || ch=='{' || ch=='['){
                q.push(ch);
            }
            else if(ch==')'){
                if(!q.empty() && q.top()=='('){
                    q.pop();
                }else{
                    return false;
                }
            }
            else if(ch==']'){
                if(!q.empty() && q.top()=='['){
                    q.pop();
                }else{
                    return false;
                }
            }
            else if(ch=='}'){
                if(!q.empty() && q.top()=='{'){
                    q.pop();
                }else{
                    return false;
                }
            }
            
        }

        if(!q.empty())return false;
        return true;
    }
};