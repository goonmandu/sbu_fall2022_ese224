#include <iostream>
#include "WaterLevel.h"

WaterLevel::WaterLevel() {
    cur = -1;
    avg = -1;
    hi = -1;
    lo = -1;
    count = 0;
    sum = 0;
}

double WaterLevel::get_cur() {
    return cur;
}

double WaterLevel::get_avg() {
    return avg;
}

double WaterLevel::get_hi() {
    return hi;
}

double WaterLevel::get_lo() {
    return lo;
}

double WaterLevel::get_count() {
    return count;
}

void WaterLevel::new_data(double new_lvl) {
    if (!count) {
        hi = new_lvl;
        lo = new_lvl;
    }
    count++;
    cur = new_lvl;
    sum += cur;
    avg = sum / count;
    if (new_lvl > hi) {
        hi = new_lvl;
    } else if (new_lvl < lo) {
        lo = new_lvl;
    }
}

void WaterLevel::print_stats() {
    std::cout << "CUR: " << get_cur() << std::endl;
    std::cout << "AVG: " << get_avg() << std::endl;
    std::cout << "HI:  " << get_hi() << std::endl;
    std::cout << "LO:  " << get_lo() << std::endl << std::endl;
}