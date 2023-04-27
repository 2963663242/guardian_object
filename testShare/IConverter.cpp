#include "IConverter.h"
#include "Converter.h"


IConverter::~IConverter()
{
}


std::shared_ptr<IConverter> create()
{
	Converter* converter = new Converter;
	shared_ptr<Converter> sPtr(converter);
	converter->setWearPointer(sPtr);
	return sPtr;
}
