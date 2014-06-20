#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LENGTH_OFFSET 2
#define LAST_ELEMENT_OFFSET 4
#define SPACE_OFFSET 2

int main(int argc, char **argv){
  char *file_name=argv[1];
  int q=1;
  //puts (file_name);

  FILE* f=fopen(file_name,"r");

  char list[1000];
// a b c 4
  while (fgets(list,1000,f)){
    int flag=0;
    int len=strlen(list);
    int i=0;
    int m;
    while (i<len){

       char num;
      sscanf(&list[i],"%c",&num);
    //  printf ("NUM IS %c\n",num);
      if (num=='-'){
      //  puts ("negative detected");
        flag=1;
        break;


      }
      if (isdigit(list[i])){
      //  puts ("inloop");
        char *p=&list[i];
        sscanf(p,"%d",&m); // m now has which element we want
      //  printf ("THE NUMBER IS %d\n\n\n\n",m);
        break;

      }
      i++;
    }
    if (flag){
    //  printf ("Skillping line: %d\n",q);
      q++;
      continue;
    }
    if (m>9){
      len=len-1;
    }
    int last=len-LAST_ELEMENT_OFFSET;
    if (((m*SPACE_OFFSET)>(last+2))){
    //  printf ("Skillping line: %d\n",q);
      q++;
    continue;

    }
    else if (m<=0){
    //  printf ("Skillping line: %d\n",q);
      q++;
      continue;
    }
    //printf ("The calculation length is:%d want=%d-(%d)*(%d) + %d\n",len,last,m,SPACE_OFFSET,LENGTH_OFFSET);
    int want=last-(m*SPACE_OFFSET)+LENGTH_OFFSET;
    int val;

  //  printf ("line number : %d ------->  %c\n",q,list[want]);
    printf ("%c\n",list[want]);
    q++;
  }






}
