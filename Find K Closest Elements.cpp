
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<arr.size();i++){
            int d=abs(x-arr[i]);
            pq.push({d,arr[i]});
            if(pq.size()>k) pq.pop();
        }
        while(pq.size()>0){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
