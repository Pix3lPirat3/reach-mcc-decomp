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
extern void jpeg_fdct_2x1
    (DCTELEM * data, JSAMPARRAY sample_data, JDIMENSION start_col);
void
jpeg_fdct_2x1 (DCTELEM * data, JSAMPARRAY sample_data, JDIMENSION start_col)
{
  INT32 tmp0, tmp1;
  JSAMPROW elemptr;
  memset((void *)(data), 0, (size_t)(((size_t) sizeof(DCTELEM)) * 64));
  elemptr = sample_data[0] + start_col;
  tmp0 = ((int) (elemptr[0]));
  tmp1 = ((int) (elemptr[1]));
  data[0] = (DCTELEM) ((tmp0 + tmp1 - 2 * 128) << 5);
  data[1] = (DCTELEM) ((tmp0 - tmp1) << 5);
}
