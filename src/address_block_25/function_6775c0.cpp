struct block {
    void* field_0;
    int reserved8;
    unsigned int field_c;
    void* field_10;
    int field_18;
    unsigned int field_1c;
};

extern "C" block* function_6775c0(block* self) {
    self->field_c = 0x80000000;
    self->field_0 = 0;
    self->reserved8 = 0;
    self->field_10 = 0;
    self->field_18 = 0;
    self->field_1c = 0x80000000;
    return self;
}
