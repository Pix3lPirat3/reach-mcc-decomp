struct item {
    unsigned char reserved0[0x4C];
    char field_4c;
};

extern "C" char function_5fea90(item* self) {
    return self->field_4c;
}
