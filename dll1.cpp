#include <iostream>
#include "header.hpp"
#include <memory>
#include <windows.h>

typedef void (*push)(SomeData *);

SomeData *strage = nullptr;
HMODULE module;
push push_func;

DLL void init(void)
{
    module = LoadLibrary("./dll2.dll");

    push_func = (push)GetProcAddress(module, "push_instance");
    if (push_func == nullptr)
        std::cout << "push func is null at: 1" << std::endl;
}

DLL SomeData *get_instance(void)
{
    return strage;
}

DLL void push_instance(SomeData *data)
{
    std::cout << "pushed to: " << 1 << std::endl;
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
        strage->val1 += 1;
        push_func(strage);
        strage = nullptr;
        std::cout << "push! from: " << 1 << " to: " << 1 - (1 - 1) + 1 << std::endl;
    }
}