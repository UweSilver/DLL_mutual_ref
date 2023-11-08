#pragma once

#if defined DLL_EXPORT
#define DLL __declspec(dllexport)
#else
#define DLL __declspec(dllimport)
#endif

struct SomeData
{
public:
    int val1;
    int val2;
};

extern "C" DLL SomeData *get_instance(void);
extern "C" DLL void push_instance(SomeData *data);
extern "C" DLL void update(void);
extern "C" DLL void init(void);