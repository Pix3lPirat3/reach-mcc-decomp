struct memory_file {
    unsigned char reserved_0[0x20];
    unsigned length;
    unsigned char reserved_24[0x1cc];
    unsigned position;
};

extern "C" int fmod_file_memory_seek_impl_63f660(memory_file* file, unsigned offset) {
    file->position = offset > file->length ? file->length : offset;
    return 0;
}
