#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
106. Una empresa comercializa 5 artículos en 3 sucursales. 
Se debe realizar un programa que presente un menú con las
siguientes opciones:
A) Carga de datos: se registrará la existencia en depósito
informando N° de sucursal, N°de artículo y cantidad
B) Venta de artículos: se registran las ventas realizadas 
informando N° de sucursal, N°de artículo y cantidad vendida. 
Se debe verificar que la cantidad vendida no supere la 
existencia, informando si la venta no se puede realizar
por este motivo
C) Existencia de mercaderías: listar por pantalla saldos 
existentes de mercaderías
D) Salir del programa
*/

#define N 100

struct articulo
{
	int numeroDeSucursal;
	int numeroDeArticulo;
	int cantidad;
	char nombre[20];
	char descripcion[30];
	float precio;
};


int cargarArticulos(int inicio);
void venderArticulo(int indiceDeArticulo);
void listarArticulos(int fin);
void ordenarPorNombre(int fin);
int buscarArticulo(int fin);
int modificarArticulo(int indiceDeArticulo);
char menu();

struct articulo stockDeArticulos[N] = {
	{3, 2345, 200, "pala", "pala mango de madera", 250.0},
	{1, 1345, 300, "rastrillo", "", 150.0},
	{1, 445, 1200, "cuchara albañil", "", 350.0},
	{2, 675, 300, "escoba", "", 50.0},
	{3, 987, 450, "cucharin", "", 299.0}
};


int main()
{
	int cargados = 5, indice;
	char opcion = ' ';

	do
	{
		opcion = menu();
		switch (opcion)
		{
		case 'c':
		case 'C':
			cargados = cargarArticulos(cargados);
			break;
		case 'l':
		case 'L':
			listarArticulos(cargados);
			break;
		case 'o':
		case 'O':
			ordenarPorNombre(cargados);
			break;
		case 's':
		case 'S':
			break;
		case 'm':
		case 'M':
			indice = buscarArticulo(cargados);
			if (indice >= 0)
				modificarArticulo(indice);
		default:
			printf("Opcion incorrecta! vuelva a intentarlo...");
			break;
		}
	} while (opcion != 'S' && opcion != 's');

	system("pause");
	return 0;
}

int modificarArticulo(int indiceDeArticulo)
{
	int opcion = 0;
	while (1)
	{
		system("cls");
		printf("Que desea Modificar?\n");
		printf("0.......SALIR\n");
		if (opcion == 0)
			break;
		printf("1.......precio\n");
		printf("2.......stock actual?\n");
		printf("3.......descripcion?\n");
		printf("4.......sucursal?\n");
		printf("10.......nombre?\n");
		scanf_s("%d", &opcion);

		switch (opcion)
		{
		case 1:
			printf("Indique el nuevo precio:\t");
			scanf_s("%f", &stockDeArticulos[indiceDeArticulo].precio);
			break;
		case 2:
			printf("Indique el stock actual:\t");
			scanf_s("%d", &stockDeArticulos[indiceDeArticulo].cantidad);
			break;
		case 3:
			printf("Actualice la descripcion:\t");
			fflush(stdin);
			scanf_s(stockDeArticulos[indiceDeArticulo].descripcion);
			break;
		case 4:
			printf("Indique la sucursal:\t");
			scanf_s("%d", &stockDeArticulos[indiceDeArticulo].numeroDeSucursal);
			break;
		case 10:
			printf("Actualice el nombre:\t");
			fflush(stdin);
			scanf_s(stockDeArticulos[indiceDeArticulo].nombre);
			break;
		default:
			printf("Opcion erronea. Vuelva a intentarlo.\n");
			break;
		}
	} 

	return opcion;

}



void ordenarPorNombre(int fin)
{

}

/// <summary>
/// Busca un articulo en la base de datos
/// </summary>
/// <param name="fin">cantidad de elementos de la BD</param>
/// <returns>
/// Devuelve el indice del elemento en el caso de ser encontrado
/// Devuelve -1 cuando no se encuentra el elemento
/// </returns>
int buscarArticulo(int fin)
{
	int i;
	char nombre[20] = ‘’;

	system("cls");
	printf("Ingrese el articulo a buscar:\t");
	//fflush(stdin);
	scanf_s(nombre);

	for (i = 0; i < fin; i++)
	{
		if (strcmp(stockDeArticulos[i].nombre, nombre) == 0 )
		{
			printf("Articulo encontrado en el indice %d\n", i);
			//getche();
			return i;
		}
	}
	return -1;
}


char menu()
{
	char letra;
	system("cls");
	printf("Elija una opcion:\n");
	printf("###################\n");
	printf("S............SALIR\n");
	printf("C............cargar articulos\n");
	printf("L............listar articulos\n");
	printf("V............vender articulos\n");
	printf("B............buscar articulo\n");
	printf("O............ordenar alfabeticamente\n");
	printf("M............modificar articulo\n");

	scanf_s("%c", &letra);
	/*fflush(stdin);
	letra = getchar();*/
	return letra;
}



void listarArticulos(int fin)
{

}


void venderArticulo(int indiceDeArticulo)
{
	int cantidadAVender;

	system("cls");
	printf("Articulo Nro:\t%d\n", stockDeArticulos[indiceDeArticulo].numeroDeArticulo);
	printf("Nombre:\t%s\n", stockDeArticulos[indiceDeArticulo].nombre);
	printf("Sucursal numero:\t%d\n", stockDeArticulos[indiceDeArticulo].numeroDeSucursal);
	printf("Stock Actual:\t%d\n", stockDeArticulos[indiceDeArticulo].cantidad);
	printf("precio:\t%.2f\n", stockDeArticulos[indiceDeArticulo].precio);
	printf("descripcion:\t%s\n", stockDeArticulos[indiceDeArticulo].descripcion);

	printf("Cantidad a Vender\t");
	scanf_s("%d", &cantidadAVender);
	if (stockDeArticulos[indiceDeArticulo].cantidad >= cantidadAVender)
		stockDeArticulos[indiceDeArticulo].cantidad -= cantidadAVender;
	else
		printf("Imposible Vender esa cantidad!\t");
	
	//getche();

}



/// <summary>
/// Permite cargar uno o varios articulos en la Base de Datos
/// </summary>
/// <param name="inicio">primer elemento disponible a cargar en la BD</param>
/// <returns>la cantidad de elementos cargados en la BD</returns>
int cargarArticulos(int inicio)
{
	int i;

	for (i = inicio; i < N; i++)
	{
		system("cls");
		printf("Ingrese el numero de sucursal (0 para SALIR)\t");
		scanf_s("%d", &stockDeArticulos[i].numeroDeSucursal);
		if (stockDeArticulos[i].numeroDeSucursal == 0)
			break;

		printf("Ingrese el numero de articulo:\t");
		scanf_s("%d", &stockDeArticulos[i].numeroDeArticulo);

		printf("Ingrese el stock actual:\t");
		scanf_s("%d", &stockDeArticulos[i].cantidad);

		printf("Ingrese el nombre del articulo:\t");
		//scanf("%d", &stockDeArticulos[i].cantidad);
		//gets_s(stockDeArticulos[i].nombre, 20);
		//fflush(stdin);
		//getche();
		gets(stockDeArticulos[i].nombre);

		printf("Ingrese la descripcion breve:\t");
		//getche();
		//fflush(stdin);
		gets(stockDeArticulos[i].descripcion);

		printf("Ingrese el precio:\t");
		scanf_s("%f", &stockDeArticulos[i].precio);
	}
	return i;
}
