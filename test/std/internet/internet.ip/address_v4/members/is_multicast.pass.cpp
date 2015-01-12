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
//  class address_v4 {
//  public:
//  ...
//  constexpr bool is_multicast() const noexcept;
//  ...
//  };
// 
// }}}} // namespace std::experimental::network_v1::ip
// 
// Returns: (to_ulong() & 0xC0000000) == 0x80000000.



#include <experimental/internet>
#include <cassert>

namespace ip = std::experimental::network_v1::ip;

constexpr bool test(const ip::address_v4 &addr)
{ return addr.is_multicast() == ((addr.to_ulong() & 0xF0000000) == 0xE0000000); }

int main()
{
    static_assert ( noexcept(ip::address_v4().is_multicast()), "" );

    {
    ip::address_v4 addr0;
    ip::address_v4 addr1(ip::address_v4::bytes_type{1,2,3,4});
    ip::address_v4 addr2(ip::address_v4::bytes_type{0xE2,1,2,3});
    ip::address_v4 addr3(ip::address_v4::bytes_type{0xC0,1,2,3});
    assert(test(addr0));
    assert(test(addr1));
    assert(test(addr2));
    assert(test(addr3));
    }
    {
    constexpr ip::address_v4 addr0;
    constexpr ip::address_v4 addr1(ip::address_v4::bytes_type{1,2,3,4});
    constexpr ip::address_v4 addr2(ip::address_v4::bytes_type{0xE2,1,2,3});
    constexpr ip::address_v4 addr3(ip::address_v4::bytes_type{0xC0,1,2,3});
    static_assert((test(addr0)), "");
    static_assert((test(addr1)), "" );
    static_assert((test(addr2)), "" );
    static_assert((test(addr3)), "" );
    }
}
