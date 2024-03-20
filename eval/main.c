#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
  char input[100];
  printf("Ingrese la expresion: ");
  fgets(input, 100, stdin);

  if(input == NULL){
    printf("Error no se proporciono ningun input");
    return 1;
  }

  if (strstr(input, "==") != NULL && strstr(input, "=") == strstr(input, "==")) {
    printf("Error: No puede haber '==' en lugar de '='.\n");
    return 1; 
  }

  if (strstr(input, "==") != NULL && strstr(input, "=") == strstr(input, "==")) {
    printf("Error: No puede haber '==' en lugar de '='.\n");
    return 1; 
  }

  if(strncmp(input, "ABRIR ", 6) != 0 || strncmp(input + strlen(input) -7, " CERRAR", 7) != 0){
    puts("La cadena no es valida, el input debe empezar en ABRIR y terminar en CERRAR");
    return 1;
  }

  char* equalSignPos = strstr(input, "=");
  char* operatorPos = strpbrk(input, "<>!=");
  if (equalSignPos == NULL || (operatorPos != NULL && operatorPos < equalSignPos)) {
    printf("Error: Falta el '=' antes del operador.\n");
    return 1; 
  }

  char* expr = (char*)malloc(strlen(input) - 12);
  strncpy(expr, input + 6, strlen(input) - 13);
  expr[strlen(input) - 13] = '\0';

  char word[50];
  int num1, num2;
  char op[3];
  if(sscanf(expr, "%[^=]=%d%[^0-9]%d", word, &num1, op, &num2) != 4 || 
  (strcmp(op, "<") != 0 && strcmp(op, ">" != 0) && strcmp(op, "=") != 0 && strcmp(op, "!=") != 0 && strcmp(op, "==") != 0)){
    puts("La cadena no es valida, se debe ingresar algun operador valido ["<", ">", "==", "!="].");
  } else {

    if (strcmp(op, "<") == 0)
    {
      if(num1 > num2){
        puts("Operacion correcta");
      } else {
        printf("Operacion incorrecta, %d no es mayor que %d", num1, num2 );
      }
    } else if (op == "<"){
      if(num1 < num2){
        puts("Operacion Correcta");
      } else {
        printf("Operacion incorrecta, %d no es menor que %d", num1, num2 );
      }
    } else if (op == "=="){
      if(num1 == num2){
        puts("Operacion Correcta");
      } else {
        printf("Operacion incorrecta, %d no es igual que %d", num1, num2 );
      }
    } else if (op == "!="){
      if(num1 != num2){
        puts("Operacion Correcta");
      } else {
        printf("Operacion incorrecta, %d no es diferente a %d", num1, num2 );
      }
    }
    

    puts("La cadena es valida");

    FILE *doc = fopen("output.txt", "w");

    if(doc == NULL){
      puts("Error al abrir el archivo");
      return 1;
    }

    fprintf(doc, "Variable: %s\n", word);
    fprintf(doc, "Primer numero: %d\n", num1);
    fprintf(doc, "Operador: %s\n", op);
    fprintf(doc, "Segundo numero: %d\n", num2);

    fclose(doc);
  }


  free(expr);
  return 0;
}