struct timed_object {
    unsigned char reserved0[0x38];
    unsigned long long time;
};

extern "C" int system_milliseconds_11a84();

extern "C" unsigned int function_321a4(timed_object* object) {
    long long now = system_milliseconds_11a84();
    object->time = (unsigned int)now;
    return (int)now;
}
