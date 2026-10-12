struct timed_object {
    unsigned char reserved0[0x58];
    int time;
};

extern "C" int system_milliseconds_11a84();

extern "C" unsigned int function_175ec0(timed_object* object) {
    int now = system_milliseconds_11a84();
    object->time = (int)now;
    return (int)now;
}
