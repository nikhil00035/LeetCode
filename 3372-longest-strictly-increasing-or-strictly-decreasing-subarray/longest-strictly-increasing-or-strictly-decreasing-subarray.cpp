class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int si=1,sd=1;
        int res=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                si++;
                res=max(res,max(si,sd));
                sd=1;
            }
            else if(nums[i]<nums[i-1]){
                sd++;
                res=max(res,max(sd,si));
                si=1;
            }
            else{
                si=1;
                sd=1;
            }
        }
        return res;
    }
};