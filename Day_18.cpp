class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        int n = citations.size();
        if(n == 1)
            return citations[0] != 0;
        int h_index ;
        
        int l=0, r = n-1;
        while(l<=r)
        {
            int mid = l + (r-l) / 2;
            
            int h = citations[mid];
            
            if(h == n - mid)
                return n-mid;
            else if(h > n - mid)
                r = mid-1;
            else
                l = mid+1;       
        }
        return n-l;
    }
};
