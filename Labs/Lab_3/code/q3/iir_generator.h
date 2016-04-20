#include <sys/time.h>// for timer related structs and setitimer()
#include <string.h>  // for memset in timer_Init
#include <signal.h>  // for sicaction
#include <stdlib.h>

struct sigaction sa;
struct itimerval timer;

// y(-2) = -sin(2wT)
// y(-1) = -sin(wT)
// y(n)  = A y(n - 1) - y(n - 2)
//       = 2cos(wT) y(n - 1) - y(n - 2)
// w = 2pi f
// T = 1 / Fs

// TODO: maybe multiply these values by 1000 like in lab 2 to use it as ints
int y_2_1200 = -0.4540; // y(-2) for 1.2 kHz; -sin(2wT) initially 
int y_1_1200 = -0.2334; // y(-1) for 1.2 kHz; -sin(wT) initially
int A_1200 = 1.9447; // precomputed 2cos(wT) = 2cos(2*pi*f/Fs)

int y_2_2400 = -0.4540; // y(-2) for 2.4 kHz; -sin(2wT) initially 
int y_1_2400 = -0.8090; // y(-1) for 2.4 kHz; -sin(wT) initially
int A_2400 = 1.7820; // precomputed 2cos(wT) = 2cos(2*pi*f/Fs)

// just set it to 1.2 kHz data for now
int current_y_2 = 0;
int current_y_1 = 0;
int A = 0; // reset every 1 second

int y_n = 0;

static void timer_Init();
static void handler(int whatever);
