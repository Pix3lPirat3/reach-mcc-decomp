struct Object7;
struct Object6;

struct Object7 {
    unsigned char reserved0[0x88];
    char* field_88;
};

struct Object6 {
    unsigned char reserved0[0x88];
    char* field_88;
};

extern "C" int function_863ae0(void *, void *);

extern "C" int function_83d370(Object6 *object6, Object7 *object7) {
    object6->field_88 = object7->field_88;
    return function_863ae0(object6, object7);
}
