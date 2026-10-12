struct counter {
    unsigned char reserved0[4];
    int count;
};

struct channel {
    unsigned char reserved0[0x10];
    counter* counter_10;
    unsigned char reserved18[0x30];
    unsigned long long field_48;
};

extern "C" int function_63bd50(channel* self) {
    counter* item = self->counter_10;
    self->field_48 = 0;
    if (item == 0)
        return 0;
    item->count = item->count + 1;
    return 0;
}
