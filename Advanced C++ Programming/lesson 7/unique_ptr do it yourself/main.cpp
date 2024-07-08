#include<iostream>
#include <exception>

template<class T>
class uniquePtr {
private: 
	T* object;
public:
	explicit uniquePtr(T* ptr) : object(ptr) {};

	T* release() {
		T* temp = object;
		object = nullptr;
		return temp;
	}

	T& operator*() {
		if (!object) {
			throw std::exception("Null pointer dereference");
		}
		return *object;
	}


	~uniquePtr() {
		delete object;
		std::cout << "dectructor called\n";
	}

	uniquePtr& operator=(const uniquePtr&) = delete;
	uniquePtr(const uniquePtr&) = delete;
};

int main() {
	setlocale(LC_ALL, "rus");
	int num = 19;
	uniquePtr<int> ptr(&num);

	try {
		std::cout << "Значения: " << *ptr << "\nАдрес: " << &*ptr << "\n" << "ptr.release():\n";
		ptr.release();
		std::cout << *ptr << "\n";
	}
	catch (const std::exception& exp) {
		std::cout << exp.what() << "\n";
	}


	return 0;
}