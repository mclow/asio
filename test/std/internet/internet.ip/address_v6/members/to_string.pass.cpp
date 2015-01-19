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
//  string to_string() const;
//  ...
//  };
// 
// }}}} // namespace std::experimental::network_v1::ip
// 



#include <experimental/internet>
#include <cassert>

namespace ip = std::experimental::network_v1::ip;

//  TODO - implement zero folding
int main()
{
    assert ( ip::address_v6().to_string()            == "00:00:00:00:00:00:00:00:00:00:00:00:00:00:00:00" );
    assert ( ip::address_v6::loopback().to_string()  == "00:00:00:00:00:00:00:00:00:00:00:00:00:00:00:01" );
}
