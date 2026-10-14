typedef unsigned __int64 size_t;
void* __cdecl memset(
      void*  _Dst,
                               int    _Val,
                               size_t _Size
    );
typedef unsigned char JSAMPLE;
typedef long INT32;
typedef unsigned int JDIMENSION;
typedef JSAMPLE  *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;
typedef int DCTELEM;
extern void jpeg_fdct_7x7
    (DCTELEM * data, JSAMPARRAY sample_data, JDIMENSION start_col);
void
jpeg_fdct_7x7 (DCTELEM * data, JSAMPARRAY sample_data, JDIMENSION start_col)
{
  INT32 tmp0, tmp1, tmp2, tmp3;
  INT32 tmp10, tmp11, tmp12;
  INT32 z1, z2, z3;
  DCTELEM *dataptr;
  JSAMPROW elemptr;
  int ctr;
  memset((void *)(data), 0, (size_t)(((size_t) sizeof(DCTELEM)) * 64));
  dataptr = data;
  for (ctr = 0; ctr < 7; ctr++) {
    elemptr = sample_data[ctr] + start_col;
    tmp0 = ((int) (elemptr[0])) + ((int) (elemptr[6]));
    tmp1 = ((int) (elemptr[1])) + ((int) (elemptr[5]));
    tmp2 = ((int) (elemptr[2])) + ((int) (elemptr[4]));
    tmp3 = ((int) (elemptr[3]));
    tmp10 = ((int) (elemptr[0])) - ((int) (elemptr[6]));
    tmp11 = ((int) (elemptr[1])) - ((int) (elemptr[5]));
    tmp12 = ((int) (elemptr[2])) - ((int) (elemptr[4]));
    z1 = tmp0 + tmp2;
    dataptr[0] = (DCTELEM)
      ((z1 + tmp1 + tmp3 - 7 * 128) << 2);
    tmp3 += tmp3;
    z1 -= tmp3;
    z1 -= tmp3;
    z1 = ((z1) * (((INT32) ((0.353553391) * (((INT32) 1) << 13) + 0.5))));
    z2 = ((tmp0 - tmp2) * (((INT32) ((0.920609002) * (((INT32) 1) << 13) + 0.5))));
    z3 = ((tmp1 - tmp2) * (((INT32) ((0.314692123) * (((INT32) 1) << 13) + 0.5))));
    dataptr[2] = (DCTELEM) (((z1 + z2 + z3) + (((INT32) 1) << ((13-2)-1))) >> (13-2));
    z1 -= z2;
    z2 = ((tmp0 - tmp1) * (((INT32) ((0.881747734) * (((INT32) 1) << 13) + 0.5))));
    dataptr[4] = (DCTELEM)
      (((z2 + z3 - ((tmp1 - tmp3) * (((INT32) ((0.707106781) * (((INT32) 1) << 13) + 0.5))))) + (((INT32) 1) << ((13-2)-1))) >> (13-2));
    dataptr[6] = (DCTELEM) (((z1 + z2) + (((INT32) 1) << ((13-2)-1))) >> (13-2));
    tmp1 = ((tmp10 + tmp11) * (((INT32) ((0.935414347) * (((INT32) 1) << 13) + 0.5))));
    tmp2 = ((tmp10 - tmp11) * (((INT32) ((0.170262339) * (((INT32) 1) << 13) + 0.5))));
    tmp0 = tmp1 - tmp2;
    tmp1 += tmp2;
    tmp2 = ((tmp11 + tmp12) * (- ((INT32) ((1.378756276) * (((INT32) 1) << 13) + 0.5))));
    tmp1 += tmp2;
    tmp3 = ((tmp10 + tmp12) * (((INT32) ((0.613604268) * (((INT32) 1) << 13) + 0.5))));
    tmp0 += tmp3;
    tmp2 += tmp3 + ((tmp12) * (((INT32) ((1.870828693) * (((INT32) 1) << 13) + 0.5))));
    dataptr[1] = (DCTELEM) (((tmp0) + (((INT32) 1) << ((13-2)-1))) >> (13-2));
    dataptr[3] = (DCTELEM) (((tmp1) + (((INT32) 1) << ((13-2)-1))) >> (13-2));
    dataptr[5] = (DCTELEM) (((tmp2) + (((INT32) 1) << ((13-2)-1))) >> (13-2));
    dataptr += 8;
  }
  dataptr = data;
  for (ctr = 0; ctr < 7; ctr++) {
    tmp0 = dataptr[8*0] + dataptr[8*6];
    tmp1 = dataptr[8*1] + dataptr[8*5];
    tmp2 = dataptr[8*2] + dataptr[8*4];
    tmp3 = dataptr[8*3];
    tmp10 = dataptr[8*0] - dataptr[8*6];
    tmp11 = dataptr[8*1] - dataptr[8*5];
    tmp12 = dataptr[8*2] - dataptr[8*4];
    z1 = tmp0 + tmp2;
    dataptr[8*0] = (DCTELEM)
      (((((z1 + tmp1 + tmp3) * (((INT32) ((1.306122449) * (((INT32) 1) << 13) + 0.5))))) + (((INT32) 1) << ((13+2)-1))) >> (13+2));
    tmp3 += tmp3;
    z1 -= tmp3;
    z1 -= tmp3;
    z1 = ((z1) * (((INT32) ((0.461784020) * (((INT32) 1) << 13) + 0.5))));
    z2 = ((tmp0 - tmp2) * (((INT32) ((1.202428084) * (((INT32) 1) << 13) + 0.5))));
    z3 = ((tmp1 - tmp2) * (((INT32) ((0.411026446) * (((INT32) 1) << 13) + 0.5))));
    dataptr[8*2] = (DCTELEM) (((z1 + z2 + z3) + (((INT32) 1) << ((13+2)-1))) >> (13+2));
    z1 -= z2;
    z2 = ((tmp0 - tmp1) * (((INT32) ((1.151670509) * (((INT32) 1) << 13) + 0.5))));
    dataptr[8*4] = (DCTELEM)
      (((z2 + z3 - ((tmp1 - tmp3) * (((INT32) ((0.923568041) * (((INT32) 1) << 13) + 0.5))))) + (((INT32) 1) << ((13+2)-1))) >> (13+2));
    dataptr[8*6] = (DCTELEM) (((z1 + z2) + (((INT32) 1) << ((13+2)-1))) >> (13+2));
    tmp1 = ((tmp10 + tmp11) * (((INT32) ((1.221765677) * (((INT32) 1) << 13) + 0.5))));
    tmp2 = ((tmp10 - tmp11) * (((INT32) ((0.222383464) * (((INT32) 1) << 13) + 0.5))));
    tmp0 = tmp1 - tmp2;
    tmp1 += tmp2;
    tmp2 = ((tmp11 + tmp12) * (- ((INT32) ((1.800824523) * (((INT32) 1) << 13) + 0.5))));
    tmp1 += tmp2;
    tmp3 = ((tmp10 + tmp12) * (((INT32) ((0.801442310) * (((INT32) 1) << 13) + 0.5))));
    tmp0 += tmp3;
    tmp2 += tmp3 + ((tmp12) * (((INT32) ((2.443531355) * (((INT32) 1) << 13) + 0.5))));
    dataptr[8*1] = (DCTELEM) (((tmp0) + (((INT32) 1) << ((13+2)-1))) >> (13+2));
    dataptr[8*3] = (DCTELEM) (((tmp1) + (((INT32) 1) << ((13+2)-1))) >> (13+2));
    dataptr[8*5] = (DCTELEM) (((tmp2) + (((INT32) 1) << ((13+2)-1))) >> (13+2));
    dataptr++;
  }
}
