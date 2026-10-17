struct object_a {
    unsigned char reserved0[0xcb98];
    unsigned char field_cb98;
};
extern "C" unsigned char* function_6aef8(object_a* object) {
    return &object->field_cb98;
}
