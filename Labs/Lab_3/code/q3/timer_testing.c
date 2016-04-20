#include <sys/time.h>// for timer related structs and setitimer()
#include <stdio.h>   // for printf
#include <string.h>  // for memset
#include <signal.h>  // for sicaction
#include <stdlib.h>
//#include <time.h>

struct sigaction sa;
struct itimerval timer;

// TODO: maybe multiply these values by 1000 like in lab 2 to use it as ints
int y_2_1200 = -0.4540; // y(-2) for 1.2 kHz; -sin(2wT) initially 
int y_1_1200 = -0.2334; // y(-1) for 1.2 kHz; -sin(wT) initially
int y_2_2400 = -0.4540; // y(-2) for 2.4 kHz; -sin(2wT) initially 
int y_1_2400 = -0.8090; // y(-1) for 2.4 kHz; -sin(wT) initially
int coeff_1_2k = 1.9447; // precomputed 2cos(wT) = 2cos(2*pi*f/Fs)
int coeff_2_4k = 1.7820; // precomputed 2cos(wT) = 2cos(2*pi*f/Fs)

// just set it to 1.2 kHz data for now
int current_y_2 = y_2_1200;
int current_y_1 = y_1_1200;
int currentCoeff = coeff_1_2k; // reset every 1 second 
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
  // 1. compute y(n)
  // 2. y_2 = y_1;
  // 3. y_1 = y(n);
  // 4. output y(n)
  int y_n = currentCoeff * current_y_1 - current_y_2;
  current_y_2 = current_y_1;
  current_y_1 = y_n;
  printf("left out = %d\n", y_n);
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
    printf("playing 1.2 kHz sinusoid\n");
    current_y_2 = y_2_1200;
    current_y_1 = y_1_1200;
    currentCoeff = coeff_1_2k; // reset every 1 second 
  } else {
    printf("playing 2.4 kHz sinusoid\n");
    current_y_2 = y_2_2400;
    current_y_1 = y_1_2400;
    currentCoeff = coeff_2_4k; // reset every 1 second 
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
