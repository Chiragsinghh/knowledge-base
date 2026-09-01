class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        vector<int>ans;

        for(int a:asteroids){
            if(a>0){
                st.push(a);
            }
            else if ((!st.empty() && a < 0 && st.top() < 0) || st.empty()) {
                st.push(a);
            }else if(a<0 && !st.empty() && st.top()>0){
                while(!st.empty() && -1*(a) > st.top() && st.top()>0 ){
                    st.pop();
                }
                if(st.empty() || st.top()<0){
                    st.push(a);
                }else if (-1*a == st.top()) {
                    st.pop(); 
                }
            }

        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};