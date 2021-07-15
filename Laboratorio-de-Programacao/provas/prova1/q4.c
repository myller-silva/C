    #include <stdio.h>
    #include <math.h>

    int main(){
        int separar, n0=0, nf=0, resto=0;
        printf("Digite um nº de 1 byte  ");
        scanf("%d", &n0);

        for(int cont=0, c=7; cont<8 && c>=0; cont++, c--){
            resto= n0%16;
            separar = resto * pow(16, c);
            n0 /= 16;
            if( (c==2) || (c==3)){
                continue;
            }
            else{
                    resto < 10  ?  printf("%i", resto):
                    resto==10   ?  printf("%i"):
                    resto==11   ?  printf("%i"):
                    resto==12   ?  printf("%i"):
                    resto==13   ?  printf("%i"):
                    resto==14   ?  printf("%i"):
                    resto==15   ?  printf("%i"): -1;
            }
        }
        return 0;
    } 