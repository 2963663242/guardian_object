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
};



