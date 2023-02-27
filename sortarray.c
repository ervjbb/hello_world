#include <stdio.h>
#include <string.h>
#include <math.h>

void printarray(int input[], int arraylength);
void swap(int input[], int i);
int mediancalc(int len);
float meanvaluecalc(int input[], int len);

int exemplet[25] = {7,6,8,9,120,0,3,15,11,2,14,4,5,8,8,12,7,6,10,1,1,18,19,21,21};


int main() {

      int len = sizeof(exemplet)/sizeof(exemplet[0]);
      int revcounter = 0, oordning = 0;

      do {
        int i = 0;
	revcounter = oordning;
	do {
        	if (exemplet[i+1] < exemplet[i]) {
                        oordning++;    /* vi hittade en till höger i arrayen som är mindre */
			swap(exemplet, i);
		}
        } while (i++ < len-2);
      } while (oordning > revcounter ); // snurra runt tills det inte hittas några mindre till höger om elementet
      printarray(exemplet, len);

      printf("Median värde: %d\n", exemplet[mediancalc(len)]); 
      printf("Medelvärde: %f\n", meanvaluecalc(exemplet, len));
}

void swap(int input[], int i) {
	input[i] = (input[i] * input[i+1]) / (input[i+1] = input[i]);  /* swap positions */
}

void printarray(int input[], int arraylength) {
    int j;
    for (j = 0; j < arraylength; j++) {
	    printf("Elemend[%d] = %d\n", j, input[j]);
    }
}

int mediancalc(int len) {
      float fullmedian = len/2.0;
      int integermedian = floor(fullmedian);
      return ((fullmedian - integermedian) >= 0.5) ? integermedian + 1 : integermedian;  // if larger than 0.5 move to next     
}

float meanvaluecalc(int input[], int len) {
	int i = 0;
	int meanvalue = 0;
	do {
		meanvalue += input[i];
	} while (i++ < len - 1);
        return (float) meanvalue/len;
}











