struct DatumArray {
    unsigned char reserved00[0x20];
    unsigned long long stride;
    unsigned char reserved28[4];
    int capacity;
    unsigned char reserved30[0x10];
    int hint;
    int bound;
    int used;
    unsigned char reserved4c[4];
    unsigned char* storage;
    unsigned int* bitmap;
};
static_assert(sizeof(void*) == 8 && sizeof(int) == 4 && sizeof(short) == 2);
static_assert(sizeof(DatumArray) == 0x60);
extern "C" unsigned char _bittest(long const*, long);
#pragma intrinsic(_bittest)
extern "C" void datum_element_init_138f0(DatumArray* array, void* element, void* counter);

extern "C" int target_13464(DatumArray* array) {
    int result = -1;
    unsigned int* const bitmap = array->bitmap;
    const int bound = array->bound;
    int index = array->hint;
    for (;;) {
        if (index < bound) {
            const unsigned __int64 word = static_cast<unsigned int>(index) >> 5;
            if (!(bitmap[word] & (1u << (index & 0x1f)))) break;
            ++index;
            continue;
        }
        goto grow;
    }
    if (index != result) goto take;
grow:
    if (bound >= array->capacity) goto done;
    index = bound;
    if (bound == result) goto done;
take:
    {
        unsigned char* const element = array->storage + array->stride * static_cast<__int64>(index);
        const unsigned __int64 word = static_cast<unsigned int>(index) >> 5;
        bitmap[word] = bitmap[word] | (1 << (index & 0x1f));
        array->used = array->used + 1;
        array->hint = index + 1;
        if (array->bound <= index) array->bound = index + 1;
        datum_element_init_138f0(array, element, reinterpret_cast<unsigned char*>(array) + 0x4c);
        result = static_cast<int>(static_cast<unsigned int>(*reinterpret_cast<short*>(element)) << 16 | static_cast<unsigned int>(index));
    }
done:
    return result;
}
