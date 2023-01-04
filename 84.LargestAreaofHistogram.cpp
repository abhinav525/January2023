//stack to find next lower ele ,
class Solution {
    public int largestRectangleArea(int[] heights) {
        if(heights.length<=0)
         return 0;
        int n=heights.length;
        int[] left=new int[n];

        // to store the indices
        Stack<Integer> stack= new Stack<>();
        //the largest num which smaller than height[i]
        for(int i=0;i<n;i++){
            while(!stack.isEmpty() && heights[i]<= heights[stack.peek()]){
                stack.pop();
            }
            if(stack.isEmpty()){
                left[i]=-1;

            }else {
                left[i] = stack.peek();
            }
            stack.push(i);

        }
        stack.clear();
        int[] right = new int[n];
        //find the next num which is smaller than heights[i]
        for(int i=n-1;i>=0;i--){
            while(!stack.isEmpty() && heights[i]<= heights[stack.peek()]){
                stack.pop();


            }
            if(stack.isEmpty()){
                right[i]=n;

            }
            else{
                right[i]=stack.peek();
            }
            stack.push(i);
        }
        int maxArea=0;
        for(int i=0;i<n;i++){
            int area = ( right[i]-left[i]-1) * heights[i];
            maxArea= Math.max(maxArea,area);
        }
        return maxArea;
        
    }
}
