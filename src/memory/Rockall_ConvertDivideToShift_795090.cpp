extern "C" char Rockall_ConvertDivideToShift_795090(int value, int* shift) {
    if (value <= 0)
        return 0;
    int count = 0;
    if ((value & 1) == 0) {
        do {
            value >>= 1;
            ++count;
        } while ((value & 1) == 0);
    }
    if (value != 1)
        return 0;
    *shift = count;
    return 1;
}
