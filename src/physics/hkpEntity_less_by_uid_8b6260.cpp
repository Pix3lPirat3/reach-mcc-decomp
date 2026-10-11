struct entity {
    unsigned char reserved0[0x13C];
    unsigned int uid;
};

extern "C" char hkpEntity_less_by_uid_8b6260(entity* left, entity* right) {
    return left->uid < right->uid;
}
