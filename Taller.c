#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTOS 100
#define LONGITUD_NOMBRE 50

typedef struct {
  char nombre[LONGITUD_NOMBRE];
  int cantidad;
  float precio;
} Producto;

Producto inventario[MAX_PRODUCTOS];
int contador_productos = 0;

void ingresarProducto() {
  if (contador_productos >= MAX_PRODUCTOS) {
    printf("No se pueden agregar más productos. El inventario está lleno.\n");
    return;
  }

  Producto nuevo_producto;

  printf("Ingrese el nombre del producto: ");
  scanf("%s", nuevo_producto.nombre);
  printf("Ingrese la cantidad del producto: ");
  scanf("%d", &nuevo_producto.cantidad);
  printf("Ingrese el precio del producto: ");
  scanf("%f", &nuevo_producto.precio);

  inventario[contador_productos] = nuevo_producto;
  contador_productos++;
  printf("Producto agregado exitosamente.\n");
}

void editarProducto() {
  char nombre[LONGITUD_NOMBRE];
  printf("Ingrese el nombre del producto a editar: ");
  scanf("%s", nombre);

  for (int i = 0; i < contador_productos; i++) {
    if (strcmp(inventario[i].nombre, nombre) == 0) {
      printf("Ingrese la nueva cantidad del producto: ");
      scanf("%d", &inventario[i].cantidad);
      printf("Ingrese el nuevo precio del producto: ");
      scanf("%f", &inventario[i].precio);
      printf("Producto editado exitosamente.\n");
      return;
    }
  }

  printf("Producto no encontrado.\n");
}

void eliminarProducto() {
  char nombre[LONGITUD_NOMBRE];
  printf("Ingrese el nombre del producto a eliminar: ");
  scanf("%s", nombre);

  for (int i = 0; i < contador_productos; i++) {
    if (strcmp(inventario[i].nombre, nombre) == 0) {
      for (int j = i; j < contador_productos - 1; j++) {
        inventario[j] = inventario[j + 1];
      }
      contador_productos--;
      printf("Producto eliminado exitosamente.\n");
      return;
    }
  }

  printf("Producto no encontrado.\n");
}

void listarProductos() {
  if (contador_productos == 0) {
    printf("No hay productos en el inventario.\n");
    return;
  }

  printf("Productos en el inventario:\n");
  for (int i = 0; i < contador_productos; i++) {
    printf("Nombre: %s, Cantidad: %d, Precio: %.2f\n", inventario[i].nombre,
           inventario[i].cantidad, inventario[i].precio);
  }
}

int main() {
  int opcion;

  do {
    printf("\nSistema de Inventarios\n");
    printf("1. Ingresar producto\n");
    printf("2. Editar producto\n");
    printf("3. Eliminar producto\n");
    printf("4. Listar productos\n");
    printf("5. Salir\n");
    printf("Seleccione una opción: ");
    scanf("%d", &opcion);

    switch (opcion) {
    case 1:
      ingresarProducto();
      break;
    case 2:
      editarProducto();
      break;
    case 3:
      eliminarProducto();
      break;
    case 4:
      listarProductos();
      break;
    case 5:
      printf("Saliendo del sistema.\n");
      break;
    default:
      printf("Opción no válida. Intente de nuevo.\n");
      break;
    }
  } while (opcion != 5);

  return 0;
}
