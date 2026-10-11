struct file_state {
    unsigned char reserved0[4];
    int error_count;
};

extern "C" int file_error_82fed0(file_state* file) {
    return file->error_count > 0;
}
