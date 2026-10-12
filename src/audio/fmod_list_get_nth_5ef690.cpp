struct list_node {
    list_node* next;
};

extern "C" list_node* fmod_list_get_nth_5ef690(list_node* head, int index) {
    if (index < 0)
        return 0;
    list_node* node = head->next;
    if (node == head)
        return 0;
    while (index > 0) {
        node = node->next;
        if (node == head)
            return 0;
        index--;
    }
    return node;
}
