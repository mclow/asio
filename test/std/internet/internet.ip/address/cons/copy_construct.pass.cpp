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
//    constexpr address(const address& a) noexcept;
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
    static_assert((std::is_nothrow_copy_constructible<ip::address_v4>::value), "");

    {
    ip::address addr1;
    ip::address addr2 = addr1;
    ip::address addr3(ip::address_v4(123456));
    ip::address addr4 = addr3;
    assert(addr1 == addr2);
    assert(addr1 != addr3);
    assert(addr3 == addr4);
    }
    {
    constexpr ip::address addr1;
    constexpr ip::address addr2 = addr1;
    constexpr ip::address addr3(ip::address_v4(123456));
    constexpr ip::address addr4 = addr3;
    static_assert((addr1 == addr2), "");
    static_assert((addr1 != addr3), "");
    static_assert((addr3 == addr4), "");
    }
}
