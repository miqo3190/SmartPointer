#include <iostream>

template <typename T> 
class UniqPtr
{
public://ctor
	UniqPtr(T* ptr);
	~UniqPtr();
	UniqPtr(const UniqPtr&& ptr)
	{
		m_ptr = ptr.m_ptr;
		ptr.m_ptr = nullptr;
	}
	UniqPtr& operator=(const UniqPtr ptr) = delete;
public://oper
	UniqPtr& operator*() { return *m_ptr; }
	UniqPtr* operator->() { return m_ptr; }
	
private:
 	T* m_ptr;
};
template<typename T>
UniqPtr<T>::UniqPtr(T* ptr)
{
	m_ptr = ptr;
}
template<typename T>
UniqPtr<T>::~UniqPtr()
{
	delete m_ptr;
}
int main()
{
	std::cout << "SAD";
}

