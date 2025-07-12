class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        if (nums.size() % 3) return {};
        
        auto cpy = nums;
        std::sort(cpy.begin(), cpy.end());
        
        std::vector<std::vector<int>> res(nums.size() / 3);

        auto size = cpy.size();

        int j = 0;
        std::vector<int> tmp(3);
        for (int i = 0; i < size;) {
            
            tmp[0] = cpy[i++];
            tmp[1] = cpy[i++];
            tmp[2] = cpy[i++];

            if (tmp[2] - tmp[0] > k) return {};

            res[j++] = tmp;
        }

        return res;
    }
};
