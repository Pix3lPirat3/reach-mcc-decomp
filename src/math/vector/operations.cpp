#include "operations.hpp"
#include <cstring>
#ifndef RECON529_MUTATION
#define RECON529_MUTATION 0
#endif
#ifndef RECON529_DIRECTION
#define RECON529_DIRECTION direction
#endif
#ifndef RECON529_BASIS
#define RECON529_BASIS basis
#endif
namespace hum::recon529 {
namespace {
float f(std::uint32_t v){float x;std::memcpy(&x,&v,4);return x;}
std::uint32_t b(float x){std::uint32_t v;std::memcpy(&v,&x,4);return v;}
std::int32_t s(std::uint32_t v){std::int32_t x;std::memcpy(&x,&v,4);return x;}
float mul(float a,float c){volatile float x=a*c;return x;}
float add(float a,float c){volatile float x=a+c;return x;}
float sub(float a,float c){volatile float x=a-c;return x;}
float div(float a,float c){volatile float x=a/c;return x;}
float cvt(std::int32_t a){volatile float x=static_cast<float>(a);return x;}
float mask(float a,const std::array<std::uint8_t,16>& bytes){
    double x=static_cast<double>(a);std::uint64_t v;std::memcpy(&v,&x,8);
    std::uint64_t m=0;for(unsigned i=0;i<8;++i)m|=std::uint64_t(bytes[i])<<(8*i);
    v&=m;std::memcpy(&x,&v,8);volatile float out=static_cast<float>(x);return out;
}
}
Continuation RECON529_DIRECTION(Memory& m,Dependency& d,address module,std::int32_t index,
                                address out,std::int32_t selector,Continuation incoming){
    const float numerator=f(m.read32(module+0xa8b140));
    const float offset=f(m.read32(module+0xa8af18));
    const address table=module+0xb9b6f0+static_cast<address>(static_cast<std::int64_t>(selector))*8;
    const auto divisor=s(m.read32(table-0x30));
    const auto face=index/divisor;
    const auto remainder=index%divisor;
    const auto grid=s(m.read32(table-0x2c));
    const auto row=remainder/grid, column=remainder%grid;
    const float step=div(numerator,cvt(grid-1));
    float y=mul(cvt(row),step);
    const float half=mul(step,f(m.read32(module+0xa8ad74)));
    y=add(sub(y,offset),half);
#if RECON529_MUTATION != 1
    if(static_cast<std::uint32_t>(row)*2U==static_cast<std::uint32_t>(grid)-2U)y=0;
#endif
    float x=add(sub(mul(cvt(column),step),offset),half);
#if RECON529_MUTATION != 1
    if(static_cast<std::uint32_t>(column)*2U==static_cast<std::uint32_t>(grid)-2U)x=0;
#endif

    if(face<0 || face>5){const auto pair=m.read64(module+0x98fa8c);m.write64(out,pair);
        const auto z=m.read32(module+0x98fa94);m.write32(out+8,z);
    }else{
        if(face==0 || face==3)m.write32(out,face==0?0x3f800000U:0xbf800000U);
        else m.write32(out,b(y));
        if(face==1 || face==4)m.write32(out+4,face==1?0x3f800000U:0xbf800000U);
        else m.write32(out+4,b(face==0 || face==3?y:x));
        m.write32(out+8,face==2?0x3f800000U:face==5?0xbf800000U:b(x));
    }
    return hum::recon525::vector_helper(m,d,module,out,incoming);
}
Continuation RECON529_BASIS(Memory& m,Dependency& d,address module,address input,
                            address first,address second,Continuation incoming){
    float xzero=mul(f(m.read32(input)),0.0f);
    float z=f(m.read32(input+8));
    float yzero=mul(f(m.read32(input+4)),0.0f);
    const float sumy=add(xzero,f(m.read32(input+4)));
    float zzero=mul(z,0.0f);
    const float sumx=add(yzero,f(m.read32(input)));
    const float ax=mask(add(sumx,zzero),m.read128(module+0xa8ce60));
    const float ay=mask(add(sumy,zzero),m.read128(module+0xa8ce60));
    bool choose=ay>ax;
#if RECON529_MUTATION == 2
    choose=!choose;
#endif
    float third;
    if(choose){third=sub(xzero,f(m.read32(input+4)));yzero=sub(yzero,zzero);xzero=sub(z,xzero);}
    else{third=sub(yzero,f(m.read32(input)));xzero=sub(xzero,zzero);yzero=sub(z,yzero);}
    m.write32(first,b(yzero));m.write32(first+4,b(xzero));m.write32(first+8,b(third));
    incoming=hum::recon525::vector_helper(m,d,module,first,incoming);
    const float iz=f(m.read32(input+8)), fz=f(m.read32(first+8));
    const float fy=f(m.read32(first+4)), iy=f(m.read32(input+4));
    const float ix=f(m.read32(input)), fx=f(m.read32(first));
    const float product0=mul(iz,fy),product1=mul(fz,iy);
    const float product2=mul(fy,ix),product3=mul(iy,fx);
    const float crossx=sub(product1,product0);
    const float product4=mul(iz,fx),product5=mul(fz,ix);
    const float crossz=sub(product2,product3);
    m.write32(second,b(crossx));
    const float crossy=sub(product4,product5);
#if RECON529_MUTATION == 3
    m.write32(second+4,b(crossy));m.write32(second+8,b(crossz));
#else
    m.write32(second+8,b(crossz));m.write32(second+4,b(crossy));
#endif
    return hum::recon525::vector_helper(m,d,module,second,incoming);
}
}
