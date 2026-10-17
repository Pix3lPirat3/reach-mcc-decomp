struct block {
    unsigned char reserved0[8];
    int field_8;
    unsigned char reservedc[0xc];
    int field_18;
};

extern "C" int function_6812c0(block* self) {
    self->field_8 = 0;
    self->field_18 = 0;
    return 0;
}
