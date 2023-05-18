# Philosophers-
introduction to threads and mutexes 
https://www.codequoi.com/en/threads-mutexes-and-concurrent-programming-in-c/

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

# some useful function you may need to understand the project !

## gettimeofday

represented as follow : int gettimeofday(struct timeval *tv, struct timezone *tz);

The gettimeofday function in C is used to retrieve the current time and date with high precision. It is declared in the <sys/time.h> header file 

Here's a breakdown of the function parameters:

tv: A pointer to a struct timeval that will be filled with the current time information.
tz: A pointer to a struct timezone that is no longer used and can be set to "NULL" (passing NULL is generally safe).

The struct timeval is defined as follows:

struct timeval {
    time_t tv_sec;      // seconds
    suseconds_t tv_usec;   // microseconds
};

The tv_sec field represents the number of seconds since the UNIX epoch (January 1, 1970), and tv_usec represents the additional microseconds within the current second.
The gettimeofday function returns 0 on success and -1 on failure. If an error occurs, you can examine the value of the errno variable to determine the specific error condition.
