#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

template <typename T>
struct Node {
    T data_;
    struct Node* next_;
    struct Node* prev_;

    Node(T data, Node<T>* next = NULL, Node<T>* prev = NULL) 
    : data_(data), next_(next), prev_(prev) {}

    void changeNext(Node<T>* next) {
    	next_ = next;
    }

    void changePrev(Node<T>* prev) {
    	prev_ = prev;
    }
};

template <typename T>
class DlList {
public:
	DlList() : start_(NULL), end_(NULL), size_(0) {}
	DlList(const DlList& other) { copy(other); }
	~DlList() {
		clear();
	}

	bool isEmpty() const { return !start_; }

	void copy(const DlList& other) {
		start_ = end_ = NULL;
		if(!other.start_) return;
		start_ = new Node<T>(other.start_->data_);
		end_ = new Node<T>(other.end_->data_);
		
		iterator itr = other->begin();
		for( itr = other->begin(); itr != other->end(); ++itr ) {
			push_back(other.itr->data_);
		}
		push_back(other.itr->data_);
	}

	void clear() {
		iterator itr = this->begin();
		for( itr = this->begin(); itr != this->end(); ++itr ) {
			deleteElement(itr);
		}
		deleteElement(itr);
	}

	size_t size() { return size_; }

private:
	Node<T>* start_;
	Node<T>* end_;

	size_t size_;

public:

	class iterator {
		Node<T>* position_;

		iterator(Node<T>* ptr) : position_(ptr) {}

		friend class DlList;
	public:
		bool operator==(const iterator& other) const {
			return position_ == other.position_;
		}

		bool operator!=(const iterator& other) const {
			return !operator==(other);
		}

		iterator& operator++() {
			position_ = position_->next_;

			return *this;
		}
		iterator& operator--() {
			position_ = position_->prev_;

			return *this;
		}
		iterator operator++(int) {
			iterator res = *this;
			operator++();
			return res;
		}
		iterator operator--(int) {
			iterator res = *this;
			operator--();
			return res;
		}

		T& operator*() { return position_->data_; }
		T* operator->() { return &position_->data_; }
	};

	iterator begin() { return iterator(start_); }
	iterator end() { return iterator(end_); }

	iterator addBefore(iterator pos, T data) {	
		Node<T>* position = pos.position_;
		if(isEmpty()) {
			start_ = end_ = new Node<T>(data, start_, end_);
			return iterator(start_);
		} 
		if(position == start_) {
			position->prev_ = new Node<T>(data,  position, end_);
			start_ = position->prev_;
			end_->next_ = position->prev_;
		} else {
			Node<T>* newEl = new Node<T>(data, position, position->prev_);
			position->changePrev(newEl);
			position->prev_->changeNext(newEl);
		}	

		size_++;	

		return iterator(position->prev_);
	}

	iterator push_back(const T& val) {
		return addAfter(start_, val);
	}

	iterator addAfter(iterator pos, T data) {
		Node<T>* position = pos.position_;
		if(isEmpty()) {
			start_ = end_ = new Node<T>(data, start_, end_);
			return iterator(start_);
		} 
		if(position == end_) {
			position->next_ = new Node<T>(data,  start_, position);
			end_ = position->next_;
			start_->prev_ = position->next_;
		} else {
			Node<T>* newEl = new Node<T>(data, position->next_, position);
			position->next_->changePrev(newEl);
			position->changeNext(newEl);
		}

		size_++;

		return iterator(position->next_);
	}

	iterator deleteElement(iterator pos) {
		Node<T>* node = pos.position_;
		Node<T>* currentPos = node->next_;

		if (node == start_) {
			start_ = node->next_;
		} else if(node == end_) {
			end_ = node->prev_;
			currentPos = node->prev_;
		}
		node->prev_->next_ = node->next_;
		node->next_->prev_ = node->prev_;
	
		delete node;

		size_--;

		return iterator(currentPos);
	}
};
