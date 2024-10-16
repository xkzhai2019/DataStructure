#include <iostream>
#include <stack>

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
private:
    Node<T>* root;
    int size;

public:
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
    Node<T>* add(Node<T> *node, T e){
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

    bool contains(T e){
        return contains(root,e);
    }

    // 查找以node为节点的二分搜索树中是否包含元素e
    bool contains(Node<T> *node,T e){
        if(node==nullptr){
            return false;
        }
        if(node->e == e){
            return true;
        }else if(node->e > e){
            return contains(node->left,e);
        }else{
            return contains(node->right,e);
        }
    }

    void preOrder(){
        preOrder(root);
    }

    // 前序访问以node为根节点的二分搜索树
    void preOrder(Node<T> *node){
        if(node==nullptr) return;
        std::cout<<node->e<<" ";
        preOrder(node->left);
        preOrder(node->right);
    }
    // 前序遍历--非递归实现
    void preOrderNR(){
        std::stack<Node<T> *> stackTree;
        stackTree.push(root);
        while(!stackTree.empty()){
            Node<T>* cur = stackTree.pop();
            std::cout<<cur->e<<" ";
            if(cur->right!=nullptr){
                stackTree.push(cur->right);
            }
            if(cur->left!=nullptr){
                stackTree.push(cur->left);
            }
        }
        std::cout<<std::endl;
    }

    void inOrder(){
        inOrder(root);
    }
    // 中序访问以node为根节点的二分搜索树
    void inOrder(Node<T> *node){
        if(node==nullptr) return;
        inOrder(node->left);
        std::cout<<node->e<<" ";
        inOrder(node->right);
    }
    
    void postOrder(){
        postOrder(root);
    }
    // 后序访问以node为根节点的二分搜索树
    void postOrder(Node<T> *node){
        if(node==nullptr) return;
        postOrder(node->left);
        postOrder(node->right);
        std::cout<<node->e<<" ";
    }
    
};

int main(){
    BST<int> bst;
    int arr[] = {26,20,15,23,14,18,37,32,43,30};
    /*
    for(int i=0;i<sizeof(arr)/sizeof(int);i++){
        bst.add(arr[i]);
    }
    */
    for(int num: arr){
        bst.add(num);
    }
    std::cout<<"是否包含10："<<bst.contains(10)<<std::endl;
    std::cout<<"是否包含32："<<bst.contains(32)<<std::endl;
    std::cout<<"前序遍历：";
    bst.preOrder();
    std::cout<<std::endl;
    bst.preOrderNR();
    std::cout<<"中序遍历：";
    bst.inOrder();
    std::cout<<std::endl;
    std::cout<<"后序遍历：";
    bst.postOrder();
    return 0;
}
