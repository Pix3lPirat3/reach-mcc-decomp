struct slot_table {
    char reserved0[0x32];
    short first_flag;
};

extern "C" short* function_210b74(slot_table* table, short* total) {
    long long remaining = 4;
    *total = 0x2000;
    const short* amount = (const short*)((const char*)table + 0x40);
    const short* flag = &table->first_flag;
    do {
        if (*flag >= 0) {
            short value = *amount;
            if (value > 0)
                *total = *total - value;
        }
        amount += 1;
        flag += 2;
        --remaining;
    } while (remaining != 0);
    return total;
}
