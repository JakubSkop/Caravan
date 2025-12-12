#pragma once 

#include <Caravan/Caravan.hpp>

using empty = Caravan::Typelist<>;
using integrals = Caravan::Typelist<short, int, long, long long>;
using integrals2 = Caravan::Typelist<short, int, long, long long>;
using constIntegrals = Caravan::Typelist<const short, const int, const long, const long long>;