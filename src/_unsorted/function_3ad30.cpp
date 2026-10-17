extern "C" int function_3ad30(int value) {
    if (value == 20) {
        return (value + 28);
    }
    if (value <= 19) {
        if (value == 19) {
            return 19;
        } else if (value <= 9) {
            if (value == 9) {
                return 9;
            }
            switch ( value ) { case 0: return 0; case 1: return 1; case 2: return 2; case 3: return 3; case 4: return 4; case 5: return 5; case 6: return 6; case 7: return 7; case 8: return value; default: return -1; }
        } else {
            switch ( value ) { case 0xA: return 0xA; case 0xB: return 0xB; case 0xC: return 0xC; case 0xD: return 0xD; case 0xE: return 0xE; case 0xF: return 0xF; case 0x10: return 0x10; case 0x11: return 0x11; case 0x12: return value; default: return -1; }
        }
    } else if (value <= 29) {
        if (value == 29) {
            return 29;
        }
        switch ( value ) { case 0x14: return 0x14; case 0x15: return 0x15; case 0x16: return 0x16; case 0x17: return 0x17; case 0x18: return 0x18; case 0x19: return 0x19; case 0x1A: return 0x1A; case 0x1B: return 0x1B; case 0x1C: return value; default: return -1; }
    } else {
        switch ( value ) { case 0x1E: return 0x1E; case 0x1F: return 0x1F; case 0x20: return 0x20; case 0x21: return 0x21; case 0x22: return 0x22; case 0x23: return 0x2D; case 0x24: return 0x2E; case 0x25: return 0x2F; case 0x26: return 0x31; default: return -1; }
    }
}
