class Solution {
    public int subarraysDivByK(int[] a, int k) {
        HashMap<Integer,Integer> map= new HashMap<Integer,Integer>();
        map.put(0,1);
        int cumsum=0;
        int count=0;
        for(int i=0;i<a.length;i++){
            cumsum+=a[i];
            int rem=cumsum%k;
            if(rem<0) rem+=k;
            if(map.containsKey(rem)){
                count+=map.get(rem);
            }
            map.put(rem,map.getOrDefault(rem,0)+1);
        }
        return count;
        
    }
}
