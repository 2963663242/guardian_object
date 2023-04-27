// testShare.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "IConverter.h"
#include <iostream>
using namespace std;
int main()
{
	{
		std::shared_ptr<IConverter> converter = create();
		converter->convert();

	};
	cout << "我被执行了" << endl;
	getchar();
}

