struct player_traits {
    unsigned char block_00[0xC];
    unsigned char block_0c[0xC];
    unsigned char block_18[8];
    unsigned char block_20[8];
    unsigned char block_28[1];
};

extern "C" void function_107af0(void* block, void* reader);
extern "C" void function_1080dc(void* block, void* reader);
extern "C" void function_1084f8(void* block, void* reader);
extern "C" void function_108820(void* block, void* reader);
extern "C" void function_108a6c(void* block, void* reader);

extern "C" void function_108d8c(player_traits* traits, void* reader) {
    function_107af0(traits->block_00, reader);
    function_1080dc(traits->block_0c, reader);
    function_1084f8(traits->block_18, reader);
    function_108820(traits->block_20, reader);
    return function_108a6c(traits->block_28, reader);
}
