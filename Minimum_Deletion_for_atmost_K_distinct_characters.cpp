class Solution {
public:
    int minDeletion(string s, int k) {
        unordered_map<char,int> mp;
        priority_queue<pair<int,char>,vector<pair<int,char>>,greater<pair<int,char>>> pq;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        
        for(auto p: mp){
            pq.push({p.second,p.first});
        }
        
        int ans=0;
        while(pq.size()>k){
            ans+=pq.top().first;
            pq.pop();
        }
        return ans;
    }
};
