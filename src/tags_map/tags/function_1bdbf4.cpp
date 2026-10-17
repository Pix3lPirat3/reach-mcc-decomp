struct lock_group {
    char reserved0[4];
    int field_4;
    char reserved8[4];
    int field_c;
};

struct owner {
    char reserved0[0x51c];
    lock_group locks;
    char reserved52c[0xc];
    char flag_538;
    char reserved539[0xb];
    char flag_544;
};

extern "C" long long lock_group_release_all_68a064(lock_group* group);

extern "C" long long function_1bdbf4(owner* self) {
    long long result = lock_group_release_all_68a064(&self->locks);
    self->flag_538 = 0;
    self->flag_544 = 0;
    return result;
}
