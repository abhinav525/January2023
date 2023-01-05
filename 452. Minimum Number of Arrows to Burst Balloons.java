//we will sort the array point based on the end index,ovelap type of question 
class Solution {
    public int findMinArrowShots(int[][] points) {
        if(points.length==0) return 0;// if there is now ballon.
        Arrays.sort(points,(a,b)->Integer.compare(a[1],b[1]));//a[1]-b[1] 
        int arrow=1;
        int end=points[0][1];
        for(int i=1;i<points.length;i++){

            if(points[i][0]>end){//overlap condition
                arrow++;
                end=points[i][1];
            }
        }
        return arrow;
    }
}
