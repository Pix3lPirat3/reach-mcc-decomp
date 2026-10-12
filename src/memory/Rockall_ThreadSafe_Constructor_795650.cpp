struct thread_safe {
    long long field_0;
    int field_8;
    unsigned char reservedc[0x74];
    unsigned char lock_80[0x80];
    char field_100;
};

extern "C" void Rockall_SpinLock_Constructor_7951c0(void* lock, int first, int second);

extern "C" thread_safe* Rockall_ThreadSafe_Constructor_795650(thread_safe* self, char value) {
    Rockall_SpinLock_Constructor_7951c0(self->lock_80, 0x1000, 0x100);
    self->field_100 = value;
    self->field_0 = -1;
    self->field_8 = 0;
    return self;
}
