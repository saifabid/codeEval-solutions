#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*
https://www.codeeval.com/open_challenges/57/
*/



int toInt(char* val) {

    int m;
    char *q=val;
    while (isdigit(*q)) {
        q++;
    }
    *q='\0';

    //puts (val);

    sscanf(val,"%d",&m);
    return m;
}
char toChar(char* val) {
    char ret;
    sscanf (val,"%c",&ret);

    return ret;

}
void fillInt(char *p,int numRow,int numCol,int i,int j,char *line,int list[numRow][numCol]) {

    while (i<numRow) {

        while (j<numCol) {
            int flag=0;
            char neg;
            if (*p) {
                sscanf (p,"%c",&neg);


                if (neg=='-') {
                    p++;
                    flag=1;
                    neg='a';

                }
            }

            if (isdigit(*p)) {

                int m=toInt(p);

                if (m!=0) {
                    int n = floor(log10(abs(m))) + 1;
                    p=p+(n-1);
                }

                if (flag) {

                    flag=0;
                    m=m*-1;
                }
                list[i][j]=m;
                j++;

            }
            p++;

        }

        j=0;
        i++;


    }


    int x=0;
    int y=0;
    int k=0;
    int total=numRow*numCol; // 8
    int m=-1;
    int rev=0;
    //START COPY
    int basei=0;
    int basej=0;
    int  topLeft=0; //0
    int topRightx=numCol-1; // 1
    int topRighty=0; // 0

    int bottomLeftx=0; // 0
    int bottomLefty=numRow-1;//3
    int q=0;

    int bottomRightx=numCol-1; //1
    int bottomRighty=numRow-1;//3






    while(total) {


        /*
        run 1:
          y=0,x=0
          try=0 trx=1
          loop1 : valid, x=0 prints 1, x=1 prints 2 x=2 BREAK;
          x=1 y=1
          bry=3 brx=1;
          loop2: valid print()

        */

        while (y==topRighty && x<=topRightx)
        {
            if (total-1==0) {
                printf("%d",list[y][x]);
            }
            else  printf("%d ",list[y][x]);
            x++;
            total--;

        }
        if (total==0) {

            break;
        }
        x--;
        y++;

        while(y<=bottomRighty && x==bottomRightx) {
            if (total-1==0) {
                printf("%d",list[y][x]);
            }
            else  printf("%d ",list[y][x]);
            y++;
            total--;

        }
        if (total==0) {
            break;
        }

        x--;
        y--;
        while(y==bottomLefty && x>=bottomLeftx) {
            if (total-1==0) {
                printf("%d",list[y][x]);
            }
            else  printf("%d ",list[y][x]);
            x--;
            total--;

        }
        if (total==0) {
            break;
        }
        x++;
        y--;
        while(y>topLeft) {
            if (total-1==0) {
                printf("%d",list[y][x]);
            }
            else  printf("%d ",list[y][x]);
            y--;
            total--;

        }
        if (total==0) {
            break;
        }

        if (total==0) {
            break;
        }

        topRightx--;
        topRighty++;
        topLeft++;
        bottomLeftx++;
        bottomLefty--;
        bottomRightx--;
        bottomRighty--;

        x=topLeft;
        y=topLeft;



    }


}

void fillChar(char *p,int numRow,int numCol,int i,int j,char *line,char list[numRow][numCol]) {
    while (i<numRow) {

        while (j<numCol) {


            if (isalpha(*p)) {

                char m=toChar(p);




                list[i][j]=m;
                j++;

            }
            p++;

        }

        j=0;
        i++;

    }

    /*
    int qq=0;
    int jj=0;
    while (qq<numRow){
      while(jj<numCol){
        printf("%c  ",list[qq][jj]);
        jj++;
      }
      jj=0;
      qq++;
      printf("\n");

    }

    */





    int x=0;
    int y=0;
    int k=0;
    int total=numRow*numCol;
    int m=-1;
    int rev=0;

    int basei=0;
    int basej=0;
    int  topLeft=0;
    int topRightx=numCol-1;
    int topRighty=0;

    int bottomLeftx=0;
    int bottomLefty=numRow-1;
    int q=0;

    int bottomRightx=numCol-1;
    int bottomRighty=numRow-1;






    while(total) {


        while (y==topRighty && x<=topRightx)
        {
            if (total-1==0) {
                printf("%c",list[y][x]);
            }
            else  printf("%c ",list[y][x]);
            x++;
            total--;

        }

        x--;
        y++;

        while(y<=bottomRighty && x==bottomRightx) {
            if (total-1==0) {
                printf("%c",list[y][x]);
            }
            else  printf("%c ",list[y][x]);
            y++;
            total--;

        }
        if (total==0) {
            break;
        }

        x--;
        y--;
        while(y==bottomLefty && x>=bottomLeftx) {
            if (total-1==0) {
                printf("%c",list[y][x]);
            }
            else  printf("%c ",list[y][x]);
            x--;
            total--;

        }
        if (total==0) {
            break;
        }
        x++;
        y--;
        while(y>topLeft) {
            if (total-1==0) {
                printf("%c",list[y][x]);
            }
            else  printf("%c ",list[y][x]);
            y--;
            total--;

        }
        if (total==0) {
            break;
        }

        if (total==0) {
            break;
        }

        topRightx--;
        topRighty++;
        topLeft++;
        bottomLeftx++;
        bottomLefty--;
        bottomRightx--;
        bottomRighty--;

        x=topLeft;
        y=topLeft;



    }



}




int main(int argc,char **argv) {


    char * file_name=argv[1];

    FILE * f=fopen(file_name,"r");
    char line[1000];
    int test=0;
    char* digp=&line[0];

    while (fgets(line,1000,f)) {

        if (test) {
            printf ("\n");
        }

        int numRow=toInt(&line[0]);
        if (numRow!=0) {
            int n = floor(log10(abs(numRow))) + 1;
            test=n;
        }

        int numCol=toInt(&line[test+1]);


        /*
          printf ("numCol:%d\n",numCol);
          printf("numRow:%d\n",numRow);
        */


        int list[numRow][numCol];
        char list2[numRow][numCol];

        int i=0;
        int j=0;
        char *p=&line[test+3];

        if (isdigit(*p)) {
            fillInt(p,numRow,numCol,i,j,line,list);
        }
        else {
            fillChar(p,numRow,numCol,i,j,line,list2);
        }
        test++;

    }




}
