struct counted_object {
    unsigned char reserved0[0x70];
    int count;
};

extern "C" int hk_set_count_return_shifted_0x70_8c9880(counted_object* object, int count) {
    object->count = count;
    return count << 6;
}
