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
//    template<class InternetProtocol>
//    class basic_resolver_entry
//
// }}}} // namespace std::experimental::network_v1::ip
// 



#include <experimental/internet>
#include <cassert>
#include <netdb.h>

namespace ip = std::experimental::network_v1::ip;

int main()
{
    static_assert(false, "Need to implement a protocol first" );
}
