## guardian_object
这是一个创建安全对象的库，单头文件，使用简单。

### 如何使用

#### 第一步

将头文件Protecter.h加入到你的项目中

#### 第二步

用你的对象继承Protecter

~~~c++
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
~~~

#### 第三步

在你想守护的函数内部，创建保护器

~~~c++
void Converter::convert()
{
	shared_ptr<Converter> ptr = this->createGuarder();

	thread obj([&,ptr]() {
		
		for (m_count = 0; m_count < 20; m_count++) {
			cout << m_count << endl;
			this_thread::sleep_for(std::chrono::milliseconds(100));
		}
		});
	obj.detach();
}
~~~

> 注意 保护器在传递的时候只支持赋值传递，引用、指针都不支持

#### 第四步

创建安全对象

~~~c++
std::shared_ptr<IConverter> create()
{
	return Protector<Converter>::create();
}
~~~

### 使用效果

~~~c++
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
~~~

![image-20230427153128349](doc\img\image-20230427153128349.png)

上图显示，虽然调用方已经析构了对象，但是由于convert还在执行所以没有立马执行析构函数，直到任务结束才执行析构函数