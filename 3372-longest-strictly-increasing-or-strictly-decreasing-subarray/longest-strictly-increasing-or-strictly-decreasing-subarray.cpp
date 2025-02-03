class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int increasingLength =1, decreasingLength =1, maxLength =1;
        
        for (int i=1; i<nums.size(); i++) {
            if (nums[i]>nums[i-1]) {
                increasingLength++;
                decreasingLength = 1;  
            } else if (nums[i]<nums[i-1]) {
                decreasingLength++;
                increasingLength=1;  
            } else {
                increasingLength=1;
                decreasingLength=1;
            }
            maxLength = max(maxLength, max(increasingLength, decreasingLength));
        }
        
        return maxLength;
    }
};
