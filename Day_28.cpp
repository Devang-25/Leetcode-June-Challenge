// Time Complexity : O(E)
// Space Complexity : O(E)
// E = # of Edges in Graph
class Solution {
public:
    void dfs(string s,unordered_map<string, priority_queue <string, vector<string>, greater<string>>> &m,vector<string> &ans){
        if(m[s].empty())
            return;
        while(!m[s].empty()){
        string v= m[s].top();
        m[s].pop();
        dfs(v,m,ans);
        ans.push_back(v);
    }
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> ans;
        if(tickets.empty())
            return ans;
        unordered_map<string, priority_queue <string, vector<string>, greater<string>>> m;
        for(auto i : tickets)
            m[i[0]].push(i[1]);
        dfs("JFK",m,ans);
        ans.push_back("JFK");
        reverse(ans.begin() , ans.end());
        return ans;

    }
};
