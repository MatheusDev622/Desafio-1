#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main(){
    unsigned char armarios = 0;
    int comando = 0 ,opcao, armario_livre,posicao_aleatoria;
    srand(time(NULL));

    do{
     printf("Armarios: ");
     for(int i = 0;i<8;i++){
         if((armarios & (1 << i)) != 0){
            printf("1");
         }else{
            printf("0");
        }
     }
      printf("\n");
      printf("1.Ocupar armario\n");
      printf("2.desocupar armario\n");
      printf("3.sair\n");
      printf("Escolha a ação desejada: ");
      scanf("%d",&comando);
      switch (comando){
         case 1:
         if((armarios == 0xFF )){
            printf("Todos os armarios estão ocupados\n");
            break;
         }
          armario_livre = 0;
          while(armario_livre == 0){
             posicao_aleatoria = rand() % 8;
             if((armarios & (1 << posicao_aleatoria)) == 0){
                armario_livre = 1;
             }
          armarios |= (1 << posicao_aleatoria); 
          printf("armario %d foi ocupado!\n",posicao_aleatoria + 1);      
        }
          break;
         case 2:
          printf("informe o número do armario que deseja libera: ");
          scanf("%d",&opcao);
          if(opcao < 1 || opcao > 8){
             printf("Comando inválido\n");
          }else{
             armarios &= ~(1<<(opcao-1));
             printf("Armario %d foi liberado\n",opcao);
         }
          break;
         case 3:
          printf("Encerrando programa.");
          break;
         default:
          printf("Comando inválido!");
          break; 
     }
    
     }  while(comando != 3);
     return 0;
}