// Time Complexity : O(N)
// Space Complexity : O(1)
class Solution {
public:
    void reverseString(vector<char>& s) {
        int l=0, r= s.size()-1;
        while(r>l){
            swap(s[l], s[r]);
            l++;
            r--;
        }
        
    }
};
