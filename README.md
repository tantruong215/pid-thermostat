# pid-thermostat

A lightweight C++ simulation of a PID-controlled thermostat with a first-order thermal plant model, CSV logging of the step response, and unit tests.

## Project Structure

```
pid-thermostat/
├── .github/workflows/        # CI workflows (if configured)
├── src/                      # PID controller, plant model, main simulation
│   ├── pid.h
│   ├── pid.cpp
│   ├── plant_sim.h
│   ├── plant_sim.cpp
│   └── main.cpp
├── tests/                    # Unit tests
│   ├── test_pid.cpp
│   └── test_plant_sim.cpp
├── tools/                    # Plotting helper script
│   └── plot_response.py
├── Makefile                  # Build rules (main, tests, clean)
├── .gitignore
└── README.md                 # Project overview (this file)
```

## Features

* **PID Controller** (`src/pid.*`)

  * Proportional–integral–derivative loop with anti-windup clamp
* **Thermal Plant Model** (`src/plant_sim.*`)

  * First-order response: `dT/dt = (u - (T - T_ambient)) / τ`
* **Simulation Driver** (`src/main.cpp`)

  * Runs a 60 s step to a target temperature, logs `time,temperature` to `response.csv`
* **Unit Tests** (`tests/*.cpp`)

  * `test_pid` checks P, I (clamp), and D behavior
  * `test_plant_sim` verifies ambient hold and step response
* **Plotting Helper** (`tools/plot_response.py`)

  * Reads `response.csv` and saves `response.png`

## Prerequisites

* C++17 compiler (e.g., `g++`)
* GNU Make
* Python 3 with `matplotlib` (optional, for plotting)

## Build & Run

1. **Build everything**

   ```bash
   make
   ```

   This produces:

   * `build/main`        # Simulation executable
   * `build/test_pid`    # PID unit test
   * `build/test_plant`  # Plant model unit test

2. **Run unit tests**

   ```bash
   ./build/test_pid
   ./build/test_plant
   ```

3. **Generate simulation output**

   ```bash
   ./build/main
   ```

   This creates `response.csv` in the project root.

4. **Plot the response** (optional)

   ```bash
   python3 tools/plot_response.py
   ```

   This saves `response.png`.

## Cleaning Up

To remove build artifacts and generated files, run:

```bash
make clean
```


