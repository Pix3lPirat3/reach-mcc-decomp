struct item {
    unsigned char reserved0[0x250];
    void* pointer_250;
};

extern "C" int function_5e5170(item* self) {
    self->pointer_250 = 0;
    return 0;
}
