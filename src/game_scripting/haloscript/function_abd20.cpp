extern "C" long long string_copy_padded_117b8(long long dest, long long source, unsigned long long size);
extern "C" long long host_user_data_path_query_utf8_abae4(long long object, unsigned int mode);
extern "C" long long function_abbb0(long long object, long long path);
extern "C" long long function_abc64(long long object, long long path);

extern "C" unsigned char* function_abd20(long long object, long long path) {
    host_user_data_path_query_utf8_abae4(object, 2);
    string_copy_padded_117b8(object + 0x210, object + 8, 0x104);
    function_abbb0(object, object + 0x10C);
    function_abc64(object, path);
    return (unsigned char*)(object + 0x210);
}
