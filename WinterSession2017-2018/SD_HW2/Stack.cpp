#include <iostream>

using namespace std;

template <class T>
struct Node {
	T data_;
	Node* pNext_;
	Node(const T& data, Node* pNext = NULL) : data_(data), pNext_(pNext) {};
};

template <class T>
class Stack {
public: 
	Stack() : top_(NULL) {}

	~Stack() { clear(top_); }

	Stack(const Stack<T>& other) { top_ = copy(other.top_); }

	Stack <T>& operator=(const Stack<T>& other) {
		if(this == &other)  return *this;
		
		clear(top_);
		top_ = copy(other.top_);
		
		return *this;
	}

	bool isEmpty() const { return !top_; }

	const T& top() const { return top_->data_; }

	T pop() {
		Node<T>* node = top_;

		top_ = top_->pNext_;
		T data_ = node->data_;

		delete node;

		return data_;
	}

	void push(const T& data) {
		Node<T>* node = new Node<T>(data);
		node->pNext_ = top_;
		top_ = node;
	}

private:
	Node<T>* top_;

	Node<T>* copy(const Node<T>* node) {
		if(!node) return NULL;

		Node <T>* newNode = copy(node->pNext_);

		try {
			Node <T>* ifs = new Node<T>(node->data_, newNode);
			return ifs;
		} catch (std::bad_alloc &) {
			clear(newNode);
			throw;
		}

		return NULL;
	}

	void clear(Node <T>* node) {
		if(!node) return;

		clear(node->pNext_);

		delete node;
	}

};
