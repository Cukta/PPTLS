#include "stdlib.h"
#include "stdio.h"
#include "time.h"
#include "ctype.h"
#include "string.h"

void imprimeOpciones(){
	printf("\nLas opciones son:\n\n");
	printf("\t1.- Piedra\n");
	printf("\t2.- Papel\n");
	printf("\t3.- Tijeras\n");
	printf("\t4.- Lagartija\n");
	printf("\t5.- Spock\n");
	printf("\n\t0.- Terminar secion\n");
	printf("\n\nEscoga una opcion:\t");
}

int computadora(){
	return (rand() % 5) + 1;
}

void resultados(int player, int comp, int *exe){

	char opciones[5][10];

	strcpy(opciones[0], "Piedra");
	strcpy(opciones[1], "Papel");
	strcpy(opciones[2], "Tijeras");
	strcpy(opciones[3], "Lagartija");
	strcpy(opciones[4], "Spock");

	if(player > 0 && player < 6){
		printf("\nUsted escogio:\t%s\n", opciones[player-1]);
		printf("\nLa computadora escogio:\t%s\n", opciones[comp-1]);
	}

	switch(player){
	case 0:
		*exe = 0;
		break;
	case 1:
		if(comp == 3 || comp == 4)
			printf("\n===Usted gano!!!===\n");
		else if(player == comp)
			printf("\nEmpate!\n");
		else{
			printf("\nUsted perdio.\n");
		}
		break;
	case 2:
		if(comp == 1 || comp == 5){
			printf("\n===Usted gano!!!===\n");
		}
		else if(player == comp){
			printf("\nEmpate!\n");
		}
		else{
			printf("\nUsted perdio.\n");
		}
		break;
	case 3:
		if(comp == 2 || comp == 4){
			printf("\n===Usted gano!!!===\n");
		}
		else if(player == comp){
			printf("\nEmpate!\n");
		}
		else{
			printf("\nUsted perdio.\n");
		}
		break;
	case 4:
		if(comp == 2 || comp == 5){
			printf("\n===Usted gano!!!===\n");
		}
		else if(player == comp){
			printf("\nEmpate!\n");
		}
		else{
			printf("\nUsted perdio.\n");
		}
		break;
	case 5:
		if(comp == 1 || comp == 3){
			printf("\n===Usted gano!!!===\n");
		}
		else if(player == comp){
			printf("\nEmpate!\n");
		}
		else{
			printf("\nUsted perdio.\n");
		}
		break;
	default:
		printf("\nNo escogio una opcions valida. Intentelo otra vez.\n");
		break;
	}
}

int main(void){

	char buffer[256];

	int num, comp, exe = 1;

	srand(time(NULL));

	printf("Bienvenidos a piedra-papel-tijeras-lagartija-spock.\n");
	printf("\nEscoga el numero de la opcion que desea ingresar.\n");

	do{

		imprimeOpciones();

		fgets(buffer, 256, stdin);

		if(isdigit(buffer[0])){
			num = atoi(buffer);
			comp = computadora();
			resultados(num, comp, &exe);
		}
		else{
			printf("\nNo ingreso un numero. Intentelo de nuevo.\n");
		}

	}while(exe);

	system("PAUSE");
}
