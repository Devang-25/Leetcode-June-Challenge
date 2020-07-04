// Time Complexity : O(N^2)
// Space Complexity : O(N^2)
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        if(!n)
            return nums;
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans(n);
        int Size=0,pos=0;
        for(int i=0;i<n;i++){
            int v=1,p=-1;
            for(int j=i-1;j>=0;j--){                
                if(nums[i]%nums[j]==0 && 1+(ans[j].size()) > v){
                    v=1+ ans[j].size();
                    p=j;
                }
            }               
            if(v>1)
                ans[i]=ans[p];
            ans[i].push_back(nums[i]);
            if(ans[i].size() > Size){
                    Size=ans[i].size();
                    pos=i;
                }
            }
        return ans[pos];
    }
};
