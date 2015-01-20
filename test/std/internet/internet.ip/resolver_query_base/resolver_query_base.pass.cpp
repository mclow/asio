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
//         class resolver_query_base
//
// }}}} // namespace std::experimental::network_v1::ip
// 



#include <experimental/internet>
#include <cassert>
#include <netdb.h>

namespace ip = std::experimental::network_v1::ip;

int main()
{
    static_assert ( std::is_same<decltype(ip::resolver_query_base::flags() & ip::resolver_query_base::flags()), ip::resolver_query_base::flags>::value,
                   "ip::resolver_query_base::flags can be and-ed" );
    static_assert ( std::is_same<decltype(ip::resolver_query_base::flags() | ip::resolver_query_base::flags()), ip::resolver_query_base::flags>::value,
                   "ip::resolver_query_base::flags can be or-ed" );

//  Did we get the flag values right?
//  This will probably need to change on non-POSIC systems.
    assert(ip::resolver_query_base::passive            == AI_PASSIVE);
    assert(ip::resolver_query_base::canonical_name     == AI_CANONNAME);
    assert(ip::resolver_query_base::numeric_host       == AI_NUMERICHOST);
    assert(ip::resolver_query_base::numeric_service    == AI_NUMERICSERV);
    assert(ip::resolver_query_base::v4_mapped          == AI_V4MAPPED);
    assert(ip::resolver_query_base::all_matching       == AI_ALL);
    assert(ip::resolver_query_base::address_configured == AI_ADDRCONFIG);
}
