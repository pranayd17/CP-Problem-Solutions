vector<vector<string> > Solution::findLadders(string start, string end, vector<string> &dict) {
unordered_set<string>st(dict.begin(),dict.end());
queue<vector<string>>q;
q.push({start});
vector<string>usedOnlevel;
usedOnlevel.push_back(start);
int level=0;
vector<vector<string>>ans;
while(!q.empty()){
    vector<string>vec=q.front();
    q.pop();
    if(vec.size()>level){
        level++;
        for( auto it:usedOnlevel){
            st.erase(it);        }
    }
    string word=vec.back();
    if(end==word){
        ans.push_back(vec);
    }
    for( int i=0;i<word.size();i++){
        char original=word[i];
        for(char ch='a';ch<='z';ch++){
            word[i]=ch;
            if(st.count(word)>0){
                vec.push_back(word);
                q.push(vec);
                usedOnlevel.push_back(word);
                vec.pop_back();
            }
        }
        word[i]=original;
    }
   
   
}
return ans;
}
