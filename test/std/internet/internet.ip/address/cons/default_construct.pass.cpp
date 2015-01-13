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
//    constexpr address() noexcept;
//  ...
//  };
// 
// }}}} // namespace std::experimental::network_v1::ip

#include <experimental/internet>
#include <cassert>

namespace ip = std::experimental::network_v1::ip;

int main()
{
    static_assert((std::is_nothrow_default_constructible<ip::address>::value), "");
	
    {
    ip::address addr1;
    assert(!addr1.is_v4());
    assert(!addr1.is_v6());
    }
    {
    constexpr ip::address addr1;
    static_assert((!addr1.is_v4()), "");
    static_assert((!addr1.is_v6()), "");
    }
}
