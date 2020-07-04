// Time Complexity : O(N) (Single Pass)
// Space Complexity : O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int left=0, right = n-1,curr=0;
        while(curr<=right){
            if(nums[curr]==2)
                swap(nums[curr],nums[right--]);
            else if(nums[curr]==0)
                swap(nums[curr++],nums[left++]);
            else
                curr++;
        }
    }
};
