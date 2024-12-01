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
    V* remove(K key){
        TreeNode *node = getNode(root,key);
        if(node==nullptr){
            return nullptr;
        }
        root = remove(root,key);
        return &(node->value);
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
        return retNode;
    }
};

int main(){
    return 0;
}
