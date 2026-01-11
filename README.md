# FASERIP
Utilities for the TSR Marvel Super Heroes Game / FASERIP / 4CS

Diceroller leads you through the Universal Table.

## Available Versions

The dice roller is available in three programming languages:

- **Perl**: `faseripdiceroller.pl`
- **Python**: `faseripdiceroller.py`
- **C++**: `faseripdiceroller.cpp`

## Usage

### Perl Version
```bash
perl faseripdiceroller.pl
```

### Python Version
```bash
python3 faseripdiceroller.py
# or
./faseripdiceroller.py
```

### C++ Version
First, compile the program:
```bash
g++ -o faseripdiceroller faseripdiceroller.cpp -std=c++11
```

Then run it:
```bash
./faseripdiceroller
```

## How It Works

1. The program generates a random d100 roll
2. You choose an effect type (0-18)
3. You choose a rank (0-18)
4. The program uses the Universal Table to determine the result color (WHITE/GREEN/YELLOW/RED)
5. The result is displayed based on the effect type and color
