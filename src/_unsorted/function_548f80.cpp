struct error_manager {
    unsigned char reserved0[0x28];
    unsigned int field_28;
    unsigned char reserved2c[0x54];
    unsigned int field_80;
};

struct jpeg_object {
    error_manager* error;
};

extern "C" error_manager* function_548f80(jpeg_object* object) {
    object->error->field_80 = 0;
    error_manager* error = object->error;
    error->field_28 = 0;
    return error;
}
