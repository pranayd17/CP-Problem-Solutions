class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int c=0;
        int prev_end=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<prev_end){
                c++;
                prev_end=min(prev_end,intervals[i][1]);
            }
            else{
                prev_end=intervals[i][1];
            }
        }
        return c;
    }
};
