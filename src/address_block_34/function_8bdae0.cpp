struct island_counters {
    unsigned char reserved0[0x10];
    int field_10;
    unsigned int field_14;
    unsigned int field_18;
    unsigned int field_1C;
};

extern "C" int function_8bdae0(island_counters* target, island_counters* source) {
    int mine = target->field_10;
    int other = source->field_10;
    target->field_10 = mine > other ? mine : other;
    target->field_14 = target->field_14 + source->field_14;
    target->field_18 = target->field_18 + source->field_18;
    int last = source->field_1C;
    target->field_1C = target->field_1C + last;
    return last;
}
