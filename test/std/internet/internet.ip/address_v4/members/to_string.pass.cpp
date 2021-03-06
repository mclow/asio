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
//  string to_string() const;
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
    assert ( ip::address_v4().to_string()            == "0.0.0.0" );
    assert ( ip::address_v4(0x0000000A).to_string()  == "0.0.0.10" );
    assert ( ip::address_v4(0x00002300).to_string()  == "0.0.35.0" );
    assert ( ip::address_v4(0x00650003).to_string()  == "0.101.0.3" );
    assert ( ip::address_v4::loopback().to_string()  == "127.0.0.1" );
    assert ( ip::address_v4::broadcast().to_string() == "255.255.255.255" );
}
