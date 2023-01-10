class Solution {
public:
/*
approach1=n=>n! permutation.take each permutatin of nums 2 and then xor with nums 1 and try to find max across all the possible canndidate
time:o(n!)
approach2=>  
dp[i][j]:min value of xor sum we can get considering vales in range nums1[i...n] having subset j corresponding to nums2.
nums2=[2,3]
0=[0,0]
1=[0,1]
2=[1,0]
3=[1,1]
ans=dp[0,0]
time complexity:0(n*2^n)
*/
    int solve(int i,int j,int n,vector<vector<int>> &dp,vector<int>&nums1,vector<int>&nums2){
        if(i==nums1.size())
         return 0;
        if(dp[i][j]!=-1)
         return dp[i][j];
        int res=INT_MAX;//xor sum ko minimize krna hai
        //try to find xor of ele nums1[i] with any left out ele in nums2
        for(int k=0;k<n;k++){
            if((j&(1<<k))==0){
                res=min(res,(nums1[i]^nums2[k]) + solve(i+1,j| (1<<k),n,dp,nums1,nums2));
            }
        }
        return dp[i][j]=res;
    }
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<vector<int>>dp(n+1,vector<int>(1<<(n+1),-1));//represent the i and for j ,left most significant bit jo 1 hai usko left shift krta  n+1 times.
        return solve(0,0,n,dp,nums1,nums2);
        
    }
};
