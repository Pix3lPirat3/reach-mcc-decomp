struct entity {
    unsigned char reserved0[0x13C];
    unsigned int unique_id;
};

extern "C" bool* hkp_compare_entities_by_unique_id_8c4440(bool* result, entity* left, entity* right) {
    *result = left->unique_id < right->unique_id;
    return result;
}
