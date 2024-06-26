// Código Base hecho por el Ing. Deymar Ampudia. REALIZAR SU DEBIDO ACREDITAMIENTO
// Primera revisión realizada por el Lic. Pérez, primeros problemas esclarecidos

// Notas adicionales del Ing. al Lic.
// Existen ocasiones en las que el programa se cierra después de ejecutar una opción del menú.
// Por ejemplo. al darle a la opción de "buscar producto", te pide que ingreses el ID, y automáticamente, te muestra el producto registrado.
// Sin embargo, si quieres buscar otro producto (o el mismo), el programa se cierra de la nada. esto también ocurre con la opción "calcular promedio de precios".
// En general, el programa funciona, solo falta eliminar dicho problema (y la opción de "eliminar producto").

// Notas del Lic.
// despues de resolver estos inconvenientes, hay que desarrollar la segunda parte del código que son las ventas de productos, no continue con esas cuestiones debido al tiempo
// Eso, y que el PC no es propiamente mío. Gracias.

// Recuerden Acreditar al Ing.

// Actualizacion del codigo.
// se añadió la opcion "vender producto". esto se hace mediante la implementacion del ID del producto para la busqueda del mismo.

// Notas adicionales del Ing. Ampudia para el Lic. Perez:
// el metodo "vender producto" funciona correctamente, sin embargo, presenta el mismo problema que el metodo "buscar producto"
// el programa se cierra depsues de terminar la funcion "vender producto"
// Se le pide su colaboracion para resolver el problema urgentemente.

// Actualizacion del código
// Notas adicionales del Ing. Ampudia para el Lic. perez:
// Se solucionó el problema con el metodo "Vender producto"
// La solucion fue cambiar la condicion a la hora de cerrar el programa
// El metodo "vender producto" se le asigno la opcion 8, y la opcion "salir" tambien tenia la misma opcion
// Por lo tanto, el programa inevitablemente se cerraria depsues de ejecutar el metodo "vender producto"
// Los problemas con el metodo "buscar producto" todavia persisten. (solucionar en lo mas pronto posiblse).

// Acualizacion del código
// Nota adicional del Ing. Ampudia para el Lic. Perez:
// Se soluciono el problema del metodo "Calcular promedio de precios"
// Los problemas con el metodo "buscar producto" todavia persisten. (solucionar en lo mas pronto posiblse).



// Notas del Lic. Pérez al Ing. Ampudia:
// Se soluciono el problema con el método buscar, era necesario colocarlo por fuera del for, ya que al estar adentro del for, mostraría si o si el mensaje
//"El Producto correspondiente al ID ingresado no se encuentra registrado en el inventario". El problema era que mostraba ese mensaje a pesar que, el prodcuto estuviera registrado
// Finalmente, y depues de tanta lucha, la funcion eliminar esta funcionando bien, tecnicamente, la unica cosa es que no lograba organizarlo de manera que aun asi mostrase los
// datos del ID del producto ingresado. Se reorganizo la funcion "switch" para que no existiera inconvenientes en su uso.
// Falta solamente solucionar los problemas de cierre de programa, luego los revisaré poco a poco aver donde están.

// Nuevas notas del Lic. Pérez al Ing. Ampudia:
// Ahora, el código emitirá un mensaje en caso de que se registre un producto con un ID ya utilizado, en caso de que el ID no sea duplicado, le dajará al usuario
// continuar con la ejecución del programa. En caso contrario, le dirá que el ID está en uso y que lo intente nuevamente

#include <iostream> // permite la entrada y salida de datos
#include <malloc.h> // permite la asignacion dinamica de memoria

using namespace std; // permite usar los metodos de la libreria std

struct RegistroProducto // Estructura de registro de productos.
{
    int ID = 0;
    char Nombre[30];
    int Cantidad = 0;
    float ValorUnitario = 0;

    int acumulador;

    RegistroProducto *sig;
};

RegistroProducto *cab, *aux, *aux2;

