struct object_a {
    unsigned char reserved0[0x30];
    unsigned int field_30;
};
extern "C" unsigned int hk_class_get_num_declared_members_878ff0(object_a* object) {
    return object->field_30;
}
