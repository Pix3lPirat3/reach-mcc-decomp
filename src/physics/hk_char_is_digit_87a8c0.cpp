extern "C" bool* hk_char_is_digit_87a8c0(bool* result, int character) {
    *result = (unsigned int)(character - '0') <= 9;
    return result;
}
