namespace reach_megalo_proposal {
using byte = unsigned char;
static_assert(sizeof(unsigned int) == 4, "requires 32-bit unsigned int");

static unsigned int word(const byte* p) {
    return unsigned(p[0]) | (unsigned(p[1]) << 8);
}
static unsigned int dword(const byte* p) {
    return word(p) | (word(p + 2) << 16);
}
static long long signed_dword(const byte* p) {
    const unsigned int v = dword(p);
    return v < 0x80000000u ? static_cast<long long>(v)
                          : static_cast<long long>(v) - 0x100000000ll;
}
static int signed_byte(byte v) {
    return v < 128 ? int(v) : int(v) - 256;
}

static bool declaration_bytes_valid(const byte* definition,
                                    unsigned int count_offset) {
    const long long count = signed_dword(definition + count_offset);
    for (long long i = 0; i < count; ++i) {
        if (byte(definition[count_offset + 8 + i] + 1) > 9)
            return false;
    }
    return true;
}

bool megalo_definition_validate(const byte* definition) {

    if (dword(definition + 0xf08) > 512) return false;
    for (long long i = 0; i < signed_dword(definition + 0xf08); ++i) {
        if (definition[0xf10 + 16 * i + 12] >= 18) return false;
    }

    if (dword(definition + 0x2f10) > 1024) return false;
    for (long long i = 0; i < signed_dword(definition + 0x2f10); ++i) {
        if (definition[0x2f18 + 20 * i + 16] >= 107) return false;
    }

    if (dword(definition) > 320) return false;
    for (long long i = 0; i < signed_dword(definition); ++i) {
        const byte* trigger = definition + 8 + 12 * i;
        const byte loop_type = trigger[8];
        const byte event_type = trigger[9];
        if (loop_type >= 6 || event_type >= 8) return false;

        if ((event_type == 2 || event_type == 3 || event_type == 4 || event_type == 7)
            && loop_type != 0) return false;
        if (loop_type == 5) {
            const int label = signed_byte(trigger[10]);
            if (label < 0 || label >= signed_dword(definition + 0x80e4))
                return false;
        } else {
            if (trigger[10] != 255) return false;
        }

        if (word(trigger) + word(trigger + 2)
            > signed_dword(definition + 0xf08)) return false;
        if (word(trigger + 4) + word(trigger + 6)
            > signed_dword(definition + 0x2f10)) return false;
    }

    if (dword(definition + 0x7f18) > 4) return false;
    for (long long i = 0; i < signed_dword(definition + 0x7f18); ++i) {
        const byte* statistic = definition + 0x7f20 + 4 * i;
        if (byte(statistic[0] - 0x70) <= 0x8e) return false;
        if (statistic[1] >= 4) return false;
        if (byte(statistic[2] + 1) > 3) return false;
        if (statistic[3] > 1) return false;
    }

    if (!declaration_bytes_valid(definition, 0x7f7c)) return false;
    if (dword(definition + 0x7fb8) > 8) return false;
    if (dword(definition + 0x7fbc) > 16) return false;
    if (!declaration_bytes_valid(definition, 0x7ff4)) return false;
    if (dword(definition + 0x8014) > 4) return false;
    if (dword(definition + 0x8018) > 4) return false;
    if (!declaration_bytes_valid(definition, 0x8050)) return false;
    if (dword(definition + 0x8070) > 4) return false;
    if (dword(definition + 0x8074) > 4) return false;
    if (!declaration_bytes_valid(definition, 0x80ac)) return false;
    if (dword(definition + 0x80d0) > 4) return false;
    if (dword(definition + 0x80d4) > 6) return false;

    if (dword(definition + 0x80d8) > 4) return false;
    for (long long i = 0; i < signed_dword(definition + 0x80d8); ++i) {
        if (definition[0x80e0 + i] >= 12) return false;
    }

    for (unsigned int offset = 0x81ec; offset <= 0x8204; offset += 4) {
        const long long trigger_index = signed_dword(definition + offset);
        if (trigger_index != -1
            && (trigger_index < 0 || trigger_index >= signed_dword(definition)))
            return false;
    }

    return dword(definition + 0x80e4) <= 16;
}
}
