struct sound {
    unsigned char reserved0[0x2C];
    unsigned int field_2c;
    unsigned char reserved30[0x14];
    unsigned int field_44;
    unsigned char reserved48[0x10];
    long field_58;
    unsigned char reserved5c[0x124];
    sound* field_180;
};

extern "C" long _InterlockedAnd(long*, long);
extern "C" long long function_58d950(sound* target, int start, int count);
extern "C" long long function_5fe460(sound* target, long long a, unsigned int count);

extern "C" long long function_5fe7c0(sound* object) {
    sound* parent = object->field_180;
    if (parent != 0) {
        unsigned int count;
        if ((object->field_2c & 0x400) == 0) {
            count = object->field_44;
            if (count <= parent->field_44)
                goto have_count;
        }
        count = parent->field_44;
    have_count:
        long long status = function_5fe460(object, 0, count);
        if (((int)status & -17) != 0)
            return status;
        sound* current = object->field_180;
        unsigned int total = current->field_44;
        if (count < total)
            function_58d950(current, count, total - count);
    }
    _InterlockedAnd(&object->field_58, -17);
    return 0;
}
