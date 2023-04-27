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

class DLLEXPORT  MConverter  {
public:
	std::shared_ptr<IConverter> operator->();
public:
	static MConverter create();
private:
	MConverter(std::shared_ptr<IConverter> ptr);
	std::shared_ptr<IConverter> m_ptr;
	 
};







