//move left to right aur jaha aapko decreasing mila (means from 5->4 fir 5 ko delete kr do )
//increasing m largest ko uda do.
//
class Solution {
    public String removeKdigits(String nums, int k) {
        int digits=nums.length()-k;
        if(nums.length()<=k) return "0";//jab delete jada krna ho aur array chota ho
        int top=-1,start=0;//leading zeroes ko hatane k liye start=0;
        char[] st=nums.toCharArray();//character string
        for(int i=0;i<st.length;i++){
            while(top>=0 && st[top]>st[i] && k>0){
                top--;
                k--;
            }
            top++;
            st[top]=st[i];

        }
        while(start<=top && st[start]=='0') start++;// agar 0 shru m aa gye to unko hatane k liye starrt to shift krte jyege jab tk non zer0 nahi ho raha.
        String ans="";//empty string corner case
        for(int i= start;i<digits;i++)
         ans=ans+st[i];
        if(ans.equals("")) return "0";
        return ans;

        
    }
}
