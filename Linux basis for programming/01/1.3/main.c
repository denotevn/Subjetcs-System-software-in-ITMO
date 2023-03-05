#include<stddef.h>
#include<stdbool.h>
#include<stdio.h>
#include<dlfcn.h>

void (*f)(float );

bool init_library()
{
	void *hdl = dlopen("./libsolution.so", RTLD_LAZY);
	if(NULL == hdl)
	{
		return false;
	}
	f = (void(*)(float))dlsym(hdl,"f");
	if (NULL == f)
	{
		return false;
	}
	return true;
}

int main()
{
	float a = 4.78;
	if(init_library())
	{
		f(a);
	}else{
		printf("Library was not loaded\n");
	}
	return 0;
}
