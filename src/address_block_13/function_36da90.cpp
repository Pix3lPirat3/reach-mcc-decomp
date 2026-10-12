struct Owner {
    unsigned char reserved0[0x78];
    unsigned char field_78;
};

struct Value {
    unsigned int field_0;
    unsigned char reserved4[4];
    unsigned char field_8;
};
extern "C" bool function_36da90(Owner* owner, long long, Value* input) {
    unsigned char loaded = owner->field_78;
    input->field_0 = 0;
    input->field_8 = loaded & 1;
    return true;
}
