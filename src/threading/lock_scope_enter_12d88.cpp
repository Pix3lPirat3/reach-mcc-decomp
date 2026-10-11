struct lock_scope {
    unsigned int lock_index;
    unsigned char held;
};

extern "C" void lock_acquire_raw_12c44(int lock_index, long long, long long, long long);

extern "C" lock_scope* lock_scope_enter_12d88(lock_scope* scope, int lock_index, long long arg2, long long arg3) {
    scope->lock_index = lock_index;
    scope->held = 0;
    if (lock_index == -1) {
        return scope;
    }
    lock_acquire_raw_12c44(lock_index, 0, arg2, arg3);
    scope->held = 1;
    return scope;
}
