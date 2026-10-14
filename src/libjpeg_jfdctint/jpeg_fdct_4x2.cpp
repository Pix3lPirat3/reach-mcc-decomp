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
extern void jpeg_fdct_4x2
    (DCTELEM * data, JSAMPARRAY sample_data, JDIMENSION start_col);
void
jpeg_fdct_4x2 (DCTELEM * data, JSAMPARRAY sample_data, JDIMENSION start_col)
{
  INT32 tmp0, tmp1;
  INT32 tmp10, tmp11;
  DCTELEM *dataptr;
  JSAMPROW elemptr;
  int ctr;
  memset((void *)(data), 0, (size_t)(((size_t) sizeof(DCTELEM)) * 64));
  dataptr = data;
  for (ctr = 0; ctr < 2; ctr++) {
    elemptr = sample_data[ctr] + start_col;
    tmp0 = ((int) (elemptr[0])) + ((int) (elemptr[3]));
    tmp1 = ((int) (elemptr[1])) + ((int) (elemptr[2]));
    tmp10 = ((int) (elemptr[0])) - ((int) (elemptr[3]));
    tmp11 = ((int) (elemptr[1])) - ((int) (elemptr[2]));
    dataptr[0] = (DCTELEM)
      ((tmp0 + tmp1 - 4 * 128) << (2+3));
    dataptr[2] = (DCTELEM) ((tmp0 - tmp1) << (2+3));
    tmp0 = ((tmp10 + tmp11) * (((INT32) 4433)));
    tmp0 += ((INT32) 1) << (13-2-4);
    dataptr[1] = (DCTELEM)
      ((tmp0 + ((tmp10) * (((INT32) 6270)))) >> (13-2-3));
    dataptr[3] = (DCTELEM)
      ((tmp0 - ((tmp11) * (((INT32) 15137)))) >> (13-2-3));
    dataptr += 8;
  }
  dataptr = data;
  for (ctr = 0; ctr < 4; ctr++) {
    tmp0 = dataptr[8*0] + (((INT32) 1) << (2-1));
    tmp1 = dataptr[8*1];
    dataptr[8*0] = (DCTELEM) ((tmp0 + tmp1) >> (2));
    dataptr[8*1] = (DCTELEM) ((tmp0 - tmp1) >> (2));
    dataptr++;
  }
}
