struct Object;

struct Object {
    unsigned char reserved0[0x50];
    char* field_50;
};

extern "C" long long function_831970(long long, long long, long long, Object *object) {
    return (*(long long (**)(void))(object->field_50 + 0x18))();
}
