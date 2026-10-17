struct table {
    char reserved0[0x2c];
    int count;
    int values[1];
};

extern "C" int function_2d02b4(table* self, int index) {
    if (index < 0)
        return self->values[0];
    if (index >= self->count)
        return self->values[0];
    return self->values[index];
}
