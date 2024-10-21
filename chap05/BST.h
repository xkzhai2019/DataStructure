#ifndef BST_H
#define BST_H

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
        }else if(e < node->e){
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

    // 删除任意结点
    void remove(T e){
        root = remove(root,e);
    }

    // 从以node为根结点的二分搜索树中删除元素e，递归
    // 返回删除结点后新的二分搜索树的根
    Node<T>* remove(Node<T> *node, T e){
        if(node == nullptr) return node;
        if(node->e > e){
            node->left = remove(node->left, e);
            return node;
        }else if(node->e <e){
            node->right = remove(node->right,e);
            return node;
        }else{// e == node->e
            // 待删除结点左子树为空时
            if(node->left == nullptr){
                Node<T> * rightNode = node->right;
                delete node;
                size--;
                return rightNode;
            }
            // 待删除结点右子树为空时
            if(node->right == nullptr){
                Node<T> * leftNode = node->left;
                delete node;
                size--;
                return leftNode;
            }
            // 待删除结点左右子树均不为空时
            Node<T>* s = new Node<T>(min(node->right)->e);
            s->right = removeMin(node->right);
            s->left = node->left;
            delete node;
            return s;
        }
    }

};
#endif
