/*
 * UNIVERSIDAD NACIONAL AUTONOMA DE HONDURAS
 * DIA-044 PROGRAMACION BASICA - EXAMEN I PARCIAL
 * PROGRAMA #2 - TIENDA DE TECNOLOGIA "PUMA TECH STORE"
 *Edras Celin Ramos 20211020157
 */

#include <iostream> 
#include <string>
#include <iomanip> 
#include <cctype>
#include <cstdlib> 
#include <cmath>
using namespace std;

// ======================= CONSTANTES =======================
const double ISV = 0.15;          // Impuesto sobre ventas
const double TASA_DOLAR = 26.42;  // 1 USD = 26.42 Lps.

// ======================= DATOS GLOBALES =======================
// Inventario actual de cada producto
int stock1 = 18, stock2 = 8,  stock3 = 20, stock4 = 10, stock5 = 6,  stock6 = 7;
int stock7 = 12, stock8 = 6,  stock9 = 9,  stock10 = 30, stock11 = 40, stock12 = 15;

// Cantidad de cada producto en el carrito del cliente actual
int car1 = 0, car2 = 0, car3 = 0, car4 = 0, car5 = 0, car6 = 0;
int car7 = 0, car8 = 0, car9 = 0, car10 = 0, car11 = 0, car12 = 0;

// Unidades vendidas en el dia (para estadisticas)
int ven1 = 0, ven2 = 0, ven3 = 0, ven4 = 0, ven5 = 0, ven6 = 0;
int ven7 = 0, ven8 = 0, ven9 = 0, ven10 = 0, ven11 = 0, ven12 = 0;

// Acumuladores del dia
double gananciaCat1 = 0, gananciaCat2 = 0, gananciaCat3 = 0, gananciaCat4 = 0;
double totalDescuentosDia = 0, totalISVDia = 0, totalGeneralDia = 0;
int pagosEfectivo = 0, pagosTransferencia = 0;
int clientesAtendidos = 0;

// ======================= PROTOTIPOS =======================
// Datos de productos
string getNombre(int c);
double getPrecio(int c);
int    getPuntos(int c);
int    getCategoria(int c);
string getNombreCategoria(int cat);
int    getStock(int c);
void   setStock(int c, int valor);
int    getCarrito(int c);
void   setCarrito(int c, int valor);
int    getVendidos(int c);
void   sumarVendidos(int c, int cant);

// Validaciones y lectura
string recortar(string s);
string aMinusculas(string s);
string leerLinea(string mensaje);
bool   soloLetras(string s);
bool   soloDigitos(string s);
string leerNombre(string mensaje);
char   leerSexo();
int    leerEnteroRango(string mensaje, int minimo, int maximo);
double leerMonto(string mensaje);
char   leerSN(string mensaje);

// Menus
int  menuTipoCliente();
void menuProductos();
int  menuCarrito();
int  menuMetodoPago();

// Carrito
void carritoDeCompras();
void agregarAlCarrito();
void quitarDelCarrito();
void mostrarCarrito();
bool carritoVacio();
void vaciarCarrito();

// Facturacion
double porcentajeDescuento(int c, int tipo, char sexo, int edad);
void   mostrarDetalleDescuento(int c, int tipo, char sexo, int edad, double subtotal);
double facturar(string nombre, char sexo, int edad, int tipo);
void   sumarGananciaCategoria(int cat, double monto);
void   procesarPago(double total);
void   mostrarEstadisticas();

// ======================= MAIN =======================
int main() {
    char otro;

    do {
        vaciarCarrito();
        clientesAtendidos++;

        cout << "\n==============================================\n";
        cout << "        PUMA TECH STORE - NUEVO CLIENTE\n";
        cout << "==============================================\n";

        // ---- Datos del cliente (todo validado) ----
        string nombre = leerNombre("Nombre del cliente: ");
        char sexo = leerSexo();
        int edad = leerEnteroRango("Edad (15 a 100): ", 15, 100);
        int tipo = menuTipoCliente();

        // ---- Compra ----
        carritoDeCompras();

        // ---- Factura y pago ----
        double total = facturar(nombre, sexo, edad, tipo);
        procesarPago(total);

        cout << "\n";
        otro = leerSN("Desea ingresar otro cliente? (S/N): ");

    } while (otro == 'S');

    mostrarEstadisticas();
    cout << "\nGracias por usar Puma Tech Store.\n";
    return 0;
}

