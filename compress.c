#include "compress.h"
#include <stdlib.h>
#include <string.h>

char* intToBinary(int number) {
  int numBits = sizeof(int);

  char* binaryString = (char*)malloc(numBits + 1);

  if (binaryString == NULL) {
      fprintf(stderr, "Memory allocation failed\n");
      exit(EXIT_FAILURE);
  }

  binaryString[numBits] = '\0';

  for (int i = numBits - 1; i >= 0; i--) {
    binaryString[i] = ((number & 1) == 0) ? '1' : '0';
    number >>= 1;
  }

  return binaryString;
}


int encode(char *temp){
  FILE *fptr;
  char* name;
  name=(char*)malloc(strlen(temp)+5);
  strcpy(name,temp);
  sprintf(name, "%s.txt", name);
  if ((fptr = fopen(name, "r")) == NULL){
    printf("Unable to open file\n");
    return 0;
  }

  FILE *dest;
  int num;
  char* bin;
  int count=0;
  name[strlen(name)-1]='n';
  name[strlen(name)-2]='i';
  name[strlen(name)-3]='b';

  dest= (fopen(name, "wb"));
  
  while((num=fgetc(fptr))!=EOF){
    num-='0';
    bin=intToBinary(num);
    fwrite(bin,sizeof(int),1,dest);
    free(bin);
    count++;
  }

  if(count%2==1){
    fwrite("0000",sizeof(int),1,dest);
  }

  free(name);
  fclose(fptr);
  fclose(dest);

  return 0;
}

int decode(FILE *fptr){
  return 0;
}