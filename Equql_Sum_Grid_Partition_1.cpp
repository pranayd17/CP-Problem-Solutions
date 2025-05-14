class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int sum=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                sum+=grid[i][j];
            }
        }
        int s=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                s+=grid[i][j];
            }
            if(s==sum-s) return 1;
        }
        
        int s=0;
        for(int i=0;i<grid[0].size();i++){
            for(int j=0;j<grid.size();j++){
                s+=grid[j][i];
            }
            if(s==sum-s) return 1;
        }
        return 0;
    }
};
