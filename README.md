_This project has been created as part of the 42 curriculum by edsole-a and jbarreir._

# push_swap

The goal of push_swap is to sort data on a stack with a limited set of instructions, using the lowest possible number of actions.

## Description
This version focuses on algorithmic flexibility, featuring an Adaptive Strategy Selector that chooses the most efficient sorting method based on the input's size and entropy (disorder).

## Instructions

### Compilation

The project includes a Makefile with all standard 42 rules. To compile the executable, run:

```Bash
make
```
This will generate the push_swap binary in the root directory. Other available rules:

- `make clean`: Removes object files.
- `make fclean`: Removes object files and the push_swap binary.
- `make re`: Performs a full recompilation.

### Execution

The program takes a list of integers as arguments. It can handle both individual arguments and quoted strings.

#### Basic Usage:

```Bash
./push_swap 3 2 1
./push_swap "3 2 1"
```
#### With Checker (Verification):
To verify the output is correct and count the operations:

```Bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
```
#### Advanced Modes & Benchmarking

Our implementation features an Adaptive Mode and a custom Benchmark suite.

#### Strategy Overrides:
You can force a specific algorithm using flags:

- `--simple`: Forces Selection Sort.
- `--medium`: Forces Hourglass Sort.
- `--complex`: Forces Radix Sort.

#### Performance Metrics:
Enable the benchmark report (outputs to stderr):

```Bash
./push_swap --bench 5 2 8 1 9
```

#### Error Handling:
The program strictly validates all input. It will display Error on stderr and exit with a non-zero status if:

- Arguments are not integers.
- Any integer exceeds INT_MIN or INT_MAX.
- There are duplicate values in the input.

### Technical Architecture

#### Data Structures
To allow efficient manipulation of both the top and the bottom of the stacks (required for rotate and reverse rotate operations), we implemented a Doubly Linked List.

```C
typedef struct s_node
{
    int             value;
	unsigned int    index;
    struct s_node   *next;
    struct s_node   *prev;
} 	t_node;
```

```c
typedef struct s_stack
{
	t_lst           *head;
	t_lst           *tail;
} 	t_stack;
```


#### Strategy Management
We use a dedicated structure to store the configuration detected during the parsing phase. This determines the algorithm complexity and enables the diagnostic mode.

```C
typedef enum e_complexity
{
    DEFAULT,
    SIMPLE,
    MEDIUM,
    COMPLEX,
    ADAPTIVE
}	t_complexity;
```

```c
typedef struct s_strat
{
    t_complexity    complex;
    bool            defined;
	int				total;
	float			disorder;
}	t_strat;
```

### Parsing & Input Validation

The parsing logic is designed to be robust, handling multiple input formats seamlessly (separated arguments, quoted strings, or a mix of both).

#### **The Parsing Workflow**

1. **Argument Normalization**
   - We use a custom `ps_split` to convert the `argv` into a unified array of strings. 
   - This ensures that all the following inputs are treated identically:
     - **Separate:** `./push_swap 1 2 3`
     - **Quoted:** `./push_swap "1 2 3"`
     - **Mixed:** `./push_swap "1 2" 3` or `./push_swap 1 "2 3"`

2. **Flag Detection**
   - The parser scans for optional selectors to set the sorting strategy:
     - `--simple`, `--medium`, `--complex`, `--adaptive`
   - It also identifies the `--bench` flag to enable performance metrics in `stderr`.

3. **Strict Validation**
   - **Type Check:** Verifies that each argument consists only of valid integers.
   - **Overflow Check:** Ensures numbers are within the `INT_MIN` and `INT_MAX` range.
   - **Uniqueness Check:** Scans for duplicate values to prevent invalid stack states.

4. **Stack Population**
   - Once validated, integers are pushed into **Stack A** (Doubly Linked List).
   - The order of appearance is strictly maintained: the first number provided becomes the **top** of the stack.


```
	   [ Start: argv ]
              |
              v
     +------------------+
     |     ps_split     | <--- Normalizes multiple args and 
     +------------------+      quoted strings into a clean array
              |
              v
    +--------------------+
    |  Loop through array| <--- Processing each string
    +--------------------+
      /       |        \
     /        |         \
    v         v          v
+-------+  +-------+  +-----------+
| FLAGS |  | NUMS  |  |  ERRORS   |
+-------+  +-------+  +-----------+
    |         |              |
    |         |              +------> [ ps_exit ]
    |         |                       Print "Error\n"
    |         |                       Free memory
    |         v                       Exit(1)
    |    +------------+
    |    | Validation | <--- 1. Is Numeric?
    |    +------------+      2. Is Int? (Overflow)
    |         |              3. Is Duplicate?
    |         v
    |    +------------+
    +--> | t_strategy | <--- Updates: .complexity
         +------------+           .bench_mode
              |
              v
      +----------------+
      |  Create Stack  | <--- Pushes validated numbers
      +----------------+      into Doubly Linked List
              |
              v
       [ Ready to Sort ]
```

