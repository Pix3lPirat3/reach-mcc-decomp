struct DatumHeader {
    unsigned char reserved00[0x20];
    unsigned __int64 stride;
    unsigned char reserved28[0x1c];
    int bound;
    unsigned char reserved48[8];
    unsigned __int64 storage;
};
static_assert(sizeof(DatumHeader) == 0x58);
static_assert(sizeof(void*) == 8 && sizeof(int) == 4 && sizeof(unsigned short) == 2);

extern "C" void* datum_lookup_native(const DatumHeader* owner, int handle) {
    void* result = nullptr;
    if (handle != -1) {
        const int index = static_cast<unsigned short>(handle);
        if (index < owner->bound) {
            const unsigned __int64 stride = owner->stride;
            const unsigned __int64 storage = owner->storage;
            const unsigned __int64 address = stride * static_cast<unsigned __int64>(index) + storage;
            const unsigned short* salt = reinterpret_cast<const unsigned short*>(address);
            if (*salt != 0) {
                if (*salt == static_cast<unsigned short>(handle >> 16))
                    result = reinterpret_cast<void*>(address);
            }
        }
    }
    return result;
}
