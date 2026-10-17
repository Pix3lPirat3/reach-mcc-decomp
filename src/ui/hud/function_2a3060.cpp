struct block {
    char reserved0[8];
    char field_8;
    char reserved9[0x237];
    short field_240;
    char reserved242[0xfe];
    short field_340;
};

extern "C" long long function_2a65d4(void* target);

extern "C" block* function_2a3060(block* self) {
    function_2a65d4(&self->field_8);
    self->field_240 = 0;
    self->field_340 = 0;
    return self;
}
