//uss stock ka price uss din se kam kab tha span always=1 and if we get hen min then we will add 1 to it.
// Brute Force--we will take two pointers and fix one pointer and other pointer will compare with all the prices before that days tc=o(n^2)
//Using Stack- will keep span and price
class StockSpanner {
 Stack<Node> st;
public StockSpanner(){
    st=new Stack<>();
        
}
    
public int next(int price) {
    int count=0;
    while(!st.isEmpty() && st.peek().val<=price){
        count+=st.peek().del;//pop and add its span value.
        st.pop();
    }
    count++;
    st.push(new Node(price,count));
    return count;
        
}
static class Node
{
    int val;
    int del;
    public Node(int val,int del)
    {
        this.val=val;
        this.del=del;
    }
}

}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
