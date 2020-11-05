#include <iostream>
#include <fstream>

#define n 80
int main() {
    system("chcp 1251 > nul");
    setlocale(LC_CTYPE, "rus");
    std::cout << "������� 15.\n���������� ������� ���� � ����, ��������� �� ������� ������, ��� ������������ �������� ������.\n������� 9382 �. - �� ��� ���\n";
    char str[n + 1];
    char answer[n + 1];
    std::cout << "������� ������ ��� ���������:\n";
    std::cin.getline(str, n+ 1);
    std::cout << "������ �� ���������:\n" << str << "\n";
    bool flag = false;
    for (int i = 0; i < strlen(str);i++)
        if (isalpha(str[i]))
            flag = true;
        if (flag) {
            _asm{
                    mov ecx, n;����� ������ � ecx
                    mov al, 0
                    lea    si, str; ������ � ds:si ����� str
                    lea di, answer; ������ � di ����� answer
                    cld; ��������� ����� �����������

                    data_processing:
                    lodsb; �������� ���� ���� �� ������ �� ������ ds:si � ������� al
                    cmp al, '�'
                    je for_exception; ���������� ���������
                    cmp al, '�'
                    je for_exception
                    cmp al, '�'
                    jl check_digit_case
                    cmp al, '�'
                    jg check_digit_case
                    loop data_processing
                    jmp finish_processing

                    for_exception:
                    loop data_processing

                    check_digit_case:; ���������� ����
                    cmp al, '0'
                    jl add_to_answer
                    cmp al, '9'
                    jg add_to_answer
                    loop data_processing

                    add_to_answer:
                    stosb; ��������� ������� al � ������ ������ �� ������ es:di
                    loop data_processing

                    finish_processing:
                    mov al, 0
                    stosb
            }
        } else {
            answer[0] = '\0';
        }
   std::cout << "����� ������������ ������:\n" << answer;
    std::fstream fout("output.txt");
    fout << "������ �� ���������:\n" << str << "\n����� ������������ ������:\n" << answer;
    return 0;
}