int registro() // Por este lado no hay problema.
{
    if (cab == NULL)
    {
        cab = (struct RegistroProducto *)malloc(sizeof(struct RegistroProducto)); // Se asigna la memoria dinamica para el registro de productos.

        cout << "Ingrese el ID del producto: ";
        cin >> cab->ID;

        cout << "Ingrese el nombre del producto: ";
        cin >> cab->Nombre;

        cout << "Ingrese el valor unitario del producto: $";
        cin >> cab->ValorUnitario;

        cout << "Ingrese la cantidad a registrar del producto: ";
        cin >> cab->Cantidad;

        cab->sig = NULL;
        free(aux);
    }
    else
    {
        aux = (struct RegistroProducto *)malloc(sizeof(struct RegistroProducto));
        cout << "Ingrese el ID del producto: ";
        cin >> aux->ID;

        // A partir de aquí se usan los datos Boolean
        bool IDExiste = false;
        aux2 = cab;
        while (aux2 != NULL)
        {
            if (aux2->ID == aux->ID)
            {
                IDExiste = true;
                break;
            }
            aux2 = aux2->sig;
        }
        if (IDExiste)
        {
            cout << "El ID ingresado ya esta en uso. Por favor, intente nuevamente."
                 << endl;
            free(aux);
        }
        else
        {

            cout << "Ingrese el nombre del producto: ";
            cin >> aux->Nombre;

            cout << "Ingrese el valor unitario del producto: $";
            cin >> aux->ValorUnitario;

            cout << "Ingrese la cantidad a registrar del producto: ";
            cin >> aux->Cantidad;

            aux->sig = NULL;

            aux2 = cab;
            while (aux2->sig != NULL) // Se busca el ultimo registro de productos.
            {
                aux2 = aux2->sig;
            }

            aux->acumulador = aux2->acumulador + 1;
            aux2->sig = aux; // Se agrega el nuevo registro de productos al final de la lista.
            aux = NULL;
            aux2 = NULL;

            free(aux);
            free(aux2);
        }
    }
    return 0;
}

int mostrar() // Funciona correctamente.
{
     if (cab == NULL)
    {
        cout << "Lo siento, pero el inventario esta vacio. Registre un nuevo producto." << endl;
        return 0;
    }
    
    for (aux = cab; aux != NULL; aux = aux->sig)
    {
        cout << "Producto #" << aux->acumulador + 1 << endl;
        cout << "Nombre del producto : " << aux->Nombre << endl;
        cout << "ID: " << aux->ID << endl;
        cout << "Valor unitario: $" << aux->ValorUnitario << endl;
        cout << "Cantidad: " << aux->Cantidad << endl;
        cout << "" << endl;
    }
    return 0;
}

int buscar() // Metodo corregido y funcionando correctamente, era necesario tan solo, cambiar de lugar el cout y ponerlo fuera del for
{
   if (cab == NULL)
    {
        cout << "No hay productos para buscar porque el inventario esta vacio." << endl;
        return 0;
    }
    int buscador = 0;
    cout << "Ingrese el ID del producto a buscar: ";
    cin >> buscador;

    for (aux = cab; aux != NULL; aux = aux->sig)
    {
        if (buscador == aux->ID)
       {
            cout << "Producto registrado" << endl;
            cout << "Producto #" << aux->acumulador + 1 << endl;
            cout << "Nombre del producto : " << aux->Nombre << endl;
            cout << "ID: " << aux->ID << endl;
            cout << "Valor Unitario: $" << aux->ValorUnitario << endl;
            cout << "Cantidad: " << aux->Cantidad << endl;
            cout << "" << endl;
            return 0;
        }
    }
    cout << "El Producto correspondiente al ID ingresado no se encuentra registrado en el inventario" << endl;

    return 0;
}

int eliminar()
{ // Finalmente, Este metodo esta tecnicamente finalizado, la logica es facil, codificarlo fue un verdadero infierno
    int elemento = 0;
    cout << "Ingrese el ID del producto que desea eliminar del inventario: ";
    cin >> elemento;
    aux = cab;
    RegistroProducto *prev = NULL;
    while (aux != NULL && aux->ID != elemento)
    { // verifica si el ID ingresado existe en el inventario
        prev = aux;
        aux = aux->sig;
    }
    if (aux != NULL)
    {

        if (prev == NULL)
        {
            cab = aux->sig;
        }
        else
        {
            prev->sig = aux->sig;
        }
        free(aux);
        cout << "Producto eliminado exitosamente." << endl;
    }
    else
    {
        cout << "No existe un producto con el ID ingresado." << endl;
    }
    return 0;
}

