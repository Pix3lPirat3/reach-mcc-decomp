extern "C" long long function_78932a(void* destination, long long value, long long length);

extern "C" long long saved_film_slot_table_clear_172060(unsigned char* table) {
    unsigned char* slot = table + 0x2c;
    long long remaining = 0xb;
    long long result;
    do {
        result = function_78932a(slot - 0x2c, 0, 0x38);
        *(long long*)slot = -1;
        *(int*)(slot - 0x2c) = -1;
        *(int*)(slot - 0x24) = -1;
        *(int*)(slot - 0x20) = -1;
        slot += 0x38;
        --remaining;
    } while (remaining != 0);
    return result;
}
