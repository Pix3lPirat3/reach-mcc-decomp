struct slot_owner {
    unsigned char reserved0[0x28];
    unsigned int field_28;
    unsigned int field_2c;
};

extern "C" void function_6e02e4(long long, slot_owner* owner, int value) {
    if (owner->field_28 == (unsigned int)value || owner->field_2c == (unsigned int)value) {
        owner->field_28 = 0xFFFFFFFF;
        return;
    }
}
