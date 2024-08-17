#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Vector {
private:
	T* elements;
	int maxCapacity;
	int currentSize;

public:
	Vector() {
		elements = new T[1];
		maxCapacity = 1;
		currentSize = 0;
	}

	void push_back(const T& value) {
		if (currentSize == maxCapacity) {
			T* tempArray = new T[2 * maxCapacity];
			for (int i = 0; i < maxCapacity; i++) {
				tempArray[i] = elements[i];
			}
			delete[] elements;
			maxCapacity *= 2;
			elements = tempArray;
		}
		elements[currentSize] = value;
		currentSize++;
	}

	void insert(int index, const T& value) {
		if (index == currentSize)
			push_back(value);
		else
			elements[index] = value;
	}

	void pop_back() {
		if (currentSize > 0)
			currentSize--;
		else
			throw underflow_error("Vector is empty");
	}

	int size() const {
		return currentSize;
	}

	int get_capacity() const {
		return maxCapacity;
	}

	T& operator[](int index) {
		if (index < currentSize)
			return elements[index];
		throw out_of_range("Index out of range");
	}

	const T& operator[](int index) const {
		if (index < currentSize)
			return elements[index];
		throw out_of_range("Index out of range");
	}

	~Vector() {
		delete[] elements;
	}
};

template<typename T>
class Stack {
private:
	Vector<T> stackVector;

public:
	void push(const T& value) {
		stackVector.push_back(value);
	}

	void pop() {
		stackVector.pop_back();
	}

	T top() const {
		return stackVector[stackVector.size() - 1];
	}

	bool empty() const {
		return stackVector.size() == 0;
	}

	int size() const {
		return stackVector.size();
	}
};

template<typename T>
class Queue {
private:
	Vector<T> queueVector;

public:
	void enqueue(const T& value) {
		queueVector.push_back(value);
	}

	void dequeue() {
		if (!empty()) {
			for (int i = 0; i < queueVector.size() - 1; i++) {
				queueVector[i] = queueVector[i + 1];
			}
			queueVector.pop_back();
		} else {
			throw underflow_error("Queue is empty");
		}
	}

	T front() const {
		return queueVector[0];
	}

	bool empty() const {
		return queueVector.size() == 0;
	}

	int size() const {
		return queueVector.size();
	}
};

template<typename Key, typename Value>
class Map {
private:
	static const int TABLE_SIZE = 100;
	pair<Key, Value> hashTable[TABLE_SIZE];
	bool isOccupied[TABLE_SIZE] = {false};

public:
	void insert(const Key& key, const Value& value) {
		int hashIndex = hash<Key>()(key) % TABLE_SIZE;
		while (isOccupied[hashIndex]) {
			if (hashTable[hashIndex].first == key) {
				hashTable[hashIndex].second = value;
				return;
			}
			hashIndex = (hashIndex + 1) % TABLE_SIZE;
		}
		hashTable[hashIndex] = {key, value};
		isOccupied[hashIndex] = true;
	}

	Value get(const Key& key) const {
		int hashIndex = hash<Key>()(key) % TABLE_SIZE;
		while (isOccupied[hashIndex]) {
			if (hashTable[hashIndex].first == key) {
				return hashTable[hashIndex].second;
			}
			hashIndex = (hashIndex + 1) % TABLE_SIZE;
		}
		throw out_of_range("Key not found");
	}

	bool exists(const Key& key) const {
		int hashIndex = hash<Key>()(key) % TABLE_SIZE;
		while (isOccupied[hashIndex]) {
			if (hashTable[hashIndex].first == key) {
				return true;
			}
			hashIndex = (hashIndex + 1) % TABLE_SIZE;
		}
		return false;
	}
};

template<typename T>
class Set {
private:
	Map<T, bool> setMap;

public:
	void insert(const T& value) {
		setMap.insert(value, true);
	}

	bool exists(const T& value) const {
		return setMap.exists(value);
	}

	void remove(const T& value) {
		if (setMap.exists(value)) {
			setMap.insert(value, false);
		}
	}
};

int main() {
	Vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	cout << "Vector Elements: ";
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << endl;

	Stack<int> stk;
	stk.push(1);
	stk.push(2);
	stk.push(3);
	cout << "Stack Top: " << stk.top() << endl;
	stk.pop();
	cout << "Stack Top after pop: " << stk.top() << endl;

	Queue<int> q;
	q.enqueue(100);
	q.enqueue(200);
	q.enqueue(300);
	cout << "Queue Front: " << q.front() << endl;
	q.dequeue();
	cout << "Queue Front after dequeue: " << q.front() << endl;

	Map<string, int> mp;
	mp.insert("one", 1);
	mp.insert("two", 2);
	mp.insert("three", 3);
	cout << "Map Get 'two': " << mp.get("two") << endl;

	Set<int> st;
	st.insert(10);
	st.insert(20);
	st.insert(30);
	cout << "Set Exists 20: " << (st.exists(20) ? "Yes" : "No") << endl;
	st.remove(20);
	cout << "Set Exists 20 after remove: " << (st.exists(20) ? "Yes" : "No") << endl;

	return 0;
}