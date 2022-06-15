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
        movsx EAX, A    // ������� �������� �������� ���������� A � ������ ��������
        imul EAX, EAX   // A*A = A^2
        mov P, EAX      // ������� A^2 � ���������� P

        movsx EAX, B    // ������� �������� �������� ���������� B � ������ ��������
        imul EAX, EAX   // B*B = B^2
        ADD P, EAX      // ��������� B^2 � ���������� P (P = A^2 + B^2)

        movsx EAX, C
        movsx EBX, C    // ������� �������� �������� ���������� B � ������ ��������
        imul EBX        // C*C = C^2
        imul EBX        // C^2 * C = C^3
        mov EBX, EAX
        movsx EAX, P    // ������� ��������
        cdq             // ���������� �������� ����� �� ���������� ��� ����������� ������ �����
        idiv EBX        // (A^2 + B^2) / C^3

        mov P, EAX      // ������� ��������� � ���������� ��� ������
        mov Rem, EDX     // ������� ������� � ���������� ��� ������ (���� ��� ���, �� ����� 0)

    }

    printf("\n P = %d \n Rem = %d", P, Rem);

    return 0;
}