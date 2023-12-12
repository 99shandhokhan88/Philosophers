# Philosophers

The Philosophers project is an implementation of the classic Dining Philosophers Problem in the C programming language. This multithreaded simulation involves philosophers sitting around a dining table, each alternating between thinking and eating. The challenge lies in coordinating their actions to prevent conflicts and deadlocks while sharing limited resources (forks).


## Project Overview:
### Dining Philosophers Problem:

The project revolves around solving the classical dining philosophers problem, a synchronization and concurrency problem.
The scenario involves a certain number of philosophers sitting around a dining table, each thinking and eating.
Philosophers must follow specific rules to avoid conflicts and ensure fair access to resources (forks).

### Concurrency:

Multiple threads are used to model the philosophers and their activities concurrently.
Each philosopher is represented by a thread, and various synchronization mechanisms (mutex locks) are employed to manage shared resources.

## Project Components:

### Philosopher Threads:

Each philosopher is represented by a thread executing a routine that includes eating, thinking, and sleeping.

### Monitor Thread:

A monitor thread is used to keep track of the progress of the philosophers.
It checks whether each philosopher has eaten a certain number of times and signals when all philosophers have finished eating.

### Supervisor Thread:

Another thread, called the supervisor, monitors the activity of each philosopher to detect if a philosopher takes too long to eat (indicating a potential deadlock or issue).
Rules and Constraints:

### Resource Sharing:

Philosophers share resources (forks) to eat.
Careful synchronization is required to prevent conflicts and deadlocks.

### Eating Limits:

Philosophers have a limited number of meals they can eat.
The program should terminate when all philosophers have finished eating the specified number of meals.

### Time Constraints:

There are time constraints to detect when a philosopher takes too long to eat, indicating a potential issue.

## Key Points and Solutions

### 1. Concurrency Challenges
Problem: Coordinating actions of multiple philosophers concurrently.
Solution: Leveraging multithreading and synchronization techniques with mutexes to control access to shared resources.

### 2. Resource Sharing
Problem: Philosophers must share forks to eat but avoid conflicts.
Solution: Using mutexes to control access to forks, ensuring exclusive use and preventing multiple philosophers from attempting to pick up the same fork simultaneously.

### 3. Deadlock Avoidance
Problem: Possibility of deadlocks when philosophers hold one fork and wait indefinitely for another.
Solution: Implementing strategies to avoid deadlocks, such as ensuring philosophers pick up both forks simultaneously or releasing forks if unable to acquire both.

### 4. Simulation of Activities
Problem: Simulating activities like eating, thinking, and sleeping.
Solution: Utilizing functions to print messages with ANSI color codes for clarity and realism, and incorporating delay functions to simulate sleeping and eating durations.


## Key Components:

### Philosopher Struct:

Each philosopher is represented by a t_philo struct, which includes attributes such as their name, the number of meals eaten, the state of currently eating, and references to left and right forks.

### Chef Struct:

The t_chef struct represents the orchestrator or chef overseeing the dining philosophers. It includes details like the number of philosophers, time constraints for eating, sleeping, and dying, as well as information about the program's state.

### Mutexes:

Mutexes are utilized to control access to shared resources, specifically the forks. Each philosopher has a pair of forks on their left and right, and mutexes ensure that only one philosopher can pick up a fork at a time.

### Threaded Execution:

Each philosopher is a separate thread, and the chef manages their interaction. Threads are created for each philosopher, and synchronization is crucial to ensure they follow the rules (e.g., picking up both forks simultaneously).

### Simulation of Activities:

Philosophers alternate between thinking, eating, and sleeping. ANSI color codes are used to enhance the visualization of activities in the console output.

### Deadlock Avoidance:

Strategies are implemented to prevent deadlocks, such as releasing forks if a philosopher cannot acquire both simultaneously.


## Program Flow:

### Initialization:

The program initializes the chef, philosophers, forks, and other necessary components.

### Thread Creation:

Threads are created for each philosopher, each running the philo_routine function.

### Philosopher Routine:

The philo_routine function is the main routine for philosophers, where they engage in thinking, eating, and sleeping activities.

### Activity Simulation:

Activities are simulated with the help of mutexes to coordinate access to shared resources.

### Deadlock Avoidance:

Deadlock avoidance strategies are applied to prevent situations where philosophers could be indefinitely blocked.

### Chef's Routine:

The chef's routine (the_routine) monitors the philosophers' activities and decides when the program should terminate based on completion conditions.


## How to Run:

### Compile:

Use the provided Makefile to compile the program.
```c
make
```

### Run:

Execute the compiled program, specifying the number of philosophers and other parameters.
```c
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> <number_of_times_each_philosopher_must_eat(optional argument)>
```
