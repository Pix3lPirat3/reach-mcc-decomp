extern "C" unsigned char function_42d4c(void* game_variant);
extern "C" unsigned char function_6c948(void* map_variant, int mode);

extern "C" unsigned char function_57c60(unsigned char* storage) {
    function_42d4c(storage + 0x14d8);
    return function_6c948((void*)((unsigned long long)(storage + 0x110e3) & ~3ull), -1);
}
