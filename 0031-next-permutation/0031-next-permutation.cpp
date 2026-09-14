class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;

        // 1. Find the first decreasing element
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        // 2. Find the next greater element
        if (i >= 0) {
            int j = n - 1;

            while (nums[j] <= nums[i]) {
                j--;
            }

            swap(nums[i], nums[j]);
        }

        // 3. Reverse the remaining part
        reverse(nums.begin() + i + 1, nums.end());
    }
};