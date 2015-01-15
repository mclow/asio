// -*- C++ -*-
//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// namespace std {  namespace experimental { inline namespace network_v1 {  namespace ip {
//   constexpr address_v4 make_address_v4(unsigned long val);
// }}}} // namespace std::experimental::network_v1::ip
// 
// Returns: address_v4(val)



#include <experimental/internet>
#include <cassert>

namespace ip = std::experimental::network_v1::ip;

int main()
{
//     static_assert ( noexcept(ip::address_v4::any()), "" );

    {
    ip::address_v4 addr0 = ip::make_address_v4(0UL);
    ip::address_v4 addr1 = ip::make_address_v4(1234);
    ip::address_v4 addr2 = ip::make_address_v4(0x12345678);
    assert( (addr0 == ip::address_v4(0)));
    assert( (addr1 == ip::address_v4(1234)));
    assert( (addr2 == ip::address_v4(0x12345678)));
    }
    {
    constexpr ip::address_v4 addr0 = ip::make_address_v4(0UL);
    constexpr ip::address_v4 addr1 = ip::make_address_v4(1234);
    constexpr ip::address_v4 addr2 = ip::make_address_v4(0x12345678);
    static_assert( (addr0 == ip::address_v4(0)), "");
    static_assert( (addr1 == ip::address_v4(1234)), "");
    static_assert( (addr2 == ip::address_v4(0x12345678)), "");
    }
}
