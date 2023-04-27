#include "Converter.h"
#include <thread>
#include <iostream>

Converter::Converter() {

}
Converter::~Converter()
{
	cout << "Converter::~Converter()" << endl;
}

void Converter::setWearPointer(weak_ptr<Converter> wPtr)
{
	m_wPtr = wPtr;
}

void Converter::convert()
{
	shared_ptr<Converter> ptr = (shared_ptr<Converter>)m_wPtr;
	thread obj([&,ptr]() {
		
		for (m_count = 0; m_count < 100; m_count++) {
			cout << m_count << endl;
			this_thread::sleep_for(std::chrono::milliseconds(100));
		}
		});
	obj.detach();
}



//shared_ptr<Converter> create() {
//	Converter* converter = new Converter;
//	shared_ptr<Converter> sPtr(converter);
//	converter->setWearPointer(sPtr);
//	return sPtr;
//}
