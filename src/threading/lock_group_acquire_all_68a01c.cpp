struct lock_scope {
    unsigned int lock_index;
    unsigned char held;
};

struct lock_group {
    unsigned char reserved0[4];
    unsigned int semaphore_count;
    unsigned int lock_index;
    unsigned int semaphore_index;
};

extern "C" void lock_scope_enter_12d88(lock_scope* scope, int lock_index, long long arg2, long long arg3);
extern "C" long long lock_scope_leave_12db4(lock_scope* scope);
extern "C" void sync_semaphore_wait_12ef4(int semaphore_index);

extern "C" long long lock_group_acquire_all_68a01c(lock_group* group, long long, long long arg2, long long arg3) {
    lock_scope scope;
    lock_scope_enter_12d88(&scope, group->lock_index, arg2, arg3);
    int index = 0;
    if ((int)group->semaphore_count <= index) {
        return lock_scope_leave_12db4(&scope);
    }
    do {
        sync_semaphore_wait_12ef4(group->semaphore_index);
        ++index;
    } while (index < (int)group->semaphore_count);
    return lock_scope_leave_12db4(&scope);
}
