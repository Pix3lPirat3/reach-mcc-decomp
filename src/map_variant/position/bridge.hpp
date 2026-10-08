#pragma once

#include "../placements/active_position.hpp"
#include "reduced.hpp"
#include <array>
#include <cstdint>
namespace hum::reconstruction::reach::position_bridge {
using address=std::uint64_t;

struct adapter_domain_violation {};

struct private_observer {
    virtual ~private_observer()=default;
    virtual void accessed(bool write,address at,unsigned size,std::uint64_t value)=0;
};

struct model_inputs {
    std::uint32_t width_scale_bits,width_threshold_bits,interpolation_half_bits;
    std::uint64_t cookie_bits;
};
struct profile {
    address module,frame;
    model_inputs inputs;
    private_observer* observer;
};

class private_memory final:public position_reduced::memory {
public:
    private_memory(position_reduced::memory& arena,const profile& p,address bounds,std::uint8_t stack5);
    std::uint8_t read8(address at) override;
    std::uint16_t read16(address at) override;
    std::uint32_t read32(address at) override;
    std::uint64_t read64(address at) override;
    void write8(address at,std::uint8_t value) override;
    void write32(address at,std::uint32_t value) override;
    void write64(address at,std::uint64_t value) override;
private:
    enum class region { arena, frame, constant };
    struct access { region where; std::uint64_t datum; };
    access classify(address at,unsigned size,bool write) const;
    std::uint64_t read(address at,unsigned size);
    void write(address at,unsigned size,std::uint64_t value);
    position_reduced::memory& arena_;
    address frame_base_,module_;
    model_inputs inputs_;
    private_observer* observer_;
    std::array<std::uint8_t,0xc0> bytes_{};
    std::array<bool,0xc0> defined_{};
};

class adapter final:public modern_position_boundary {
public:
    adapter(position_reduced::memory& arena,const profile& p):arena_(arena),profile_(p) {}
    position_child_result call_position_3c6884(map_decoder_address reader,map_decoder_address position,
        std::uint32_t width,std::uint32_t repair,std::uint8_t stack5_low_byte,
        map_decoder_address bounds) override;
private:
    position_reduced::memory& arena_;
    profile profile_;
};
}
