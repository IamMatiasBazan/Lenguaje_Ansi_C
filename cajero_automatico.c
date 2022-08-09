#include <stdio.h>
#include <stdlib.h>

/*
102. Un banco tiene 50 cuentas. Se pide hacer un programa
que realice las siguientes opciones:
ALTA: Permitir ingresa los siguientes datos de cada cuenta�
Numero de cuenta--- entero
Tipo de cuenta --- car�cter (C: cuenta corriente, A: caja de ahorro)
Saldo de la cuenta --- flotante
MODICACION: Permite cambiar el saldo de una cuenta
CONSULTA: Muestra los datos de una cuenta cualquiera
*/

#define N 50

struct cuentaBancaria{
	int numeroDeCuenta;
	char tipoDeCuenta;
	float saldoDeLaCuenta;
};

struct cuentaBancaria cuentasBancarias[N] = {
	{3444, 'C', 90000},
	{1234, 'A', 80000},
	{6644, 'A', 150000},
	{9821, 'C', 45000},
	{341, 'A', 5000}
};

int cargarCuentaNueva(int cargados);
int menu();

int main(){
	int cargados = 5;
	int opcion = 0;

	while (1){
		opcion = menu();

		switch (opcion){
		case 0:
			break;
		case 1:
			cargados = cargarCuentaNueva(cargados);
			break;
		case 2:
			//modificar
		case 3:
			//consultar
		default:
			printf("Opcion invalida... vuelva a intentarlo!");
			getche();
			break;
		}
	}

	system("pause");
	return 0;
}

int menu(){
	int opcionSeleccionada;
	system("cls");
	printf("Elija una opcion:\n");
	printf("================\n");
	printf("0..............SALIR\n");
	printf("1..............Nueva cuenta bancaria\n");
	printf("2..............Modificar cuenta\n");
	printf("3..............Consultar cuenta\n");
	scanf("%d", &opcionSeleccionada);
	return opcionSeleccionada;
}


int cargarCuentaNueva(int cargados){
	int i;

	for (i = cargados; i < N; i++){
		system("cls");
		printf("Ingrese el numero de cuenta (0 para SALIR):\t");
		scanf("%d", &cuentasBancarias[i].numeroDeCuenta);
		if (cuentasBancarias[i].numeroDeCuenta == 0)
			break;

		printf("Ingrese el tipo de cuenta (C: cuenta corriente, A: caja de ahorro):\t");
		//fflush(stdin);
		scanf(" %c", &cuentasBancarias[i].tipoDeCuenta);
		printf("Ingrese el saldo de la cuenta:\t");
		scanf("%f", &cuentasBancarias[i].saldoDeLaCuenta);
	}
	return i;
}
