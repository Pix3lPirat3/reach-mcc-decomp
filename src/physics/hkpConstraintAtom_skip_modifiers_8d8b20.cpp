struct atom {
    unsigned short type;
    unsigned char reserved2[0x16];
    atom* next;
};

extern "C" atom* hkpConstraintAtom_skip_modifiers_8d8b20(atom* current) {
    do {
        current = current->next;
    } while (current->type >= 0x17);
    return current;
}
