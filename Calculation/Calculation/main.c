#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
    short int A, B, C;
    int P, Rem;

    printf("Enter A, B and C: ");
    scanf("%hi %hi %hi", &A, &B, &C);

    __asm
    {
        movsx EAX, A    // Помещаю введённое значение переменной A в разные регистры
        imul EAX, EAX   // A*A = A^2
        mov P, EAX      // Помещаю A^2 в переменную P

        movsx EAX, B    // Помещаю введённое значение переменной B в разные регистры
        imul EAX, EAX   // B*B = B^2
        ADD P, EAX      // Прибавляю B^2 к переменной P (P = A^2 + B^2)

        movsx EAX, C
        movsx EBX, C    // Помещаю введённое значение переменной B в разные регистры
        imul EBX        // C*C = C^2
        imul EBX        // C^2 * C = C^3
        mov EBX, EAX
        movsx EAX, P    // Помещаю значение
        cdq             // Расширение двойного слова до четверного для правильного вывода знака
        idiv EBX        // (A^2 + B^2) / C^3

        mov P, EAX      // Помещаю результат в переменную для вывода
        mov Rem, EDX     // Помещаю остаток в переменную для вывода (если его нет, то будет 0)

    }

    printf("\n P = %d \n Rem = %d", P, Rem);

    return 0;
}