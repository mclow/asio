// -*- C++ -*-
//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

//
//  enum class resolver_errc {
//    host_not_found = implementation defined, // EAI_NONAME
//    host_not_found_try_again = implementation defined, // EAI_AGAIN
//    service_not_found = implementation defined // EAI_SERVICE
//  };
//

#include <experimental/internet>
#include <type_traits>
#include <cassert>

#include <netdb.h>

namespace ip = std::experimental::network_v1::ip;

int main()
{
    assert(static_cast<int>(ip::resolver_errc::host_not_found)           == EAI_NONAME);
    assert(static_cast<int>(ip::resolver_errc::host_not_found_try_again) == EAI_AGAIN);
    assert(static_cast<int>(ip::resolver_errc::service_not_found)        == EAI_SERVICE);
}
