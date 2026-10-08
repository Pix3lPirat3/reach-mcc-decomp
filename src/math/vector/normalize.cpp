#include "normalize.hpp"
#include <cstring>
#include <limits>
#ifndef RECON525_ENTRY
#define RECON525_ENTRY vector_helper
#endif
#ifndef RECON525_MUTATION
#define RECON525_MUTATION 0
#endif
namespace hum::recon525 {
namespace {
static_assert(sizeof(float)==4 && sizeof(double)==8 &&
    std::numeric_limits<float>::is_iec559 && std::numeric_limits<double>::is_iec559,
    "IEEE floating point required");
float scalar(std::uint32_t bits) { float out;std::memcpy(&out,&bits,4);return out; }
std::uint32_t bits(float value) {std::uint32_t out;std::memcpy(&out,&value,4);return out;}
float multiply(float a,float b) {volatile float out=a*b;return out;}
float add(float a,float b) {volatile float out=a+b;return out;}
float subtract(float a,float b) {volatile float out=a-b;return out;}
float divide(float a,float b) {volatile float out=a/b;return out;}
float masked_difference(float difference,const std::array<std::uint8_t,16>& mask) {
    const double wide=static_cast<double>(difference);
    std::uint64_t raw;std::memcpy(&raw,&wide,8);
    std::uint64_t low_mask=0;
    for(unsigned i=0;i<8;++i)low_mask|=std::uint64_t(mask[i])<<(8*i);
    raw&=low_mask;
    double altered;std::memcpy(&altered,&raw,8);
    volatile float narrowed=static_cast<float>(altered);return narrowed;
}
}
Continuation RECON525_ENTRY(Memory& m,Dependency& dependency,address module,address vector,Continuation incoming) {
    const float x=scalar(m.read32(vector));
    const float y=scalar(m.read32(vector+4));
    const float xx=multiply(x,x);
    const float yy=multiply(y,y);
    const float z=scalar(m.read32(vector+8));
    const float xy=add(xx,yy);
    const float zz=multiply(z,z);
#if RECON525_MUTATION == 1
    const float squared=xy;
#else
    const float squared=add(xy,zz);
#endif

    auto returned=dependency.call_91a19e(m,{vector,bits(squared),bits(yy),bits(zz)},incoming);
    const float result=scalar(returned.xmm0_low);
    const float difference=subtract(result,scalar(m.read32(module+0xa7a434)));
    const auto mask=m.read128(module+0xa8ce60);
    const float magnitude=masked_difference(difference,mask);
    const float threshold=scalar(m.read32(module+0xa8a9b8));
#if RECON525_MUTATION == 2
    const bool bypass=threshold>=magnitude;
#else
    const bool bypass=threshold>magnitude;
#endif
    if(bypass) {returned.xmm0_low=0;return returned;}
    const float scale=divide(scalar(m.read32(module+0xa8af18)),result);
    const float scaled_x=multiply(x,scale);
    const float scaled_y=multiply(y,scale);
    const float scaled_z=multiply(z,scale);
    m.write32(vector,bits(scaled_x));
    m.write32(vector+4,bits(scaled_y));
#if RECON525_MUTATION == 3
    static_cast<void>(scaled_z);
    m.write32(vector+8,bits(scaled_y));
#else
    m.write32(vector+8,bits(scaled_z));
#endif
    return returned;
}
}
