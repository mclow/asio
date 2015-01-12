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
// 
// template<class T> constexpr T address_cast(const address&);
// template<class T> constexpr T address_cast(const address_v4&);
// template<class T> constexpr T address_cast(const address_v6&);
// }}}} // namespace std::experimental::network_v1::ip
// 


#include <experimental/internet>
#include <type_traits>
#include <cassert>

namespace ip = std::experimental::network_v1::ip;

int main()
{
    static_assert( noexcept(ip::address_cast<ip::address>(ip::address())), "" );
    static_assert( noexcept(ip::address_cast<ip::address>(ip::address_v4())), "" );
    static_assert( noexcept(ip::address_cast<ip::address>(ip::address_v6())), "" );

    static_assert(!noexcept(ip::address_cast<ip::address_v4>(ip::address())), "" );
    static_assert( noexcept(ip::address_cast<ip::address_v4>(ip::address_v4())), "" );
//  static_assert( noexcept(ip::address_cast<ip::address_v4>(ip::address_v6())), "" );

    static_assert(!noexcept(ip::address_cast<ip::address_v6>(ip::address())), "" );
//  static_assert( noexcept(ip::address_cast<ip::address_v6>(ip::address_v4())), "" );
    static_assert( noexcept(ip::address_cast<ip::address_v6>(ip::address_v6())), "" );
}
