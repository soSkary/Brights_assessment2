#ifndef RANDOM_FUNCS_HPP
#define RANDOM_FUNCS_HPP

#include <random>

namespace random_funcs
{
    inline std::mt19937 generate()
    {
        //random device to be used in seeding
        std::random_device rd{};

        //create a seed sequence from eight random devices
        std::seed_seq ss{ rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd() };

        //return a seeded twister
        return std::mt19937{ ss };
    }

    //One global seeded mersenne twister object
    inline std::mt19937 mt{ generate() };

    template <typename T>
    inline T get(T min, T max)
    {
        return std::uniform_int_distribution<T>{min, max}(mt);
    }
}

#endif
