struct update_state {
    unsigned char reserved0[8];
    int field_8;
    unsigned char reserved_c[5];
    unsigned char field_11;
};

struct control_source {
    unsigned char reserved0[8];
    long long field_8;
    unsigned char reserved10[0x68];
    int field_78;
    unsigned char reserved7c[0x7A8];
    unsigned char field_824[1];
};

extern "C" int function_544da4(update_state* state, long long, control_source* source) {
    state->field_8 = source->field_78;
    long long cursor = source->field_8;
    long long count = *(int*)(cursor + 0x44);
    if (count > 0) {
        long long index = 0;
        cursor = (long long)source->field_824;
        while (*(unsigned char*)cursor == 0) {
            ++index;
            cursor += 0xDC;
            if (index < count)
                continue;
            state->field_11 = 0;
            return (int)cursor;
        }
        return (int)cursor;
    }
    state->field_11 = 0;
    return (int)cursor;
}
