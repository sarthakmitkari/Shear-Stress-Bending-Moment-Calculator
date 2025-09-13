
# Shear Stress and Bending Moment 

C++ project to calculate shear stress and bending moment for square beams under simply supported and cantilever cases with point/UDL loads. More sections like circular, T, and I will be added soon.


## Authors

- [@sarthakmitkari](https://github.com/sarthakmitkari)


## Installation


Installation
Clone this repository and compile with a standard C++ compiler:

```
git clone https://github.com/YourUsername/beam-calculator-cpp.git
cd beam-calculator-cpp
```
```
g++ -std=c++11 main.cpp -o beam_calculator
```

## Usage
Run the compiled executable:
```bash
  ./beam_calculator
```


## 🚀 About Me
I'm Mechanical Engineer,
I'm Interested in Designing .
# Shear Stress and Bending Moment 

C++ project to calculate shear stress and bending moment for square beams under simply supported and cantilever cases with point/UDL loads. More sections like circular, T, and I will be added soon.




## How It Works
- User selects whether to calculate shear stress or bending stress.

- For bending stress, user either inputs a bending moment or inputs beam and load parameters to calculate it.

- For shear stress, user inputs shear force or beam load details to calculate it.

- User defines cross-section shape and dimensions (currently rectangle or circle).

- Program calculates moment of inertia (MoI).

- User inputs position (y) on the beam section for stresses calculation or uses defaults.

- Program outputs calculated shear stress and bending moment (or bending stress).

## Supported Cases

```
Beam Types:
Simply Supported Beam
Cantilever Beam

Load Types:
Point Load (option for center or other location)
Uniformly Distributed Load (full span or partial)
```

