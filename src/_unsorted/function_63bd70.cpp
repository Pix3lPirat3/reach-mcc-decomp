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

extern "C" int function_63bd70(channel* self) {
    counter* item = self->counter_10;
    if (item != 0)
        item->count = item->count + 1;
    self->field_48 = 0;
    return 0;
}
