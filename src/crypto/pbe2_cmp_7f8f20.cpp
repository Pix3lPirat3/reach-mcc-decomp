struct pair {
    int first;
    int second;
};

extern "C" int pbe2_cmp_7f8f20(pair* left, pair* right) {
    int difference = left->first - right->first;
    if (difference != 0)
        return difference;
    return left->second - right->second;
}
