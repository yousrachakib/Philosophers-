# Philosophers-
introduction to threads and mutexes 

 # I- all you need to know about threads :

In C programming, a thread refers to a sequence of instructions that can be executed independently of other parts of a program. Threads provide a way to achieve concurrent execution within a single program, allowing multiple tasks to be performed simultaneously.The concept of threads is based on the idea of multitasking, where different tasks or operations can be executed concurrently, sharing the same resources of a program. By using threads, you can divide a program into smaller, more manageable units of execution, each with its own set of instructions and data.

## 1.Including the Appropriate Header Files:
To work with threads in C, you need to include the appropriate header files. The most common header file is <pthread.h>, which provides the necessary functions, data types, and macros for thread creation and management.

## 2.Creating a Thread:
To create a thread, you typically follow these steps:

a. Define a function that represents the code to be executed by the thread. This function should have a void* return type and take a void* argument.

	void* threadFunction(void* arg) {
    // Code to be executed by the thread
    // ...
    return NULL;
	}

b. Declare a variable of type pthread_t to represent the thread.

pthread_t thread;

c. Use the pthread_create function to create the thread. This function takes the address of the thread variable, a thread attribute (usually NULL), the thread function, and an optional argument.

pthread_create(&thread, NULL,threadFunction,arg);

The new thread is now created and scheduled for execution.

## 3.Waiting for a Thread to Complete:
If you need to wait for a thread to complete its execution before continuing with the rest of the program, you can use the pthread_join function.

pthread_join(thread, NULL);

## 4.Thread Synchronization:
When multiple threads access shared data, synchronization mechanisms must be employed to prevent race conditions and ensure data consistency. Common synchronization techniques include mutexes, condition variables, and semaphores.

### Mutexes:
A mutex (short for mutual exclusion) is used to protect shared resources from concurrent access. You can use "pthread_mutex_t" to declare a mutex variable, and the functions "pthread_mutex_init", "pthread_mutex_lock", and "pthread_mutex_unlock" to initialize, lock, and unlock the mutex, respectively.

## 5.Compiling and Linking:
To compile a program that uses threads, you need to link it with the appropriate thread library. For POSIX Threads, you typically add the -pthread option during compilation.

gcc -o program program.c -pthread

