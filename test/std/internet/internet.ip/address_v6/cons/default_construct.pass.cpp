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
//    constexpr address_v6() noexcept;
//  ...
//  };
// 
// }}}} // namespace std::experimental::network_v1::ip
// 
//  Postconditions: 
//      is_unspecified() == true
//      scope_id() == 0


#include <experimental/internet>
#include <cassert>

namespace ip = std::experimental::network_v1::ip;

int main()
{
    static_assert((std::is_nothrow_default_constructible<ip::address_v6>::value), "");

    {
    ip::address_v6 addr1;
    assert(addr1.is_unspecified());
    assert(addr1.scope_id() == 0);
    }
    {
    constexpr ip::address_v6 addr1;
    static_assert((addr1.is_unspecified()), "");
    static_assert((addr1.scope_id() == 0), "");
    }
}
