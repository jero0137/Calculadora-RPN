#include <stdio.h>
#include <math.h>
#include <stdint.h>

float stack[8];

// Imprime el stack por consola
void imprimirStack(void)
{

    for (int i = 7; i >= 0; i--)
    {
        printf("%d. ", i + 1);
        printf("%f", stack[i]);
        printf("\n");
    }
}
void imprimirMenu(void)
{
    printf("Que desea hacer\n");
    printf("[ 1. Ingresar numero al stack ] [ 2. Seleccionar operacion ]\n[ 3. Limpiar ultimo ] [ 4. Limpiar todo ]\n[ 5. Salir ] \n");
}

void imprimirMenuOperaciones(void)
{
    printf("Suma(+) Resta(-) Multiplicacion(*) Division(/) Seno(s) Coseno(c) Tangente(t) Raiz(r) potencia(p): ");
}

void moveStackUp(void)
{
    for (int i = 0; i < 8; i++)
    {
        stack[i - 1] = stack[i];
    }
    stack[7] = 0;
}

void moveStackDown(void)
{

    for (int i = 7; i > 0; i--)
    {
        stack[i] = stack[i - 1];
    }
    stack[0] = 0;
}

int main(void)
{
    int opcion = 0;
    float nro;
    float resultado;
    char operacion;
    do
    {
        printf("------ CALCULADORA RPN ------\n");

        imprimirStack();
        imprimirMenu();
        scanf("%d", &opcion);

        switch (opcion)
        {
        // Ingresar numero al stack
        case 1:;
            printf("\033[2J");
            imprimirStack();
            printf("Ingrese numero: ");
            scanf("%f", &nro);
            moveStackDown();
            stack[0] = nro;
            printf("\033[2J");
            break;
        // Seleccionar una operacion
        case 2:
            printf("\033[2J");
            imprimirStack();
            imprimirMenuOperaciones();
            scanf(" %c", &operacion); // Dejamos un espacio, para que no tome en cuenta un espacio vacio o salto de linea como caracter ingresado

            switch (operacion)
            {
            case '+':
                imprimirStack();
                resultado = stack[1] + stack[0];
                moveStackUp();
                stack[0] = round(resultado);
                printf("\033[2J");
                break;

            case '-':
                imprimirStack();
                resultado = stack[1] - stack[0];
                moveStackUp();
                stack[0] = round(resultado);
                printf("\033[2J");
                break;

            case '*':
                imprimirStack();
                resultado = stack[1] * stack[0];
                moveStackUp();
                stack[0] = round(resultado);
                printf("\033[2J");
                break;

            case '/':
                imprimirStack();
                if (stack[0] != 0)
                {

                    resultado = stack[1] / stack[0];
                    moveStackUp();
                    stack[0] = round(resultado);
                    printf("\033[2J");
                }
                else
                {
                    printf("\033[2J");
                    printf("MATH ERROR!\n");
                }

                break;

            case 'r':
                imprimirStack();
                if (stack[0] > 0)
                {
                    resultado = sqrt(stack[0]);
                    stack[0] = round(resultado);
                    printf("\033[2J");
                }
                else
                {
                    printf("\033[2J");
                    printf("MATH ERROR!\n");
                }

                break;

            case 'p':
                imprimirStack();
                resultado = pow(stack[1], stack[0]);
                moveStackUp();
                stack[0] = round(resultado);
                printf("\033[2J");
                break;

            case 's': // Seno
                imprimirStack();
                resultado = sin(stack[0]);
                stack[0] = round(resultado);
                printf("\033[2J");
                break;

            case 'c': // Coseno
                imprimirStack();
                resultado = cos(stack[0]);
                stack[0] = resultado;
                printf("\033[2J");
                break;

            case 't': // Tangente
                imprimirStack();
                if (stack[0] != 90)
                {
                    resultado = tan(stack[0]);
                    stack[0] = round(resultado);
                    printf("\033[2J");
                }
                else
                {
                    printf("\033[2J");
                    printf("MATH ERROR!\n");
                }

                break;

            default:
                printf("\033[2J");
                printf("Esta operacion no es valida");
                break;
            }

            break;
        // Limpiar ultimo
        case 3:
            moveStackUp();
            printf("\033[2J");
            break;

        case 4:
            for (int i = 0; i < 7; i++)
            {
                stack[i] = 0;
            }
            printf("\033[2J");
            break;
        default:;
            printf("\033[2J");
            printf("Esta opcion no existe\n");
            break;
        }

    } while (opcion != 5);
}