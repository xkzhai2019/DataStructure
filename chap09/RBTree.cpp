#include <iostream>
#include "AVLTree.h"
#include "FileOperation.h"
#include "BSTMap.h"
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

int main(){
    cout << "pride-and-prejudice.txt" << endl;
    string filename = "pride-and-prejudice.txt";
    AVLTree<string, int> *avl = new AVLTree<string, int>();
    vector<string> words;
    if (FileOps::readFile(filename, words)) {
        cout << "Total words: " << words.size() << endl;
        clock_t startTime = clock();
        for (string word : words) {
            if (avl->contains(word)) {
                avl->set(word, avl->get(word) + 1);
            } else {
                avl->add(word, 1);
            }
        }
        for(string word: words){
            avl->contains(word);
        }
        clock_t endTime = clock();
        cout << "AVLTree: "<< double(endTime - startTime)/CLOCKS_PER_SEC << "s" <<endl;
        cout << "Total different words: " << avl->getSize() << endl;
        cout << "Frequency of PRIDE: " << avl->get("pride") << endl;
        cout << "Frequency of PREJUDICE: " << avl->get("prejudice") << endl;
    }
    
    BSTMap<string, int> *bstMap = new BSTMap<string, int>();
    vector<string> words2;
    if (FileOps::readFile(filename, words2)) {
        cout << "Total words: " << words2.size() << endl;
        clock_t startTime = clock();
        for (string word : words2) {
            if (bstMap->contains(word)) {
                bstMap->set(word, bstMap->get(word) + 1);
            } else {
                bstMap->add(word, 1);
            }
        }
        for(string word: words2){
            bstMap->contains(word);
        }
        clock_t endTime = clock();
        cout << "BSTMap: "<< double(endTime - startTime)/CLOCKS_PER_SEC << "s" <<endl;
        cout << "Total different words: " << bstMap->getSize() << endl;
        cout << "Frequency of PRIDE: " << bstMap->get("pride") << endl;
        cout << "Frequency of PREJUDICE: " << bstMap->get("prejudice") << endl;
    }
    
    RBTree<string, int> *rbTree = new RBTree<string, int>();
    vector<string> words3;
    if (FileOps::readFile(filename, words3)) {
        cout << "Total words: " << words3.size() << endl;
        clock_t startTime = clock();
        for (string word : words3) {
            if (rbTree->contains(word)) {
                rbTree->set(word, rbTree->get(word) + 1);
            } else {
                rbTree->add(word, 1);
            }
        }
        for(string word: words3){
            rbTree->contains(word);
        }
        clock_t endTime = clock();
        cout << "RBTree: "<< double(endTime - startTime)/CLOCKS_PER_SEC << "s" <<endl;
        cout << "Total different words: " << rbTree->getSize() << endl;
        cout << "Frequency of PRIDE: " << rbTree->get("pride") << endl;
        cout << "Frequency of PREJUDICE: " << rbTree->get("prejudice") << endl;
    }
    return 0;
}
