struct file {
    unsigned char reserved0[0x1F0];
    int field_1f0;
};

extern "C" int fmod_file_memory_open_impl_63f620(file* self, void*, int* out_value) {
    self->field_1f0 = 0;
    *out_value = 0;
    return 0;
}
