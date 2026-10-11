struct list_node {
    list_node* first;
    list_node* second;
};

extern "C" list_node* fmod_linkedlist_node_add_before_57c0a0(list_node* node, list_node* position) {
    list_node* previous = position->first;
    node->first = previous;
    node->second = position;
    previous->second = node;
    list_node* inserted = node->second;
    inserted->first = node;
    return inserted;
}