// ======================= DATOS DE PRODUCTOS =======================
/*
   Los datos se consultan mediante funciones con switch. Esta organizacion
   permite manejar los productos sin utilizar arreglos ni vectores.
*/
/*
   Estas funciones consultan la informacion de cada producto mediante switch.
   Asi se puede trabajar con los 12 productos sin utilizar arreglos o vectores.
*/
string getNombre(int c) {
    switch (c) {
        case 1:  return "Smartphone Android Puma A55";
        case 2:  return "iPhone Puma i13";
        case 3:  return "Celular basico Puma Mini";
        case 4:  return "Laptop i5 PumaBook 15";
        case 5:  return "Laptop Gamer PumaGamer X";
        case 6:  return "PC Escritorio PumaDesk";
        case 7:  return "Tablet 10 pulg PumaTab";
        case 8:  return "iPad PumaPad Air";
        case 9:  return "Impresora WiFi PumaPrint";
        case 10: return "Audifonos Bluetooth";
        case 11: return "Mouse inalambrico";
        case 12: return "Teclado mecanico";
    }
    return "";
}

double getPrecio(int c) {
    switch (c) {
        case 1:  return 6800.00;
        case 2:  return 19500.00;
        case 3:  return 1800.00;
        case 4:  return 18900.00;
        case 5:  return 32500.00;
        case 6:  return 14800.00;
        case 7:  return 7900.00;
        case 8:  return 16500.00;
        case 9:  return 4500.00;
        case 10: return 650.00;
        case 11: return 350.00;
        case 12: return 1250.00;
    }
    return 0;
}

int getPuntos(int c) {
    switch (c) {
        case 1:  return 120;
        case 2:  return 250;
        case 3:  return 60;
        case 4:  return 220;
        case 5:  return 350;
        case 6:  return 180;
        case 7:  return 140;
        case 8:  return 230;
        case 9:  return 90;
        case 10: return 25;
        case 11: return 15;
        case 12: return 45;
    }
    return 0;
}

// 1 Celulares, 2 Laptops y Computadoras, 3 Tablets y Equipos, 4 Accesorios
int getCategoria(int c) {
    if (c >= 1 && c <= 3)   return 1;
    if (c >= 4 && c <= 6)   return 2;
    if (c >= 7 && c <= 9)   return 3;
    if (c >= 10 && c <= 12) return 4;
    return 0;
}

string getNombreCategoria(int cat) {
    switch (cat) {
        case 1: return "Celulares";
        case 2: return "Laptops y Computadoras";
        case 3: return "Tablets y Equipos";
        case 4: return "Accesorios";
    }
    return "";
}

int getStock(int c) {
    switch (c) {
        case 1:  return stock1;
        case 2:  return stock2;
        case 3:  return stock3;
        case 4:  return stock4;
        case 5:  return stock5;
        case 6:  return stock6;
        case 7:  return stock7;
        case 8:  return stock8;
        case 9:  return stock9;
        case 10: return stock10;
        case 11: return stock11;
        case 12: return stock12;
    }
    return 0;
}

void setStock(int c, int valor) {
    switch (c) {
        case 1:  stock1 = valor;  break;
        case 2:  stock2 = valor;  break;
        case 3:  stock3 = valor;  break;
        case 4:  stock4 = valor;  break;
        case 5:  stock5 = valor;  break;
        case 6:  stock6 = valor;  break;
        case 7:  stock7 = valor;  break;
        case 8:  stock8 = valor;  break;
        case 9:  stock9 = valor;  break;
        case 10: stock10 = valor; break;
        case 11: stock11 = valor; break;
        case 12: stock12 = valor; break;
    }
}

int getCarrito(int c) {
    switch (c) {
        case 1:  return car1;
        case 2:  return car2;
        case 3:  return car3;
        case 4:  return car4;
        case 5:  return car5;
        case 6:  return car6;
        case 7:  return car7;
        case 8:  return car8;
        case 9:  return car9;
        case 10: return car10;
        case 11: return car11;
        case 12: return car12;
    }
    return 0;
}

