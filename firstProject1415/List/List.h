#pragma once

template<typename T>
class List
{
private:
	struct Node
	{
		Node* prev;
		Node* next;
		T value;
		Node(const T& value_ = T(), Node* next_ = nullptr, Node* prev_ = nullptr) :
			value(value_),
			next(next_),
			prev(prev_)
		{
		}
	};

	Node* head;
	Node* tail;
	Node* emptyNode;
	int s;

public:
	List() :
		head(nullptr),
		tail(nullptr),
		emptyNode(new Node()),
		s(0)
	{
	}

	class iterator
	{
	private:
		Node* ptr;

	public:
		template <typename T>
		friend class List;

		iterator() :
			ptr(nullptr)
		{
		}

		explicit iterator(Node* ptr_) :
			ptr(ptr_)
		{
		}

		iterator(const iterator& copy) :
			ptr(copy.ptr)
		{
		}

		T& operator*() { return ptr->value; }

		const T& operator*() const { return ptr->value; }

		iterator operator++()
		{
			ptr = ptr->next;
			return *this;
		}

		iterator operator++(int)
		{
			ptr = ptr->next;
			return *this;
		}

		iterator operator--()
		{
			ptr = ptr->prev;
			return *this;
		}

		iterator operator--(int)
		{
			ptr = ptr->prev;
			return *this;
		}

		bool operator==(const iterator& cmp)
		{
			return ptr == cmp.ptr;
		}

		bool operator!=(const iterator& cmp)
		{
			return ptr != cmp.ptr;
		}
	};

	//returns iterator to first element
	iterator begin() const
	{
		if (head == nullptr)
		{
			return iterator(emptyNode);
		}
		return iterator(head);
	}

	//returns iterator to element after last one
	iterator end() const
	{
		return iterator(emptyNode);
	}

	~List();

	void pushFront(const T&);

	void pushBack(const T&);

	//returns first element's value
	T front() const { return head->value; }

	//returns last element's value
	T back() const { return tail->value; }

	//returns iterator containing value to find
	//uses interval to find value (gets also iterator to begin, and iterator to element after last on interval)
	iterator find(const T& value, const iterator& startSearch, const iterator& endSearch) const
	{
		iterator iterToSearch = startSearch;

		do
		{
			if (*iterToSearch == value)
			{
				return iterToSearch;
			}
			iterToSearch++;
		} while (iterToSearch != endSearch);

		return endSearch;
	}

	//inserts value before element in list
	void insert(iterator&, const T&);

	//removes element
	void erase(iterator&);

	T popBack();
	T popFront();

	int size() const { return s; }
};

template <typename T>
List<T>::~List()
{
	while (head)
	{
		Node* ptrToDel = head;
		head = head->next;
		delete ptrToDel;
	}
}

template <typename T>
void List<T>::pushBack(const T & value)
{
	s++;
	if (tail)
	{
		tail->next = new Node(value, nullptr, tail);
		tail = tail->next;
		tail->next = emptyNode;
	}

	else
	{
		tail = head = new Node(value);
		tail->next = emptyNode;
	}

	emptyNode->prev = tail;
}

template <typename T>
void List<T>::pushFront(const T & value)
{
	s++;
	if (head)
	{
		head->prev = new Node(value, head, head->next);
		head = head->prev;
	}
	else
	{
		tail = head = new Node(value);
	}
}

template <typename T>
void List<T>::insert(iterator& iterToInsert, const T& value)
{
	if (iterToInsert == begin())
	{
		pushFront(value);
		return;
	}

	else if (iterToInsert == end())
	{
		pushBack(value);
		return;
	}

	Node* insertNode = new Node(value, iterToInsert.ptr);

	iterToInsert.ptr->prev->next = insertNode;
	insertNode->prev = iterToInsert.ptr->prev;
	iterToInsert.ptr->prev = insertNode;
}

template <typename T>
void List<T>::erase(iterator& iterToDel)
{
	if (iterToDel.ptr != head)
	{
		iterToDel.ptr->prev->next = iterToDel.ptr->next;
	}
	else
	{
		head = iterToDel.ptr->next;
	}
	if (iterToDel.ptr != tail)
	{
		iterToDel.ptr->next->prev = iterToDel.ptr->prev;
	}
	else
	{
		tail = iterToDel.ptr->prev;
		emptyNode->prev = tail;
	}
	delete iterToDel.ptr;
	iterToDel.ptr = nullptr;
}

template <typename T>
T List<T>::popBack()
{
	iterator iterToDel = --end();
	T valueToReturn = *iterToDel;
	erase(iterToDel);
	return valueToReturn;
}

template <typename T>
T List<T>::popFront()
{
	iterator iterToDel = begin();
	T valueToReturn = *iterToDel;
	erase(iterToDel);
	return valueToReturn;
}
