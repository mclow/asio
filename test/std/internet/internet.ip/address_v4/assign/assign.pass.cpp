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
//  address_v4& operator=(const address_v4& a) noexcept;
//  ...
//  };
// 
// }}}} // namespace std::experimental::network_v1::ip
// 
// Postconditions: *this == a
// 
// Returns: *this



#include <experimental/internet>
#include <type_traits>
#include <cassert>

namespace ip = std::experimental::network_v1::ip;

int main()
{
    static_assert((std::is_nothrow_assignable<ip::address_v4&, ip::address_v4&>::value), "" );

    {
    ip::address_v4 addr0;
    ip::address_v4 addr1(ip::address_v4::bytes_type {1,3,5,7});
    ip::address_v4 addr2(ip::address_v4::bytes_type {2,4,6,8});
    assert( addr0 != addr1 );
    assert( addr0 != addr2 );
    assert( addr1 != addr2 );
    addr0 = addr1;
    assert( addr0 == addr1 );
    assert( addr0 != addr2 );
    assert( addr1 != addr2 );
    addr0 = addr2;
    assert( addr0 != addr1 );
    assert( addr0 == addr2 );
    assert( addr1 != addr2 );
    static_assert ((noexcept(addr0 = addr1)), "" );
    }
}
