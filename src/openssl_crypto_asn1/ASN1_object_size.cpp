int ASN1_object_size(int constructed, int length, int tag);
int ASN1_object_size(int constructed, int length, int tag)
{
    int ret = 1;
    if (length < 0)
        return -1;
    if (tag >= 31) {
        while (tag > 0) {
            tag >>= 7;
            ret++;
        }
    }
    if (constructed == 2) {
        ret += 3;
    } else {
        ret++;
        if (length > 127) {
            int tmplen = length;
            while (tmplen > 0) {
                tmplen >>= 8;
                ret++;
            }
        }
    }
    if (ret >= 2147483647 - length)
        return -1;
    return ret + length;
}
