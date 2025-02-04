class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int max_sum = 0;
        for (int i = 0; i < n; i++) {
            int current_sum = nums[i];
            for (int j=i+1; j<n; j++) {
                if (nums[j]>nums[j-1]) {
                    current_sum+=nums[j];
                } else {
                    break;
                }
            }
            if (current_sum>max_sum) {
                max_sum=current_sum;
            }
        }
        return max_sum;
    }
};