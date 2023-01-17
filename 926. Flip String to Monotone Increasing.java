// we will flip the lesser occuring digit 
class Solution {
    public int minFlipsMonoIncr(String s) {
        int oc=0;
        int zto=0;
        int i=0;
        while(i<s.length() && s.charAt(i)=='0'){
            i++;

        }
        for(;i<s.length();i++){
            char c=s.charAt(i);
            if(c=='0'){
                zto++;;

            }
            else{
                oc++;
            }
            if(zto>oc){
                zto=oc;
            }
            

        }
        return zto; 
        
    }
}
