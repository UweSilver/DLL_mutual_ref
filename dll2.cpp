#include <iostream>
#include "header.hpp"
#include <memory>
#include <windows.h>

typedef void (*push)(SomeData *);

SomeData *strage = nullptr;
int index = 2;
HMODULE module;
push push_func;

DLL void init(void)
{
    module = LoadLibrary("./dll1.dll");

    push_func = (push)GetProcAddress(module, "push_instance");
    if (push_func == nullptr)
        std::cout << "push func is null at:  " << index << std::endl;
}

DLL SomeData *get_instance(void)
{
    return strage;
}

DLL void push_instance(SomeData *data)
{
    std::cout << "pushed to: " << index << std::endl;
    strage = data;
}

DLL void update(void)
{
    if (strage == nullptr)
    {
        std::cout << "nullptr" << std::endl;
    }
    else
    {
        std::cout << strage->val1 << std::endl;
        strage->val1 += index;
        push_func(strage);
        strage = nullptr;
        std::cout << "push! from: " << index << " to: " << 1 - (index - 1) + 1 << std::endl;
    }
}