struct zero_target {
    unsigned char reserved0[0x100];
    int field_100;
};

extern "C" zero_target* function_8ed450(zero_target* target) {
    target->field_100 = 0;
    return target;
}
