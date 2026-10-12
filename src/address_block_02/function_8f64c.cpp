struct object_a {
    unsigned char reserved0[0x30];
    unsigned long long field_30;
};
extern "C" void function_8f64c(object_a* object) {
    if (object->field_30 != 0) {
        object->field_30 = 0;
    }
}
