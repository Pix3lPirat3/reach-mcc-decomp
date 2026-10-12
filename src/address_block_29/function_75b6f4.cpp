struct short_holder {
    unsigned char reserved0[2];
    short field_2;
};

extern "C" short function_75b6f4(long long, long long, long long, short_holder* holder) {
    return holder->field_2 <= 0 ? 0 : 2;
}
