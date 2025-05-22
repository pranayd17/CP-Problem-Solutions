class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int s=0,maxi=INT_MIN;
        for(int i=0;i<gain.size();i++){
            s+=gain[i];
            maxi=max(maxi,s);
        }
        if(maxi<0) return 0;
        return maxi;
    }
};
