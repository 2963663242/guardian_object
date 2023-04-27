#pragma once
#include <memory>

#ifdef _WIN32
#define DLLEXPORT __declspec(dllexport)
#elif defined __APPLE__
#define DLLEXPORT 
#endif 


class DLLEXPORT IConverter
{
public:
	virtual void convert()=0;
	virtual ~IConverter();
};

template class DLLEXPORT std::shared_ptr<IConverter>;



std::shared_ptr<IConverter> DLLEXPORT create();







