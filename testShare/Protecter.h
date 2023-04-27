#pragma once
#include <memory>

using namespace std;

template<class T>
class Protector {

public:
	shared_ptr<T> createGuarder() {
		return (shared_ptr<T>)m_wPtr;
	}
public:
	static shared_ptr<T> create() {
		T* ptr = new T;
		return create(ptr);
	}
	static shared_ptr<T> create(T* ptr) {
		shared_ptr<T> sPtr(ptr);
		ptr->setWearPointer(sPtr);
		return sPtr;
	}
private:
	void setWearPointer(shared_ptr<T> wPtr) {
		m_wPtr = wPtr;
	}
private:
	weak_ptr<T> m_wPtr;
};
 
