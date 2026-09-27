#include<iostream>
#include<vector>
#include<memory>

template<class T>
class my_unique_ptr {
	T* __m_ptr;
public:
	my_unique_ptr(T* ptr) {
		__m_ptr = ptr;
	};
	my_unique_ptr(const my_unique_ptr&) = delete;
	T& operator*() { return *__m_ptr; }
	my_unique_ptr& operator=(const my_unique_ptr&) = delete;

	T* release() {
		T* my_ptr = __m_ptr;
		__m_ptr = 0;
		return my_ptr;
	}

	~my_unique_ptr() { if (__m_ptr != nullptr) { delete __m_ptr; } std::cout << "destructor called\n"; }
};


int main() {
	my_unique_ptr<int> ptr(new int(10));
	std::cout << *ptr << std::endl;
	auto* P = ptr.release();
	std::cout << *P << std::endl;
	delete P;

	return EXIT_SUCCESS;
}