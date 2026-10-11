extern "C" char* hkpConstraintAtom_get_indexed_block_0x20_8dded0(char* atom, int index) {
    long long triple = index * 3;
    return atom + 0x20 + triple * 48;
}
