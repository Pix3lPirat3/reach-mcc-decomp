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
extern void jpeg_fdct_3x3
    (DCTELEM * data, JSAMPARRAY sample_data, JDIMENSION start_col);
void
jpeg_fdct_3x3 (DCTELEM * data, JSAMPARRAY sample_data, JDIMENSION start_col)
{
  INT32 tmp0, tmp1, tmp2;
  DCTELEM *dataptr;
  JSAMPROW elemptr;
  int ctr;
  memset((void *)(data), 0, (size_t)(((size_t) sizeof(DCTELEM)) * 64));
  dataptr = data;
  for (ctr = 0; ctr < 3; ctr++) {
    elemptr = sample_data[ctr] + start_col;
    tmp0 = ((int) (elemptr[0])) + ((int) (elemptr[2]));
    tmp1 = ((int) (elemptr[1]));
    tmp2 = ((int) (elemptr[0])) - ((int) (elemptr[2]));
    dataptr[0] = (DCTELEM)
      ((tmp0 + tmp1 - 3 * 128) << (2+2));
    dataptr[2] = (DCTELEM)
      (((((tmp0 - tmp1 - tmp1) * (((INT32) ((0.707106781) * (((INT32) 1) << 13) + 0.5))))) + (((INT32) 1) << ((13-2-2)-1))) >> (13-2-2));
    dataptr[1] = (DCTELEM)
      (((((tmp2) * (((INT32) ((1.224744871) * (((INT32) 1) << 13) + 0.5))))) + (((INT32) 1) << ((13-2-2)-1))) >> (13-2-2));
    dataptr += 8;
  }
  dataptr = data;
  for (ctr = 0; ctr < 3; ctr++) {
    tmp0 = dataptr[8*0] + dataptr[8*2];
    tmp1 = dataptr[8*1];
    tmp2 = dataptr[8*0] - dataptr[8*2];
    dataptr[8*0] = (DCTELEM)
      (((((tmp0 + tmp1) * (((INT32) ((1.777777778) * (((INT32) 1) << 13) + 0.5))))) + (((INT32) 1) << ((13+2)-1))) >> (13+2));
    dataptr[8*2] = (DCTELEM)
      (((((tmp0 - tmp1 - tmp1) * (((INT32) ((1.257078722) * (((INT32) 1) << 13) + 0.5))))) + (((INT32) 1) << ((13+2)-1))) >> (13+2));
    dataptr[8*1] = (DCTELEM)
      (((((tmp2) * (((INT32) ((2.177324216) * (((INT32) 1) << 13) + 0.5))))) + (((INT32) 1) << ((13+2)-1))) >> (13+2));
    dataptr++;
  }
}
