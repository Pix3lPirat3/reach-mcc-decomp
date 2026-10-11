extern "C" long long BN_is_odd_7a5f40(unsigned char** number) {
    if (*(int*)&number[1] <= 0) {
        return 0;
    }
    if ((*number[0] & 1) == 0) {
        return 0;
    }
    return 1;
}
