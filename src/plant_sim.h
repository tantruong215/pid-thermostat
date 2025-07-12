#pragma once

class Plant {
public:
    Plant(double ambient, double tau);
    double read() const;
    void step(double input, double dt);

private:
    double T;       // current temperature
    double ambient; // ambient temperature
    double tau;     // time constant
};
