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
//         class bad_address_cast : bad_cast
//         {
//         public:
//           virtual const char* what() const noexcept;
//         };
//
// }}}} // namespace std::experimental::network_v1::ip
// 



#include <experimental/internet>
#include <cassert>

namespace ip = std::experimental::network_v1::ip;

int main()
{
    static_assert ( std::is_base_of<std::bad_cast, ip::bad_address_cast>::value,
                   "std::is_base_of<std::bad_cast, ip::bad_address_cast>::value" );
    static_assert(std::is_polymorphic<std::bad_cast>::value,
                 "std::is_polymorphic<std::bad_cast>::value");
    static_assert ( noexcept(((ip::bad_address_cast *)0)->what()),
                   "noexcept(((ip::bad_address_cast *)0)->what())" );

    ip::bad_address_cast b;
    ip::bad_address_cast b2 = b;
    b2 = b;
    const char* w = b2.what();
    assert(w);
}
