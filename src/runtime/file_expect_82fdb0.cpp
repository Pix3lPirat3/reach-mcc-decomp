struct file_state {
    unsigned char reserved0[0x48];
    int expected;
};

extern "C" int file_expect_82fdb0(file_state* file, int expected) {
    file->expected = expected;
    return 1;
}
