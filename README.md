# Repasos Fundamentos de Sistemas Operativos (Universidad Rovira i Virgili)

## Problems

#### Paralelization and synchronization
Programming paradigm which is a natural extension of the sequential programming paradigm. In this paradigm more than one execution threads are collaborating to compute an algorithm. In our case we will see two implementation of this paradigm: 
- Threading paralelization paradigm
- Process paralelization paradigm

Each has different characteristics regarding the level of abstraction from the execution context.

##### Threading
Every process has the ability to create new threads that will help him to perform its task. This threads are execution contexts that share the same heap (malloc) and initialized data (global variables). Threads can communicate with each other by using global variables, which are shared between threads or using locks, which is a binary semaphor that can only be unlocked by the thread that made the lock. 

##### Processes
Each process its completely independent from the other and do not share anything except the execution context at the moment of the process creation with a *fork()* call. Processes can communicate with each other by explicitly sharing a portion of allocated memory, using send / receive buffers or using semafors.


#### Memory management

#### Filesystems

#### Process scheduling
