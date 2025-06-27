class Node{
    public:
    Node* links[26];
    bool flag = false;
};
class Trie{
    Node* root = new Node();
    public:
    void insert(string word){
        Node* temp = root;
        for(int i=0; i<word.length(); i++){
            if(!temp->links[word[i]-'a']) temp->links[word[i]-'a'] = new Node();
            temp = temp->links[word[i]-'a'];
        }
        temp->flag = true;
    }
    bool search(string word){
        Node* temp = root;
        for(int i=0; i<word.length(); i++){
            if(temp->links[word[i]-'a']) temp = temp->links[word[i]-'a'];
            else return false;
        }return temp->flag;
    }
};
vector<string> fun(string A){
    int i=0;
    string k="";
    vector<string> ans;
    while(i<A.length()){
        if(A[i]=='_'){
            ans.push_back(k);
            k = "";
        }else k+=A[i];
        i++;
    }
    ans.push_back(k);
    return ans;
}
static bool comp(pair<int,int> &a,pair<int,int>&b){
    if(a.first==b.first) return a.second<b.second;
    return (a.first>b.first);
}
vector<int> Solution::solve(string A, vector<string> &B) {
    vector<string> goodword = fun(A);
    Trie trie;
    for(auto it: goodword) trie.insert(it);
    vector<pair<int,int>> goodness;
    int ind=0;
    for(auto it: B){
        vector<string> Bword = fun(it);
        int cnt=0;
        for(auto k:Bword) if(trie.search(k)) cnt++;
        goodness.push_back({cnt,ind});
        ind++;
    }
    sort(goodness.begin(),goodness.end(),comp);
    vector<int> ans;
    for(auto k:goodness) ans.push_back(k.second);
    return ans;
}
