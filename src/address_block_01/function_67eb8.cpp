struct game_variant_wrapper {
    unsigned char reserved0[0x73e];
    unsigned short flags;
    unsigned char reserved740[0x148f4];
    unsigned char reserved15034[2];
    unsigned char description[1];
};

extern "C" void * function_102f4c(void* header, const void* text);
extern "C" void * function_35c3c(void* destination, const void* text, unsigned long long length);

extern "C" void * function_67eb8(game_variant_wrapper* wrapper, const void* text) {
    wrapper->flags = wrapper->flags & 0xfffe;
    function_102f4c(reinterpret_cast<char*>(wrapper) + 0x14, text);
    return function_35c3c(wrapper->description, text, 0x80);
}
