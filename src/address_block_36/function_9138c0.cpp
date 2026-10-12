struct job {
    unsigned char reserved0[0x20];
    void* field_20;
    unsigned char reserved28[0x10];
    void* field_38;
    int field_40;
};

extern "C" int function_904df0(void * queue, void * current, void * source, int flag);
extern "C" void function_913700(void * current, void* first, void* second, int count);

extern "C" int function_9138c0(void * queue, job* current) {
    function_913700(current, current->field_20, current->field_38, current->field_40);
    return function_904df0(queue, current, current, 0);
}
