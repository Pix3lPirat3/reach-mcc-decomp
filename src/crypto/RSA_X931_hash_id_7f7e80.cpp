extern "C" long long RSA_X931_hash_id_7f7e80(int nid) {
    switch (nid) {
    case 0x40:
        return 0x33;
    case 0x2A0:
        return 0x34;
    case 0x2A1:
        return 0x36;
    case 0x2A2:
        return 0x35;
    default:
        return 0xFFFFFFFF;
    }
}
