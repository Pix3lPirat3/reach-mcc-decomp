struct heap_user {
    unsigned char reserved0[8];
    int field_8;
};

extern "C" void function_46a2a0(void* heap);
extern "C" void function_a0274(int region, int member);

extern "C" void function_47cbe4(heap_user* user) {
    function_46a2a0(0);
    return function_a0274(4, user->field_8);
}
