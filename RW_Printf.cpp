//C语言变形参数目的函数和重写printf函数

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

namespace myone{

	void simple_va_fun(int start, ...){
		va_list arg_ptr;
		int nargvalue = start;
		int nargcout = 0;
		va_start(arg_ptr, start);
		do{
			++nargcout;
			printf("the %dth arg: %d", nargcout, nargvalue);
			nargvalue = va_arg(arg_ptr, int);//得到下一个可变参数
		} while (nargvalue != -1);
		va_end(arg_ptr);
		return;
	}

	int myprintf(char* format, ...){
		va_list va_ptr;
		int n;
		va_start(va_ptr, format);
		n = vprintf(format, va_ptr);
		va_end(va_ptr);
		return n;
	}

	int printf(char* format, ...){
		char* m = "\nBegin:\n";
		char* n = "End\n";
		va_list va_ptr;
		va_start(va_ptr, format);
		char* p;
		for (p = (char*)m; *p; ++p){
			putchar(*p);
		}
		for (p = (char*)format; *p; p++){
			putchar(*p);
		}
		for (p = (char*)n; *p; p++){
			putchar(*p);
		}
		va_end(va_ptr);
		return 0;
	}
	void hello(){
		myone::printf("   Hello,world!\n");
	}
	
}

int main(){
	myone::simple_va_fun(100, -1);
	int i = 8; int j = 10;
	myone::myprintf("\nthis is %d %d", i, j);
	myone::hello();
	system("pause");
	return 0;
}