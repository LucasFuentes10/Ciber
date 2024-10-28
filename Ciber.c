#include <stdio.h>
#include <string.h>

#define MAX_CUENTAS 5
#define MIN_CUENTA 1

struct Cuentas {
    char nombre[50];
    char clave[50];
};

struct admin {
    char admin[50];
    char clave[50];
};

struct Cuentas usuarios[MAX_CUENTAS];
int totalUsuarios = 0;

struct admin admins[MIN_CUENTA] = {{"admin", "1234"}}; 

void menuUsuario();
void menuAdmin();
void precios();
void tiempoRestante();
void historial();
int calculadora();
void VerUsuarios(struct Cuentas usuarios[], int totalUsuarios);
int buscarCuentaUsuario(char nombre[], char clave[]);
int buscarCuentaAdmin(char nombre[], char clave[]);
void iniciarSesion(int tipoSesion);
void CrCuUsuario();
void crearCuenta();
int menu();
int salir();

int buscarCuentaUsuario(char nombre[], char clave[]) {
    for (int i = 0; i < totalUsuarios; i++) {
        if (strcmp(usuarios[i].nombre, nombre) == 0 && strcmp(usuarios[i].clave, clave) == 0) {
            printf("Cuenta de usuario encontrada: %s\n", usuarios[i].nombre);
            return 1;  
        }
    }
    printf("Cuenta de usuario no encontrada.\n");
    return 0;
}

int buscarCuentaAdmin(char nombre[], char clave[]) {
    for (int i = 0; i < MIN_CUENTA; i++) {
        if (strcmp(admins[i].admin, nombre) == 0 && strcmp(admins[i].clave, clave) == 0) {
            printf("Cuenta de administrador encontrada: %s\n", admins[i].admin);
            return 1;  
        }
    }
    printf("Cuenta de administrador no encontrada.\n");
    return 0;
}

void iniciarSesion(int tipoSesion) {
    char nombre[50], clave[50];
    
    printf("Ingrese su nombre de usuario:\n");
    scanf("%s", nombre);
    printf("Ingrese su contraseña:\n");
    scanf("%s", clave);
    
    if (tipoSesion == 1) { 
        if (buscarCuentaAdmin(nombre, clave)) {
            menuAdmin();  
        }
    } else if (tipoSesion == 2) { 
        if (buscarCuentaUsuario(nombre, clave)) {
            menuUsuario();  
        }
    }
}

void VerUsuarios(struct Cuentas usuarios[], int totalUsuarios) {
    printf("Usuarios registrados:\n");
    for (int i = 0; i < totalUsuarios; i++) {
        printf("Nombre: %s, Contraseña: %s\n", usuarios[i].nombre, usuarios[i].clave);
    }
}

void menuUsuario() {
    int opcion;
    do {
        printf("\nMenu de Usuario\n");
        printf("1_ Ver tiempo restante\n");
        printf("2_ Ver historial\n");
        printf("3_ Calculadora\n");
        printf("4_ Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                tiempoRestante();
                break;
            case 2:
                historial();
                break;
            case 3:
                calculadora();
                break;
            case 4:
                printf("Saliendo del menu de usuario...\n");
                break;
            default:
                printf("Opcion no valida.\n");
                break;
        }
    } while (opcion != 4);
}

int calculadora() {
    float g = 0, h = 0, resultado = 0;
    char op; 
    do {
        printf("Primer número: ");
        scanf("%f", &g);
        printf("Segundo número: ");
        scanf("%f", &h);
        printf("Operación (+, -, /, *) o '1' para salir: ");
        scanf(" %c", &op); 
        
        if (op == '1') { 
            break;
        }

        switch (op) {
            case '+':
                resultado = g + h;
                printf("Resultado: %.2f\n", resultado);
                break;
            case '*':
                resultado = g * h;
                printf("Resultado: %.2f\n", resultado);
                break;
            case '/':
                if (h != 0) { 
                    resultado = g / h;
                    printf("Resultado: %.2f\n", resultado);
                } else {
                    printf("Error: División por cero.\n");
                }
                break;
            case '-':
                resultado = g - h;
                printf("Resultado: %.2f\n", resultado);
                break;
            default:
                printf("Operador inválido.\n");
                break;
        }
    } while (1);
    
    return 0;
}

void menuAdmin() {
    int opcion;
    do {
        printf("\nMenu de Administrador\n");
        printf("1_ Ver computadoras\n");
        printf("2_ Ver precios\n");
        printf("3_ Ver Usuarios Registrados\n");
        printf("4_ Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Mostrando las computadoras (contenido pendiente)...\n");
                break;
            case 2:
                precios();
                break;
            case 3:
                VerUsuarios(usuarios, totalUsuarios);
                break;
            case 4:
                printf("Saliendo del menú de administrador...\n");
                break;
            default:
                printf("Opción no válida.\n");
                break;
        }
    } while (opcion != 4);
}

void CrCuUsuario() {
    if (totalUsuarios < MAX_CUENTAS) {
        printf("\tMenu para agregar un usuario\n");
        printf("Ingrese su nombre de usuario: \n");
        scanf("%s", usuarios[totalUsuarios].nombre);
        printf("Ingrese su contraseña: \n");
        scanf("%s", usuarios[totalUsuarios].clave);
        totalUsuarios++;
        printf("Registro realizado con exito!\n");
    } else {
        printf("Se ha alcanzado el límite de usuarios.\n");
    }
}

void crearCuenta() {
    CrCuUsuario();
}

void precios() {
    printf("LISTA DE PRECIOS\n");
    printf("-------------------------\n");
    printf("1 hs = $700\n");
    printf("2 hs = $1300\n");
    printf("4 hs = $2000\n");
    printf("16 hs = $7000\n");
    printf("Presione enter para volver\n");
    getchar();
    getchar();
}

void tiempoRestante() {
    printf("Función de tiempo restante (pendiente de implementación)...\n");
}

void historial() {
    printf("Función de historial (pendiente de implementación)...\n");
}

int menu() {
    int op = 0;
    printf("\t\tBIENVENIDO AL CIBER DEL PIBE.\n");
    while (op != 4) {
        printf("1_ Iniciar sesion.\n");
        printf("2_ Crear cuenta.\n");
        printf("3_ Precios.\n");
        printf("4_ Salir.\n");
        printf("Opcion seleccionada:");
        scanf("%d", &op);
        if (op >= 1 && op <= 4) {
            return op;
        } else {
            printf("Opcion no valida...\n");
        }
    }
    return 0;
}

int salir() {
    int op = 0;
    printf("¿Esta seguro que quiere cerrar sesion?\n");
    printf("1_ Si.\n");
    printf("2_ No.\n");
    scanf("%d", &op);
    switch (op) {
    case 1:
        printf("Saliendo, tenga un excelente dia...\n");
        return 1;
    case 2:
        printf("Regresando al menu principal...\n");
        return 0;
    default:
        printf("Opcion no valida.\n");
        break;
    }
    return 0;
}

int main() {
    int op = 0;

    do {
        op = menu();
        switch (op) {
        case 1: {
            int tipoSesion;
            printf("Seleccione el tipo de inicio de sesion:\n");
            printf("1_ Administrador\n");
            printf("2_ Cliente\n");
            scanf("%d", &tipoSesion);
            iniciarSesion(tipoSesion);
            break;
        }
        case 2:
            crearCuenta();
            break;
        case 3:
            precios();
            break;
        case 4:
            salir();
            break;
        default:
            printf("Opcion no valida.\n");
            break;
        }
    } while (op != 4);
    
    return 0;
}