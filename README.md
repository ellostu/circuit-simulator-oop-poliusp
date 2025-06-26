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

---

## ⚙️ How to Compile and Run

To compile this project, navigate to the `Ep2` directory in your terminal and use the provided `Makefile`.

1.  **Navigate to the project directory:**
    ```bash
    cd Ep2
    ```

2.  **Compile the project using Makefile:**
    ```bash
    make
    ```
    This will create an executable file named `meu_projeto` (or `circuito_sim` if you change the `TARGET` in the Makefile).

3.  **Run the executable:**
    ```bash
    ./meu_projeto
    ```

4.  **Clean compiled files (optional):**
    To remove object files and the executable:
    ```bash
    make clean
    ```

### Makefile Content

To ensure successful compilation, make sure a file named `Makefile` (no extension) exists in the root of your project directory with the following content:

```makefile
CXX = g++
CXXFLAGS = -std=c++11 -Wall
TARGET = meu_projeto
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
