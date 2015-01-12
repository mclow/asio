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
//  constexpr bool is_loopback() const noexcept;
//  ...
//  };
// 
// }}}} // namespace std::experimental::network_v1::ip
// 
// Returns: (to_ulong() & 0xFF000000) == 0x7F000000.



#include <experimental/internet>
#include <cassert>

namespace ip = std::experimental::network_v1::ip;

constexpr bool test(const ip::address_v4 &addr)
{ return addr.is_loopback() == ((addr.to_ulong() & 0xFF000000) == 0x7F000000); }

int main()
{
    static_assert ( noexcept(ip::address_v4().is_loopback()), "" );

    {
    ip::address_v4 addr0;
    ip::address_v4 addr1(ip::address_v4::bytes_type{1,2,3,4});
    ip::address_v4 addr2 = ip::address_v4::loopback();
    
    assert(test(addr0));
    assert(test(addr1));
    assert(test(addr2));
    }
    {
    constexpr ip::address_v4 addr0;
    constexpr ip::address_v4 addr1(ip::address_v4::bytes_type{1,2,3,4});
    constexpr ip::address_v4 addr2 = ip::address_v4::loopback();
    static_assert((test(addr0)), "" );
    static_assert((test(addr1)), "" );
    static_assert((test(addr2)), "" );
    }
}
