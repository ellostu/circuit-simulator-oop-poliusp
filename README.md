# C++ Circuit Simulator – OOP Academic Project @ Poli-USP (2023)

> 📘 **Academic Project – C++ Circuit Simulator | Poli-USP, 2023**  
> Developed as part of the Object-Oriented Programming (OOP) course in Electrical Engineering at the Polytechnic School of the University of São Paulo (Poli-USP).  
> Demonstrates strong software architecture, modular C++ design, and abstraction of engineering problems — aligned with expectations for internships in software development, signal processing, and telecommunications.

---

## 🚀 Project Overview

This project simulates electronic circuits through a fully modular and extensible **object-oriented architecture** written in C++. It models core components (e.g., amplifiers, integrators, differentiators) and their interconnections (series, parallel, feedback), processing input signals and simulating the resulting behavior.

The project bridges theoretical knowledge in Electrical Engineering and practical software engineering, showcasing the abstraction of real-world problems through OOP.

---

## ✨ Key Features & Concepts Demonstrated

* **Object-Oriented Design:** Robust use of encapsulation, inheritance, polymorphism, and composition to build a flexible system.
* **Modularity & Reusability:** Circuit components implemented as standalone modules that can be combined in series, parallel, or feedback configurations.
* **Abstract Hierarchies:** `Modulo` and `Circuito` abstract classes allow consistent handling of components and structures.
* **Signal Processing:** Input signal transformation through simulated systems.
* **Persistence:** Save/load capabilities for module configurations using file I/O (`PersistenciaDeModulo`).
* **Command-Line Interface:** Interactive interface implemented in `menu.cpp` and `main.cpp` for running simulations.
* **Scalability:** Clean architecture facilitates future additions like new components or UI layers.

---

## 🛠️ Technical Stack

* **Language:** C++ (C++11 standard)
* **Compiler:** g++
* **Build System:** Makefile

---

## 📂 Project Structure

```
.
├── Amplificador.cpp
├── Amplificador.h
├── Circuito.cpp
├── Circuito.h
├── CircuitoMISO.cpp
├── CircuitoMISO.h
├── CircuitoSISO.cpp
├── CircuitoSISO.h
├── Derivador.cpp
├── Derivador.h
├── Grafico.cpp
├── Grafico.h
├── Integrador.cpp
├── Integrador.h
├── main.cpp
├── menu.cpp
├── Modulo.cpp
├── Modulo.h
├── ModuloEmParalelo.cpp
├── ModuloEmParalelo.h
├── ModuloEmSerie.cpp
├── ModuloEmSerie.h
├── ModuloRealimentado.cpp
├── ModuloRealimentado.h
├── PersistenciaDeModulo.cpp
├── PersistenciaDeModulo.h
├── Sinal.cpp
└── Sinal.h
```

---

## ⚙️ How to Compile and Run

1. **Navigate to the project directory:**
   ```bash
   cd circuit-simulator-oop-poliusp
   ```

2. **Compile the project using Makefile:**
   ```bash
   make
   ```
   This creates an executable file named `meu_projeto`.

3. **Run the executable:**
   ```bash
   ./meu_projeto
   ```

4. **Clean compiled files (optional):**
   ```bash
   make clean
   ```

---

## 🧠 Skills & Industry Relevance

This project demonstrates a strong alignment between **engineering problem-solving** and **software design best practices**, crucial for internships in **telecom**, **embedded systems**, and **signal processing** — such as those at Ericsson:

- **Advanced OOP Design:** Implemented abstract and polymorphic hierarchies to simulate real-world electronics with precision.
- **Modular Architecture:** Created a system of independent, testable components (e.g., `Amplificador`, `Integrador`) for flexibility and scalability.
- **Engineering Abstraction:** Translated signal flow and analog circuit theory into C++ object structures and data pipelines.
- **CLI and I/O Management:** Designed a simple terminal UI to simulate configuration inputs and visualize signal output.
- **Persistence and Serialization:** Built `PersistenciaDeModulo` to store and reload module configurations via files.
- **Git and Workflow Discipline:** Maintained a clean commit history and structured project repository.
- **Time and Pressure Management:** Delivered the project within **one week**, under the pressure of overlapping exams and course deadlines.
- **Attention to Detail:** Used flags like `-Wall` and careful type safety to reduce bugs and enforce coding discipline.

---

## 💡 Future Enhancements

* **Graphical User Interface (GUI):** Add a visual editor for creating and connecting modules.
* **Advanced Components:** Add filters, oscillators, and configurable logic modules.
* **Error Handling:** Improve handling of invalid user inputs or circuit topologies.
* **Performance Tuning:** Optimize performance for larger and more complex circuits.
* **Unit Testing:** Introduce a unit test suite for module verification.
* **Config Files:** Replace hardcoded configurations with external files in JSON or XML.

---

## 🔗 Repository

GitHub: [https://github.com/ellostu/cpp-oop-circuit-simulator](https://github.com/ellostu/cpp-oop-circuit-simulator)

Feel free to explore the code and reach out with feedback or suggestions!

---
