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
//  class address {
//  public:
//  ...
//  constexpr bool is_loopback() const noexcept;
//  ...
//  };
// 
// }}}} // namespace std::experimental::network_v1::ip
// 



#include <experimental/internet>
#include <cassert>

namespace ip = std::experimental::network_v1::ip;

int main()
{
    static_assert ( noexcept(ip::address().is_loopback()), "" );

    {
    ip::address addr0;
    assert(!addr0.is_loopback());
    }

    {
    ip::address addr0{ip::address_v4()};
    ip::address_v4 v4addr1(ip::address_v4::bytes_type{1,2,3,4});
    ip::address_v4 v4addr2(ip::address_v4::bytes_type{127,0,0,1});
    ip::address addr1{v4addr1};
    ip::address addr2{v4addr2};
    assert(!addr0.is_loopback());
    assert( addr1.is_loopback() == v4addr1.is_loopback());
    assert( addr2.is_loopback() == v4addr2.is_loopback());
    }
    {
    ip::address addr0{ip::address_v6()};
    ip::address_v6 v6addr1(ip::address_v6::bytes_type{1,2,3,4,0,0,0,0,0,0,0,0,0,0,0,0});
    ip::address_v6 v6addr2 = ip::address_v6::loopback();
    ip::address addr1{v6addr1};
    ip::address addr2{v6addr2};
    assert(!addr0.is_loopback());
    assert( addr1.is_loopback() == v6addr1.is_loopback());
    assert( addr2.is_loopback() == v6addr2.is_loopback());
    }

    {
    constexpr ip::address_v4 addr0;
    constexpr ip::address_v4 v4addr1(ip::address_v4::bytes_type{127,0,0,1});
    constexpr ip::address_v6 v6addr2(ip::address_v6::bytes_type{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0});
    constexpr ip::address addr1{v4addr1};
    constexpr ip::address addr2{v6addr2};
    static_assert(!(addr0.is_loopback()), "");
    static_assert( (addr1.is_loopback()), "");
    static_assert(!(addr2.is_loopback()), "");
    }
}
