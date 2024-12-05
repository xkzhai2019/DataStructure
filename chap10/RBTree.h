#include <iostream>
using namespace std;

#define RED 1
#define BLACK 0

template<typename K,typename V>
class RBTree{
private:
    class TreeNode{
        public:
            K key;
            V value;
            TreeNode* left;
            TreeNode* right;
            bool color;

            TreeNode(K key, V value){
                this->key = key;
                this->value = value;
                left = nullptr;
                right = nullptr;
                color = RED;
            }
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

        if(isRed(node->right) && !isRed(node->left)){
            node = leftRotate(node);
        }
        if(isRed(node->left) && isRed(node->left->left)){
            node = rightRotate(node);
        }
        if(isRed(node->left) && isRed(node->right)){
            flipColor(node);
        }
        return node;
    }
public:
    RBTree(){
        root = nullptr;
        size = 0;
    }
    bool isRed(TreeNode* node){
        if(node==nullptr){
            return BLACK;
        }
        return node->color;
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
        root->color = BLACK;
    }
    void set(K key, V value){
        TreeNode *node = getNode(root,key);
        if(node==nullptr){
            add(key,value);
        }else{
            node->value = value;
        }
    }
    TreeNode* leftRotate(TreeNode *node){
        TreeNode* x = node->right;
        node->right = x->left;
        x->left = node;
        x->color = node->color;
        node->color = RED;
        return x;
    }
    
    void flipColor(TreeNode* node){
        node->color = RED;
        node->left->color = BLACK;
        node->right->color = BLACK;
    }

    TreeNode* rightRotate(TreeNode* node){
        TreeNode* x = node->left;
        node->left = x->right;
        x->right = node;
        x->color = node->color;
        node->color = RED;
        return x;
    }
    
};
