struct block {
    char reserved0[0x28];
    int field_28;
    int field_2c;
    char names[0x200];
    char field_230;
};

extern "C" long long function_35c3c(void* destination, void* source, long long size);

extern "C" long long function_2a6640(block* self, int value, void** sources) {
    int index = 0;
    long long source_index = 0;
    long long result;
    self->field_28 = value;
    self->field_2c = 2;
    do {
        result = function_35c3c(&self->names[(long long)index << 8], sources[source_index], 0x80);
        ++index;
        ++source_index;
    } while (source_index < 2);
    self->field_230 = 0;
    return result;
}
