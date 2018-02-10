#include <iostream>
#include <string>
using namespace std;

template <typename T>
struct BSTNode {
	int key;
    T data;
    BSTNode<T>* left;
    BSTNode<T>* right;

    BSTNode(int key_, const T& data_ = T(), BSTNode<T>* left_ = NULL, BSTNode<T>* right_ = NULL) {
    	this->key = key_;
        this->data = data_;
        this->left = left_;
        this->right = right_;
    }
};

template <typename T>
class BST {
private:
    BSTNode<T>* root;
public:
    BST(BSTNode<T>* nodes, int length) {
        this->root = createTree(nodes, 0, length - 1);
    }
    ~BST() {
        this->destroyFunc();
    }
    void insertFunc(int key, const T& data) {
        this->addElem(key, data, this->root);
    }
    bool searchFunc(int key, const T& data) {
        return findElem(key, data, this->root);
    }
    bool removeFunc(int key, const T& data) {
        BSTNode<T>*& node = findElem(key, data, root);
        if(!node) {
            return false;
        }

        if (node->left && node->right) {
            BSTNode<T>* temp = findMaxElem(node->left);
            node->key = temp->key;
            node->data = temp->data;

            delete temp;
        } else if (node->left) {
            BSTNode<T>* temp = node;
            node = node->left;

            delete temp;
        } else {
            BSTNode<T>* temp = node;
            node = node->right;

            delete temp;
        }

        return true;
    }

    int removeAllFunc(int key) {
        return deleteAllElems(key, root, 0);
    }
    void destroyFunc() {
        this->destroy(this->root);
    }
    void printFunc() const {
        this->print(this->root);
    }

private:
    BSTNode<T>* createTree(BSTNode<T>* nodes, int left, int right) {
        if (left > right) {
            return NULL;
        }
        if (left == right) {
            return new BSTNode<T>(nodes[left].key, nodes[left].data, NULL, NULL);
        }

        int middle = (left + right) / 2;
        BSTNode<T>* root = new BSTNode<T>(nodes[middle].key, nodes[middle].data, NULL, NULL);
        root->left = createTree(nodes, left, middle - 1);
        root->right = createTree(nodes, middle + 1, right);
        return root;
    }

    void addElem(int key, const T& data, BSTNode<T>*& node) {
        if (node) {
            if (key <= node->key) {
                if (node->left) {
                    addElem(key, data, node->left);
                } else {
                    node->left = new BSTNode<T>(key, data, NULL, NULL);
                }
            } else {
                if (node->right) {
                    addElem(key, data, node->right);
                } else {
                    node->right = new BSTNode<T>(key, data, NULL, NULL);
                }
            }
        } else {
            node = new BSTNode<T>(key, data, NULL, NULL);
        }
    }

    BSTNode<T>*& findElem(int key, const T& data, BSTNode<T>*& node) {
        if (!node) {
            return node;
        } else if (key < node->key) {
            return findElem(key, data, node->left);
        } else if (key > node->key) {
            return findElem(key, data, node->right);
        } else if(data != node->data) {
            return findElem(key, data, node->left);
        } else {
            return node;
        }
    }

    BSTNode<T>* findMaxElem(BSTNode<T>* elem) const {
        BSTNode<T>* node = elem;

        while (node->right) {
            node = node->right;
        }

        return node;
    }

    int deleteAllElems(int key, BSTNode<T>*& node, int removed) {
        if(!node) {
            return removed;
        }
        
        if(key < node->key) {
            return deleteAllElems(key, node->left, removed);
        }
        
        if(key > node->key) {
            return deleteAllElems(key, node->right, removed);
        }

        while(node->left && node->left->key == key) {
            removed = deleteAllElems(key, node->left, removed);
        }

        removeFunc(key, node->data);
        return removed + 1;
    }
    void destroy(BSTNode<T>* node) {
        if (node) {
            destroy(node->left);
            destroy(node->right);

            delete node;
        }
    }
    void print(BSTNode<T>* node) const {
        if (node) {
            if(node->left) {
                cout << "<";
                print(node->left);
            }

            cout << "(" << node->key << ":" << node->data << ")" << endl;

            if(node->right) {
                cout << ">";
                print(node->right);
            }
        }
    }
};

