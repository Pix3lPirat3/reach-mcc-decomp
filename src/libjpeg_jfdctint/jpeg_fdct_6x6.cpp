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
extern void jpeg_fdct_6x6
    (DCTELEM * data, JSAMPARRAY sample_data, JDIMENSION start_col);
void
jpeg_fdct_6x6 (DCTELEM * data, JSAMPARRAY sample_data, JDIMENSION start_col)
{
  INT32 tmp0, tmp1, tmp2;
  INT32 tmp10, tmp11, tmp12;
  DCTELEM *dataptr;
  JSAMPROW elemptr;
  int ctr;
  memset((void *)(data), 0, (size_t)(((size_t) sizeof(DCTELEM)) * 64));
  dataptr = data;
  for (ctr = 0; ctr < 6; ctr++) {
    elemptr = sample_data[ctr] + start_col;
    tmp0 = ((int) (elemptr[0])) + ((int) (elemptr[5]));
    tmp11 = ((int) (elemptr[1])) + ((int) (elemptr[4]));
    tmp2 = ((int) (elemptr[2])) + ((int) (elemptr[3]));
    tmp10 = tmp0 + tmp2;
    tmp12 = tmp0 - tmp2;
    tmp0 = ((int) (elemptr[0])) - ((int) (elemptr[5]));
    tmp1 = ((int) (elemptr[1])) - ((int) (elemptr[4]));
    tmp2 = ((int) (elemptr[2])) - ((int) (elemptr[3]));
    dataptr[0] = (DCTELEM)
      ((tmp10 + tmp11 - 6 * 128) << 2);
    dataptr[2] = (DCTELEM)
      (((((tmp12) * (((INT32) ((1.224744871) * (((INT32) 1) << 13) + 0.5))))) + (((INT32) 1) << ((13-2)-1))) >> (13-2));
    dataptr[4] = (DCTELEM)
      (((((tmp10 - tmp11 - tmp11) * (((INT32) ((0.707106781) * (((INT32) 1) << 13) + 0.5))))) + (((INT32) 1) << ((13-2)-1))) >> (13-2));
    tmp10 = (((((tmp0 + tmp2) * (((INT32) ((0.366025404) * (((INT32) 1) << 13) + 0.5))))) + (((INT32) 1) << ((13-2)-1))) >> (13-2));
    dataptr[1] = (DCTELEM) (tmp10 + ((tmp0 + tmp1) << 2));
    dataptr[3] = (DCTELEM) ((tmp0 - tmp1 - tmp2) << 2);
    dataptr[5] = (DCTELEM) (tmp10 + ((tmp2 - tmp1) << 2));
    dataptr += 8;
  }
  dataptr = data;
  for (ctr = 0; ctr < 6; ctr++) {
    tmp0 = dataptr[8*0] + dataptr[8*5];
    tmp11 = dataptr[8*1] + dataptr[8*4];
    tmp2 = dataptr[8*2] + dataptr[8*3];
    tmp10 = tmp0 + tmp2;
    tmp12 = tmp0 - tmp2;
    tmp0 = dataptr[8*0] - dataptr[8*5];
    tmp1 = dataptr[8*1] - dataptr[8*4];
    tmp2 = dataptr[8*2] - dataptr[8*3];
    dataptr[8*0] = (DCTELEM)
      (((((tmp10 + tmp11) * (((INT32) ((1.777777778) * (((INT32) 1) << 13) + 0.5))))) + (((INT32) 1) << ((13+2)-1))) >> (13+2));
    dataptr[8*2] = (DCTELEM)
      (((((tmp12) * (((INT32) ((2.177324216) * (((INT32) 1) << 13) + 0.5))))) + (((INT32) 1) << ((13+2)-1))) >> (13+2));
    dataptr[8*4] = (DCTELEM)
      (((((tmp10 - tmp11 - tmp11) * (((INT32) ((1.257078722) * (((INT32) 1) << 13) + 0.5))))) + (((INT32) 1) << ((13+2)-1))) >> (13+2));
    tmp10 = ((tmp0 + tmp2) * (((INT32) ((0.650711829) * (((INT32) 1) << 13) + 0.5))));
    dataptr[8*1] = (DCTELEM)
      (((tmp10 + ((tmp0 + tmp1) * (((INT32) ((1.777777778) * (((INT32) 1) << 13) + 0.5))))) + (((INT32) 1) << ((13+2)-1))) >> (13+2));
    dataptr[8*3] = (DCTELEM)
      (((((tmp0 - tmp1 - tmp2) * (((INT32) ((1.777777778) * (((INT32) 1) << 13) + 0.5))))) + (((INT32) 1) << ((13+2)-1))) >> (13+2));
    dataptr[8*5] = (DCTELEM)
      (((tmp10 + ((tmp2 - tmp1) * (((INT32) ((1.777777778) * (((INT32) 1) << 13) + 0.5))))) + (((INT32) 1) << ((13+2)-1))) >> (13+2));
    dataptr++;
  }
}
