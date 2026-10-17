struct table {
    char reserved0[8];
    char values[4];
    int count;
};

extern "C" char function_2d08ec(table* self, int index) {
    if (index < 0)
        return self->values[0];
    if (index >= self->count)
        return self->values[0];
    return self->values[index];
}
