class trie{
public:
    trie *node[2];
    int count;
    trie(){
        node[0]=node[1]=nullptr;
        count=0;
    }
};
void insert(trie* root,int n){
    for(int i=16;i>=0;i--){
        bool x = (n & (1<<i));
        if(!root->node[x]){
            root->node[x]=new trie();
        }
        root->node[x]->count++;
        root=root->node[x];
    }
}
int cntp(trie* root,int n,int k){
    int res=0;
    for(int i=16;i>=0 and root;i--){
        bool x=n&(1<<i);
        bool y=k&(1<<i);
        if(y==0){
            root=root->node[x];
        }
        else{
            if(root->node[x]){
                res+=root->node[x]->count;
            }
            root=root->node[1-x];
        }
    }
    return res;
}
class Solution {
public:
    int countPairs(vector<int>& nums, int low, int high) {
        int n=nums.size();
        trie* root=new trie();
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=cntp(root,nums[i],high+1)-cntp(root,nums[i],low);
            insert(root,nums[i]);
        }
        return ans;
    }
};
