# Turing Machine Style Base Converter — C++ Implementation

This project implements a simplified Turing machine in C++ that performs base conversion on a number using a symbolic transition system.

Unlike traditional approaches, this machine simulates the process of computation using:
- State transitions (`q0` to `qf`)
- Symbol rewriting
- Left/Right head movement
- Arithmetic simulation through `a+1`, `a-1` operations

## 🧠 Concept

The algorithm mimics a multi-state Turing machine. The input is read symbol by symbol, and transformations are applied based on a transition table defined in the code.

### Key Features:
- Pure symbolic computation (no use of standard base-10 logic)
- Simulated arithmetic using state changes
- Input/output managed using a virtual tape
- Final output extracted between `#` and `_` symbols

## 💡 Example

Please enter a number: 121
Output: 14


## 📁 File Structure

turing-machine-base-converter-cpp/
├── main.cpp # Main Turing machine simulation logic
└── README.md # Project documentation


## 🛠️ Compile & Run

```bash
g++ -o base_converter main.cpp
./base_converter
```

## 📜 License

MIT License
## 👤 Author

Designed and implemented by Pouya Rostami, inspired by theoretical computation and automata theory
