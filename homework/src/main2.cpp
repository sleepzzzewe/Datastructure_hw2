#include <iostream>
#include <algorithm>

struct Node{
    int   key;
    Node *left  = nullptr;
    Node *right = nullptr;
    explicit Node(int k):key(k){}
};

class BST{
    Node *root = nullptr;

    static Node* insert(Node* n,int k){
        if(!n) return new Node(k);
        if(k < n->key) n->left  = insert(n->left,k);
        else           n->right = insert(n->right,k);
        return n;
    }
    static Node* minNode(Node* n){ return n->left ? minNode(n->left) : n; }

    static Node* erase(Node* n,int k){
        if(!n) return nullptr;
        if(k < n->key)      n->left  = erase(n->left,k);
        else if(k > n->key) n->right = erase(n->right,k);
        else{
            if(!n->left || !n->right){
                Node* t = n->left ? n->left : n->right;
                delete n; return t;
            }
            Node* succ = minNode(n->right);
            n->key = succ->key;
            n->right = erase(n->right, succ->key);
        }
        return n;
    }
    static int height(Node* n){
        return n ? 1 + std::max(height(n->left), height(n->right)) : 0;
    }
    static void destroy(Node* n){
        if(!n) return;
        destroy(n->left); destroy(n->right); delete n;
    }
public:
    ~BST(){ destroy(root); }
    void Insert(int k){ root = insert(root,k); }
    void Delete(int k){ root = erase(root,k); }
    int  Height() const { return height(root); }
};

int main(){
    BST tree;
    int keys[] = {50,20,75,10,30,60,80};
    for(int k:keys) tree.Insert(k);

    std::cout << "Height (init): " << tree.Height() << '\n';
    tree.Delete(50);
    std::cout << "Height (after delete 50): " << tree.Height() << '\n';
    return 0;
}



