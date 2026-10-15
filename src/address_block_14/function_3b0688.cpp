struct callable_object {
    void** vtable;
};

extern "C" void* function_3b0688(callable_object* object, long long* value) {
    *value = 0x9FFFFFFF07F0FLL;
    ((void (*)(callable_object*, long long*, int))object->vtable[22])(object, value, 0);
    return value;
}
