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
// template<address_v4> constexpr address_v4 address_cast(const address_v6&) = delete;
// }}}} // namespace std::experimental::network_v1::ip
// 


#include <experimental/internet>
#include <type_traits>
#include <cassert>

namespace ip = std::experimental::network_v1::ip;

int main()
{
    ip::address_cast<ip::address_v4>(ip::address_v6());
}
