// Time Complexity :  O(N*log(N))
// Space Complexity : O(1)
class Solution {
public:
    static bool compare(vector<int>& a , vector<int>& b){
        return a[1]-a[0] > b[1]-b[0];
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(),costs.end(),compare);
        int a=0,n= costs.size();
        for(int i=0;i<n;i++){
            if(i<n/2)
                a+=costs[i][0];
            else
                a+=costs[i][1];
        }
        return a;
    }
};
