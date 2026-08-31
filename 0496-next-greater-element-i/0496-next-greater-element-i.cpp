class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>next;
        stack<int>st;
        vector<int> ans;

        for(int num:nums2){
            while(!st.empty() && num>st.top()){
                next[st.top()]= num;
                st.pop();
            }
            st.push(num);
        }

        for (int num : nums1) {
            if (next.count(num))
                ans.push_back(next[num]);
            else
                ans.push_back(-1);
        }

        return ans;
    }
};