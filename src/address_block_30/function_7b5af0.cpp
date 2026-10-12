struct object_a_field_8 {
    unsigned char reserved0[0x10];
    unsigned int field_10;
};

struct object_a {
    unsigned char reserved0[8];
    object_a_field_8* field_8;
};
extern "C" void function_7b5af0(object_a* object) {
    object->field_8->field_10 += 1;
}
