struct object_a {
    unsigned char reserved0[8];
    unsigned long long field_8;
};
extern "C" unsigned long long hk_class_get_parent_879020(object_a* object) {
    return object->field_8;
}
