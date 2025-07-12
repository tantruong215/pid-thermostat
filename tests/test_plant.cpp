#include "plant_sim.h"
#include <cassert>
#include <iostream>

int main() {
    Plant plant(0.0, 2.0);
    double initial = plant.read();
    // One step with zero input: temperature should remain at ambient
    plant.step(0.0, 1.0);
    assert(plant.read() == initial);

    // Step with positive input: temperature should increase
    plant.step(10.0, 1.0);
    assert(plant.read() > initial);

    std::cout << "test_plant passed." << std::endl;
    return 0;
}
