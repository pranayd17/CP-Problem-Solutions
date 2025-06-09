class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
    return canMakeAll(nums, k, 1) || canMakeAll(nums, k, -1);
    }

private:
    bool canMakeAll(vector<int> nums, int k, int tar){
    int n = nums.size();
    int op=0;
    for (int i = 0; i < n - 1; i++) {
        if (nums[i] != tar){
            nums[i] = -nums[i];
            nums[i + 1] = -nums[i + 1];
            op++;
            if (op>k) return false;
        }
    }
    return nums[n - 1] == tar;
    }
};
