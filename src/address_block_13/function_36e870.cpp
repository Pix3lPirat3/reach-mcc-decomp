struct object_a {
    unsigned char reserved0[0xe4b0];
    unsigned int field_e4b0;
};
extern "C" bool function_36e870(object_a* object) {
    return object->field_e4b0 <= 1;
}
