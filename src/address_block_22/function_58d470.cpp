struct list_node {
    list_node* next;
    list_node* previous;
    unsigned char reserved10[8];
    unsigned int key;
};

struct list_head {
    list_node* first;
};

extern "C" list_node* function_58d470(list_node* node, list_head* list, list_node* end, unsigned int key) {
    list_node* current = list->first;
    while (key >= current->key) {
        current = current->next;
        if (current->previous != end)
            continue;
        node->key = key;
        node->previous = end->previous;
        node->next = end;
        end->previous = node;
        list_node* previous = node->previous;
        previous->next = node;
        return previous;
    }
    node->key = key;
    node->previous = current->previous;
    node->next = current;
    current->previous = node;
    list_node* previous = node->previous;
    previous->next = node;
    return previous;
}
