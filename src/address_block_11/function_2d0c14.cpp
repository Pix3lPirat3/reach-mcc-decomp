struct table {
    char reserved0[0x14];
    int count;
    int values[1];
};

extern "C" int function_2d0c14(table* self, int index) {
    if (index < 0)
        return self->values[0];
    if (index >= self->count)
        return self->values[0];
    return self->values[index];
}
