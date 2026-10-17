struct track_holder {
    unsigned char reserved0[0x10];
    void* field_10;
    unsigned char reserved18[0x28];
    int field_40;
    unsigned char reserved44[0x4C];
    void* field_90;
    unsigned char field_98;
};

extern "C" void function_899d70(void* machine, void* second, void* third, long long fourth);

extern "C" void function_88b8a0(track_holder* holder, long long value) {
    function_899d70(&holder->field_40, holder->field_90, holder->field_10, value);
    holder->field_40 = 0;
    holder->field_98 = 1;
}
