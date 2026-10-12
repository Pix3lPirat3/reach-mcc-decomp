struct field_ref {
    char reserved0[0x18];
    unsigned char* data;
    unsigned char mask;
};

extern "C" unsigned char* function_2d08d8(field_ref* self, unsigned char* result) {
    *result = *self->data & self->mask;
    return result;
}
