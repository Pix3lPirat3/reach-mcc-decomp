struct table {
    char reserved0[0x70];
    int count;
    char reserved74[4];
    int values[1];
};

extern "C" int function_2d0980(table* self, int index) {
    if (index < 0)
        return self->values[0];
    if (index >= self->count)
        return self->values[0];
    return self->values[index];
}
