class Solution {
public:
    vector<int> prefixSum;
    Solution(vector<int>& w) {
        for(int weight:w)
        {
            if(prefixSum.empty())
                prefixSum.push_back(weight);
            else
                prefixSum.push_back(weight + prefixSum.back());
        }
    }
    
    int pickIndex() {
        int x = prefixSum.back();
        int random = rand() % x;
        auto it = upper_bound(prefixSum.begin(), prefixSum.end(), random);
        return it - prefixSum.begin();
    }
};

 */