#include "compress.h"
#include <string.h>
int main(int argc, char *argv[]){

  if(argc != 3){
    printf("Usage: %s -c,d <input file>\n", argv[0]);
    return 1;
  }

  if(strcmp(argv[1], "-c") == 0){
    //check if file name ends with .txt
    if(strstr(argv[2], ".txt") == NULL){
      printf("Invalid file type\n");
      return 1;
    }
    encode(argv[2]);
  } else if(strcmp(argv[1], "-d") == 0){
    //check if file name ends with .bin
    if(strstr(argv[2], ".bin") == NULL){
      printf("Invalid file type\n");
      return 1;
    }
    decode(argv[2]);
  }
return 0;
}