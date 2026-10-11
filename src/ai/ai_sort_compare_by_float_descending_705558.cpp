struct ai_sort_entry {
    int index;
    float key;
};

extern "C" int ai_sort_compare_by_float_descending_705558(const ai_sort_entry* left, const ai_sort_entry* right) {
    return left->key >= right->key ? -1 : 1;
}
