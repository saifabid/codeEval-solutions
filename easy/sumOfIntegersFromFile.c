#include <stdio.h>



int toInt(int c){
  int val=c-'0';
  return val;
}

int main(int argc, char **argv){

char * file_name=argv[1];
FILE *f = fopen(file_name, "r");
char num[100];
int sum=0;
int i=0;
int num_array[100];

while (fgets(num,100,f)!=NULL){

sscanf(num,"%d",&num_array[i]);

sum=sum+num_array[i];
i++;

}
printf ("%d",sum);
}
