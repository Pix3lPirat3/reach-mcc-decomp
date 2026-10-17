extern "C" long long function_136fc8(int* ring, int first, int second) {
    ring[(long long)*ring + 1] = first;
    ring[(long long)*ring + 5] = second;
    long long next = 3;
    int index = *ring;
    if (index != (int)next)
        next = (unsigned int)(index + 1);
    *ring = (int)next;
    return next;
}
