struct slot {
    unsigned char reserved0[0x212];
    unsigned short field_212;
    unsigned char reserved214[4];
    unsigned char field_218[1];
};

extern "C" long long function_16fdc0(void* block);

extern "C" slot* function_4065d0(slot* item) {
    item->field_212 = 0;
    function_16fdc0(item->field_218);
    return item;
}
