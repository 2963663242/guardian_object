#include "IConverter.h"
#include "Converter.h"


IConverter::~IConverter()
{
}


std::shared_ptr<IConverter> create()
{
	return Protector<Converter>::create();
}
