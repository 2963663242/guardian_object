#include "IConverter.h"
#include "Converter.h"


IConverter::~IConverter()
{
}



std::shared_ptr<IConverter> MConverter::operator->()
{
	return m_ptr;
}

MConverter MConverter::create()
{

	Converter* converter = new Converter;
	shared_ptr<Converter> sPtr(converter);
	converter->setWearPointer(sPtr);
	MConverter mc(sPtr);
	return mc;
}

MConverter::MConverter(std::shared_ptr<IConverter> ptr) :m_ptr(ptr)
{

}

