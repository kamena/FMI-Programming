#pragma once

#include <iostream>
#include <iomanip>  
#include <fstream> 
#include <string>

template <typename T>
struct Node {
    T data;
    Node<T>* left;
    Node<T>* right;

    Node(const T& data_ = T(), Node<T>* left_ = NULL, Node<T>* right_ = NULL)
    : data(data_), left(left_), right(right_) {}
};

template <typename T>
class Multiset {
public:
    Multiset() : root(NULL) {}

    ~Multiset() {
        this->destroy();
    }

    Node<T>* getRoot() {
        return root;
    }

    void add(const T& data) {
        if(root != NULL) {
            addHelper(root, data);
        } else {
            root = new Node<T>(data);
        }

        Node<T>* node = findElem(this->root, data);

        std::ofstream saveFile;
        saveFile.open("multisetLastVersion55896.dat", std::ios::binary | std::ios::app);
        
        saveFile.seekp(0, std::ios::end);
        saveFile.write((char*)&node, sizeof(Node<T>));

        saveFile.close();
    }

    bool search(const T& data_) {
        return findElem(this->root, data_);
    }

    bool removeIt(const T& data) {
        Node<T>*& node = findElem(root, data);
        return removeHelper(node);
    }

    int removeAll(T data) {
        return removeAllHelper(data, this->root, 0);
    }

    bool isSubSetHelper(Node<T>* root1, Node<T>* root2) {
        if(root1 == NULL && root2 == NULL) return true;
        if(root2 == NULL) return true;    
        if(root1 == NULL && !(root2 == NULL)) return false;
            
        return (root1->data == root2->data && isSubSetHelper(root1->left, root2->left) && isSubSetHelper(root1->right, root2->right) );
    }

    bool isSubSet(Node<T>* subTree) {
        Node<T>* rootBegin = findElem(this->root, subTree->data);
        
        if(rootBegin) {
            return isSubSetHelper(rootBegin, subTree);
        } else {
            return false;
        }
    } 

    int count() {
        return countHelper(this->root);
    }

    int count(T data) {
        return countHelper(data, this->root, 0);
    }

    void merge(Multiset<T> newRoot, Multiset<T>* newTree) { 

        int count = this->count() + newRoot.count();
        T arr[count];

        int lastPos = addToArray(root, arr, 0);
        addToArray(newRoot.root, arr, lastPos);

        T temp;
        for (int i = 0; i < count; i++) {
            for (int j = i + 1; j < count; j++) {
                if (arr[j] < arr[i]) {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }

        remove("multisetLastVersion55896.txt");

        newTree->arrToTree(arr, 0, count - 1);
    }

    void destroy() {
        this->destroyHelper(this->root);
    }

    void print() const {
        printHelper(this->root);
    }

    bool operator<(const Multiset<T>& rhs) {
        return this->count() < rhs.count();
    }
    bool operator>(const Multiset<T>& rhs) {
        return this->count() > rhs.count();
    }
    bool operator<=(const Multiset<T>& rhs) {
        return this->count() <= rhs.count();
    }
    bool operator>=(const Multiset<T>& rhs) {
        return this->count() >= rhs.count();
    }

    bool operator==(const Multiset<T>& rhs) {
        return (isSubSet(rhs) && this->count() == rhs.count());
    }
    bool operator!=(const Multiset<T>& rhs) {
        return !(isSubSet(rhs) && this->count() == rhs.count());
    }
    
private:
    Node<T>* root;

    int addToArray(Node<T>* node, T arr[], int i) {
        if(node == NULL) return i;

        arr[i] = node->data;
        i++;

        if(node->left != NULL) i = addToArray(node->left, arr, i);
        if(node->right != NULL) i = addToArray(node->right, arr, i);

        return i;
    }

    void arrToTree(T arr[], int start, int end) { 
        if(start > end) return;

        int mid = (start + end) / 2;

        add(arr[mid]);

        if(start <= end) {
            arrToTree(arr, start, mid - 1);
            arrToTree(arr, mid + 1, end);
        }
    }

    bool removeHelper(Node<T>* node) {     
        if(!node) {
            std::cerr << "Something went wrong: not valid node" << std::endl;
            return false;
        }

        if (node->left && node->right) {
            Node<T>* temp = findMin(node->right);
            
            node->data = temp->data;

            removeHelper(temp);
        } else if (node->left) {
            Node<T>* temp = node;
            node = node->left;

            delete temp;
        } else if (node->right){
            Node<T>* temp = node;
            node = node->right;

            delete temp;
        } else {
            delete node;
        }

        return true;
    }

    void addHelper(Node<T>*& node, const T& data_) {
        if(!node) {
            std::cerr << "Something went wrong: not valid node" << std::endl;
            return;
        } 

        if(data_ < node->data) {
            if(!node->left) {
                node->left = new Node<T>(data_);
            } else {
                addHelper(node->left, data_);
            }
        } else {
            if(!node->right) {
                node->right = new Node<T>(data_);
            } else {
                addHelper(node->right, data_);
            }
        } 
    }

    Node<T>*& findElem(Node<T>*& node, const T& data_) {
        if (!node) {
            std::cerr << "Something went wrong: not valid node" << std::endl;
            return node;
        } 

        if (data_ < node->data) return findElem(node->left, data_);
        if (node->data < data_) return findElem(node->right, data_);

        return node; 
    }

    Node<T>* findMin(Node<T>* root) {
        if(root->left) findMin(root->left);
        else return root;
    }

    int countHelper(Node<T>* node) {
        if(node == NULL) { 
            return 0;
        } else { 
            return countHelper(node->left) + countHelper(node->right) + 1;
        }
    }

    int countHelper(T data, Node<T>*& node, int count) {
        if(!node) return count;

        if (data < node->data) return countHelper(data, node->left, count);
        if (node->data < data) return countHelper(data, node->right, count);

        count++;

        if(node->right) return countHelper(data, node->right, count);

        return count;
    }

    int removeAllHelper(T data, Node<T>*& node, int removed) {
        if(!node) return removed;
        
        if(data < node->data) return removeAllHelper(data, node->left, removed);
        if(node->data < data) return removeAllHelper(data, node->right, removed);

        while(node->left && !(node->left->data < data || data < node->left->data ) ) {
            removed = removeAllHelper(data, node->left, removed);
        }

        remove(node->data);
        return removed + 1;
    }

    void destroyHelper(Node<T>* node) {
        if(node == NULL) return;

        if(node->left != NULL) destroyHelper(node->left);
        if(node->right != NULL) destroyHelper(node->right);
         
        delete node;
         
        return;
    }

    void printHelper(Node<T>* node, int indent = 0) const {
        if(node != NULL) {
            if(node->left) printHelper(node->left, indent+4);
            if(node->right) printHelper(node->right, indent+4);
            if (indent) {
                std::cout << std::setw(indent) << ' ';
            }
            std::cout << node->data << std::endl;
        }
    }
};
