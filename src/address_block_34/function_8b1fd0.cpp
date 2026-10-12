struct object_a {
    unsigned char reserved0[0xce];
    bool field_ce;
};
extern "C" void function_8b1fd0(object_a* object, bool second) {
    object->field_ce = second;
}
