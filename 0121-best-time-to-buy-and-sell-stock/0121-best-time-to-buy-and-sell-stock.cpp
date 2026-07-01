class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit=0;
        int minprice=INT_MAX;
        for(int price: prices){
            minprice=min(minprice,price);

            int profit=price-minprice;

            maxprofit=max(maxprofit,profit);
        }
        return maxprofit;
    }
};