struct slot_owner {
    unsigned char reserved0[0x94];
    int field_94;
};

extern "C" void function_6ca274(int value, long long, slot_owner* owner) {
    if (value != owner->field_94)
        return;
    owner->field_94 = -1;
}
