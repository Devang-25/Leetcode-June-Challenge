// Time Complexity : O(N*N)
// Space Complexity : O(1)
class Solution {
public:
    static bool com(vector<int>& a, vector<int>&b){
        if(a[0]==b[0])
            return a[1] < b[1];
        return a[0]>b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> ans;
        sort(people.begin(),people.end(),com);
        for(auto i: people)
            ans.insert(ans.begin()+i[1] , i);
        return ans;
    }
};
