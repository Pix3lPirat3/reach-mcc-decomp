static_assert(sizeof(int) == 4);
static_assert(sizeof(void*) == 8 && sizeof(unsigned long long) == 8);
extern "C" int g_count(void*);
extern "C" int g_get(void*, int);
extern "C" void* memcpy(void*, const void*, unsigned long long);
extern "C" bool fn(void* obj, int index, unsigned char* out)
{
    int count = g_count(obj);
    bool ok = false;
    if (index >= 0 && index < count) {
        const int value = g_get(obj, index);
        memcpy(out + 8, &value, 4);
        const int kind = 1;
        memcpy(out, &kind, 4);
        ok = true;
    }
    return ok;
}
