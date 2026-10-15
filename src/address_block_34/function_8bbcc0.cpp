struct contact_mgr {
    unsigned char reserved0[0x40];
    unsigned char* index_table;
    unsigned char reserved48[0x20];
    long long properties;
};

extern "C" long long function_8bbcc0(contact_mgr* self, unsigned short id) {
    return self->properties + 0x30 + ((unsigned long long)self->index_table[id] << 5);
}
