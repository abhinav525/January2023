//Largest Rectangle in Histogram Preq.
//we will go row wise and consider 1's as a building and make them histogram.
//consider first row and in  first row every col's value will be thier height and pass on it to function
//and traverse to second and update the heights

/*// if 0 the height will go back to zero. 
class Solution {
public:
// larges area of histo same code;
    int largestrectanglearea(vector<int> & histo)
    {
        stack<int>st;
        int maxa=0;
        int n=histo.size();
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n||histo[st.top()]>=histo[i])){
                int height=histo[st.top()];
                st.pop();
                int width;
                if(st.empty())
                 width=1;
                else
                 width=i-st.top()-1;
                maxa=max(maxa,width*height);
            }
            st.push(i);
        }
        return maxa;

}
    int maximalRectangle(vector<vector<char>>& mat,int m,int n) {
        int maxarea=0;
        vector<int> height(m,0);
        for(int i=0;i<n;i++){
             for(int j=0;j<m;j++){
            if(mat[i][j]==1) height[j]++;
            else height[j]=0;
        }
        int area =largestrectanglearea(height);
        maxarea=max(area,maxarea);

        }
        return maxarea;
       
        
    }
};
*/
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        if (n == 0) return 0;
        int maxRect = 0;
        vector<int> height(n, 0);
        for (int i = 0; i < m; ++i)
        {
            stack<int> st;
            for (int j = 0; j < n; ++j)
            {
                if (matrix[i][j] == '0')
                    height[j] = 0;
                else
                    height[j]++;
            }
            for (int j = 0; j <= n; ++j)
            {
                while (!st.empty() && (j == n || height[st.top()] > height[j]))
                {
                    int k = st.top();
                    st.pop();
                    int length = (!st.empty()) ? (j - st.top() - 1) : (j - 0);
                    maxRect = std::max(maxRect, length * height[k]);
                }
                st.push(j);
            }
        }
        return maxRect;
    }
};
