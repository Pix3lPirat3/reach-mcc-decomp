struct lock_group {
    char reserved0[4];
    int field_4;
    int field_8;
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

extern "C" long long lock_group_acquire_all_68a01c(lock_group* group, long long a, long long b, long long c);

extern "C" long long function_1bdbc8(owner* self, long long a, long long b, long long c) {
    long long result = lock_group_acquire_all_68a01c(&self->locks, a, b, c);
    self->flag_538 = 1;
    self->flag_544 = 1;
    return result;
}
