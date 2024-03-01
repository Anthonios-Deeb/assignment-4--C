#include "compress.h"
#include <string.h>
int main(int args,char* argc){
  if(args!=3)
    return 1;

  
  if(strcmp(&argc[1],"-c")==1){
    char* name;
    char* test;
    test=&argc[2];
    for(int i=0;i<argc[2]&& test[i]!='.';i++){
      name[i]=test[i];
    }
    printf("%s",name);

   // encode(argc)
  }
  
  

}