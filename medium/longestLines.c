#include <stdio.h>
#include <stdlib.h>


int strlength(char* array){
  int val=0;
  int spaces=0;
  while (*array!='\n'){
    if (*array==' '){
      array++;
      continue;
    }
    val++;

    array++;
  }
  return val;
}
int* sort (int* array,int max,int size){
  // sort

  int i=0;
  int j=1;
  int k=0;
  int val;
  while (k<size){
  while (i<size){

    while (j<size){
      if (array[i]<array[j]){
        int temp=array[j];
        array[j]=array[i];
        array[i]=temp;

      }

        break;


    }
    i++;
    j++;


  }
  k++;
  i=0;
  j=1;
}

return array;

}

int main(int argc, char **argv){

  char *file_name=argv[1];
//  printf ("The file name is %s\n",file_name);

  FILE* f=fopen(file_name,"r");

  char max[1000];
  int test;

  fgets(max,1000,f);
  sscanf(max,"%d",&test);
//  printf ("The number of lines asked for is %d\n\n",test);
char **arrays=(char**)malloc(sizeof(char*)*test);
int lengths[1000];
int j=0;
while (fgets(max,1000,f)!=NULL){
lengths[j]=strlength(max);
j++;

}


int k=0;



int *p=sort(lengths,test,j);

k=0;
while (k<j){
//  printf ("-------%d-----\n",p[k]);
  k++;
}


// p is the ordered list;

int i=0;
k=0;
int diz[test];
while (i<test){
  diz[i]=p[i];
  //printf ("THE TOP NUMBERS ARE : %d\n",diz[i]);
  i++;
}

i=0;
int m=0;
while (m<test){

  FILE* foo=fopen(file_name,"r");
  char final[1000];
  fgets(final,1000,foo);

while (fgets(final,1000,foo)!=NULL){

k=diz[i];
if (strlength(final)==k){
  printf ("%s",final);
  i++;
}
}
m++;
}







  return 0;
}
