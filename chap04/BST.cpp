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
        if(root==nullptr){
            root = new Node<T>(e);
            size++;
        }else{
            add(root,e);
        }
    }
    //将元素e放入以node为根结点的二分搜索树中
    void add(Node<T> *node, T e){
        if(e == node->e){
            return;
        }else if(e < node->e && node->left==nullptr){
            node->left = new Node<T>(e);
            size++;
            return;
        }else if(e > node->e && node->right==nullptr){
            node->right = new Node<T>(e);
            size++;
            return;
        }

        if(e > node->e){
            add(node->right, e);
        }else{
            add(node->left, e);
        }
    }
};
