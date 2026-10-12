struct owner_object {
    unsigned char reserved0[0x38];
    long long field_38;
};

struct holder_object {
    unsigned char reserved0[0x10];
    owner_object* field_10;
};

struct constraint_instance {
    unsigned char reserved0[0x28];
    holder_object* holder;
    long long expected;
};

extern "C" char* function_8b2fd0(constraint_instance* instance, char* result) {
    long long expected = instance->expected;
    if (expected != 0) {
        owner_object* owner = instance->holder->field_10;
        if (owner == 0 || expected != owner->field_38) {
            *result = 0;
            return result;
        }
        *result = 1;
        return result;
    }
    *result = 1;
    return result;
}
