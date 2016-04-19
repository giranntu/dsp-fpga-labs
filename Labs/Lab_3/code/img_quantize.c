#include <stdio.h>
#define SIZE 640*480*3 // 1D img size


// Read pixel by pixel and print value
int * quantize_file (const char * fname, int old, int new) {
	FILE* file = fopen (fname, "r");
	int i = 0;  // index
    int x = 0;  // pixel at index
    int s = old/new;
	int out[SIZE];   // quantized file
	
	for (i=0; i < SIZE; i++) {
 		fscanf (file, "%d", &x);
        int new_x = (x/s)*s + s/2 ;
		out[i] = new_x;
        printf("%d ", new_x);
//		printf ("%d -> %d\n", x, new_x);
 	}
	fclose (file);
    printf("\n\nConverted %d bits to %d bits\n", old, new);
	printf("Processed %d out of %d pixels\n", i, SIZE);
    return out;
}


int main(void) {
	char f[32] = "img.raw"; // input plaintext of ints
	int * out;
	int old_levels = 256;  // 8 bits
	int new_levels = 32;   // 16 bits

	printf("File :\t%s\n", f);
	out = quantize_file(f, old_levels, new_levels);
	return 0;
}

