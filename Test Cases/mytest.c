#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>


int main()
  {
        int pid;
        printf("1");
        pid = fork();
        if (pid == 0) {
            execl("l1","l1","1","10000","100000","60",NULL);
        }
        printf("2");
        pid = fork();
        if (pid == 0) {
            execl("l2","l2","2","10000","100000","50",NULL );
        }
        printf("3");
        pid = fork();
        if (pid == 0) {
            execl("l3","l3","3","10000","100000","35",NULL);
        }
  }