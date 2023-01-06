class LRUCache {
public:
    class node{
        public://doubly ll node
            int key;
            int val;
            node* next;
            node* prev;
        node(int _key,int _val){
            key=_key;//constructor to create new head and tail
            val=_val;
        }
    };
    node* head=new node(-1,-1);//-1 as dummy value
    node* tail=new node(-1,-1);

    int cap;//total sie of cache allowed
    unordered_map<int ,node*>m;
    LRUCache(int capacity) {//initial configuration
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void addnode(node* newnode){
        node* temp = head->next;//temp head ka next hoga aur naya nodde ayega uska next temp hoga aur prev head hoga ,then head ka next newnode hoga aur temp ka prev new node hoga.
        newnode->next=temp;
        newnode->prev=head;
        head->next=newnode;
        temp->prev=newnode;
    }
    void deletenode(node* delnode){
        node* delprev=delnode->prev;//link to middle ele will cut and the node will directly connected
        node* delnext=delnode->next;
        delprev->next=delnext;
        delnext->prev=delprev;
    }
    
    int get(int key) {// val stored prev get it and erase it and put it in the heads next (most recent used) and then return the node.
        if(m.find(key)!=m.end()){

            node* resnode=m[key];
            int res = resnode->val;
            m.erase(key);
            deletenode(resnode);
            addnode(resnode);
            m[key]=head->next;
            return res;
        }
        return -1;

        
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){// if exsist prev  if exsist then delete.
            node* existingnode=m[key];
            m.erase(key);
            deletenode(existingnode);
        }
        if(m.size()==cap){
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key,value));// insert it right after head;
        m[key]=head->next;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
