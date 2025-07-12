#include "pid.h"
#include <algorithm>

PID::PID(double kp, double ki, double kd)
    : Kp(kp), Ki(ki), Kd(kd), integral(0), prev_error(0) {}

double PID::compute(double setpoint, double measurement, double dt) {
    double error = setpoint - measurement;
    integral += error * dt;
    double derivative = (error - prev_error) / dt;
    prev_error = error;
    // Anti-windup clamp
    integral = std::clamp(integral, -100.0, 100.0);
    return Kp * error + Ki * integral + Kd * derivative;
}
