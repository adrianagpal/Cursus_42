*This project has been created as part of the 42 curriculum by adrianag.*

# Description
Push swap is a program that receives a list of numbers as input and sorts them using two stacks (A and B). A stack is a data structure where operations are only allowed at the top. The permitted operations are: 

- swap: swaps the first two elements
- push: moves the top element from one stack to the other
- rotate: shifts all elements up by one (top becomes bottom)
- reverse rotate: shifts all elements down by one (bottom becomes top)

# Instructions

## Parsing
The program can receive as arguments either strings with space-separated numbers or individual numbers. First, it validates that all characters in the input are valid. If validation is successful, all arguments are concatenated into a single string. The numbers are loaded into a doubled linked, non-circular list, and while loading each number is converted and checked for integer overflow. After loading the list, the program verifies that there are not duplicate values. If any of the conditions is not met, the porgram exits and frees all previously allocated memory. 

The list consists of nodes defined by the t_list structure. Each node stores the value, its index, LIS-related information, and pointers to the previous and next nodes. The LIs-related attributes will be used by the algorithm and are initialized by default (in_lis = 0, lis = 1).

## Push swap

### Calculating LIS
The implementation uses the Turk algorithm improved by seeking the Longest Increasing Subsequence (LIS). First, using the *apply_index* function, each node is assigned an index corresponding to its position in a sorted list. 

Then, *calculate_lis_end* calculates how many increasing values end in each node and this value is saved in the lis attribute of the node. The function returns the node with the longest increasing subsequence. With this node, *calculate_lis_start* marks the nodes that belong to the LIS by setting in_lis = 1. 

After identifyind the LIS, the function *keep_lis_in_a* pushes all nodes not in the LIS to stack B.  

Note: The longest LIS does not always yield the optimal number of moves. The efficiency depends on the distribution of values. A possible improvement is to test multiple LIS candidates and choose the one with the lowest total cost.

### Calculating costs and applying rotations
For each node, two costs are calculated:

- cost_b: moves needed to bring the node to the top of stack B.
- cost_a: moves needed to insert the node into stack A in the correct position.

Theses values are stored in the attributes of the nodes. 

The function *reinsertion* calculates these costs for each node using the function *calculate_costs*, finds the optimal node with *find_cheapest_node* (minimum total moves) and applies the required movements. After that, it both stacks rotate in the same direction, the function *rotate_both* is used; if rotations are in opposite direction, *rotate_single* is used.

Finally, *return_a_to_origin* rotates stack A so that the smallest element (lowest index) is at the top.

# Resources

GeeksforGeeks. (2025). *Longest increasing subsequence (LIS)*. https://www.geeksforgeeks.org/dsa/longest-increasing-subsequence-dp-3/

CP-Algorithms. (2025). *Longest increasing subsequence*. https://cp-algorithms.com/dynamic_programming/longest_increasing_subsequence.html

st-yes. (2022). *42push_swap* [GitHub repository]. https://github.com/st-yes/42push_swap

Ayogun, A. (2022). *Push Swap — A journey to find most efficient sorting algorithm*. https://medium.com/@ayogun/push-swap-c1f5d2d41e97

Red Hat. (n. d.). *Example: Building a C program using a Makefile*. https://docs.redhat.com/es/documentation/red_hat_enterprise_linux/8/html/developing_c_and_cpp_applications_in_rhel_8/example-building-a-c-program-using-a-makefile_managing-more-code-with-make

After testing different approaches in which the number of movements exceeded the project’s minimum requirements, the AI was used to determine which type of logic would be more efficient in minimizing the number of movements.