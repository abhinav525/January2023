// we can choose minimum from every row and add it top to botttom approach,but it will not work in every test cases.
// but bottom to top approach using dp will work and will check which of the sum either from two is small or small ele will be added to parent node
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n =triangle.size();

        vector<int>dp(n,0);
        for(int i=0;i<n;i++){
            dp[i]=triangle[n-1][i];

        }
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<triangle[i].size();j++){
                dp[j]=min(dp[j],dp[j+1])+triangle[i][j];
            }
        }
        return dp[0];
        
    }
};
