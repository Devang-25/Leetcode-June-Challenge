// Time Complexity : O(N)
// Space Complexity : O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result=0,s;
        for(int i=0;i<32;i++){
            s=0;
            for(int n:nums)
            {
                s+=(n>>i)&1;
                s%=3;
            }
            result |= (s<<i);
        }
        return result;
    }
};
