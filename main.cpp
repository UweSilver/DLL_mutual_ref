#include <iostream>
#include <windows.h>
#include "header.hpp"

typedef SomeData *(*get)(void);
typedef void (*push)(SomeData *);
typedef void (*u)(void);
typedef void (*init_func)(void);
void main()
{
    std::cout << "hello, world" << std::endl;

    HMODULE module = LoadLibrary("./dll1.dll");
    HMODULE module2 = LoadLibrary("./dll2.dll");
    if (module == NULL)
        return;
    if (module2 == NULL)
        return;

    auto pushfunc = (push)GetProcAddress(module, "push_instance");
    auto pushfunc2 = (push)GetProcAddress(module2, "push_instance");
    auto updatefunc = (u)GetProcAddress(module, "update");
    auto updatefunc2 = (u)GetProcAddress(module2, "update");
    auto ini = (init_func)GetProcAddress(module, "init");
    auto ini2 = (init_func)GetProcAddress(module2, "init");

    ini();
    ini2();

    updatefunc();
    updatefunc2();

    auto ptr = new SomeData;
    ptr->val1 = 1;
    pushfunc(ptr);

    updatefunc();
    updatefunc2();
    updatefunc();
    updatefunc2();
    updatefunc();
    updatefunc2();
    updatefunc();
    updatefunc2();
}