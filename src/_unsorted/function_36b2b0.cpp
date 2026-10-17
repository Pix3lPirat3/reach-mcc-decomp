struct object_a {
    unsigned char reserved0[0x378];
    unsigned int field_378;
};
extern "C" unsigned int function_36b2b0(object_a* object) {
    return object->field_378;
}
