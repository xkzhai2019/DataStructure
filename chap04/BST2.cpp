template<typename T>
class Node{
public:
    T e;
    Node<T>* left;
    Node<T>* right;

    Node(T e){
        this->e = e;
        left = nullptr;
        right = nullptr;
    }

};


template<typename T>
class BST{
    Node<T>* root;
    int size;

    BST(){
        root = nullptr;
        size = 0;
    }

    int getSize(){
        return size;
    }

    bool isEmpty(){
        return size==0;
    }
    
    // 向二分搜索树中添加新的元素
    void add(T e){
        root = add(root,e);
    }
    //将元素e放入以node为根结点的二分搜索树中
    // 返回插入新结点后二分搜索树的根
    Node* add(Node<T> *node, T e){
        if(node==nullptr){
            size++;
            return new Node<T>(e);
        }

        if(e > node->e){
            node->right = add(node->right, e);
        }else{
            node->left = add(node->left, e);
        }
        return node;
    }
};
