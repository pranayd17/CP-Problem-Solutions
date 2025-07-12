class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> result;
        bool dir=true;
        int left = 1, right = k+1;
        while(left<=right){
            if (dir)    result.push_back(left++);
            else        result.push_back(right--);
            dir = !dir;
        }
        for(int i=k+2;i<=n;i++)
            result.push_back(i);
        return result;

    }
};
