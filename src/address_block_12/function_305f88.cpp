struct source {
    char reserved0[0x28];
    char field_28;
    char reserved29[0x11f];
    int field_148;
    int reserved14c;
    int field_150;
    int reserved154;
    int field_158;
};

extern "C" long long function_2d5034(source* object);
extern "C" void* function_2f6d14(source* object, int a, char b, char c, char d);

extern "C" int function_305f88(source* object) {
    function_2d5034(object);
    int index = object->field_150;
    int low = index <= 0 ? 0 : index;
    int count = object->field_148;
    long long clamped = low < count ? low : count;
    object->field_158 = (int)clamped;
    if (object->field_28 < 1)
        return (int)clamped;
    return (int)(long long)function_2f6d14(object, 0x280017, 1, 0, 1);
}
