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
//  class address_v6 {
//  public:
//  ...
//  constexpr bool is_v4_mapped() const noexcept;
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
    static_assert ( noexcept(ip::address_v6().is_v4_mapped()), "" );

    {
    ip::address_v6 addr0;
    ip::address_v6 addr1(ip::address_v6::bytes_type{1,2,3,4,0,0,0,0,0,0,0,0,0,0,0,0});
    ip::address_v6 addr2(ip::address_v6::bytes_type{0,0,0,0,0,0,0,0,0,0,255,255,1,2,3,4});
    assert(!addr0.is_v4_mapped());
    assert(!addr1.is_v4_mapped());
    assert( addr2.is_v4_mapped());
    }
    {
    constexpr ip::address_v6 addr0;
    constexpr ip::address_v6 addr1(ip::address_v6::bytes_type{1,2,3,4,0,0,0,0,0,0,0,0,0,0,0,0});
    constexpr ip::address_v6 addr2(ip::address_v6::bytes_type{0,0,0,0,0,0,0,0,0,0,255,255,1,2,3,4});
    static_assert((!addr0.is_v4_mapped()), "");
    static_assert((!addr1.is_v4_mapped()), "");
    static_assert(( addr2.is_v4_mapped()), "");
    }
}
