struct Object147;
struct Object129;

struct Object147 {
    unsigned char reserved0[2];
    char field_2;
};

struct Object129 {
    unsigned char reserved0[8];
    char field_8;
    unsigned char reserved9[0xf];
    Object147* field_18;
};

extern "C" int function_23e154(Object129 *object129) {
    if (object129->field_8) {
        return (object129->field_18->field_2 & 6) != 0;
    }
    if ((object129->field_18->field_2 & 2)) {
        return 0;
    }
    if (object129->field_18->field_2 & 4) {
        return 1;
    }
    return 0;
}
