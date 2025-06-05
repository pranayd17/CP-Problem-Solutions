class Solution {
public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<int>mp(1<<n,-1);
        for(int i=0;i<grid.size();i++){
            int x=0;
            for(auto &j:grid[i]){
                x<<=1;
                x+=j;
            }
            mp[x] = i;
        }    
//      if we found a row that full by zeros we return its idnex
        if(mp[0] != -1)
            return {mp[0]};

        for(int i=1;i<(1<<n);i++){
            for(int j=i+1;j<(1<<n);j++){
                if((i&j) == 0 && mp[i]!= -1 && mp[j] != -1){
                    int x = mp[i] , y = mp[j];
                    if(x>y)
                        swap(x,y);
                    return {x,y};
                }
            }
        }

        return {};
    }    
};
