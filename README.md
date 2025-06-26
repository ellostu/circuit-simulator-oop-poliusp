# EP2 - Object-Oriented Circuit Simulation Project

This repository showcases a university lab project developed in C++ using **Object-Oriented Programming (OOP) principles**. The project simulates various electronic circuit modules and their interconnections, demonstrating core software engineering practices for modular design, reusability, and robust system architecture.

This project highlights a practical application of theoretical concepts in software development, focusing on how real-world problems can be abstracted and solved using object-oriented paradigms.

---

## 🚀 Project Overview

The primary goal of this project was to model and simulate the behavior of different circuit components (such as amplifiers, integrators, differentiators, and adders) and their complex interconnections (series, parallel, feedback loops). It processes input signals through these simulated circuits and can potentially output results for analysis.

This project highlights a practical application of theoretical concepts in software development, focusing on how real-world problems can be abstracted and solved using object-oriented paradigms.

---

## ✨ Key Features & Concepts Demonstrated

* **Object-Oriented Design (OOD):** Extensive use of **classes, objects, encapsulation, inheritance, and polymorphism** to model circuit components (`Module` hierarchy) and circuit structures (`Circuito` hierarchy).
* **Modularity & Reusability:** Designing individual circuit modules as distinct, reusable components that can be combined to form complex circuits.
* **Polymorphism:** Utilizing **virtual functions** and **abstract classes** (e.g., `Modulo`, `Circuito`) to allow different types of modules and circuits to be handled uniformly.
* **Composition:** Building complex circuits (e.g., `ModuloEmSerie`, `ModuloEmParalelo`, `ModuloRealimentado`) by composing simpler modules.
* **Data Structures & Algorithms:** Handling and processing signals, managing lists of modules, and performing calculations based on circuit topology.
* **Input/Output Handling:** Reading configuration from files and potentially generating graphical output (`Grafico`).
* **Persistence:** Implementing **data persistence** for modules (`PersistenciaDeModulo`) to save and load circuit configurations.
* **User Interface (CLI):** A **command-line interface** (`menu.cpp`, `main.cpp`) for interacting with the simulation.

---

## 🛠️ Technical Stack

* **Language:** C++ (using C++11 standard)
* **Compiler:** g++
* **Build System:** Makefile

---

## 📂 Project Structure

The project is organized into `.cpp` (source) and `.h` (header) files for each class, alongside `main.cpp` for the program entry point and `menu.cpp` for the user interface logic.