void setCarrito(int c, int valor) {
    switch (c) {
        case 1:  car1 = valor;  break;
        case 2:  car2 = valor;  break;
        case 3:  car3 = valor;  break;
        case 4:  car4 = valor;  break;
        case 5:  car5 = valor;  break;
        case 6:  car6 = valor;  break;
        case 7:  car7 = valor;  break;
        case 8:  car8 = valor;  break;
        case 9:  car9 = valor;  break;
        case 10: car10 = valor; break;
        case 11: car11 = valor; break;
        case 12: car12 = valor; break;
    }
}

int getVendidos(int c) {
    switch (c) {
        case 1:  return ven1;
        case 2:  return ven2;
        case 3:  return ven3;
        case 4:  return ven4;
        case 5:  return ven5;
        case 6:  return ven6;
        case 7:  return ven7;
        case 8:  return ven8;
        case 9:  return ven9;
        case 10: return ven10;
        case 11: return ven11;
        case 12: return ven12;
    }
    return 0;
}

void sumarVendidos(int c, int cant) {
    switch (c) {
        case 1:  ven1 += cant;  break;
        case 2:  ven2 += cant;  break;
        case 3:  ven3 += cant;  break;
        case 4:  ven4 += cant;  break;
        case 5:  ven5 += cant;  break;
        case 6:  ven6 += cant;  break;
        case 7:  ven7 += cant;  break;
        case 8:  ven8 += cant;  break;
        case 9:  ven9 += cant;  break;
        case 10: ven10 += cant; break;
        case 11: ven11 += cant; break;
        case 12: ven12 += cant; break;
    }
}

// ======================= VALIDACIONES Y LECTURA =======================
/*
   Estas funciones verifican nombres, edades, cantidades y montos para evitar
   que se ingresen datos con formatos incorrectos.
*/
/*
   Las funciones de esta seccion revisan los datos antes de aceptarlos.
   Por ejemplo, evitan nombres con numeros, edades fuera del rango y montos
   que contengan letras. Esto reduce errores durante la compra.
*/

// Quita espacios al inicio y al final
string recortar(string s) {
    size_t i = 0;
    while (i < s.size() && isspace((unsigned char)s[i])) i++;
    size_t j = s.size();
    while (j > i && isspace((unsigned char)s[j - 1])) j--;
    return s.substr(i, j - i);
}

string aMinusculas(string s) {
    for (size_t i = 0; i < s.size(); i++)
        s[i] = (char)tolower((unsigned char)s[i]);
    return s;
}

// Lee una linea completa (si se cierra la entrada, termina el programa)
string leerLinea(string mensaje) {
    string s;
    cout << mensaje;
    if (!getline(cin, s)) {
        cout << "\nEntrada finalizada. Saliendo del programa...\n";
        exit(0);
    }
    return recortar(s);
}

// Solo letras y espacios (acepta tildes y ñ, que son bytes >= 128)
bool soloLetras(string s) {
    if (s.size() < 2 || s.size() > 40) return false;
    bool hayLetra = false;
    for (size_t i = 0; i < s.size(); i++) {
        unsigned char ch = (unsigned char)s[i];
        if (isalpha(ch) || ch >= 128) hayLetra = true;
        else if (ch != ' ') return false;   // numero o simbolo
    }
    return hayLetra;
}

// Solo digitos 0-9
bool soloDigitos(string s) {
    if (s.empty()) return false;
    for (size_t i = 0; i < s.size(); i++)
        if (!isdigit((unsigned char)s[i])) return false;
    return true;
}

string leerNombre(string mensaje) {
    string s;
    while (true) {
        s = leerLinea(mensaje);
        if (soloLetras(s)) return s;
        cout << "  [ERROR] Solo letras y espacios (2 a 40 caracteres). Sin numeros ni simbolos.\n";
    }
}

// Devuelve 'M' (masculino) o 'F' (femenino)
char leerSexo() {
    while (true) {
        string s = aMinusculas(leerLinea("Sexo (masculino / femenino): "));
        if (s == "masculino" || s == "m") return 'M';
        if (s == "femenino" || s == "f")  return 'F';
        cout << "  [ERROR] Solo se acepta: masculino o femenino.\n";
    }
}

// Lee un entero validando que sean solo digitos y este en [minimo, maximo]
int leerEnteroRango(string mensaje, int minimo, int maximo) {
    while (true) {
        string s = leerLinea(mensaje);
        if (!soloDigitos(s) || s.size() > 9) {
            cout << "  [ERROR] Ingrese solo numeros enteros positivos (sin letras, simbolos ni decimales).\n";
            continue;
        }
        int n = atoi(s.c_str());
        if (n < minimo || n > maximo) {
            cout << "  [ERROR] El valor debe estar entre " << minimo << " y " << maximo << ".\n";
            continue;
        }
        return n;
    }
}

