class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>idx;
        unordered_map<char,int>mp;

        for(auto a :t){
            mp[a]++;
        }

        int left =0;
        int count =t.size();
        int minlen =INT_MAX;
        int start=0;
        
        for(int right = 0;right<=s.size();right++){
            char a = s[right];
            if(mp[a]>0){
                count--;
            }
            mp[a]--;
                
                while(count==0){
                    if(minlen > right-left+1){
                        minlen = right-left+1;
                        start = left;
                    }

                    mp[s[left]]++;
                    if(mp[s[left]]>0){
                        count++;
                    }
                    left++;
                }


        }
        return minlen==INT_MAX?"":s.substr(start,minlen);
    }
};