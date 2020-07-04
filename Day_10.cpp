// Time Complexity : O(log(N))
// Space Complexity : O(1)
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0,r=(nums.size())-1;
        int mid=0;
        while(l<=r){
            mid=l+(r-l)/2;
            if(nums[mid]==target)
                return(mid);
            else if(nums[mid]>target)
                r=mid-1;
            else
                l=mid+1;
        }
        return l;
    }
};
