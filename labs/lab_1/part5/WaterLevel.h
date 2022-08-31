#pragma once

class WaterLevel {
    private:
        double cur;
        double avg;
        double hi;
        double lo;
        int count;
        double sum;

    public:
        WaterLevel();
        double get_cur();
        double get_avg();
        double get_hi();
        double get_lo();
        double get_count();
        void new_data(double current_level);
        void print_stats();
};