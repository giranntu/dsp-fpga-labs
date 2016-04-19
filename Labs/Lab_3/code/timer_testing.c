#include <sys/time.h>// for timer related structs and setitimer()
#include <stdio.h>   // for printf
#include <string.h>  // for memset
#include <signal.h>  // for sicaction
#include <stdlib.h>
//#include <time.h>

struct sigaction sa;
struct itimerval timer;

int y_2 = -2; // y(-2); -sin(2wT) initially 
int y_1 = -1; // y(-1); -sin(wT) initially
int currentCoeff = 5; // reset every 1 second 
int coeff_1_2k = 5; // precomputed 2cos(wT) = 2cos(2*pi*f/Fs)
int coeff_2_4k = 5; // precomputed 2cos(wT) = 2cos(2*pi*f/Fs)
// y(-2) = -sin(2wT)
// y(-1) = -sin(wT)
// y(n)  = A y(n - 1) - y(n - 2)
//       = 2cos(wT) y(n - 1) - y(n - 2)

// w = 2pi f
// T = 1 / Fs

void timer_Init();
void handler(int whatever);
void leftready();

void leftready() {
  // compute y(n)
  // y_2 = y_1;
  // y_1 = y(n);
  // output y(n)
  printf("left out = %d\n", currentCoeff);
}


int main(int argc, char** argv) {
  timer_Init();
  //time_t t;
  //srand(time(&t));
  srand(time(NULL));
  while (1);
}

void handler(int whatever) {
  int r = rand() % 100;
  printf("r = %d\n", r);
  if (r < 50) {
    printf("playing 2.4 kHz sinusoid\n");
    freq = 2400;
  } else {
    printf("playing 1.2 kHz sinusoid\n");
    freq = 1200;
  }
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
