struct source_block {
    unsigned char reserved0[0x6a0];
    int field_6a0;
    unsigned char reserved6a4[0x115ac - 0x6a4];
    int field_115ac;
};

struct target_block {
    unsigned char reserved0[0xb0];
    source_block* source;
    unsigned char reservedb8[0x210 - 0xb8];
    int field_210;
    int field_214;
    unsigned char reserved218[0x228 - 0x218];
    int field_228;
    float field_22c;
    int field_230;
};

struct holder {
    target_block* target;
};

extern "C" long long function_65e410(holder* self) {
    target_block* target = self->target;
    source_block* source = target->source;
    target->field_214 = 0;
    float value = (float)source->field_6a0;
    target->field_210 = 0;
    target->field_228 = -1;
    target->field_22c = value;
    target->field_230 = source->field_115ac;
    return 0;
}
