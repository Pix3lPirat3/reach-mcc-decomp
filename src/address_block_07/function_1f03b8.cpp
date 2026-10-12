struct record {
    char reserved0[5];
    unsigned char value;
};

extern "C" char function_1f03b8(record* self, unsigned int value) {
    self->value = value <= 0xE ? (unsigned char)value : 0;
    return (unsigned char)value;
}
