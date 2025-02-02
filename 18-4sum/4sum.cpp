class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int n = nums.size();
        if (n < 4) return result;
        sort(nums.begin(), nums.end());
        
        for (int a = 0; a < n - 3; ++a) {
            if (a > 0 && nums[a] == nums[a - 1]) continue;
            for (int b = a + 1; b < n - 2; ++b) {
                if (b > a + 1 && nums[b] == nums[b - 1]) continue;
                int left = b + 1, right = n - 1;
                while (left < right) {
                    long long sum = (long long)nums[a] + nums[b] + nums[left] + nums[right];
                    if (sum < target) {
                        ++left;
                    } else if (sum > target) {
                        --right;
                    } else {
                        result.push_back({nums[a], nums[b], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left + 1]) ++left;
                        while (left < right && nums[right] == nums[right - 1]) --right;
                        ++left;
                        --right;
                    }
                }
            }
        }
        return result;
    }
};
