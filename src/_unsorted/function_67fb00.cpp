struct block {
    unsigned char reserved0[0xb4];
    char field_b4;
};

extern "C" char function_67fb00(block* self) {
    return self->field_b4;
}
