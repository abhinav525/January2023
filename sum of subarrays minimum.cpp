
//monotoic stack concept
//area of histogram concept.
class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        stack<int> s1,s2;
        int n=A.size();
        vector<int> next_smaller(n),prev_smaller(n);
        for(int i=0;i<n;i++){
            next_smaller[i]=n-i-1;//base case
            prev_smaller[i]=i;//base case
        }
        //nexxt smaller element
        for(int i=0;i<n;i++){
            while(!s1.empty() && A[s1.top()]>A[i])
            {
                next_smaller[s1.top()]=i-s1.top()-1;
                s1.pop();

            }
            s1.push(i);
        }//prev smaller ele
         for(int i=n-1;i>=0;i--){
            while(!s2.empty() && A[s2.top()]>=A[i])
            {
                prev_smaller[s2.top()]=s2.top()-i-1;
                s2.pop();

            }
            s2.push(i);
        }
        long ans=0;
        int mod=1e9+7;
        for(int i=0;i<n;i++)
        {
            ans+=((long)A[i]*(prev_smaller[i]+1)*(next_smaller[i]+1));
            ans%=mod;

        }
        return (int)ans;
        
    }
};
