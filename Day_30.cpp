class Trie {
public:
    /** Initialize your data structure here. */
    Trie* next[26] = {};
    bool isword = false;
    Trie() {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* node = this;
        for (char ch : word) {
            ch -= 'a';
            if (!node->next[ch]) { node->next[ch] = new Trie(); }
            node = node->next[ch];
        }
        node->isword = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* node = this;
        for (char ch : word) {
            ch -= 'a';
            if (!node->next[ch]) { return false; }
            node = node->next[ch];
        }
        return node->isword;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* node = this;
        for (char ch : prefix) {
            ch -= 'a';
            if (!node->next[ch]) { return false; }
            node = node->next[ch];
        }
        return true;
    }
};

class Solution {
public:
    int n,m;
    vector<string> ans;
    void dfs(int i,int j,vector<vector<char>>& board, unordered_set<string>& words,
            vector<vector<int> >& vis,string &s,Trie *obj){
        if(i<0 || i>=n || j<0 || j>=m || vis[i][j])
            return ;
        vis[i][j]=1;
        s.push_back(board[i][j]);
        if(words.count(s)){
            ans.push_back(s);
            words.erase(s);
        }
        if(!(obj->startsWith(s))){
            vis[i][j]=0;
            s.pop_back();
            return;
        }
            
        dfs(i+1,j,board,words,vis,s,obj);
        dfs(i-1,j,board,words,vis,s,obj);
        dfs(i,j+1,board,words,vis,s,obj);
        dfs(i,j-1,board,words,vis,s,obj);
        s.pop_back();
        vis[i][j]=0;
        
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {        
        n= board.size();
        if(!n)return ans;
        m= board[0].size();
        vector<vector<int> > vis(n,vector<int>(m,0));
        unordered_set<string > s;
        Trie *obj = new Trie();
        for(auto i : words){
            s.insert(i);obj->insert(i);
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                string str="";
                dfs(i,j,board,s,vis,str,obj);
            }
       return ans;
    }
};
