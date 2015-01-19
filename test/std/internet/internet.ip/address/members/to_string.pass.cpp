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
//  string to_string() const;
//  ...
//  };
// 
// }}}} // namespace std::experimental::network_v1::ip
// 



#include <experimental/internet>
#include <cassert>

namespace ip = std::experimental::network_v1::ip;

void test_empty ()
{
    ip::address addr;
    try { addr.to_string(); }
    catch ( const ip::bad_address_cast &) { return ; }
    assert(false);
}

int main()
{
    test_empty();
    
    {
    ip::address_v4 v4addr1(ip::address_v4::bytes_type{1,2,3,4});
    ip::address_v4 v4addr2(ip::address_v4::bytes_type{127,0,0,1});
    ip::address addr1{v4addr1};
    ip::address addr2{v4addr2};

    assert( addr1.to_string() == v4addr1.to_string());
    assert( addr2.to_string() == v4addr2.to_string());
    }
    {
    ip::address addr0{ip::address_v6()};
    ip::address_v6 v6addr1(ip::address_v6::bytes_type{1,2,3,4,0,0,0,0,0,0,0,0,0,0,0,0});
    ip::address_v6 v6addr2 = ip::address_v6::loopback();
    ip::address addr1{v6addr1};
    ip::address addr2{v6addr2};

    assert( addr1.to_string() == v6addr1.to_string());
    assert( addr2.to_string() == v6addr2.to_string());
    }
}
