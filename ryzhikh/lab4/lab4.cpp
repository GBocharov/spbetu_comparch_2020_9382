#include <iostream>
#include <stdio.h>
#include <windows.h>
#define N 80
using namespace std;

int main() {

    system("chcp 1251 > nul");
    cout << "������������ ������ ����� 4, ������� 17\n"
        "�������������� ��������� �� ������� ������ ��������� ���� � ������� � ������������\n"
        "� ��������� ��������������, ��������� ������� ������� ������ ���������� � ��������\n"
        "������ ���������������. \n";
        "�������� ����� �.�. ������ 9382\n";
    char input[N+1];
    cin.getline(input, N+1);
    char output[N+1] = "";
    _asm {
        lea si, input
        lea di, output
        cld
        replacer:
            lodsb
        replacer_1:
            cmp al, 'a'; ���� < a �� �����
            jl WriteSymbol;

            cmp al, 'z'; ���� > z �� �����
            jg WriteSymbol;

            cmp al, 'a'
            je replace_a

            cmp al, 'b'
                je replace_b

            cmp al, 'c'
                je replace_c

            cmp al, 'd'
                je replace_d

            cmp al, 'e'
                je replace_e

            cmp al, 'f'
                je replace_f

            cmp al, 'g'
                je replace_g

            cmp al, 'h'
                je replace_h

            cmp al, 'i'
                je replace_i

            cmp al, 'j'
                je replace_j

            cmp al, 'k'
                je replace_k

            cmp al, 'l'
                je replace_l

            cmp al, 'm'
                je replace_m

            cmp al, 'n'
                je replace_n

            cmp al, 'o'
                je replace_o

            cmp al, 'p'
                je replace_p

            cmp al, 'q'
                je replace_q

            cmp al, 'r'
                je replace_r

            cmp al, 's'
                je replace_s

            cmp al, 't'
                je replace_t

            cmp al, 'u'
                je replace_u

            cmp al, 'v'
                je replace_v

            cmp al, 'w'
                je replace_w

            cmp al, 'x'
                je replace_x

            cmp al, 'y'
                je replace_y

            cmp al, 'z'
                je replace_z

                jmp WriteSymbol

                    replace_a:
                mov al, '�'
                    stosb
                    jmp replacer

                    replace_b :
                mov al, '�'
                    stosb
                    jmp replacer

                    replace_c :
                    lodsb
                    cmp al, 'h'
                    je replace_ch
                    mov bl, al
                    mov al, '�'
                    stosb
                    mov al, bl
                    jmp replacer_1

                    replace_ch:
                mov al, '�'
                    stosb
                    jmp replacer

                    replace_d :
                mov al, '�'
                    stosb
                    jmp replacer

                    replace_e :
                mov al, '�'
                    stosb
                    jmp replacer

                    replace_f :
                mov al, '�'
                    stosb
                    jmp replacer

                    replace_g :
                mov al, '�'
                    stosb
                    jmp replacer

                    replace_h :
                mov al, '�'
                    stosb
                    jmp replacer

                    replace_i :
                mov al, '�'
                    stosb
                    jmp replacer

                    replace_j :
                mov al, '�'
                    stosb
                    jmp replacer

                    replace_k :
                mov al, '�'
                    stosb
                    jmp replacer

                    replace_l :
                mov al, '�'
                    stosb
                    jmp replacer

                    replace_m :
                mov al, '�'
                    stosb
                    jmp replacer

                    replace_n :
                mov al, '�'
                    stosb
                    jmp replacer

                    replace_o :
                mov al, '�'
                    stosb
                    jmp replacer

                    replace_p :
                mov al, '�'
                    stosb
                    jmp replacer

                    replace_q :
                    mov al, '�'
                    stosb
                    mov al, '�'
                    stosb
                        jmp replacer

                    replace_r :
                mov al, '�'
                    stosb
                    jmp replacer

                    replace_s :
                    lodsb
                    cmp al, 'c'
                    je replace_sc
                    cmp al, 'h'
                    je replace_sh
                    mov bl, al
                    mov al, '�'
                    stosb
                    mov al, bl
                    jmp replacer_1

                    replace_sc:
                lodsb
                    mov bl, al
                    cmp al, 'h'
                    je replace_sch
                    mov al, '�'
                    stosb
                    mov al, '�'
                    stosb
                    mov al, bl
                    jmp replacer_1

                    replace_sch:
                mov al, '�'
                    stosb
                    jmp replacer

                    replace_sh:
                mov al, '�'
                    stosb
                    jmp replacer

                    replace_t :
                mov al, '�'
                    stosb
                    jmp replacer

                    replace_u :
                mov al, '�'
                    stosb
                    jmp replacer

                    replace_v :
                mov al, '�'
                    stosb
                    jmp replacer

                    replace_w :
                mov al, '�'
                    stosb
                    jmp replacer

                    replace_x :
                mov al, '�'
                    stosb
                    jmp replacer

                    replace_y :
                lodsb
                    cmp al, 'a'
                    je replace_ya
                    cmp al, 'u'
                    je replace_yu
                    cmp al, 'o'
                    je replace_yo
                    mov bl, al
                    mov al, '�'
                    stosb
                    mov al, bl
                    jmp replacer_1

                    replace_ya:
                mov al, '�'
                    stosb
                    jmp replacer

                    replace_yu :
                mov al, '�'
                    stosb
                    jmp replacer

                    replace_yo :
                mov al, '�'
                    stosb
                    jmp replacer

                    replace_z :
                lodsb
                    cmp al, 'h'
                    je replace_zh
                    mov bl, al
                    mov al, '�'
                    stosb
                    mov al, bl
                    jmp replacer_1

                    replace_zh:
                mov al, '�'
                    stosb
                    jmp replacer

            WriteSymbol:
                stosb
                    dec ecx
                    jns replacer

                mov al, 0

    }
    cout << output;
    return 0;
}