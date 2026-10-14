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
extern void jpeg_fdct_8x4
    (DCTELEM * data, JSAMPARRAY sample_data, JDIMENSION start_col);
void
jpeg_fdct_8x4 (DCTELEM * data, JSAMPARRAY sample_data, JDIMENSION start_col)
{
  INT32 tmp0, tmp1, tmp2, tmp3;
  INT32 tmp10, tmp11, tmp12, tmp13;
  INT32 z1;
  DCTELEM *dataptr;
  JSAMPROW elemptr;
  int ctr;
  memset((void *)(&data[8*4]), 0, (size_t)(((size_t) sizeof(DCTELEM)) * 8 * 4));
  dataptr = data;
  for (ctr = 0; ctr < 4; ctr++) {
    elemptr = sample_data[ctr] + start_col;
    tmp0 = ((int) (elemptr[0])) + ((int) (elemptr[7]));
    tmp1 = ((int) (elemptr[1])) + ((int) (elemptr[6]));
    tmp2 = ((int) (elemptr[2])) + ((int) (elemptr[5]));
    tmp3 = ((int) (elemptr[3])) + ((int) (elemptr[4]));
    tmp10 = tmp0 + tmp3;
    tmp12 = tmp0 - tmp3;
    tmp11 = tmp1 + tmp2;
    tmp13 = tmp1 - tmp2;
    tmp0 = ((int) (elemptr[0])) - ((int) (elemptr[7]));
    tmp1 = ((int) (elemptr[1])) - ((int) (elemptr[6]));
    tmp2 = ((int) (elemptr[2])) - ((int) (elemptr[5]));
    tmp3 = ((int) (elemptr[3])) - ((int) (elemptr[4]));
    dataptr[0] = (DCTELEM)
      ((tmp10 + tmp11 - 8 * 128) << (2+1));
    dataptr[4] = (DCTELEM) ((tmp10 - tmp11) << (2+1));
    z1 = ((tmp12 + tmp13) * (((INT32) 4433)));
    z1 += ((INT32) 1) << (13-2-2);
    dataptr[2] = (DCTELEM) ((z1 + ((tmp12) * (((INT32) 6270)))) >> (13-2-1));
    dataptr[6] = (DCTELEM) ((z1 - ((tmp13) * (((INT32) 15137)))) >> (13-2-1));
    tmp10 = tmp0 + tmp3;
    tmp11 = tmp1 + tmp2;
    tmp12 = tmp0 + tmp2;
    tmp13 = tmp1 + tmp3;
    z1 = ((tmp12 + tmp13) * (((INT32) 9633)));
    z1 += ((INT32) 1) << (13-2-2);
    tmp0  = ((tmp0) * (((INT32) 12299)));
    tmp1  = ((tmp1) * (((INT32) 25172)));
    tmp2  = ((tmp2) * (((INT32) 16819)));
    tmp3  = ((tmp3) * (((INT32) 2446)));
    tmp10 = ((tmp10) * (- ((INT32) 7373)));
    tmp11 = ((tmp11) * (- ((INT32) 20995)));
    tmp12 = ((tmp12) * (- ((INT32) 3196)));
    tmp13 = ((tmp13) * (- ((INT32) 16069)));
    tmp12 += z1;
    tmp13 += z1;
    dataptr[1] = (DCTELEM)
      ((tmp0 + tmp10 + tmp12) >> (13-2-1));
    dataptr[3] = (DCTELEM)
      ((tmp1 + tmp11 + tmp13) >> (13-2-1));
    dataptr[5] = (DCTELEM)
      ((tmp2 + tmp11 + tmp12) >> (13-2-1));
    dataptr[7] = (DCTELEM)
      ((tmp3 + tmp10 + tmp13) >> (13-2-1));
    dataptr += 8;
  }
  dataptr = data;
  for (ctr = 8-1; ctr >= 0; ctr--) {
    tmp0 = dataptr[8*0] + dataptr[8*3] + (((INT32) 1) << (2-1));
    tmp1 = dataptr[8*1] + dataptr[8*2];
    tmp10 = dataptr[8*0] - dataptr[8*3];
    tmp11 = dataptr[8*1] - dataptr[8*2];
    dataptr[8*0] = (DCTELEM) ((tmp0 + tmp1) >> (2));
    dataptr[8*2] = (DCTELEM) ((tmp0 - tmp1) >> (2));
    tmp0 = ((tmp10 + tmp11) * (((INT32) 4433)));
    tmp0 += ((INT32) 1) << (13+2-1);
    dataptr[8*1] = (DCTELEM)
      ((tmp0 + ((tmp10) * (((INT32) 6270)))) >> (13+2));
    dataptr[8*3] = (DCTELEM)
      ((tmp0 - ((tmp11) * (((INT32) 15137)))) >> (13+2));
    dataptr++;
  }
}
