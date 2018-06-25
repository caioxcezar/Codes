#include <stdio.h>

int main() {

int i;

for(i = 0; i < 26; i++){

printf("%c = %d | %c = %d \n",'A'+i,'A'+i,'a'+i,'a'+i);

}

getchar();

return 0;

}
