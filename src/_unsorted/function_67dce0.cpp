struct block {
    unsigned char reserved0[0xce];
    char field_ce;
};

extern "C" char function_67dce0(block* self) {
    return self->field_ce;
}