// Lee un monto en Lempiras: digitos con un solo punto decimal opcional
double leerMonto(string mensaje) {
    while (true) {
        string s = leerLinea(mensaje);
        int puntos = 0;
        bool valido = !s.empty() && s.size() <= 12;
        for (size_t i = 0; i < s.size() && valido; i++) {
            if (s[i] == '.') puntos++;
            else if (!isdigit((unsigned char)s[i])) valido = false;
        }
        if (puntos > 1 || s == ".") valido = false;
        if (!valido) {
            cout << "  [ERROR] Ingrese un monto valido (solo numeros y un punto decimal).\n";
            continue;
        }
        return atof(s.c_str());
    }
}

// Devuelve 'S' o 'N'
char leerSN(string mensaje) {
    while (true) {
        string s = aMinusculas(leerLinea(mensaje));
        if (s == "s") return 'S';
        if (s == "n") return 'N';
        cout << "  [ERROR] Responda unicamente S o N.\n";
    }
}

// ======================= MENUS =======================
int menuTipoCliente() {
    cout << "\n--- TIPO DE CLIENTE ---\n";
    cout << "1. Estudiante   (8% desc. en Accesorios)\n";
    cout << "2. Profesional  (10% desc. en Laptops y Computadoras)\n";
    cout << "3. Corporativo  (12% desc. en Tablets y Equipos Empresariales)\n";
    return leerEnteroRango("Seleccione una opcion (1-3): ", 1, 3);
}

void menuProductos() {
    cout << "\n=========================== CATALOGO PUMA TECH STORE ===========================\n";
    cout << left << setw(5) << "COD" << setw(30) << "PRODUCTO" << right
         << setw(14) << "PRECIO (Lps.)" << setw(12) << "DISPONIBLE" << setw(10) << "PUNTOS" << "\n";
    cout << "--------------------------------------------------------------------------------\n";

    int categoriaAnterior = 0;
    for (int c = 1; c <= 12; c++) {
        if (getCategoria(c) != categoriaAnterior) {
            categoriaAnterior = getCategoria(c);
            cout << "[" << getNombreCategoria(categoriaAnterior) << "]\n";
        }
        int disponible = getStock(c) - getCarrito(c);
        cout << left << setw(5) << c << setw(30) << getNombre(c) << right
             << fixed << setprecision(2) << setw(14) << getPrecio(c)
             << setw(12) << disponible << setw(10) << getPuntos(c) << "\n";
    }
    cout << "================================================================================\n";
}

int menuCarrito() {
    cout << "\n--- CARRITO DE COMPRAS ---\n";
    cout << "1. Agregar producto\n";
    cout << "2. Ver carrito\n";
    cout << "3. Quitar producto del carrito\n";
    cout << "4. Finalizar compra (facturar)\n";
    return leerEnteroRango("Seleccione una opcion (1-4): ", 1, 4);
}

int menuMetodoPago() {
    cout << "\n--- METODO DE PAGO ---\n";
    cout << "1. Efectivo\n";
    cout << "2. Transferencia\n";
    return leerEnteroRango("Seleccione una opcion (1-2): ", 1, 2);
}

// ======================= CARRITO =======================
/*
   Administra los productos seleccionados, comprueba el stock y permite
   agregar, consultar o quitar articulos antes de facturar.
*/
/*
   El carrito guarda las cantidades seleccionadas por el cliente.
   Antes de agregar productos se comprueba el inventario disponible;
   al finalizar la compra, la funcion de facturacion descuenta las unidades.
*/
bool carritoVacio() {
    for (int c = 1; c <= 12; c++)
        if (getCarrito(c) > 0) return false;
    return true;
}

void vaciarCarrito() {
    for (int c = 1; c <= 12; c++)
        setCarrito(c, 0);
}

