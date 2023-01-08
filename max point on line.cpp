class Solution {
public:
    int maxPoints(vector<vector<int>>& p) {
        //har 2 points se straight line bana lo and then find how many of the points lie on it.
        int n=p.size();
        if(n<=2) return n;//only two points 
        int maxx=2;// u can take only two points minimum for a line

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int total=2;
                for(int k=0;k<n;k++){// we tarverse whole points on the line 
                    if(k!=i && k!=j){// except i and j and check what are the other two points who has same slope
                        if((p[j][1]-p[i][1])*(p[i][0]-p[k][0]) == (p[i][1]-p[k][1]) * (p[j][0]-p[i][0])) total++;
                        //(y2-y1/x2-x1) = (y3-y1/x3-x1) slope formula
                    }
                }
                maxx=max(maxx,total);// if same then this point also lie on the line
            }
        } 
        return maxx;
        
    }
};
