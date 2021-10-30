#ifndef __LINKED_LIST_CPP
#define __LINKED_LIST_CPP

template <typename T>
struct LinkedListElement {
	T data;
	LinkedListElement<T>* next;
};

template <typename T>
class LinkedListIterator {
	LinkedListElement<T>* ptr;
	using LLE = LinkedListElement<T>;
	using I = LinkedListIterator<T>;
public:
	LinkedListIterator(LLE* p = nullptr) : ptr(p) {}

	I next() const {
		if (!valid) {
			return *this;
		}

		return I(ptr->next);
	}

	bool valid() const {
		return ptr != nullptr;
	}

	T const& getConst() const {
		return ptr->data;
	}

	T& get() const {
		return ptr->data;
	}

	// синтактична захар
	// it <=> it.valid();
	operator bool() const {
		return valid();
	}

	// ++it
	I& operator++() {
		return (*this = next());
	}

	// it++
	I operator++(int) {
		I saved = *this;
		++(*this);
		return saved;
	}

	// *it = 3;
	T& operator*() {
		return get();
	}

	// it1 == it2
	bool operator==(I const& it) {
		return ptr == it.ptr;
	}

	// it1 != it2
	bool operator!=(I const& it) {
		return !(*this == it);
	}

	// it += n
	I& operator+=(unsigned n) {
		for (int i = 0; i < n; ++i) {
			++(*this);
		}

		return *this;
	}
};

template <typename T>
class LinkedList {
	using LLE = LinkedListElement<T>;
	using I = LinkedListIterator<T>;

	LLE* front, * back;

	void erase();
	void copy(LinkedList<T> const & ls);

public:

	// итератор?
	I begin() const {
		return I(front);
	}

	I end() const {
		return I();
	}

	LinkedList();

	LinkedList(LinkedList<T> const& ll);
	LinkedList<T>& operator=(LinkedList<T> const& ll);
	
	~LinkedList();

	// move конструктор
	LinkedList(LinkedList<T> && ll);
	LinkedList<T>& operator=(LinkedList<T> && ll);

	bool empty() const;

	bool insertBefore(I const& it, T const& x);
	bool insertAfter(I const& it, T const& x);
	
	// O(1)
	bool insertFirst(T const& x);
	bool insertLast(T const& x);

	bool deleteBefore(I const& it);
	bool deleteAfter(I const& it);
	bool deleteAt(I const& it);

	bool deleteBefore(I const& it, T& x);
	bool deleteAfter(I const& it, T&x);
	bool deleteAt(I const& it, T& x);

	bool deleteFirst(T& x);
	bool deleteLast(T& x);

	T const& getAt(I const& it) const;
	T& getAt(I const& it);


	void append(LinkedList<T> const& ll);
	void appendAssign(LinkedList<T> & ll);
};


#endif
