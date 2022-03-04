# PHILOSOPHERS

School 21 (Ecole42) 'Philosophers' project. 
Score 100/100. Passed 2022/01/14

In this project, I have learned the basics of threading a process, how to create threads and what is the mutexes.

The programm solves the problem of dining philosophers: https://en.wikipedia.org/wiki/Dining_philosophers_problem

It uses threads instead philosophers and mutexes instead forks. Other main rules:

* A number of philosophers are sitting at a round table doing one of three things: eating, thinking or sleeping.
* While eating, they are not thinking or sleeping, while sleeping, they are not eating or thinking and of course, while thinking, they are not eating or sleeping.
* The philosophers sit at a circular table with a large bowl of spaghetti in the center.
* There are some forks on the table.
* As spaghetti is difficult to serve and eat with a single fork, it is assumed that a philosopher must eat with two forks, one for each hand.
* The philosophers must never be starving.
* Every philosopher needs to eat.
* Philosophers don’t speak with each other.
* Philosophers don’t know when another philosopher is about to die.
* Each time a philosopher has finished eating, he will drop his forks and start sleeping.
* When a philosopher is done sleeping, he will start thinking.
* The simulation stops when a philosopher dies.
* Each program should have the same options: number_of_philosophers time_to_die time_to_eat time_to_sleep (not necessary, but shoul be implemented - number_of_times_each_philosopher_must_eat)


# USAGE

clone this repository

git clone https://github.com/RGaneeva/05_Philosophers-School21.git

then

| command | result |
|:----|:----|
| make | compile philosophers project |
| make clean | clean .o files |
| make fclean | clean .o and .a files |

Example of using programm:

./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]

> ./philo 5 800 200 200

no one should die

> ./philo 5 800 200 200 7

no one should die and the simulation should stop when all the philosopher has eaten 7 times

> ./philo 4 410 200 200

no one should die

> ./philo 4 310 200 100

a philosopher should die


# RESOURCES

Unix Threads in C, playlist by CodeVault: https://www.youtube.com/playlist?list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2

Multithreaded Programming: https://randu.org/tutorials/threads/

Столяров А.В. Введение в операционные системы: http://www.stolyarov.info/static/pdf/osintro.pdf