void mostrarCarrito() {
    if (carritoVacio()) {
        cout << "\nEl carrito esta vacio.\n";
        return;
    }
    cout << "\n--- CONTENIDO DEL CARRITO ---\n";
    cout << left << setw(5) << "COD" << setw(30) << "PRODUCTO" << right
         << setw(6) << "CANT" << setw(14) << "SUBTOTAL" << "\n";
    double suma = 0;
    for (int c = 1; c <= 12; c++) {
        int q = getCarrito(c);
        if (q > 0) {
            double sub = q * getPrecio(c);
            suma += sub;
            cout << left << setw(5) << c << setw(30) << getNombre(c) << right
                 << setw(6) << q << fixed << setprecision(2) << setw(14) << sub << "\n";
        }
    }
    cout << "Subtotal sin descuentos: Lps. " << fixed << setprecision(2) << suma << "\n";
}

void agregarAlCarrito() {
    menuProductos();
    int codigo = leerEnteroRango("Codigo del producto (1-12): ", 1, 12);
    int disponible = getStock(codigo) - getCarrito(codigo);

    if (disponible <= 0) {
        cout << "  Stock insuficiente\n";
        return;
    }
    int cantidad = leerEnteroRango("Cantidad: ", 1, 100000);
    if (cantidad > disponible) {
        cout << "  Stock insuficiente (solo hay " << disponible << " unidad(es) disponibles).\n";
        return;
    }
    setCarrito(codigo, getCarrito(codigo) + cantidad);
    cout << "  Agregado: " << cantidad << " x " << getNombre(codigo) << "\n";
}

void quitarDelCarrito() {
    if (carritoVacio()) {
        cout << "\nEl carrito esta vacio, no hay nada que quitar.\n";
        return;
    }
    mostrarCarrito();
    int codigo = leerEnteroRango("Codigo del producto a quitar (1-12): ", 1, 12);
    if (getCarrito(codigo) == 0) {
        cout << "  Ese producto no esta en el carrito.\n";
        return;
    }
    setCarrito(codigo, 0);
    cout << "  Producto eliminado del carrito.\n";
}

// Funcion principal del carrito: se repite hasta que el cliente finaliza
void carritoDeCompras() {
    bool terminar = false;
    while (!terminar) {
        int opcion = menuCarrito();
        switch (opcion) {
            case 1: agregarAlCarrito(); break;
            case 2: mostrarCarrito();   break;
            case 3: quitarDelCarrito(); break;
            case 4:
                if (carritoVacio())
                    cout << "  [ERROR] Debe agregar al menos un producto para facturar.\n";
                else
                    terminar = true;
                break;
        }
    }
}

// ======================= DESCUENTOS =======================
/*
   Calcula los porcentajes que corresponden a cada producto. Los descuentos
   aplicables se acumulan y se calculan sobre el subtotal original.
*/
/*
   Los descuentos se calculan por producto. Se pueden acumular varios motivos:
   tipo de cliente, genero, edad y promociones especiales.
   El porcentaje total se aplica al subtotal original de cada producto.
*/
// Devuelve el porcentaje TOTAL de descuento para el producto c
double porcentajeDescuento(int c, int tipo, char sexo, int edad) {
    double p = 0;
    int cat = getCategoria(c);
    int q = getCarrito(c);

    // 1) Descuento por tipo de cliente
    if (tipo == 1 && cat == 4) p += 8;    // Estudiante: Accesorios
    if (tipo == 2 && cat == 2) p += 10;   // Profesional: Laptops y Computadoras
    if (tipo == 3 && cat == 3) p += 12;   // Corporativo: Tablets y Equipos

    // 2) Descuentos adicionales por genero y edad
    if (sexo == 'F' && cat == 4) p += 10; // Mujeres: Accesorios
    if (sexo == 'M' && cat == 2) p += 5;  // Hombres: Laptops y Computadoras
    if (edad >= 60) p += 10;              // Tercera edad: general

    // 3) Promociones especiales
    // Combo Gaming: Laptop Gamer (5) + Teclado mecanico (12) -> 7% a ambos
    if ((c == 5 || c == 12) && getCarrito(5) > 0 && getCarrito(12) > 0) p += 7;

    // Por volumen: mas de 3 unidades del mismo accesorio -> 4%
    if (cat == 4 && q > 3) p += 4;

    // Proteccion movil: celular (1,2,3) + audifonos (10) -> 5% solo a audifonos
    if (c == 10 && (getCarrito(1) > 0 || getCarrito(2) > 0 || getCarrito(3) > 0)) p += 5;

    return p;
}

