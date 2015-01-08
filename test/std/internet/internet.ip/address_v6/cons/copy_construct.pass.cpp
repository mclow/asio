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
//    constexpr address_v6(const address_v6& a) noexcept;
//  ...
//  };
// 
// }}}} // namespace std::experimental::network_v1::ip
//
//  Postconditions: *this == a


#include <experimental/internet>
#include <cassert>

namespace ip = std::experimental::network_v1::ip;

int main()
{
    static_assert((std::is_nothrow_copy_constructible<ip::address_v6>::value), "");

    {
    ip::address_v6 addr1;
    ip::address_v6 addr2 = addr1;
    ip::address_v6 addr3(ip::address_v6::bytes_type{0,2,4,6,8,1,3,5,7,9,11,13,17,19,23,29});
    ip::address_v6 addr4 = addr3;
    assert(addr1 == addr2);
    assert(addr1 != addr3);
    assert(addr3 == addr4);
    }
    {
    constexpr ip::address_v6 addr1;
    constexpr ip::address_v6 addr2 = addr1;
    constexpr ip::address_v6 addr3(ip::address_v6::bytes_type{0,2,4,6,8,1,3,5,7,9,11,13,17,19,23,29});
    constexpr ip::address_v6 addr4 = addr3;
    static_assert((addr1 == addr2), "");
    static_assert((addr1 != addr3), "");
    static_assert((addr3 == addr4), "");
    }
}
