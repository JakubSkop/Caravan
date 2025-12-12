#include "Caravan_test.hpp"

#include <cassert>
#include <iostream>
#include <vector>

using namespace Caravan;

auto main() -> int
{

    // Test Equality
    static_assert(compareEqual<integrals2, integrals>());
    static_assert(!compareEqual<integrals, constIntegrals>());

    static_assert(contains<integrals, int>());
    static_assert(!contains<integrals, float>());
    static_assert(!contains<empty, void>());

    static_assert(compareEqual<unbundle<bundle<integrals,std::tuple>>, integrals>());
    static_assert(compareEqual<decompose<compose<integrals,std::vector>, std::vector>, integrals>());

    static_assert(compareEqual<Caravan::remove<add<integrals, float>, float>, integrals>());
    static_assert(compareEqual<Caravan::remove<add<integrals, Typelist<float,float>>, float>, integrals>());
    static_assert(compareEqual<subtractOne<add<integrals, float>, float>, integrals>());
    static_assert(!compareEqual<subtractOne<add<integrals, Typelist<float,float>>, float>, integrals>());
    static_assert(subset<integrals, add<integrals, float>>());
    //static_assert(!isSubset<add<integrals, float>, integrals>());
    //static_assert(haveSameTypes<add<integrals, float>, add<float,integrals>>());
    //static_assert(haveSameTypes<add<integrals, Typelist<float,float>>, add<float,integrals>>());


    return 0;
}
