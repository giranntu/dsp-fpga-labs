#include <sys/time.h>// for timer related structs and setitimer()
#include <stdio.h>   // for printf
#include <string.h>  // for memset
#include <signal.h>  // for sicaction

struct sigaction sa;
struct itimerval timer;

void timer_Init();
void handler(int whatever);

int main(int argc, char** argv) {
  timer_Init();
  while (1);
}

void handler(int whatever) {
  printf("hi\n");
}

void timer_Init() {
  memset (&sa, 0, sizeof (sa));  // set null character to first sizeof(sa) buffers in sa
  sa.sa_handler = &handler;
  sigaction(SIGVTALRM, &sa, NULL);

  /* Configure the timer to expire after 2 sec... */
  //timer.it_value.tv_sec = 0;
  timer.it_value.tv_usec = 1; // micro second
  /* ... and every 333 msec after that. */
  timer.it_interval.tv_sec = 1; // every 1 second
  //timer.it_interval.tv_usec = 0;
  /* Start a virtual timer. It counts down whenever this process is
  *      executing. */
  setitimer (ITIMER_VIRTUAL, &timer, NULL);
}
