struct table {
    unsigned short field_0;
    unsigned char reserved2[0x36];
    unsigned char slots[0x10][0x818];
    unsigned char reserved81b8[0x240];
    unsigned char cleared[0xC50];
    unsigned int field_9048;
    unsigned char field_904C;
    unsigned char reserved904d[3];
    unsigned long long field_9050;
};

extern "C" long long function_4065d0(void* slot);
extern "C" long long function_2acd30(void* block);
extern "C" long long function_78932a(void* destination, int value, unsigned long long size);

extern "C" table* function_40654c(table* item) {
    unsigned char* slot = item->slots[0];
    item->field_0 = 0;
    long long remaining = 0x10;
    do {
        function_4065d0(slot);
        slot += 0x818;
        --remaining;
    } while (remaining != 0);
    function_2acd30((unsigned char*)item + 0x8450);
    item->field_904C = 0;
    function_78932a(item->cleared, 0, sizeof(item->cleared));
    item->field_9048 = 0;
    item->field_9050 = 0;
    return item;
}
