struct job {
    unsigned char reserved0[0x20];
    void* field_20;
    unsigned char reserved28[0x20];
    void* field_48;
    int field_50;
};

extern "C" int function_904df0(void * queue, void * current, void * source, int flag);
extern "C" void function_912f00(void * current, void* first, void* second, int count);

extern "C" int function_9131c0(void * queue, job* current) {
    function_912f00(current, current->field_20, current->field_48, current->field_50);
    return function_904df0(queue, current, current, 0);
}
