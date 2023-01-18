class Solution {
    private int kadans(int[] nums) {
        int n=nums.length;
        int sum=nums[0],maxsum=nums[0];
        for(int i=1;i<n;i++){
            sum+=nums[i];
            if(sum<nums[i]) sum=nums[i];
            maxsum=Math.max(maxsum,sum);
        }
        return maxsum;
        
    }
    public int maxSubarraySumCircular(int [] A){
        if(A.length==0) return 0;
        int x=kadans(A);
        int y=0;
        for(int i=0;i<A.length;i++){
            y+=A[i];
            A[i]*=-1;
        }
        int z=kadans(A);
        if(y+z==0) return x;
        return Math.max(x,y+z);
    }
    
}
