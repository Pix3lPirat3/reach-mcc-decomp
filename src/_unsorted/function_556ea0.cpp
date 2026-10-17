struct marker_state {
    unsigned char reserved0[0x38];
    unsigned int field_38;
};

struct encoder {
    unsigned char reserved0[0x138];
    char write_jfif;
    unsigned char reserved139[7];
    char write_adobe;
    unsigned char reserved141[0xAF];
    marker_state* marker;
};

extern "C" void function_555d20(encoder* object, int marker);
extern "C" void function_556a20(encoder* object);
extern "C" void function_556c60(encoder* object);

extern "C" void function_556ea0(encoder* object) {
    marker_state* marker = object->marker;
    function_555d20(object, 0xD8);
    marker->field_38 = 0;
    if (object->write_jfif != 0)
        function_556a20(object);
    if (object->write_adobe != 0)
        function_556c60(object);
}
