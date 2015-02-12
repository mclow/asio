// -*- C++ -*-
//===-------------------------- internet.cpp ------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include <experimental/buffer>

_LIBCPP_BEGIN_NAMESPACE_NETWORK

#if 0
// resolver_category
class _LIBCPP_HIDDEN __stream_error_category
    : public _VSTD::__do_message
{
public:
    virtual const char* name() const _NOEXCEPT;
    virtual _VSTD::string message(int ev) const;
    virtual _VSTD::error_condition default_error_condition(int ev) const _NOEXCEPT;
};

const char*
__stream_error_category::name() const _NOEXCEPT
{
    return "stream";
}

_VSTD::string
__stream_error_category::message(int ev) const
{
    switch (static_cast<stream_errc>(ev)) {
        case stream_errc::eof:       return "eof";
        case stream_errc::not_found: return "not found";
        default:                     return "unknown stream error";
        }
//    return __do_message::message(ev);
}

error_condition
__stream_error_category::default_error_condition(int ev) const _NOEXCEPT
{
    switch (static_cast<stream_errc>(ev)) {
        case stream_errc::eof:
        case stream_errc::not_found:
                 return _VSTD::error_condition(ev, stream_category());
        default: return _VSTD::error_condition(ev, generic_category());
        }
}

const error_category&
stream_category() _NOEXCEPT
{
    static __stream_error_category s;
    return s;
}

#endif
    
_LIBCPP_END_NAMESPACE_NETWORK