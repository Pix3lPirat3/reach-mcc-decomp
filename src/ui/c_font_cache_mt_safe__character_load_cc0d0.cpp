extern "C" int font_cache_load_internal_cc7bc(void* cache, int font, unsigned short character, int flags, void* first, void* second, void* result);

extern "C" char c_font_cache_mt_safe__character_load_cc0d0(void* cache, int font, unsigned short character, unsigned char flags, void* first, void* second, void* result) {
    return font_cache_load_internal_cc7bc(cache, font, character, flags | 2, first, second, result) == 2;
}
