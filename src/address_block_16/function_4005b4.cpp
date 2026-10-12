struct object_a {
    unsigned char reserved0[0x58];
    bool field_58;
    unsigned char reserved59[3];
    unsigned int field_5c;
};
extern "C" void function_4005b4(object_a* object, long long, long long, unsigned int fourth) {
    object->field_58 = false;
    object->field_5c = fourth;
}
