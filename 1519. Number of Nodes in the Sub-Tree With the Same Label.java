//label"a a b a b"->a-0,a-1,b-2,a-3,b-4
//consider each node as root node and check whether its label is equal to the subtree nodes and return the num
//har node k liye adjacency list maintain karo uss list m vo sare  nodes hote hai jo uss node ke adjacent hot hai.
/*
0-1,2,4
1-0,3
2-0
3-1
4-0
ek hi bar dfs lgao aur child se ouchte jao ki konse konse label hai aisa krne se har bar dfs call nai krna pdega
time-o(n)
space-o(n)
*/
class Solution {
    private int[] ans;
    private List<List<Integer>>adjlist;
    private Set<Integer> visited;
    public int[] countSubTrees(int n, int[][] edges, String labels) {
        ans=new int[n];
        adjlist=new ArrayList<>(n);
        for(int i=0;i<n;i++){
            adjlist.add(new ArrayList<>());
        }
        for(int[] e: edges){
            adjlist.get(e[0]).add(e[1]);// agar a b edge hai to a ki adj nikal kr b ko add krta hai aur b ki nikal kr a ki.
            adjlist.get(e[1]).add(e[0]);
        }
        visited = new HashSet<Integer>(n);
        dfs(0,labels);
        return ans;
        
    }
    private int[] dfs(int node,String labels){

        visited.add(node);
        int[] count = new int[26];
        for(int adj:adjlist.get(node)){
            if(!visited.contains(adj)){
                int[] adjCount =dfs(adj,labels);
                for(int i=0;i<26;i++){
                    count[i]+=adjCount[i];
                }
            }
        }
        char ch=labels.charAt(node);//to count char at node itself
        count[ch-'a']++;//iss node ka jo bhi label hai uska count ek se badha dega
        ans[node] =count[ch-'a'];
        return count;
    }
}