// Muestra en la factura de dónde proviene el descuento de cada producto.
// Cada motivo se presenta por separado para que el cliente pueda verificarlo.
void mostrarDetalleDescuento(int c, int tipo, char sexo, int edad, double subtotal) {
    int cat = getCategoria(c);
    int q = getCarrito(c);
    double porcentaje = 0;

    // Descuento según el tipo de cliente y la categoría del producto.
    if (tipo == 1 && cat == 4) {
        porcentaje = 8;
        cout << "       * Estudiante: 8% en Accesorios = Lps. "
             << subtotal * porcentaje / 100.0 << "\\n";
    }
    if (tipo == 2 && cat == 2) {
        porcentaje = 10;
        cout << "       * Profesional: 10% en Laptops y Computadoras = Lps. "
             << subtotal * porcentaje / 100.0 << "\\n";
    }
    if (tipo == 3 && cat == 3) {
        porcentaje = 12;
        cout << "       * Corporativo: 12% en Tablets y Equipos = Lps. "
             << subtotal * porcentaje / 100.0 << "\\n";
    }

    // Descuentos adicionales por genero y edad.
    if (sexo == 'F' && cat == 4) {
        porcentaje = 10;
        cout << "       * Descuento femenino: 10% en Accesorios = Lps. "
             << subtotal * porcentaje / 100.0 << "\\n";
    }
    if (sexo == 'M' && cat == 2) {
        porcentaje = 5;
        cout << "       * Descuento masculino: 5% en Laptops y Computadoras = Lps. "
             << subtotal * porcentaje / 100.0 << "\\n";
    }
    if (edad >= 60) {
        porcentaje = 10;
        cout << "       * Tercera edad: 10% general = Lps. "
             << subtotal * porcentaje / 100.0 << "\\n";
    }

    // Promociones que dependen de comprar dos productos o varias unidades.
    if ((c == 5 || c == 12) && getCarrito(5) > 0 && getCarrito(12) > 0) {
        porcentaje = 7;
        cout << "       * Combo Gaming (Laptop Gamer + Teclado): 7% = Lps. "
             << subtotal * porcentaje / 100.0 << "\\n";
    }
    if (cat == 4 && q > 3) {
        porcentaje = 4;
        cout << "       * Compra por volumen (mas de 3 accesorios): 4% = Lps. "
             << subtotal * porcentaje / 100.0 << "\\n";
    }
    if (c == 10 && (getCarrito(1) > 0 || getCarrito(2) > 0 || getCarrito(3) > 0)) {
        porcentaje = 5;
        cout << "       * Proteccion movil (celular + audifonos): 5% = Lps. "
             << subtotal * porcentaje / 100.0 << "\\n";
    }
}

void sumarGananciaCategoria(int cat, double monto) {
    switch (cat) {
        case 1: gananciaCat1 += monto; break;
        case 2: gananciaCat2 += monto; break;
        case 3: gananciaCat3 += monto; break;
        case 4: gananciaCat4 += monto; break;
    }
}

