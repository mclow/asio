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
//     struct address_v4::bytes_type : array<unsigned char, 4>
//     {
//       template<class... T> explicit constexpr bytes_type(T... t)
//         : array<unsigned char, 4>{{static_cast<unsigned char>(t)...}} {}
//     };
// }}}} // namespace std::experimental::network_v1::ip
//
// The ip::address_v4::bytes_type type is a standard-layout struct that provides a 
// byte-level representation of an IPv4 address in network byte order.


#include <experimental/internet>

namespace ip = std::experimental::network_v1::ip;

int main()
{
    static_assert((sizeof( ip::address_v4::bytes_type) == 4), "" );
    static_assert((std::is_standard_layout<ip::address_v4::bytes_type>::value), "" );
}
