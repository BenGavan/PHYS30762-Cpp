//
// Created by Ben Gavan on 17/04/2022.
//

#ifndef PHYS30762_C_TWO_NUM_H
#define PHYS30762_C_TWO_NUM_H

namespace two_num
{
    template <class T> class pair_of_numbers
    {
    private:
        T x, y;
    public:
        pair_of_numbers() : x{}, y{} {}
        pair_of_numbers(const T x, const T y) : x{x}, y{y} {}
        T add();
        T sub();
    };
}

using namespace two_num;
template<class T> T pair_of_numbers<T>::add() { return x + y; }
template<class T> T pair_of_numbers<T>::sub() { return x - y; }

#endif //PHYS30762_C_TWO_NUM_H
