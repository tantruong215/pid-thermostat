#include <iostream>
#include <fstream>
#include "pid.h"
#include "plant_sim.h"

int main() {
    const double dt = 0.1;        // time step (s)
    const double target = 50.0;   // desired temperature (°C)
    PID pid(2.0, 0.5, 1.0);       // Kp, Ki, Kd
    Plant plant(20.0, 5.0);       // ambient temp, time constant

    // Open CSV for logging
    std::ofstream csv("response.csv");
    csv << "time,temperature\n";

    // Run 60 seconds of simulation
    for (double t = 0.0; t <= 60.0; t += dt) {
        double measurement = plant.read();
        double u = pid.compute(target, measurement, dt);
        plant.step(u, dt);
        csv << t << ',' << plant.read() << '\n';
    }

    std::cout << "Simulation complete: response.csv generated.\n";
    return 0;
}
