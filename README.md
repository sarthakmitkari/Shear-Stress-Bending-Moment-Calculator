Beam Shear Stress and Bending Moment Calculator (C++)
Description
This C++ project calculates shear stress and bending moment specifically for square beam sections. It supports beams of two types: simply supported and cantilever, under two common loading scenarios: point load and uniformly distributed load (UDL).

The program is interactive; it prompts users for required inputs such as beam type, load type, span length, load magnitude, and sectional dimensions. The code performs necessary calculations to output shear stress and bending moment values critical for structural and mechanical engineering analyses.

Features
Supports calculation of bending moment with either given bending moment or by inputting data based on beam and load type.

Supports calculation of shear force with either given force or by input of loading conditions.

Calculates the moment of inertia (MoI) for rectangular and circular cross-sections.

Computes bending stress and shear stress using given or calculated parameters.

Interactive console-based input system guides the user step-by-step.

Error checking on inputs such as distance and sectional dimensions.

Modular handling of beam shapes and loading types for extension.

Supported Cases
Beam Types:

Simply Supported Beam

Cantilever Beam

Load Types:

Point Load (option for center or other location)

Uniformly Distributed Load (full span or partial)

How It Works
User selects whether to calculate shear stress or bending stress.

For bending stress, user either inputs a bending moment or inputs beam and load parameters to calculate it.

For shear stress, user inputs shear force or beam load details to calculate it.

User defines cross-section shape and dimensions (currently rectangle or circle).

Program calculates moment of inertia (MoI).

User inputs position (y) on the beam section for stresses calculation or uses defaults.

Program outputs calculated shear stress and bending moment (or bending stress).

Prerequisites
C++ compiler supporting C++11 or above.

Basic familiarity with running programs from command line or terminal.

Installation
Clone this repository and compile with a standard C++ compiler:

bash
git clone https://github.com/YourUsername/beam-calculator-cpp.git
cd beam-calculator-cpp
g++ -std=c++11 main.cpp -o beam_calculator
Usage
Run the compiled executable:

bash
./beam_calculator
Follow on-screen prompts to input beam details and loads, and view calculated shear stress and bending moment.

Example
text
What you want to calculate?
1. Shear Stress
2. Bending Stress
Enter 1 or 2: 2

What is given?
1. Bending Moment?
Enter 1:Yes or 0:No : 0
Enter type of beam enter 1 for simply supported, 0 for cantilever: 1
Type of load enter 1 for point load, 0 for UDL: 1
Enter load (W) in kN: 10
Enter Span of Beam (L) in m: 5
Is the load at center? Enter 1 for yes, 0 for no: 1
...
Calculated Bending Moment is X kNm
...
Calculated Bending Stress is Y N/mm^2
Roadmap
Extend support to additional cross-section shapes like T-section and I-section.

Add graphical interface or visualization tools.

More comprehensive input validation and user experience improvements.

Contribution
Contributions and suggestions for future improvements are welcome. Please open an issue or submit pull requests.

License
This project is licensed under the MIT License.

