class Solution {
public:
    int minimumDistance(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        
        vector<int> v,res;
        for(int i=0;i<points.size()-1;i++){
            int dist=abs(points[i][0]-points[i+1][0]) + abs(points[i][1]-points[i+1][1]);
            v.push_back(dist);
        }
        sort(v.begin(),v.end());
        int n=v.size();
        for(int i=0;i<v.size();i++){
            if(i==n-1) res.push_back(v[n-2]);
            res.push_back(v[n-1]);
        }
        sort(res.begin(),res.end());
        return res[0];
        
    }
};
