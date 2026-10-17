struct field_ref {
    char reserved0[0x18];
    unsigned char* data;
    unsigned char mask;
};

extern "C" char function_2d08c4(field_ref* self, char value) {
    unsigned char* data = self->data;
    char inverted = ~self->mask;
    *data = *data & inverted | value;
    return inverted;
}
