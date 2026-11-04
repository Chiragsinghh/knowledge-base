class Solution {
public:
    multiset<long long> left, right;
    long long leftSum = 0, rightSum = 0;
    int need;

    void insertNum(long long val) {
        if (left.empty() || val <= *left.rbegin()) {
            left.insert(val);
            leftSum += val;
        } 
        else {
            right.insert(val);
            rightSum += val;
        }

        balance();
    }

    void eraseNum(long long val) {
        auto it = left.find(val);

        if (it != left.end()) {
            leftSum -= val;
            left.erase(it);
        } 
        else {
            it = right.find(val);
            rightSum -= val;
            right.erase(it);
        }

        balance();
    }

    void balance() {
        while (left.size() > need) {
            auto it = prev(left.end());
            long long val = *it;

            left.erase(it);
            leftSum -= val;

            right.insert(val);
            rightSum += val;
        }

        while (left.size() < need && !right.empty()) {
            auto it = right.begin();
            long long val = *it;

            right.erase(it);
            rightSum -= val;

            left.insert(val);
            leftSum += val;
        }
    }

    long long getCost() {
        long long median = *left.rbegin();

        long long l = median * left.size() - leftSum;
        long long r = rightSum - median * right.size();

        return l + r;
    }

    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        need = (x + 1) / 2;

        vector<long long> cost(n - x + 1);


        for (int i = 0; i < x; i++) {
            insertNum(nums[i]);
        }

        cost[0] = getCost();


        for (int i = x; i < n; i++) {
            eraseNum(nums[i - x]);
            insertNum(nums[i]);

            cost[i - x + 1] = getCost();
        }


        const long long INF = 1e18;

        vector<long long> prev(n + 1, 0);
        vector<long long> curr(n + 1, INF);

        for (int t = 1; t <= k; t++) {
            fill(curr.begin(), curr.end(), INF);

            for (int i = 1; i <= n; i++) {

                curr[i] = curr[i - 1];

   
                if (i >= x && prev[i - x] != INF) {
                    curr[i] = min(
                        curr[i],
                        prev[i - x] + cost[i - x]
                    );
                }
            }

            prev.swap(curr);
        }

        return prev[n];
    }
};