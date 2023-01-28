class SummaryRanges {
    private Set<Integer> numbers;


    public SummaryRanges() {
        numbers=new TreeSet<>();
        
    }
    
    public void addNum(int value) {
        numbers.add(value);
        
    }
    
    public int[][] getIntervals() {
        List<int[]> disjointInterval = new ArrayList<>();
        for(int n:  numbers){

            int size = disjointInterval.size();
            if(size>0&& disjointInterval.get(size-1)[1]+1==n){
                disjointInterval.get(size-1)[1]=n;

            }
            else{
                disjointInterval.add(new int[]{n,n});
            }
        }
        return disjointInterval.toArray(new int[0][]);
    
        
    }
}

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(value);
 * int[][] param_2 = obj.getIntervals();
 */
