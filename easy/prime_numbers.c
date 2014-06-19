//completed wednesday june 18th, 10pm
#include <stdio.h>

#define MAX_NUMBERS 1000


int main(){
  int i=1; // index
  int sum=0;
  int j=1;
  int curr_num=2; // a prime is anynumber greater than 1 so we start at 2
  int temp_count=0;


  while (i<=MAX_NUMBERS){ // keep track how how many prime numbers we have hit
  //  printf ("entering loop with curr_num %d\n",curr_num);

    while (j<=curr_num){ // to find if the number is a prime

    //  printf ("-------\nStarting %d check\n------\n",curr_num);
      int temp = curr_num/j;
      if ((temp*j)==curr_num){
      //  printf ("increasing temp count\n");
        temp_count++;
      }
    //  printf ("%d\n",temp_count);
      j++;
    }
  //  printf ("left loop\n");
    if (temp_count==2){
      //printf ("Found a prime ! this is the %d prime number : %d we found\n",i,curr_num);
      sum=sum+curr_num;

      i++;
    }
    temp_count=0;
    j=1;


    curr_num++;

  }

printf ("%d",sum);

return 0;

}
