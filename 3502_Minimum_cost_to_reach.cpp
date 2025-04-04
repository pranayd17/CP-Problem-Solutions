class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        vector<int> v;
        int mini=INT_MAX;
        for(int i=0;i<cost.size();i++){
            mini=min(mini,cost[i]);
            v.push_back(mini);
        }
        return v;
    }
};
