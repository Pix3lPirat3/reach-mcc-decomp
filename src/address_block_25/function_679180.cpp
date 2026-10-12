struct block {
    unsigned char reserved0[8];
    unsigned int field_8;
    unsigned char reservedc[0x2c - 0xc];
    unsigned int field_2c;
    long long field_30;
};

extern "C" void function_679180(block* self) {
    self->field_30 = 0;
    self->field_2c = 0x7F7FFFEE;
    self->field_8 = 0x7F7FFFEE;
}