// ======================= FACTURA =======================
/*
   Calcula subtotal, descuentos, ISV y total final. Tambien explica el origen
   de cada descuento y actualiza inventario y estadisticas de ventas.
*/
// Imprime la factura, actualiza inventario/estadisticas y devuelve el total a pagar
double facturar(string nombre, char sexo, int edad, int tipo) {
    double subtotalGeneral = 0, descuentoGeneral = 0;
    int puntosTotales = 0;

    cout << "\n\n=================================================================================================\n";
    cout << "                              PUMA TECH STORE - FACTURA\n";
    cout << "=================================================================================================\n";
    cout << "Cliente: " << nombre << "   |   Sexo: " << (sexo == 'M' ? "Masculino" : "Femenino")
         << "   |   Edad: " << edad << "\n";
    cout << "Tipo de cliente: "
         << (tipo == 1 ? "Estudiante" : (tipo == 2 ? "Profesional" : "Corporativo")) << "\n";
    cout << "-------------------------------------------------------------------------------------------------\n";
    cout << left << setw(5) << "COD" << setw(28) << "PRODUCTO" << right << setw(6) << "CANT"
         << setw(12) << "PRECIO" << setw(13) << "SUBTOTAL" << setw(8) << "DESC%"
         << setw(12) << "DESC Lps." << setw(14) << "TOTAL" << "\n";
    cout << "-------------------------------------------------------------------------------------------------\n";

    for (int c = 1; c <= 12; c++) {
        int q = getCarrito(c);
        if (q > 0) {
            double subtotal = q * getPrecio(c);
            double pct = porcentajeDescuento(c, tipo, sexo, edad);
            double desc = subtotal * pct / 100.0;
            double neto = subtotal - desc;

            cout << left << setw(5) << c << setw(28) << getNombre(c) << right << setw(6) << q
                 << fixed << setprecision(2) << setw(12) << getPrecio(c)
                 << setw(13) << subtotal << setw(7) << pct << "%"
                 << setw(12) << desc << setw(14) << neto << "\n";

            // Se detallan los motivos que generaron el porcentaje de descuento.
            if (pct > 0) {
                cout << "     Origen del descuento aplicado:\\n";
                mostrarDetalleDescuento(c, tipo, sexo, edad, subtotal);
            }

            subtotalGeneral += subtotal;
            descuentoGeneral += desc;
            puntosTotales += q * getPuntos(c);

            // Actualizar inventario y estadisticas
            setStock(c, getStock(c) - q);
            sumarVendidos(c, q);
            sumarGananciaCategoria(getCategoria(c), neto);   // subtotal - descuentos (sin ISV)
        }
    }

    // El ISV se calcula despues de restar todos los descuentos.
    double baseImponible = subtotalGeneral - descuentoGeneral;
    double impuesto = baseImponible * ISV;
    double total = baseImponible + impuesto;

    cout << "-------------------------------------------------------------------------------------------------\n";
    cout << fixed << setprecision(2);
    cout << right << setw(60) << "Subtotal:"            << setw(15) << subtotalGeneral << " Lps.\n";
    cout << right << setw(60) << "Descuentos:"          << setw(15) << descuentoGeneral << " Lps.\n";
    cout << right << setw(60) << "Total con descuento:" << setw(15) << baseImponible << " Lps.\n";
    cout << right << setw(60) << "ISV (15%):"           << setw(15) << impuesto << " Lps.\n";
    cout << right << setw(60) << "TOTAL A PAGAR:"       << setw(15) << total << " Lps.\n";
    cout << right << setw(60) << "TOTAL A PAGAR (USD):" << setw(15) << total / TASA_DOLAR << " USD\n";
    cout << "-------------------------------------------------------------------------------------------------\n";
    cout << "Puntos acumulados por esta compra: " << puntosTotales << " puntos\n";
    cout << "=================================================================================================\n";

    // Acumuladores del dia
    totalDescuentosDia += descuentoGeneral;
    totalISVDia += impuesto;
    totalGeneralDia += total;

    return total;
}

// ======================= PAGO =======================
void procesarPago(double total) {
    // El cliente puede elegir si desea pagar en lempiras o en dolares.
    cout << "\n--- MONEDA DE PAGO ---\n";
    cout << "1. Lempiras (Lps.)\n";
    cout << "2. Dolares (USD)\n";
    int moneda = leerEnteroRango("Seleccione la moneda (1-2): ", 1, 2);

    // Si elige dolares, se convierte el total con la tasa definida al inicio.
    double totalPagar = (moneda == 1) ? total : total / TASA_DOLAR;
    string unidad = (moneda == 1) ? "Lps." : "USD";

    cout << fixed << setprecision(2);
    cout << "\nTotal a pagar: " << unidad << " " << totalPagar << "\n";
    if (moneda == 2)
        cout << "Tasa utilizada: 1 USD = Lps. " << TASA_DOLAR << "\n";

    int metodo = menuMetodoPago();

    if (metodo == 1) {
        // EFECTIVO: permite recibir mas del total y calcula el cambio en la moneda elegida.
        double recibido;
        while (true) {
            recibido = leerMonto(string("Monto recibido (") + unidad + "): ");
            if (recibido + 0.001 >= totalPagar) break;
            cout << "  [ERROR] El monto es menor al total a pagar (" << unidad
                 << " " << totalPagar << ").\n";
        }
        double cambio = recibido - totalPagar;
        if (cambio < 0) cambio = 0;
        pagosEfectivo++;
        cout << "\nPago en EFECTIVO registrado.\n";
        cout << "Recibido: " << unidad << " " << recibido
             << "   |   Cambio: " << unidad << " " << cambio << "\n";
    } else {
        // TRANSFERENCIA: valida la referencia y exige el monto exacto en la moneda elegida.
        string referencia;
        while (true) {
            referencia = leerLinea("Numero de comprobante/referencia (solo numeros, 4 a 20 digitos): ");
            if (soloDigitos(referencia) && referencia.size() >= 4 && referencia.size() <= 20) break;
            cout << "  [ERROR] La referencia debe tener solo numeros (4 a 20 digitos).\n";
        }
        double monto;
        while (true) {
            monto = leerMonto(string("Monto transferido en ") + unidad + " (cantidad exacta): ");
            if (fabs(monto - totalPagar) < 0.01) break;
            cout << "  [ERROR] Debe ingresar la cantidad exacta: " << unidad
                 << " " << totalPagar << "\n";
        }
        string bancoEmisor = leerNombre("Banco de emision: ");
        string bancoDestino = leerNombre("Banco de destino: ");
        pagosTransferencia++;
        cout << "\nPago por TRANSFERENCIA registrado.\n";
        cout << "Referencia: " << referencia << "   |   Monto: " << unidad << " " << monto << "\n";
        cout << "Banco emisor: " << bancoEmisor << "   |   Banco destino: " << bancoDestino << "\n";
    }
}

