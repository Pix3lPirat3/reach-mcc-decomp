struct free_list {
    unsigned char reserved0[0x20];
    void* second_chain;
};

extern "C" int function_876aa0(free_list* list, void* chain);

extern "C" int function_877110(free_list* list) {
    int result = function_876aa0(list, list->second_chain);
    list->second_chain = 0;
    return result;
}
