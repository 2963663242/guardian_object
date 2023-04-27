#pragma once
#include <memory>
#include "IConverter.h"

using namespace std;



class Converter : public IConverter
{
public:
	virtual void convert();
	virtual ~Converter();
private:
	Converter();
	void setWearPointer(weak_ptr<Converter>);
private:
	int m_count;
	weak_ptr<Converter> m_wPtr;
	
	friend std::shared_ptr<IConverter> create();
};



