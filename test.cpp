#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>

typedef struct TwoInts {
    int i1;
    int i2;
} TwoInts;

class Test {
    private:
        std::vector<TwoInts> twodeeintvec;
    
    public:
        Test() {
            for (int i = 0; i < 10; i++) {
                twodeeintvec.push_back({i, i*i});
            }
        }
        void change_index(int idx, int val) {
            twodeeintvec[idx].i1 = val;
            twodeeintvec[idx].i2 = val * val;
        }
        void change_index_by_ptr(int idx, int val) {
            TwoInts *tiptr = &twodeeintvec[idx];
            tiptr->i1 = val;
            tiptr->i2 = val * val;
        }
        void print_vector() {
            for (TwoInts item : twodeeintvec) {
                std::cout << item.i1 << ", " << item.i2 << " | ";
            }
            std::cout << std::endl;
        }

};

int main() {
    /*
    Test t = Test();
    t.change_index(2, -11);
    t.change_index_by_ptr(3, 69);
    t.print_vector();
    int last_event = 0;
     */
    while (1) {
        auto start = std::chrono::steady_clock::now();
        getchar();
        auto end = std::chrono::steady_clock::now();
        int milliseconds_passed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        std::cout << milliseconds_passed << std::endl;
    }
}