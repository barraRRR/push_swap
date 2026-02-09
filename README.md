_This project was developed as part of the 42 curriculum by LORD EDUARDO DECIMO MERIDIO and jbarreir._

# push_swap

The goal of push_swap is to sort data on a stack with a limited set of instructions, using the lowest possible number of actions.

## Description
This version of the project focuses on algorithmic flexibility, requiring the implementation of four different sorting strategies and a performance benchmark mode.

### Technical Architecture

#### Data Structures
To allow efficient manipulation of both the top and the bottom of the stacks (required for rotate and reverse rotate operations), we implemented a Doubly Linked List.

```C
typedef struct s_node {
    int             value;
    struct s_node   *next;
    struct s_node   *prev;
} t_node;
```


#### Strategy Management
We use a dedicated structure to store the configuration detected during the parsing phase. This determines which algorithm will be executed and whether performance metrics should be displayed.

```C
typedef enum e_complexity {
    DEFAULT,
    SIMPLE,
    MEDIUM,
    COMPLEX,
    ADAPTIVE
} t_complexity;
```

```c
typedef struct s_strategy {
    t_complexity    complex;
    bool            defined; 	// True if a specific flag was provided
    bool            bench; 	// True if --bench flag is present
} t_strategy;
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


## Resources

### Theoretical Documentation
* [Oceano's Push Swap Notion Site](https://suspectedoceano.notion.site/push_swap-ee2c472005d54d978412bfc37a1ab3e7) - Extensive guide on 42 requirements and project logic.

### Algorithm Deep Dives
* [Push_Swap Turk Algorithm Explained](https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0) - Efficient strategy for Medium/Complex modes based on calculation of cost.
* [Push_swap: Performant Sorting Video](https://www.youtube.com/watch?v=OaG81sDEpVk&t=2945s) - Visual walkthrough of stack coordination and operations.

### Visualizers
* [Push_swap Visualizer (o-reo)](https://github.com/o-reo/push_swap_visualizer) - Essential tool for debugging, verifying moves, and seeing the algorithm in real-time.

## AI Usage Disclosure - TERMINAR DE REDACTAR

In compliance with 42's evaluation standards regarding Artificial Intelligence:

- **Concept Clarification**: bla bla
- **Translation & Localization**: AI assisted in translating technical explanations from Spanish to English to ensure professional documentation standards.
- **Debugging & Strategy**: bla bla
- **Strict Policy**:
  - **No Copy-Paste**: No code was directly copied from AI. All implementations were written manually.
  - **Ownership**: Every line of code was understood and is capable of being replicated or modified by the author during a defense.
  - **Verification**: AI-generated suggestions were always cross-referenced with official documentation and verified using the testers mentioned in the Resources section.

