VE 482 Project 2 Lottery Scheduling
--------------------------------------
Introduction:
The goal of this project is change MINIX 3 scheduling algorithm to lottery scheduling. The implementation is based on MINIX 3.2.1.

Refer:
github.com/lastland/MINIX-3.1.7-Lottery-Scheduler
github.com/bhupeshrajs/Minix-Scheduler-Implementation-And-Analysis
wiki.minix3.org/doku.php?id=developersguide:userspacescheduling

Modified Files:
src/include/minix/config.h
src/servers/sched/schedproc.h
src/servers/sched/schedule.c
src/servers/sched/proto.h
src/servers/pm/schedule.c

Design:
Because the implement of scheduling in MINIX 3.2.1 is in user space, so we could change the implementation of scheduling algorithm.
We just want to change the user process. We will keep system process unchanged.
The process will be managed by process manager.
Process manager will schedule the process in /pm/schedule.c, we modified schedule_process() to make the input from nice command transfer to /sched/schedule.c .
It will help us to distribute tickets.
Now for a user process, nice value is its tickets numbers.
Then we generate a random number in 0 to total tickets number. And if the current process has more tickets than this number, it will be promoted to higher priority queue. It means it will first be executed.
Then after one quantum, the process priority will be reduced by 1 (back to USER_Q priority).
Then after each quantum, each finshed process or each do_nice action, we will call do_lottery() to decide which process to run next.

Test Case:
compile test.c in MINIX with 
cc -o test test.c
execute it
nice -n -5 ./test a & nice -n 10 ./test b &
You could find before b finished, a is rearly executed, because a has 10-5=5 tickets, while b has 10+10=20 tickets.

2016 Fall