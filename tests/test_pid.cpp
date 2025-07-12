#include "pid.h"
#include <cassert>
#include <iostream>

int main() {
    // Test proportional term only
    PID pid_p(1.0, 0.0, 0.0);
    assert(pid_p.compute(10.0, 0.0, 1.0) == 10.0);

    // Test integral accumulation and anti-windup clamp
    PID pid_i(0.0, 1.0, 0.0);
    double dt = 1.0;
    for (int i = 0; i < 200; ++i) {
        pid_i.compute(1.0, 0.0, dt);
    }
    double u_i = pid_i.compute(1.0, 0.0, dt);
    assert(u_i <= 100.0); # integral clamped at +100

    // Test derivative behavior
    PID pid_d(0.0, 0.0, 1.0);
    double first = pid_d.compute(1.0, 0.0, dt);
    double second = pid_d.compute(1.0, 0.0, dt);
    assert(second == 0.0); # no change so derivative zero

    std::cout << "test_pid passed." << std::endl;
    return 0;
}
