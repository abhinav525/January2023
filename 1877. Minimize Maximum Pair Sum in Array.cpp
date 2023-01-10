class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n/2;i++){
            //i,n-1-i 1 ele from begning and first ele from the last.
            ans=max(ans,nums[i]+nums[n-i-1]);
        }
        return ans;
        
    }
};
