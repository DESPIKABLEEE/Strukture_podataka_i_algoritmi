//reverse
#include <stdio.h>
char* reverse(char* prvi, char* drugi){
    int brojac=0,j;
    for (j=0;prvi[j] != '\0'; j++){
        brojac++;
    }
    int i;
    for(i=0; prvi[i] != '\0';i++){
        drugi[brojac-1] = prvi[i];
        brojac--;
    }
    return drugi;

}

int main(){
    char* str1 = "Kopirano";
    char str2[20];
    char* rez = reverse(str1,str2);
    printf("%s",rez);
    return 0;
}