int PrecioTotal() // Funciona correctamente
{
    int total = 0;
    int cantTotal = 0;
    for (aux = cab; aux != NULL; aux = aux->sig)
    {
        cantTotal = aux->Cantidad * aux->ValorUnitario;
        total = total + cantTotal;
    }

    cout << "El valor total de todos los productos es de: $" << total << endl;
    return 0;
}

int Promediar() // Metodo solucionado
{
    int total2 = 0;
    int total3 = 0;
    int promediar = 0;
    int PrecioTotal = 0;
    int CantidadTotal = 0;
    for (aux = cab; aux != NULL; aux = aux->sig)
    {
        CantidadTotal = aux->Cantidad;
        total2 = total2 + CantidadTotal;

        PrecioTotal = aux->ValorUnitario * aux->Cantidad;
        total3 = total3 + PrecioTotal;
    }
    promediar = total3 / total2;

    cout << "Existe una cantidad total de " << total2 << " de productos registrados" << endl;

    cout << "El promedio del precio de todos los productos es de: " << promediar << endl;
    return 0;
}

int vender() // metodo completo
{
    int IDVender = 0;
    int cantVender = 0;
    cout << "Ingrese el ID del producto a vender: ";
    cin >> IDVender;

    for (aux = cab; aux != NULL; aux = aux->sig)
    {
        if (IDVender == aux->ID)
        {
            cout << "producto existente en el inventario" << endl;
            cout << "Producto #" << aux->acumulador + 1 << endl;
            cout << "Nombre del producto : " << aux->Nombre << endl;
            cout << "ID: " << aux->ID << endl;
            cout << "vValor unitario: $" << aux->ValorUnitario << endl;
            cout << "Cantidad: " << aux->Cantidad << endl;
            cout << "" << endl;

            cout << "ingrese la cantidad de unidades del producto: ";
            cin >> cantVender;

            if (cantVender > aux->Cantidad)
            {
                cout << "ATENCION. La cantidad de unidades a vender es mayor a la cantidad de unidades disponibles" << endl;
                cout << "Cancelando la venta" << endl;
            }
            if (cantVender <= aux->Cantidad)
            {
                aux->Cantidad = aux->Cantidad - cantVender;

                cout << "Venta realizada con exito. mostrando resultados: " << endl;

                cout << "producto existente en el inventario" << endl;
                cout << "Producto #" << aux->acumulador + 1 << endl;
                cout << "Nombre del producto : " << aux->Nombre << endl;
                cout << "ID: " << aux->ID << endl;
                cout << "Valor unitario: $" << aux->ValorUnitario << endl;
                cout << "Cantidad: " << aux->Cantidad << endl;
                cout << "" << endl;

                int ganancias = 0;

                ganancias = cantVender * aux->ValorUnitario;

                cout << "Usted ha obtenido una ganancia de $" << ganancias << endl;
                return 0;
            }
        }
        if (IDVender != aux->ID)
        {
            cout << "producto no registrado" << endl;
            return 0;
        }
    }
    return 0;
}

int main()
{
    int opcion = 0;
    do
    {
        cout << "" << endl;
        cout << "Bienvenido al servicio de gestion de inventario de productos" << endl;
        cout << "Elija una de la siguientes opciones:" << endl;
        cout << "" << endl;

        cout << "1. Registrar un producto" << endl;
        cout << "2. Ver Lista de productos" << endl;
        cout << "3. Buscar producto" << endl;
        cout << "4. Eliminar producto" << endl;
        cout << "5. Calcular valor total de productos" << endl;
        cout << "6. Calcular el promedio de los precios de los productos" << endl;
        cout << "7. Vender producto" << endl;
        cout << "8. Salir" << endl;
        cout << "Ingrese su opcion: ";
        cin >> opcion;
        cout << "" << endl;

        switch (opcion)
        {
        case 1:
            registro();
            break;

        case 2:
            mostrar();
            break;

        case 3:
            buscar();
            break;

        case 4:
            eliminar();
            break;

        case 5:
            PrecioTotal();
            break;

        case 6:
            Promediar();
            break;

        case 7:
            vender();
            break;

        case 8:
            cout << "Programa finalizado. Que tenga buen dia" << endl;
            break;

        default:
            cout << "Opcion invalida. Intente nuevamente" << endl;
            break;
        }
    } while (opcion != 8);
    return 0;
}
