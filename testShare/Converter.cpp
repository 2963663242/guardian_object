#include "Converter.h"
#include <thread>
#include <iostream>

Converter::Converter() {

}
Converter::~Converter()
{
	cout << "Converter::~Converter()" << endl;
}

void Converter::convert()
{
	shared_ptr<Converter> ptr = this->createGuarder();

	thread obj([&,ptr]() {
		
		for (m_count = 0; m_count < 100; m_count++) {
			cout << m_count << endl;
			this_thread::sleep_for(std::chrono::milliseconds(100));
		}
		});
	obj.detach();
}




