struct block {
    char reserved0[0x28];
    int field_28;
    int field_2c;
    char names[0x14];
    char field_44;
};

extern "C" long long function_35c3c(void* destination, void* source, long long size);

extern "C" long long function_2c9994(block* self, int value, void** sources) {
    int index = 0;
    long long source_index = 0;
    long long result;
    self->field_28 = value;
    self->field_2c = 2;
    do {
        result = function_35c3c(&self->names[(long long)index * 10], sources[source_index], 5);
        ++index;
        ++source_index;
    } while (source_index < 2);
    self->field_44 = 0;
    return result;
}
