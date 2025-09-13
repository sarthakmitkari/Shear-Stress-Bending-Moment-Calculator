
markdown
Shear Stress & Bending Moment Calculator (C++)

[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)
[![GitHub stars](https://img.shields.io/github/stars/sarthakmitkari/Shear-Stress-Bending-Moment-Calculator?style=social)]()
[![GitHub forks](https://img.shields.io/github/forks/sarthakmitkari/Shear-Stress-Bending-Moment-Calculator?style=social)]()


## About The Project

A **C++ console application** for calculating **shear stress** and **bending moment** of **square beams** under:

- Simply supported beams or cantilever beams
- Point loads (centered or offset)
- Uniformly Distributed Loads (UDL) — fully or partially spanning

Future versions will support extra beam sections such as circular, T-section, and I-section.

---

## Table of Contents

- [Installation](#installation)
- [Usage](#usage)
- [How It Works](#how-it-works)
- [Supported Cases](#supported-cases)
- [Roadmap](#roadmap)
- [Contributing](#contributing)
- [License](#license)
- [About Me](#about-me)

---

## Installation

Clone the repository and compile the project:

```
git clone https://github.com/sarthakmitkari/Shear-Stress-Bending-Moment-Calculator.git
cd Shear-Stress-Bending-Moment-Calculator
g++ -std=c++11 main.cpp -o beam_calculator
```

---

## Usage

Run the executable:

```
./beam_calculator
```

Follow the interactive console prompts to input beam parameters, load types, and section dimensions. The program will calculate and display shear stress and bending moment.

---

## How It Works

- Choose whether to calculate **shear stress** or **bending stress**.
- Enter given data or allow the program to compute bending moment or shear force.
- Specify beam type (simply supported or cantilever).
- Specify load type (point load or UDL).
- Enter beam length, loading position, and beam section dimensions.
- Program calculates moment of inertia and the requested stresses.

---

## Supported Cases

- **Beam Types:**
  - Simply Supported
  - Cantilever

- **Load Types:**
  - Point Load (center or offset)
  - Uniformly Distributed Load (full or partial span)

---

## Roadmap

- Add support for circular, T-section, and I-section beams.
- Improve UI and input validation.
- Add graphical visualization of stress distribution.
- Include unit tests and extend automated CI/CD workflow.

---

## Contributing

Contributions are welcome! Feel free to fork the repository and submit pull requests. Please follow the standard GitHub flow for contributions.

---

## License

Distributed under the MIT License. See `LICENSE` for more information.

---

## About Me

Mechanical Engineer passionate about structural design and computational analysis.

---

Made with ❤️ by [sarthakmitkari](https://github.com/sarthakmitkari)
```
