struct source_object {
    unsigned char reserved0[8];
    long long destination;
};

extern "C" int utf8_string_to_wchar_string_36400(long long destination, long long source, unsigned long long count);

extern "C" char function_381f90(source_object* object, long long source, long long count) {
    long long destination = object->destination;
    if (destination == 0 || source == 0)
        return 0;
    utf8_string_to_wchar_string_36400(destination, source, count);
    return 1;
}
