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

## Data and Corresponding Slurm Numbers:

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

## Running:
1. We ran this code using [bridges 2](https://www.psc.edu/resources/bridges-2/) we recommend you do the same
2. Edit the batch_script files by entering: <Username>, <Inputfile> and <Outputfile> into the given spaces
3. We compile in the batch scripts but you can also compile using the following lines: <br>
  ` nvc++ -acc -gpu=cc70 -Minfo=accel iterative_traversal.cpp -o iterative`  <br>
  ` nvc++ -ta=multicore -Minfo=accel iterative_traversal.cpp -o iterative`  <br>
  ` nvc++ parallel_traversal.cpp -mp=multicore -Minfo=mp -o parallel`  <br>
4. Example of running the code:  <br>
  `nvc++ -acc -gpu=cc70 -Minfo=accel iterative_traversal.cpp -o iterative` <br>
  `sbatch batch_script_GPU_ACC`
  
## Resources:
### Code From:
- https://www.techiedelight.com/inorder-tree-traversal-iterative-recursive/
- https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/ 
### Literature:
- OpenMP Tasks: http://web.engr.oregonstate.edu/~mjb/cs575/Handouts/tasks.1pp.pdf
- Ray tracing: https://developer.nvidia.com/blog/thinking-parallel-part-ii-tree-traversal-gpu/
- C# Tasks: https://docs.microsoft.com/en-us/dotnet/standard/parallel-programming/how-to-traverse-a-binary-tree-with-parallel-tasks
- Breadth-first and Depth-first:  https://link.springer.com/content/pdf/10.1007%2F3-540-53504-7_97.pdf 



