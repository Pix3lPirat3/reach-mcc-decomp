struct Target {
    char reserved_0[0xc];
    char result;
};

struct Callback {
    Target* target;
    char (*function)(void*, void*);
    void* argument0;
    void* argument1;
};

extern "C" unsigned int function_348144(Callback* callback)
{
    callback->target->result = callback->function(callback->argument0, callback->argument1);
    return 1;
}
