struct OwnerInterface {
    virtual void* slot0(void*) = 0;
    virtual void* release(void* object) = 0;
};
static_assert(sizeof(void*) == 8);
extern "C" void* relative_heap_clear_78932a(void* destination, int value, unsigned long long size);

extern "C" void* target_68a104(unsigned char* heap) {
    OwnerInterface* const owner = *reinterpret_cast<OwnerInterface**>(heap + 0x28);
    relative_heap_clear_78932a(heap, 0, 0x58);
    return owner->release(heap);
}
