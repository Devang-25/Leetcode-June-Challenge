// Time Complexity : O(N*N)
// Space Complexity : O(N)
class Solution {
public:
    string getPermutation(int n, int k) {
        int i,j,f=1;
    string s="";
    for(i=1;i<=n;i++){
        f*=i;
        s+= to_string(i);
    }
    k--;
    for(i=0;i<n;i++){
        f/=n-i;
        j=i+ k/f;
        char c= s[j];
        while(j>i){
            s[j]=s[j-1];
            j--;
        }
        s[i]=c;
        k%=f;
    }
    return s;
    }
};
