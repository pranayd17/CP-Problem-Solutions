class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        // vector<int> ans;
        priority_queue<pair<int,int>> pq;
        map<int,int> mp;
        for(int i=0;i<barcodes.size();i++) mp[barcodes[i]]++;

        for(auto i=mp.begin();i!=mp.end();i++){
            pq.push({i->second,i->first});
        }
        barcodes.clear();
        while(pq.size()>1){
            int x1=pq.top().first;
            int x2=pq.top().second;
            pq.pop();
            int y1=pq.top().first;
            int y2=pq.top().second;
            pq.pop();
            barcodes.push_back(x2);
            barcodes.push_back(y2);
            x1--,y1--;
            if(x1>0) pq.push({x1,x2});
            if(y1>0) pq.push({y1,y2});
        }
        if(pq.size()>0) barcodes.push_back(pq.top().second);
        return barcodes;
    }
};
