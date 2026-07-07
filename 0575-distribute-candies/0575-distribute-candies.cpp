class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int typesofcandy =1;
        sort(candyType.begin(),candyType.end());
        for(int i=1;i<candyType.size();i++){
            if(candyType[i]!=candyType[i-1]){
                typesofcandy++;
            }
        }

        int n= candyType.size()/2;
        if(typesofcandy<n){
            return typesofcandy;
        }else{
            return n;
        }
    }
};