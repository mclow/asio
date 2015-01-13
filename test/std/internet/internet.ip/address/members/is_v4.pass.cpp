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
//  constexpr bool is_v4() const noexcept;
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
    static_assert ( noexcept(ip::address().is_v4()), "" );

    {
    ip::address addr0;
    assert(!addr0.is_v4());
    }
    
    {
    ip::address addr0{ip::address_v4()};
    ip::address_v4 v4addr1(ip::address_v4::bytes_type{240,2,3,4});
    ip::address_v4 v4addr2(ip::address_v4::bytes_type{0,0,1,0});
    ip::address addr1{v4addr1};
    ip::address addr2{v4addr2};
    assert( addr0.is_v4());
    assert( addr1.is_v4());
    assert( addr2.is_v4());
    }
    {
    ip::address addr0{ip::address_v6()};
    ip::address_v6 v6addr1(ip::address_v6::bytes_type{1,2,3,4,0,0,0,0,0,0,0,0,0,0,0,0});
    ip::address_v6 v6addr2(ip::address_v6::bytes_type{255,0,3,0,5,0,7,0,9,0,0,0,0,0,0,0});
    ip::address addr1{v6addr1};
    ip::address addr2{v6addr2};
    assert(!addr0.is_v4());
    assert(!addr1.is_v4());
    assert(!addr2.is_v4());
    }

    {
    constexpr ip::address_v4 v4addr1(ip::address_v4::bytes_type{1,2,3,4});
    constexpr ip::address_v6 v6addr2(ip::address_v6::bytes_type{255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0});
    constexpr ip::address addr1{v4addr1};
    constexpr ip::address addr2{v6addr2};
    static_assert( (addr1.is_v4()), "");
    static_assert(!(addr2.is_v4()), "");
    }
}
