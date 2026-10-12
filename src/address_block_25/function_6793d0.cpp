struct block {
    unsigned char reserved0[8];
    unsigned int field_8;
    unsigned char reservedc[4];
    unsigned char field_10;
    unsigned char reserved11[0x3c - 0x11];
    unsigned int field_3c;
};

extern "C" void function_6793d0(block* self) {
    self->field_10 = 0;
    self->field_3c = 0x7F7FFFEE;
    self->field_8 = 0x7F7FFFEE;
}
