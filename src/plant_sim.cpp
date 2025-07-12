#include \"plant_sim.h\"

Plant::Plant(double ambient_, double tau_)
    : T(ambient_), ambient(ambient_), tau(tau_) {}

double Plant::read() const {
    return T;
}

void Plant::step(double input, double dt) {
    // first-order response: dT/dt = (input - (T - ambient)) / tau
    double dT = (input - (T - ambient)) / tau;
    T += dT * dt;
}
