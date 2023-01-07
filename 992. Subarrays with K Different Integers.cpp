class Solution {
public:
    int ok(vector<int>&a,int k){

        if(k==0)
         return 0;
        int n=a.size();
        int total=0;
        int diff=0;
        int j=0;
        vector<int>cnt(20002);
        for(int i=0;i<n;i++){
            if(cnt[a[i]]==0){
                diff++;
                cnt[a[i]]++;
            }
            else{
                cnt[a[i]]++;

            }
            if(diff<=k){
                total+=(i-j+1);
            }
            else{
                while(j<n && j<=i && diff>k){
                    cnt[a[j]]--;
                    if(cnt[a[j]]==0)
                     diff--;
                    j++;
                }
                total+=(i-j+1);
            }
        }
        return total;


    }
    int subarraysWithKDistinct(vector<int>& a, int k) {
        return ok(a,k)-ok(a,k-1);
        
    }
};
