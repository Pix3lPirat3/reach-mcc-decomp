struct Object3;

struct Object3 {
    unsigned char reserved0[0x88f8];
    long long field_88f8;
    int field_8900;
    unsigned char reserved8904[4];
    int field_8908;
    int field_890c;
};

extern "C" void *function_36fd68(Object3 *object3, int value) {
    int local1;
    int local2;
    int local3;
    int local4;
    local1 = object3->field_8908;
    local2 = value - object3->field_8900;
    if (local1 == -1) {
        local3 = value;
    } else {
        local3 = local1 > value ? value : local1;
    }
    object3->field_8908 = local3;
    local4 = object3->field_890c;
    if (local4 != -1) {
        value = local4 > value ? local4 : value;
    }
    object3->field_890c = value;
    if (local2 < 0) {
        return 0;
    }
    void *result;
    if (local2 >= object3->field_88f8) {
        result = 0;
    } else {
        result = (char *)object3 + (long long)local2 * 0x444 + 120;
    }
    return result;
}
