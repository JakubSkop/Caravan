#include "Caravan_test.hpp"

#include <cassert>
#include <iostream>
#include <vector>

using namespace Caravan;

auto main() -> int
{

    // Test Equality
    static_assert(areIdentical<integrals2, integrals>());
    static_assert(!areIdentical<integrals, constIntegrals>());

    static_assert(contains<integrals, int>());
    static_assert(!contains<integrals, float>());
    static_assert(!contains<empty, void>());

    static_assert(areIdentical<unbundle<bundle<integrals,std::tuple>>, integrals>());
    static_assert(areIdentical<decompose<compose<integrals,std::vector>, std::vector>, integrals>());

    static_assert(areIdentical<Caravan::remove<add<integrals, float>, float>, integrals>());
    static_assert(areIdentical<Caravan::remove<add<integrals, Typelist<float,float>>, float>, integrals>());

    static_assert(areIdentical<subtractOne<add<integrals, float>, float>, integrals>());
    static_assert(!areIdentical<subtractOne<add<integrals, Typelist<float,float>>, float>, integrals>());

    static_assert(isSubset<integrals, add<integrals, float>>());
    static_assert(!isSubset<add<integrals, float>, integrals>());
    static_assert(isSubset<empty, empty>());
    
    static_assert(!areIdentical<add<integrals, float>, add<float,integrals>>());
    static_assert(areEqual<add<integrals, float>, add<float,integrals>>());


    return 0;
}
