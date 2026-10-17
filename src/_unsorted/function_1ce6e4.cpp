extern "C" int function_1ce6e4(int kind) {
    switch (kind) {
    case 1:
    case 8:
        return 0x12;
    case 2:
        return 0x18;
    case 3:
        return 0x2A;
    case 4:
        return kind + 0x1A;
    case 5:
        return 0xD;
    case 6:
    case 7:
        return 0xF;
    case 9:
        return 0x10;
    case 0xA:
        return kind + 7;
    default:
        return 9;
    }
}
