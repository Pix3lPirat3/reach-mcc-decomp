struct memory_file {
    unsigned char reserved_0[0x24];
    unsigned length;
    unsigned char reserved_28[0x1c8];
    unsigned position;
};

extern "C" int fmod_file_memory_seek_63dd40(memory_file* file, unsigned offset) {
    file->position = offset > file->length ? file->length : offset;
    return 0;
}
