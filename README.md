# In-Order BST tree traversal: Recursive, Iterative, Parallelized  
## Authors: 
Emily Oldham, Andrew McCracken

## Introduction: 
In this project we are looking into the inorder traversal algorithm. This algorithm can be implemented both recursively and iteratively. We first want to compare the difference in time between recursive and iterative implementations. From there, we would like to parallelize the iterative/recursive code to find a way to improve the performance as well as compare the performance across different sized trees. 

## Experimental Setup: 
- Language: C++
- System: Bridges 2
- Compiler: NVC++, Nvhpc/21.7
- Editor: Vi

## File Descriptions:
- License: Basic Licensing for our parallelization.
- batch_script_CPU_ACC: run this batch script to compile and run a program that traverses a BST using parallel OpenACC via CPU
- batch_script_GPU_ACC: run this batch script to compile and run a program that traverses a BST using parallel OpenACC via GPU
- batch_script_GPU_MP: run this batch script to compile and run a program that traverses a BST using parallel OpenMP via GPU
- iterative_traversal.cpp: c++ code to create and traverse a BST iteratively
- openACC.cpp: c++ code to create and traverse a BST parallely with OpenACC
- parallel_MP_traversal.cpp: c++ code to create and traverse a BST in parallel with OpenMP
- recursive_traversal.cpp: c++ code to create and traverse a BST recursively

## Data and corresponding slurm numbers:

### Data
|                 | Iterative | Recursive |        Iterative       | Recursive |
|-----------------|:---------:|:---------:|:----------------------:|:---------:|
| Height of Trees |    GPU    |           | Multicore CPU (1 core) |           |
| Small(5)        |  .000066  |  0.000084 |         .000066        |  .000056  |
| Medium(10)      |  .000121  |  .000156  |         .000170        |  .000126  |
| Large(15)       |  .002423  |  .002392  |         .003314        |  .002934  |

### Slurm Numbers
|                 | Iterative | Recursive |        Iterative       | Recursive |
|-----------------|:---------:|:---------:|:----------------------:|:---------:|
| Height of Trees |    GPU    |           | Multicore CPU (1 core) |           |
| Small(5)        |  5281968  |  5281462  |         5282001        |  5281933  |
| Medium(10)      |  5282022  |  5281523  |         5282042        |  5281529  |
| Large(15)       |  5282085  |  5281579  |         5282157        |  5281892  |

## How to run yourself: 

