struct object_a_field_8 {
    unsigned char field_0;
};

struct object_a {
    unsigned char reserved0[8];
    object_a_field_8* field_8;
};
extern "C" void function_6af58(object_a* object, unsigned char second) {
    object->field_8->field_0 = (unsigned char)(second & 1);
}
