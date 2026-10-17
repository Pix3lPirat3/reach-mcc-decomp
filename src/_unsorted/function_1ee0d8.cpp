struct block {
    char reserved0[0x524];
    int field_524;
    char reserved528[0x214];
    int field_73c;
    char reserved740[0x56c];
    int field_cac;
    char reservedcb0[0x214];
    int field_ec4;
};

extern "C" block* function_1ee0d8(block* self) {
    self->field_524 = 0;
    self->field_73c = 0;
    self->field_cac = 0;
    self->field_ec4 = 0;
    return self;
}
