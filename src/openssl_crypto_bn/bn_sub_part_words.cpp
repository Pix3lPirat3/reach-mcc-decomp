unsigned long long bn_sub_words(unsigned long long *rp, const unsigned long long *ap, const unsigned long long *bp,
                      int num);
unsigned long long bn_sub_part_words(unsigned long long *r, const unsigned long long *a, const unsigned long long *b,
                           int cl, int dl);
unsigned long long bn_sub_part_words(unsigned long long *r,
                           const unsigned long long *a, const unsigned long long *b,
                           int cl, int dl)
{
    unsigned long long c, t;
    ((void)0);
    c = bn_sub_words(r, a, b, cl);
    if (dl == 0)
        return c;
    r += cl;
    a += cl;
    b += cl;
    if (dl < 0) {
        for (;;) {
            t = b[0];
            r[0] = (0 - t - c) & (0xffffffffffffffffLL);
            if (t != 0)
                c = 1;
            if (++dl >= 0)
                break;
            t = b[1];
            r[1] = (0 - t - c) & (0xffffffffffffffffLL);
            if (t != 0)
                c = 1;
            if (++dl >= 0)
                break;
            t = b[2];
            r[2] = (0 - t - c) & (0xffffffffffffffffLL);
            if (t != 0)
                c = 1;
            if (++dl >= 0)
                break;
            t = b[3];
            r[3] = (0 - t - c) & (0xffffffffffffffffLL);
            if (t != 0)
                c = 1;
            if (++dl >= 0)
                break;
            b += 4;
            r += 4;
        }
    } else {
        int save_dl = dl;
        while (c) {
            t = a[0];
            r[0] = (t - c) & (0xffffffffffffffffLL);
            if (t != 0)
                c = 0;
            if (--dl <= 0)
                break;
            t = a[1];
            r[1] = (t - c) & (0xffffffffffffffffLL);
            if (t != 0)
                c = 0;
            if (--dl <= 0)
                break;
            t = a[2];
            r[2] = (t - c) & (0xffffffffffffffffLL);
            if (t != 0)
                c = 0;
            if (--dl <= 0)
                break;
            t = a[3];
            r[3] = (t - c) & (0xffffffffffffffffLL);
            if (t != 0)
                c = 0;
            if (--dl <= 0)
                break;
            save_dl = dl;
            a += 4;
            r += 4;
        }
        if (dl > 0) {
            if (save_dl > dl) {
                switch (save_dl - dl) {
                case 1:
                    r[1] = a[1];
                    if (--dl <= 0)
                        break;
                case 2:
                    r[2] = a[2];
                    if (--dl <= 0)
                        break;
                case 3:
                    r[3] = a[3];
                    if (--dl <= 0)
                        break;
                }
                a += 4;
                r += 4;
            }
        }
        if (dl > 0) {
            for (;;) {
                r[0] = a[0];
                if (--dl <= 0)
                    break;
                r[1] = a[1];
                if (--dl <= 0)
                    break;
                r[2] = a[2];
                if (--dl <= 0)
                    break;
                r[3] = a[3];
                if (--dl <= 0)
                    break;
                a += 4;
                r += 4;
            }
        }
    }
    return c;
}
