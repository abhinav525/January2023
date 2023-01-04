//we will use monotonic stack 
// decresing stack- finds prev greater nd next greater ele.
// when ever we pop the ele and push next ele it is nexxt greater ele of that ele.
// increasing stack-finds prev lesser and next lesseer ele.
class Solution {
    public long subArrayRanges(int[] nums) {
        Stack<Integer> dec_stack=new Stack<>();
        Stack<Integer> inc_stack=new Stack<>();
        long sum=0;
        for(int i=0;i<=nums.length;++i)
        {
            sum+=pushToStack(dec_stack,nums,i,(a,b)->a<b)- pushToStack(inc_stack,nums,i,(a,b)->a>b);//range
        }
        return sum;
       //**BRUTE FORCE APPROACH
        
        /*long sum=0;
        int size=nums.length;
        for(int i=0;i<size;i++){
            int min=nums[i];
            int max=nums[i];
            for(int j=i;j<size;j++){
                min=Math.min(min,nums[j]);
                max=Math.max(max,nums[j]);
                sum+=max-min;
            }
        }
        return sum;*/
    }
    private long pushToStack(Stack<Integer> stack,int[] nums,int i,BiFunction<Integer,Integer,Boolean>compare)
    {
        long sum=0;

        while(!stack.isEmpty() && (i==nums.length || compare.apply(nums[stack.peek()],nums[i])))
        {
            int pop_i=stack.pop();
            int prev_i=stack.isEmpty()?-1:stack.peek();
            sum+=(pop_i-prev_i) * (i-pop_i) * (long)nums[pop_i];
        }
        stack.push(i);
        return sum;
    }
}
