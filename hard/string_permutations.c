#include <stdio.h>
#include <string.h>

char * shiftRight (char* line, int len){
  int i=0;
  int j=1;
  char temp2;
  char temp[len];

  strcpy(temp,line);



  while (j<len){
      temp[j]=line[i];
      j++;
      i++;
      if (j==len-1){
        temp[0]=line[j];
      }




  }
strcpy(line,temp);
  puts (temp);







}




int fact(int num){

puts ("running this");
  if (num==0){
    return 1;
  }

  else {
    return fact(num-1)*num;
  }


}






char * chooseSelect(char *line, int len){

  char *a =strdup(line);
  char* b=strdup(line);
  int j=0;
  int i=0;

  while (j<len){


    char *p=a;







  }


















}

int main(int argc, char **argv){
  char *file_name=argv[1];
  printf ("The file to open is %s\n",file_name); // remove for final
  FILE* f=fopen(file_name,"r"); // f looks at the file;
  char line[100];
  int len=0;

  while (fgets(line,100,f)){
      len=strlen(line)-1; // -1 becasue of new line
      printf ("The line is %d char long\n ",len); // remove for final
      char * permutations[1000];
      char *line_temp;
      line_temp=strdup(line);
      int i=0;
      int j=0;

      while (i<len){
        permutations[i]=shiftRight(line,len);

        i++;
      }

      int rem=fact(len)-i;
      printf ("REMAINING IS %d\n",rem);


       while (i<rem){
         permutations[i]=chooseSelect(line_temp,len);
       }


  }



}
