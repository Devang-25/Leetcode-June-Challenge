
class Solution {
public:
    int prime = 10000007;
    vector<int> power;
    
    string rabinKarp(string s, int len)
    {
        if(len == 0)
            return "";
        int n = s.size(), cur = 0;
        unordered_map<int, vector<int>> hash;
        
        for(int i=0; i<len; i++)
            cur = (cur * 26 + (s[i] - 'a')) % prime;
        
        hash[cur] = {0};
        
        for(int i=len; i<n; i++)
        {
            cur = ((cur - power[len-1] * (s[i-len] - 'a')) % prime + prime) % prime;
            cur = (cur * 26 + (s[i] - 'a')) % prime;
            
            if(hash.find(cur) == hash.end())
                hash[cur] = {i-len+1};
            
            else
            {
                for(int index : hash[cur])
                    if(s.substr(index, len) == s.substr(i-len+1, len))
                        return s.substr(index, len);
                hash[cur].push_back(i-len+1);
            }
        }
        return "";
    }
    
    string longestDupSubstring(string s) 
    {
        int n = s.size(), l=0, r = n-1;
    
        power = vector<int>(n);

        for(int i=0; i<n; i++)
            power[i] = (i==0) ?  1 : (power[i-1]*26) % prime;
        
        string res;
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            string dup = rabinKarp(s, mid);
            
            if(dup.size() > res.size())
            {
                res = dup;
                l = mid+1;
            }
            else
                r = mid-1;
        }
        return res;
    }
};
