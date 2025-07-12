#pragma once

class PID {
public:
    PID(double kp, double ki, double kd);
    double compute(double setpoint, double measurement, double dt);

private:
    double Kp;
    double Ki;
    double Kd;
    double integral;
    double prev_error;
};
