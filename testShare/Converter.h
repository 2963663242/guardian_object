#pragma once

#include "Protecter.h"
#include "IConverter.h"





class Converter :public Protector<Converter> ,public IConverter
{
public:
	virtual void convert();
	virtual ~Converter();
	Converter();
private:
	int m_count;
	weak_ptr<Converter> m_wPtr;
	
	friend std::shared_ptr<IConverter> create();
};



