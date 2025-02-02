class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int dropCount = 0;
        for (int i=0; i<n; i++) {
            if (nums[i]>nums[(i+1)%n]) {
                dropCount++;
            }
            if (dropCount>1) {
                return false;
            }
        }
        return true;
        }
};