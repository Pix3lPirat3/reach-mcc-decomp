struct source_object {
    unsigned char reserved0[0x1C0];
    unsigned char decoder[0x74];
    unsigned int first;
    unsigned int second;
};

struct size_pair {
    unsigned long long first;
    unsigned long long second;
};

extern "C" int jpeg_calc_output_dimensions_547410(void* decoder);

extern "C" char function_38b6b0(source_object* source, size_pair* size) {
    jpeg_calc_output_dimensions_547410(source->decoder);
    size->first = source->first;
    size->second = source->second;
    return 0;
}
