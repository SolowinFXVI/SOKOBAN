#include <stdio.h>
#include <stdlib.h>
#include "sokoban.h"
#include "constantes.h"
#include <string.h>
#include <time.h>


int largeur_niveau(){
return 100;
}

int hauteur_niveau(){
  return 100;
}

SOKOBAN lire(char* str){
  SOKOBAN S;
  int x = 0;
  int y = 0;
  int j,k;
  int c;
  FILE *fic = fopen(str ,"r");

  if (fic == NULL){
    printf("echec ouverture fichier%s\n",str );
    exit(EXIT_FAILURE);
  }

  char rip[300];

/*  while ((c = fgetc(fic)) != EOF){

      if(c == 10){
        y++;
      }
      S.une_case[x][y].val=c;
      if(c == 10){
        //printf("\n");
      }


      //sprintf(rip, "%d", c);

      //printf("%s ",rip);
  }*/

char rts[300];
sprintf(rts, "%d", 42);
  /*for(y = N-1; y>=0;y--){
    for(x = 0; x < N; x++){
      fscanf(fic,"%s",buffer);
      fgets(buffer,2,fic);
      printf("Contenu du fichier=%s\n",buffer);
      S.une_case[x][y].val = buffer;
      printf("Contenu val=%s\n",S.une_case[x][y].val);


      fscanf(fic,"%s ",&k);
			S.une_case[x][y].val=k;
      printf("%s\n",S.une_case[x][y].val);
      i++;
      printf("i= %d\n",i);
  }
}*/


  /*while(k[i] != ';'){
    printf("pass =%d\n",i);
    i++;
  }*/
  //printf("val = %s",&S.une_case[1][1].val);
  fclose(fic);
  return S;
}
