struct block {
    char reserved0[0xf08];
    char field_f08;
    char reservedf09[0x1f];
    char field_f28;
};

extern "C" block* function_2a304c(block* self) {
    self->field_f08 = 0;
    self->field_f28 = 0;
    return self;
}
