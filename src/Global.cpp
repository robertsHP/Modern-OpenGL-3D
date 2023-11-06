#include "Global.h"

#include <random>

namespace Func {
    int randRanged (int start, int end) {
        static std::random_device rd; // obtain a random number from hardware
        static std::mt19937 gen(rd()); // seed the generator
        static std::uniform_int_distribution<int> distr(start, end); // define the range
        return distr(gen);
    }
    template<typename Base, typename T>
    inline bool instanceOf(const T&) {
        return std::is_same<Base, T>::value;
    }
}
