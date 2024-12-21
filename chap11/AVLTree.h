#ifndef AVLTREE_H
#define AVLTREE_H
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<typename K,typename V>
class AVLTree{
private:
    class TreeNode{
        public:
            K key;
            V value;
            int height;
            TreeNode* left;
            TreeNode* right;

            TreeNode(K key, V value){
                this->key = key;
                this->value = value;
                left = nullptr;
                right = nullptr;
                height = 1;
            }

            /*
            TreeNode(TreeNode* node){
                this->key = node->key;
                this->value = node->value;
                this->left = node->left;
                this->right = node->right;
                this->height = node->height;
            }
            */
    };
    TreeNode* root;
    int size;
    // 在以node为根的二分搜索树中查找键key所在结点
    TreeNode *getNode(TreeNode *node,K key){
        if(node==nullptr) return nullptr;
        if(key == node->key){
            return node;
        }else if(key > node->key){
            return getNode(node->right,key);
        }else{
            return getNode(node->left,key);
        }
    }
    int getHeight(TreeNode* node){
        if(node == nullptr){
            return 0;
        }
        return node->height;
    }
    int getBalanceFactor(TreeNode* node){
        if(node==nullptr){
            return 0;
        }
        return getHeight(node->left) - getHeight(node->right);
    }
    TreeNode* rightRotate(TreeNode* y){
        TreeNode* x = y->left;
        TreeNode* T3 = x->right;
        x->right = y;
        y->left = T3;
        y->height = std::max(getHeight(y->left),getHeight(y->right))+1;
        x->height = std::max(getHeight(x->left),getHeight(x->right))+1;
        return x;
    }
    TreeNode* leftRotate(TreeNode* y){
        TreeNode* x = y->right;
        TreeNode* T3 = x->left;
        x->left = y;
        y->right = T3;
        y->height = std::max(getHeight(y->left),getHeight(y->right))+1;
        x->height = std::max(getHeight(x->left),getHeight(x->right))+1;
        return x;
    }
    //将键值对放入以node为根结点的二分搜索树中
    // 回插入新结点后二分搜索树的根
    TreeNode* add(TreeNode *node, K key, V value){
        if(node==nullptr){
            size++;
            return new TreeNode(key,value);
        }
        if(key > node->key){
            node->right = add(node->right, key, value);
        }else if(key < node->key){
            node->left = add(node->left, key, value);
        }else{
            node->value = value;
        }
        node->height = 1 + std::max(getHeight(node->left),getHeight(node->right));
        int balanceFactor = getBalanceFactor(node);
        /*
        if(std::abs(balanceFactor)>1){
            std::cout<<"unbalanced: "<<balanceFactor<<std::endl;
        }
        */
        // LL
        if(balanceFactor > 1 && getBalanceFactor(node->left)>=0){
            return rightRotate(node);    
        }
        // RR
        if(balanceFactor < -1 && getBalanceFactor(node->right)<=0){
            return leftRotate(node);    
        }
        // LR
        if(balanceFactor > 1 && getBalanceFactor(node->left)<0){
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        //RL
        if(balanceFactor < -1 && getBalanceFactor(node->right)>0){
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }
    // 中序遍历BST，构成有序向量
    void inOrder(TreeNode* node,vector<K> keys){
        if(node==nullptr){
            return;
        }
        inOrder(node->left,keys);
        keys.push_back(node->key);
        inOrder(node->right,keys);
    }
    // 判断以node为根的二分搜索树是否平衡
    bool isBalanced(TreeNode* node){
        if(node==nullptr){
            return true;
        }
        int balanceFactor = getBalanceFactor(node);
        if(abs(balanceFactor)>1){
            return false;
        }
        return isBalanced(node->left) && isBalanced(node->right);
    }
public:
    AVLTree(){
        root = nullptr;
        size = 0;
    }
    bool isBST(){
        vector<K> keys;
        inOrder(root,keys);
        for(int i = 1; i<keys.size();++i){
            if(keys.at(i-1) < keys.at(i)){
                return false;
            }
        }
        return true;
    }
    void getAllKey(TreeNode* node, vector<K>* ret){
        if(node==nullptr) return;
        getAllKey(node->left,ret);
        ret->push_back(node->key);
        getAllKey(node->right,ret);
    }

    vector<K> keySet(){
        vector<K> ret;
        getAllKey(root,&ret);
        return ret;
    }
    bool isBalanced(){
        return isBalanced(root);
    }

    int getSize(){
        return size;
    }
    bool isEmpty(){
        return size==0;
    }
    bool contains(K key){
        return getNode(root,key)!=nullptr;
    }
    V get(K key){
        TreeNode *node = getNode(root,key);
        if(node==nullptr){
            throw "no this key";
        }
        return node->value;
    }

    void add(K key,V value){
        root = add(root,key,value);
    }
    void set(K key, V value){
        TreeNode *node = getNode(root,key);
        if(node==nullptr){
            add(key,value);
        }else{
            node->value = value;
        }
    }
    V* remove(K key){
        TreeNode *node = getNode(root,key);
        if(node==nullptr){
            return nullptr;
        }
        root = remove(root,key);
        return &(node->value);
    }
    
    // 返回以node为根结点的二分搜索树的最小键值所在结点
    TreeNode* min(TreeNode *node){
        if(node->left == nullptr){
            return node;
        }
        return min(node->left);
    }
    // 删除以node为根的二分搜索树的最小键值所在结点
    // 返回删除结点后新的二分搜索树的根
    TreeNode* removeMin(TreeNode *node){
        if(node->left == nullptr){
            TreeNode* rightNode = node->right;
            delete node;
            size--;
            return rightNode;
        }
        node->left = removeMin(node->left);
        return node;
    }

    // 返回以node为根结点的二分搜索树的最大键值所在结点
    TreeNode* max(TreeNode *node){
        if(node->right == nullptr){
            return node;
        }
        return max(node->right);
    }

    // 删除以node为根的二分搜索树的最大键值所在结点
    // 返回删除结点后新的二分搜索树的根
    TreeNode* removeMax(TreeNode *node){
        if(node->right == nullptr){
            TreeNode* leftNode = node->left;
            delete node;
            size--;
            return leftNode;
        }
        node->right = removeMax(node->right);
        return node;
    }

    // 从以node为根结点的二分搜索树中删除键值为key的结点，递归
    // 返回删除结点后新的二分搜索树的根
    TreeNode* remove(TreeNode *node, K key){
        if(node == nullptr)
            return nullptr;
        TreeNode* retNode;
        if(node->key > key){ 
            node->left = remove(node->left, key);
            retNode = node;
        }else if(node->key <key){
            node->right = remove(node->right,key);
            retNode = node;
        }else{// key == node->key
            // 待删除结点左子树为空时
            if(node->left == nullptr){
                TreeNode * rightNode = node->right;
                delete node;
                size--;
                retNode = rightNode;
            }else if(node->right == nullptr){// 待删除结点右子树为空时
                TreeNode * leftNode = node->left;
                delete node;
                size--;
                retNode = leftNode;
            }else{ // 待删除结点左右子树均不为空时
                TreeNode* s = new TreeNode(min(node->right)->key,min(node->right)->value);
                s->right = remove(node->right,s->key);
                s->left = node->left;
                delete node;
                retNode = s;
            }
        }
        if(retNode==nullptr){
            return nullptr;
        }
        // 更新根节点高度
        retNode->height = 1 + std::max(getHeight(retNode->left),getHeight(retNode->right));
        int balanceFactor = getBalanceFactor(retNode);
        // LL
        if(balanceFactor > 1 && getBalanceFactor(retNode->left)>=0){
            return rightRotate(retNode);    
        }
        // RR
        if(balanceFactor < -1 && getBalanceFactor(retNode->right)<=0){
            return leftRotate(retNode);    
        }
        // LR
        if(balanceFactor > 1 && getBalanceFactor(retNode->left)<0){
            retNode->left = leftRotate(retNode->left);
            return rightRotate(retNode);
        }
        //RL
        if(balanceFactor < -1 && getBalanceFactor(retNode->right)>0){
            retNode->right = rightRotate(retNode->right);
            return leftRotate(retNode);
        }
        
        return retNode;
    }
};
#endif
