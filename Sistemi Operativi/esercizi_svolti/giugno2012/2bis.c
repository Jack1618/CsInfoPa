#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<time.h>


int main(int argc, char *argv[]){
 int n=argc-1, i,  *numero, w;
 float x;
 pid_t padre, figlio;
 FILE *fp;

   if(argc<2){
     printf("Serve almeno un numero...");
      getchar();
   exit(-1);
  }
   numero=(int *)malloc(n*sizeof(int));
  
    for(i=0; i<n; i++){
     numero[i]=atoi(argv[i+1]);
     }
     padre=getpid();

       srand(time(NULL));
      fp=fopen("file.txt","w");
       for(i=0; i<(n-1); i++){
           figlio=fork();
          if(figlio==0){
             switch(rand()%3){
              case 0: x=numero[i]+numero[i+1]; break;
              case 1: x=numero[i]-numero[i+1]; break;
              case 2: x=numero[i]*numero[i+1]; break;
              case 3: x=numero[i]/numero[i+1]; break;
               }
            fprintf(fp,"%.2f ",x);
        exit(i);
          }
      }
   fclose(fp);
   fp=fopen("file.txt","r");
   if(padre){
   for(i=0; i<(n-1); i++){
     wait(&w);
   if(WIFEXITED(w)){
       fscanf(fp,"%f", &x);
        printf("%.2f ", x);
      }
    }
  }
 fclose(fp);
printf("\n");
exit(EXIT_SUCCESS);
}
