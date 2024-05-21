#include<iostream>
#include <memory>
#include <vector>
#include"unit.h"



 void Unit::add(Unit * , Flags) {
        throw std::runtime_error("Not supported");
    }

    std::string Unit::generateShift(unsigned int level) const {
        static
            const auto DEFAULT_SHIFT = " ";
        std::string result;
        for (unsigned int i = 0; i < level; ++i) {
            result += DEFAULT_SHIFT;
        }
        return result;
    }




