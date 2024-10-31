#ifndef BSTMAP_H
#define BSTMAP_H
#include <iostream>
#include <stack>
#include <vector>

using namespace std;
#include "Map.h"

template<typename K, typename V>
class TreeNode{
public:
    K key;
    V value;
    TreeNode<K,V>* left;
    TreeNode<K,V>* right;

    TreeNode(K key, V value){
        this->key = key;
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};

template<typename K,typename V>
class BSTMap: public Map<K,V>{
private:
    TreeNode<K,V>* root;
    int size;
    // 在以node为根的二分搜索树中查找键key所在结点
    TreeNode<K,V> *getNode(TreeNode<K,V> *node,K key){
        if(node==nullptr) return nullptr;
        if(key == node->key){
            return node;
        }else if(key > node->key){
            return getNode(node->right,key);
        }else{
            return getNode(node->left,key);
        }
    }
    //将键值对放入以node为根结点的二分搜索树中
    // 回插入新结点后二分搜索树的根
    TreeNode<K,V>* add(TreeNode<K,V> *node, K key, V value){
        if(node==nullptr){
            size++;
            return new TreeNode<K,V>(key,value);
        }

        if(key > node->key){
            node->right = add(node->right, key, value);
        }else if(key < node->key){
            node->left = add(node->left, key, value);
        }else{
            node->value = value;
        }
        return node;
    }
public:
    BSTMap(){
        root = nullptr;
        size = 0;
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
        TreeNode<K,V> *node = getNode(root,key);
        if(node==nullptr){
            throw "no this key";
        }
        return node->value;
    }

    void add(K key,V value){
        root = add(root,key,value);
    }
    void set(K key, V value){
        TreeNode<K,V> *node = getNode(root,key);
        if(node==nullptr){
            add(key,value);
        }else{
            node->value = value;
        }
    }
    //前序遍历拿到keySet,非递归写法
    vector<K> keySet(){
        vector<K> ret;
        stack<TreeNode<K,V> *> stackTree;        
        stackTree.push(root);
        while(!stackTree.empty()){
            TreeNode<K,V>* cur = stackTree.top();
            stackTree.pop();
            ret.push_back(cur->key);
            if(cur->right!=nullptr){
                stackTree.push(cur->right);
            }
            if(cur->left!=nullptr){
                stackTree.push(cur->left);
            }
        }
        return ret;
    }


    V remove(K key){
        TreeNode<K,V> *node = getNode(root,key);
        if(node==nullptr){
            throw "no this key";
        }
        V ret = node->value;
        root = remove(root,key);
        return ret;
    }
    
    // 返回以node为根结点的二分搜索树的最小键值所在结点
    TreeNode<K,V>* min(TreeNode<K,V> *node){
        if(node->left == nullptr){
            return node;
        }
        return min(node->left);
    }
    // 删除以node为根的二分搜索树的最小键值所在结点
    // 返回删除结点后新的二分搜索树的根
    TreeNode<K,V>* removeMin(TreeNode<K,V> *node){
        if(node->left == nullptr){
            TreeNode<K,V>* rightNode = node->right;
            delete node;
            size--;
            return rightNode;
        }
        node->left = removeMin(node->left);
        return node;
    }

    // 返回以node为根结点的二分搜索树的最大键值所在结点
    TreeNode<K,V>* max(TreeNode<K,V> *node){
        if(node->right == nullptr){
            return node;
        }
        return max(node->right);
    }

    // 删除以node为根的二分搜索树的最大键值所在结点
    // 返回删除结点后新的二分搜索树的根
    TreeNode<K,V>* removeMax(TreeNode<K,V> *node){
        if(node->right == nullptr){
            TreeNode<K,V>* leftNode = node->left;
            delete node;
            size--;
            return leftNode;
        }
        node->right = removeMax(node->right);
        return node;
    }

    // 从以node为根结点的二分搜索树中删除键值为key的结点，递归
    // 返回删除结点后新的二分搜索树的根
    TreeNode<K,V>* remove(TreeNode<K,V> *node, K key){
        if(node == nullptr) return node;
        if(node->key > key){
            node->left = remove(node->left, key);
            return node;
        }else if(node->key <key){
            node->right = remove(node->right,key);
            return node;
        }else{// key == node->key
            // 待删除结点左子树为空时
            if(node->left == nullptr){
                TreeNode<K,V> * rightNode = node->right;
                delete node;
                size--;
                return rightNode;
            }
            // 待删除结点右子树为空时
            if(node->right == nullptr){
                TreeNode<K,V> * leftNode = node->left;
                delete node;
                size--;
                return leftNode;
            }
            // 待删除结点左右子树均不为空时
            TreeNode<K,V>* s = new TreeNode<K,V>(min(node->right)->key,min(node->right)->value);
            s->right = removeMin(node->right);
            s->left = node->left;
            delete node;
            return s;
        }
    }
};

#endif
