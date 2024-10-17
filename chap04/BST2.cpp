#include <iostream>
#include <stack>
#include <queue>

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
            Node<T>* cur = stackTree.top();
            stackTree.pop();
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

    // 层序遍历
    void levelOrder(){
        if(root==nullptr) return;

        std::queue<Node<T> *>  *q = new std::queue<Node<T> *>();
        q->push(root);
        while(!q->empty()){
            Node<T> *node = q->front(); 
            q->pop();
            std::cout<<node->e<<" ";
            if(node->left!=nullptr){
                q->push(node->left);
            }
            if(node->right!=nullptr){
                q->push(node->right);
            }
        }
        std::cout<<std::endl;
    }
    
    // 找到二分搜索树的最小值
    T min(){
        if(root==nullptr){
            throw "BST is empty";
        }
        return min(root)->e;
    }
    // 返回以node为根结点的二分搜索树的最小值所在结点
    Node<T>* min(Node<T> *node){
        if(node->left == nullptr){
            return node;
        }
        return min(node->left);
    }
    // 删除最小值所在结点，返回最小值
    T removeMin(){
        T ret = min();
        root = removeMin(root);
        return ret;
    }

    // 删除以node为根的二分搜索树的最小结点
    // 返回删除结点后新的二分搜索树的根
    Node<T>* removeMin(Node<T> *node){
        if(node->left == nullptr){
            Node<T>* rightNode = node->right;
            delete node;
            size--;
            return rightNode;
        }
        node->left = removeMin(node->left);
        return node;
    }


    // 找到二分搜索树的最大值
    T max(){
        if(root==nullptr){
            throw "BST is empty";
        }
        return max(root)->e;
    }
    // 返回以node为根结点的二分搜索树的最大值所在结点
    Node<T>* max(Node<T> *node){
        if(node->right == nullptr){
            return node;
        }
        return max(node->right);
    }
    // 删除最大值所在结点，返回最大值
    T removeMax(){
        T ret = max();
        root = removeMax(root);
        return ret;
    }

    // 删除以node为根的二分搜索树的最大结点
    // 返回删除结点后新的二分搜索树的根
    Node<T>* removeMax(Node<T> *node){
        if(node->right == nullptr){
            Node<T>* leftNode = node->left;
            delete node;
            size--;
            return leftNode;
        }
        node->right = removeMax(node->right);
        return node;
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
    std::cout<<"前序遍历：";
    bst.preOrderNR();
    std::cout<<"中序遍历：";
    bst.inOrder();
    std::cout<<std::endl;
    std::cout<<"后序遍历：";
    bst.postOrder();
    std::cout<<std::endl;
    std::cout<<"层序遍历：";
    bst.levelOrder();

    std::cout<<"删除最大结点:";
    bst.removeMax();
    bst.levelOrder();
    std::cout<<"删除最小结点:";
    bst.removeMin();
    bst.levelOrder();

    return 0;
}
