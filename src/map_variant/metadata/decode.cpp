#include "decode.hpp"
#include "../../bitstream/fixed64/continuation.hpp"

namespace hum::reconstruction::reach::recon2902_r2 {
namespace {

std::uint32_t sign_extend_byte_if_negative(std::uint32_t eax, std::uint8_t sign_test_mask) {
    if ((sign_test_mask & static_cast<std::uint8_t>(eax)) != 0U)
        return eax | 0xffffff00U;
    return eax;
}
}

metadata_decoder_result decode_metadata_103638(metadata_decoder_dependencies& d, address reader, address variant) {
    using recon663::read_fixed64;

    auto r = read_native_bitstream_integer(d, reader, 4U, d);
    d.write8(variant + 0x00, static_cast<std::uint8_t>(static_cast<std::uint8_t>(r.rax_bits) - 1U));

    r = read_native_bitstream_integer(d, reader, 32U, d);
    d.write32(variant + 0x04, static_cast<std::uint32_t>(r.rax_bits));

    auto f = read_fixed64(d, reader, 64U, d);
    d.write64(variant + 0x08, f.rax_bits);
    f = read_fixed64(d, reader, 64U, d);
    d.write64(variant + 0x10, f.rax_bits);
    f = read_fixed64(d, reader, 64U, d);
    d.write64(variant + 0x18, f.rax_bits);
    f = read_fixed64(d, reader, 64U, d);
    d.write64(variant + 0x20, f.rax_bits);

    r = read_native_bitstream_integer(d, reader, 3U, d);
    d.write8(variant + 0x28, static_cast<std::uint8_t>(static_cast<std::uint8_t>(r.rax_bits) - 1U));

    r = read_native_bitstream_integer(d, reader, 3U, d);
    d.write8(variant + 0x29, static_cast<std::uint8_t>(r.rax_bits));

    r = read_native_bitstream_integer(d, reader, 3U, d);
    d.write8(variant + 0x2a, static_cast<std::uint8_t>(r.rax_bits));

    r = read_native_bitstream_integer(d, reader, 32U, d);
    d.write32(variant + 0x2c, static_cast<std::uint32_t>(r.rax_bits));

    r = read_native_bitstream_integer(d, reader, 8U, d);
    (void)sign_extend_byte_if_negative(static_cast<std::uint32_t>(r.rax_bits), 0x80U);
    d.write8(variant + 0x30, static_cast<std::uint8_t>(r.rax_bits));

    auto obj1 = d.call_103968(reader, variant + 0x38);
    (void)obj1;

    auto obj2 = d.call_103968(reader, variant + 0x5c);

    auto span1 = d.call_dc5fc(reader, obj2.rdx_bits, variant + 0x80, 128U);

    auto span2 = d.call_dc5fc(reader, span1.rdx_bits, variant + 0x180, 128U);
    std::uint64_t rdx_bits = span2.rdx_bits;

    const std::uint8_t type_byte = d.read8(variant + 0x00);
    const std::uint8_t type_minus_3 = static_cast<std::uint8_t>(type_byte - 3U);
    if (type_minus_3 <= 1U) {

        r = read_native_bitstream_integer(d, reader, 32U, d);
        rdx_bits = r.rdx_bits;
        d.write32(variant + 0x280, static_cast<std::uint32_t>(r.rax_bits));
    } else if (d.read8(variant + 0x00) == 6U) {

        r = read_native_bitstream_integer(d, reader, 8U, d);
        rdx_bits = r.rdx_bits;
        (void)sign_extend_byte_if_negative(static_cast<std::uint32_t>(r.rax_bits), 0x80U);
        d.write8(variant + 0x280, static_cast<std::uint8_t>(r.rax_bits));
    }

    constexpr std::uint8_t two = 2U;

    if (d.read8(variant + 0x28) == two) {

        r = read_native_bitstream_integer(d, reader, 16U, d);
        rdx_bits = r.rdx_bits;
        d.write16(variant + 0x290, static_cast<std::uint16_t>(r.rax_bits));
    }

    const std::uint8_t byte29 = d.read8(variant + 0x29);
    if (byte29 == 1U) {

        r = read_native_bitstream_integer(d, reader, 8U, d);
        rdx_bits = r.rdx_bits;
        d.write8(variant + 0x2a0, static_cast<std::uint8_t>(r.rax_bits));

        r = read_native_bitstream_integer(d, reader, 2U, d);
        rdx_bits = r.rdx_bits;
        d.write8(variant + 0x2a1, static_cast<std::uint8_t>(r.rax_bits));

        r = read_native_bitstream_integer(d, reader, 2U, d);
        rdx_bits = r.rdx_bits;
        d.write8(variant + 0x2a2, static_cast<std::uint8_t>(r.rax_bits));

        r = read_native_bitstream_integer(d, reader, 8U, d);
        rdx_bits = r.rdx_bits;
        d.write8(variant + 0x2a3, static_cast<std::uint8_t>(r.rax_bits));

        r = read_native_bitstream_integer(d, reader, 32U, d);
        rdx_bits = r.rdx_bits;
        d.write32(variant + 0x2a4, static_cast<std::uint32_t>(r.rax_bits));
    } else if (byte29 == two) {

        r = read_native_bitstream_integer(d, reader, 2U, d);
        rdx_bits = r.rdx_bits;
        d.write8(variant + 0x2a0, static_cast<std::uint8_t>(r.rax_bits));
        r = read_native_bitstream_integer(d, reader, 32U, d);
        rdx_bits = r.rdx_bits;
        d.write32(variant + 0x2a4, static_cast<std::uint32_t>(r.rax_bits));
    }

    return {rdx_bits};
}
}
