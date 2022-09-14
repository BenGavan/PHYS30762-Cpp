//
// Created by Ben Gavan on 14/04/2022.
//

#ifndef PHYS30762_C_MYCLASS_H
#define PHYS30762_C_MYCLASS_H

namespace namespace1 {
    class my_class
    {
    private:
        int x;
    public:
        my_class() : x{} {}
        my_class(int xx) : x{xx} {}
        ~my_class() {}
        void show();
    };
}

#endif //PHYS30762_C_MYCLASS_H