## Algorithmic Strategies

### Heuristic Selection (The Disorder Coefficient)

To ensure the most efficient approach, the program calculates the `Disorder Coefficient (D)` before performing any operations. This is done by counting inversions (pairs of elements that are in the wrong relative order).

- **Low Entropy (D < 0.2)**: Executes `Selection Sort`. Ideal for nearly sorted stacks where only a few elements are out of place.
- **Medium Entropy (0.2 ≤ D < 0.5)**: Executes `Hourglass Sort`. Optimized for average distributions where a sliding window can partition data effectively.
- **High Entropy (D ≥ 0.5)**: Executes `Radix Sort`. Best for maximum chaos, providing a stable and predictable number of moves.

### Selection Sort (O(n^2))

Our strategy for small sets or nearly sorted stacks.

- **Path of Least Resistance**: The algorithm repeatedly scans Stack A to find the absolute minimum value. By pushing the smallest elements to Stack B one by one, we effectively "shorten" the problem until only 3 elements remain in Stack A.
	- If the index is in the upper half, it uses `ra`.
	- If the index is in the lower half, it uses `rra`.
- **Tiny Sort**: Once the stack is reduced to 3 elements, a hardcoded logic solves it in a maximum of `3 moves`, regardless of their initial position.

### Hourglass Sort (O(n√n))

This is our primary engine for the 100 and 500 number challenges. It pushes elements to Stack B in a way that resembles an hourglass shape.

- **Newton-Raphson Optimization**: To determine the ideal `"radius" (r)` for the sliding window without using forbidden math libraries, we implemented a custom square root function: `r = newton_sqrt(n) × 1.2`. This ensures the window size is mathematically tuned to the input size n.
- **Sliding Window**: By rotating Stack B based on the `element's index`, we keep the smallest and largest values of each chunk at the extremes, facilitating a much faster recovery to Stack A.
- **Instruction Coupling**: The algorithm looks ahead to the next node; if both stacks require a rotation, it utilizes `rr` or `rrr` to merge two moves into one.

### Radix Sort (O(n log n))

For stacks with high entropy, Radix Sort provides a consistent bitwise partitioning.

* **Normalization (Indexing)**: We map every value to its rank (0 to n−1). This *"compression"* ensures that the algorithm only processes the necessary number of bits (e.g., 9 bits for 500 numbers), regardless of whether the original integers were very large or negative.
* **Bitwise Partitioning**: It iterates through **each bit**, pushing elements with a 0 bit to Stack B and rotating those with a 1 bit in Stack A, ensuring a stable sort across multiple passes.

## Resources

### Theoretical Documentation
* [Oceano's Push Swap Notion Site](https://suspectedoceano.notion.site/push_swap-ee2c472005d54d978412bfc37a1ab3e7) - Extensive guide on 42 requirements and project logic.

### Algorithm Deep Dives
* [Push_swap: Performant Sorting Video](https://www.youtube.com/watch?v=OaG81sDEpVk&t=2945s) - Visual walkthrough of stack coordination and operations.
* [PUSH_SWAP: the smallest number of movements](https://medium.com/@ridwaneelfilali/push-swap-eff35d3ee0c4) - Explanation of Hourglass algorithm by 42 student B.R.O.L.Y.

### Visualizers
* [Push_swap Visualizer (o-reo)](https://github.com/o-reo/push_swap_visualizer) - Essential tool for debugging, verifying moves, and seeing the algorithm in real-time.

## Contributions
In compliance with the 42 curriculum requirements, the following breakdown outlines the core contributions of each learner:

### jbarreir:
* Implementation of the Parsing & Input Validation system (handling quoted strings and mixed arguments).
* Design of the Doubly Linked List and core stack operations (sa, pa, ra, rra, etc.).
* Development of the Selection Sort (Simple strategy) and Sandglass Sort (Medium strategy).
* Design of the --bench mode diagnostic system.

### edsole-a:
* Design and implementation of the algo_selector and the Disorder Coefficient heuristic.
* Development of the Radix Sort (Complex strategy) and the stack Normalization logic.
* Optimization of bitwise operations for large datasets.

### Joint Work:
* Unified Error Handling and memory leak prevention system.

## AI Usage Disclosure

In compliance with 42's evaluation standards regarding Artificial Intelligence:

- **Concept Clarification**: AI was used to clarify the mathematical logic behind the algorithms.
- **Translation & Localization**: AI assisted in translating technical explanations from Spanish to English to ensure professional documentation standards.
- **Strict Policy**:
  - **No Copy-Paste**: No code was directly copied from AI. All implementations were written manually.
  - **Ownership**: Every line of code was understood and is capable of being replicated or modified by the author during a defense.
  - **Verification**: AI-generated suggestions were always cross-referenced with official documentation and verified using the testers mentioned in the Resources section.
