/*
Copyright (c) 2016-18, Lawrence Livermore National Security, LLC.
Produced at the Lawrence Livermore National Laboratory
Maintained by Tom Scogland <scogland1@llnl.gov>
CODE-756261, All rights reserved.
This file is part of camp.
For details about use and distribution, please read LICENSE and NOTICE from
http://github.com/llnl/camp
*/

#ifndef CAMP_LIST_LIST_HPP
#define CAMP_LIST_LIST_HPP

#include "camp/number.hpp"
#include "camp/size.hpp"

namespace camp
{
// TODO: document

template <typename... Ts>
struct list {
  using type = list;
};

namespace detail
{
  template <typename T>
  struct _as_list;
  template <template <typename...> class T, typename... Args>
  struct _as_list<T<Args...>> {
    using type = list<Args...>;
  };
  template <typename T, T... Args>
  struct _as_list<int_seq<T, Args...>> {
    using type = list<integral_constant<T, Args>...>;
  };
}  // namespace detail

template <typename T>
struct as_list_s : detail::_as_list<T>::type {
};

template <typename T>
using as_list = typename as_list_s<T>::type;

template <typename... Args>
struct size<list<Args...>> {
  constexpr static idx_t value{sizeof...(Args)};
  using type = num<sizeof...(Args)>;
};

}  // namespace camp

#endif /* CAMP_LIST_LIST_HPP */
