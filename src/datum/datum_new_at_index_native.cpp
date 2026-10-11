struct DatumArray {
    unsigned char reserved00[0x20];
    unsigned long long stride;
    unsigned char reserved28[4];
    int capacity;
    unsigned char reserved30[0x14];
    int bound;
    int used;
    unsigned char reserved4c[4];
    unsigned char* storage;
    unsigned int* bitmap;
};
static_assert(sizeof(void*) == 8 && sizeof(int) == 4 && sizeof(short) == 2);
static_assert(sizeof(DatumArray) == 0x60);
extern "C" void datum_element_init_138f0(DatumArray* array, void* element, void* counter);

extern "C" int target_135a0(DatumArray* array, int index) {
    int result = -1;
    if (index >= 0 && index < array->capacity) {
        unsigned char* const element = array->storage + array->stride * index;
        if (*reinterpret_cast<short*>(element) == 0) {
            const unsigned __int64 word = static_cast<unsigned int>(index) >> 5;
            unsigned int* const bitmap = array->bitmap;
            bitmap[word] = bitmap[word] | (1 << (index & 0x1f));
            array->used = array->used + 1;
            if (index >= array->bound) array->bound = index + 1;
            datum_element_init_138f0(array, element, reinterpret_cast<unsigned char*>(array) + 0x4c);
            result = *reinterpret_cast<short*>(element) << 16 | index;
        }
    }
    return result;
}
