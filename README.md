# Banker's Algorithm - Programming Assignment #2

This project implements the Banker's Algorithm to determine whether a given system state is **safe or unsafe** based on the allocation of resources to processes.

## How to Compile and Run (Manual Method)
If you are not using the Makefile, you can compile manually using:
```
g++ bankers.cpp -o bankers
./bankers input.txt
```

## Recommended: Use the Makefile
The project includes a `Makefile` to simplify compilation and testing:
```
make         # Compiles bankers.cpp
make run     # Runs the program using input.txt
```

## Test Cases
The project includes built-in test files to check both safe and unsafe scenarios.
```
make safe      # Runs the known SAFE configuration (test_safe.txt)
make unsafe    # Runs the known UNSAFE configuration (test_unsafe.txt)
make test      # Runs both safe and unsafe tests one after another
```
These targets temporarily overwrite `input.txt` during execution.

## Project Structure
- `bankers.cpp` - Main C++ implementation
- `input.txt` - Default input file
- `test_safe.txt` - Input for a safe system
- `test_unsafe.txt` - Input for an unsafe system
- `Makefile` - Build and test automation
- `README.md` - Project documentation

## Input File Format (input.txt or test_*.txt)
1. First line: Number of processes and number of resource types  
2. Next `P` lines: Allocation matrix  
3. Next `P` lines: Maximum demand matrix  
4. Final line: Available resources

Example:
```
5 3
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2
7 5 3
3 2 2
9 0 2
2 2 2
4 3 3
3 3 2
```

## Example Output: Safe System
```
System is in a safe state.
Safe sequence: P1 -> P3 -> P4 -> P0 -> P2
```

## Example Output: Unsafe System
```
System is NOT in a safe state.
```

## Clean Up
To remove the compiled binary:
```
make clean
```