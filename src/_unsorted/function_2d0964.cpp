struct table {
    char reserved0[8];
    int values[0x1a];
    int count;
};

extern "C" int function_2d0964(table* self, int index) {
    if (index < 0)
        return self->values[0];
    if (index >= self->count)
        return self->values[0];
    return self->values[index];
}
