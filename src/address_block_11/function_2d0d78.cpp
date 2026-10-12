struct table {
    char reserved0[8];
    short values[0x100];
    int count;
};

extern "C" short function_2d0d78(table* self, int index) {
    if (index < 0)
        return self->values[0];
    if (index >= self->count)
        return self->values[0];
    return self->values[index];
}
