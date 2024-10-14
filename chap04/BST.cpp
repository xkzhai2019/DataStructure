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
};
