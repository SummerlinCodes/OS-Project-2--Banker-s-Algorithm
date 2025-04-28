
# Banker's Algorithm - Programming Assignment #2

This project implements Banker's Algorithm to determine if a given system state is safe.

## How to Compile and Run

```bash
g++ bankers.cpp -o bankers
./bankers input.txt
```

## Project Structure
- `bankers.cpp` - Main source code.
- `input.txt` - Input file with resource allocation, max needs, and available resources.
- `README.md` - Project documentation.

## How Input.txt is Structured
1. First line: Number of processes and number of resource types
2. Next P lines: Allocation matrix
3. Next P lines: Max matrix
4. Last line: Available resources

Example:
```
5 3
0 1 0
...
4 3 3
3 3 2
```

## Output

If system is safe, output will be:
```
System is in a safe state.
Safe sequence: P1 -> P3 -> P4 -> P0 -> P2
```
Otherwise:
```
System is NOT in a safe state.
```
