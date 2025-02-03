class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int res=0,rr=0;
        int m=-1,mm=-1;
        for(int i=1; i < nums.size(); i++){
            if(nums[i]>nums[i-1]){
                res++;
            }
            else{
                m=max(res,m);
                res=0;
            }
            if(nums[i]<nums[i-1]){
                rr++;
            }
            else{
                mm=max(rr,mm);
                rr=0;
            }
        }
        mm=max(rr,mm);
        m=max(res,m);
        return max(m,mm)+1;
    }
};