# Push_swap

_This project has been created as part of the 42 curriculum by mvazquez, mpeskov._

## Description

Push_swap is a project focused on algorithmic complexity. The goal is to sort a stack of integers using two stacks (a and b) and a limited set of instructions, minimizing the total number of operations.

The program calculates and displays the smallest program (sequence of operations) that sorts the integers received as arguments. It features an adaptive engine that analyzes the "disorder" of the input to select the most efficient sorting strategy at runtime.

## Instructions

### Compilation
Use the provided Makefile to compile the project. It compiles the libft library and the push_swap executable.
'''make'''

### Execution
Run the program with a list of integers as arguments:
./push_swap 2 1 3 6 5 8

### Strategy Flags
You can force specific algorithms or enable benchmark mode using the following flags:
 * --adaptive: (Default) Automatically selects the best strategy based on disorder metrics.
 * --simple: Forces the O($n^2$) algorithm.
 * --medium: Forces the O($n\sqrt{n}$) algorithm.
 * --complex: Forces the O($n \log n$) algorithm.
 * --bench: Displays performance metrics (disorder %, strategy used, operation counts) to stderr.

## Algorithms and Complexity
We implemented four distinct strategies to handle different data configurations efficiently.
1. Simple Algorithm: **Selection Sort**
 * Complexity: **O($n^2$)**
 * Logic: The algorithm scans stack a to find the smallest element (or largest), pushes it to b, and repeats. Once a is empty, everything is pushed back.
 * Justification: This is the baseline strategy. It is extremely efficient for very small list sizes (e.g., 3-5 numbers) or lists that are already nearly sorted, where complex overhead is unnecessary.
2. Medium Algorithm: **Chunk Sort**
 * Complexity: **O($n\sqrt{n}$)**
 * Logic: The stack is divided into $\sqrt{n}$ logical "chunks" based on value ranges. Elements belonging to the current chunk are pushed to b. This acts as a rough pre-sort. Once all chunks are in b, elements are moved back to a in strict order.
 * Justification: This approach balances the number of operations for medium-sized inputs or medium disorder. It avoids the worst-case scenarios of QuickSort on stacks while being faster than O($n^2$).
3. Complex Algorithm: **Turk Sort**
 * Complexity: **O($n \log n$)**
 * Logic: A greedy algorithm that moves numbers to b while keeping b partially sorted (descending). It calculates the "cost" to move every node in a to its correct position in b and executes the cheapest move.
 * Justification: For large, random datasets, this heuristic approach significantly reduces operations compared to structured geometric sorts, staying well within the O($n \log n$) performance target.
4. Adaptive Strategy (Default)
Our adaptive engine measures the disorder metric (percentage of inverted pairs) before sorting to choose the optimal path.
Thresholds and Rationale:
 * Low Disorder (< 0.2):
   * Strategy: **Selection Sort**
   * Reasoning: If the list is mostly sorted, the cost of setting up chunks or calculating heuristic costs outweighs simply swapping the few misplaced elements. Meets the O($n^2$) requirement.
 * Medium Disorder (0.2 - 0.5) OR Small Stack Size (< 150):
   * Strategy: **Chunk Sort**
   * Reasoning: For moderately messy lists, dividing the problem into chunks reduces the search space efficiently. Meets the O($n\sqrt{n}$) requirement.
 * High Disorder (>= 0.5):
   * Strategy: **Radix Sort (LSD)**
   * Reasoning: When the list is completely random (high entropy), bit-wise Radix sort provides a strictly linear-logarithmic guarantee without the overhead of comparisons. Meets the O($n \log n$) requirement.

## Contributors
This is a pair project. Both learners contributed to the codebase and understand all algorithms.
 * *mvazquez*: Project structure, stack manipulation primitives (push, swap, rotate), argument parsing, main logic, simple sorting and turk sort implementation, norminette compliance, memory leaks debugging.
 * *mpeskov*: Benchmark system (t_bench), medium-level sorting algorithm (Chunk sort) , complex sorting logic (Radix), and optimization of operation costs.

## Resources
 None

## AI Usage
As per the subject guidelines, AI tools were used to assist in specific tasks.
 * Prompting & Coding: AI was used to generate boilerplate code for the t_bench structure and print functions to avoid repetitive typing. It also assisted in debugging memory leaks in the init_stack function.
 * Logic & Algorithms: We used AI to explain the mathematical concept of the "Disorder Metric" (calculating inversions) to ensure our adaptive thresholds were mathematically sound.
 * Verification: AI generated test cases (random number lists) to verify that our check_args function correctly handled edge cases like duplicates and non-integer inputs.