// ======================= ESTADISTICAS =======================
/*
   Resume las ventas del dia: productos vendidos, ganancias por categoria,
   descuentos, ISV recaudado y metodos de pago utilizados.
*/
void mostrarEstadisticas() {
    cout << "\n\n=================================================\n";
    cout << "          ESTADISTICAS DEL DIA - PUMA TECH\n";
    cout << "=================================================\n";
    cout << "Clientes atendidos: " << clientesAtendidos << "\n\n";

    // 1) Producto mas vendido (se muestran todos los que empaten)
    int maximo = getVendidos(1);
    int minimo = getVendidos(1);
    for (int c = 2; c <= 12; c++) {
        if (getVendidos(c) > maximo) maximo = getVendidos(c);
        if (getVendidos(c) < minimo) minimo = getVendidos(c);
    }

    if (maximo == 0) {
        cout << "1. Producto mas vendido: no se realizaron ventas.\n";
        cout << "2. Producto menos vendido: no se realizaron ventas.\n";
    } else {
        cout << "1. Producto mas vendido (" << maximo << " unidades):\n";
        for (int c = 1; c <= 12; c++)
            if (getVendidos(c) == maximo) cout << "     - " << getNombre(c) << "\n";

        cout << "2. Producto menos vendido (" << minimo << " unidades):\n";
        for (int c = 1; c <= 12; c++)
            if (getVendidos(c) == minimo) cout << "     - " << getNombre(c) << "\n";
    }

    // 3) Ganancia por categoria
    cout << fixed << setprecision(2);
    cout << "3. Ganancia por categoria (sin ISV):\n";
    cout << "     " << left << setw(26) << "Celulares:"               << right << setw(14) << gananciaCat1 << " Lps.\n";
    cout << "     " << left << setw(26) << "Laptops y Computadoras:"  << right << setw(14) << gananciaCat2 << " Lps.\n";
    cout << "     " << left << setw(26) << "Tablets y Equipos:"       << right << setw(14) << gananciaCat3 << " Lps.\n";
    cout << "     " << left << setw(26) << "Accesorios:"              << right << setw(14) << gananciaCat4 << " Lps.\n";

    // 4, 5, 6) Totales
    cout << "4. Total descuentos aplicados del dia: Lps. " << totalDescuentosDia << "\n";
    cout << "5. Total ISV recaudado: Lps. " << totalISVDia << "\n";
    cout << "6. Total general vendido: Lps. " << totalGeneralDia
         << "  |  USD " << totalGeneralDia / TASA_DOLAR << "\n";

    // 7) Metodo de pago mas utilizado
    cout << "7. Metodo de pago mas utilizado: ";
    if (pagosEfectivo == 0 && pagosTransferencia == 0)
        cout << "sin pagos registrados\n";
    else if (pagosEfectivo > pagosTransferencia)
        cout << "Efectivo (" << pagosEfectivo << " pagos)\n";
    else if (pagosTransferencia > pagosEfectivo)
        cout << "Transferencia (" << pagosTransferencia << " pagos)\n";
    else
        cout << "Empate: Efectivo (" << pagosEfectivo << ") y Transferencia ("
             << pagosTransferencia << ")\n";
    cout << "=================================================\n";
}