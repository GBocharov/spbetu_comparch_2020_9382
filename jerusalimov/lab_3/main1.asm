STACKSG SEGMENT  PARA STACK 'Stack'
          DW       32 DUP(?)
STACKSG	ENDS

DATASG  SEGMENT  PARA 'Data'				;SEG DATA
     a	    DW	2h
     b	    DW	4h
     i	    DW	1h
     k      DW  3h
     i1     DW  ?
     i2     DW  ?
     res    DW  ?
DATASG	ENDS								;ENDS DATA

CODE      SEGMENT   						;SEG CODE
ASSUME  DS:DATASG, CS:CODE

Main    PROC  FAR
     	mov  ax, DATASG
     	mov  ds, ax

f1:
    mov ax, a ;�������� � �� �
    cmp ax, b   ;�������� � � b
    jle f1_jle      ;a<=b

    ;a>b(jg)
    mov ax, i   ;� �� �������� i
    shl ax, 1   ;�������� �� �� 2
    mov i2, ax  ;�������� � i2 ��
    mov bx, -2  ; ��������� ������ �� ������ ������� �������� -2 �������� �� � bx
    sub i2, bx  ; ������ �� i2 bx � �������� ����� � i2
    ;end f2 

    shl ax, 1   ; �������� ax �� 2
    mov bx, 7   ; �������� ������ �������� 7 �������� ��
    sub bx, ax  ;����� �� 7 ax
    mov i1, bx  ;�������� ����� � i1
    jmp f3

f1_jle: ;a <= b
    mov ax, i
    mov bx, 2
    mov i2, ax
    shl ax, 1
    add i2, ax
    neg i2
    add i2, bx
    ;end f2

    mov bx, i
    shl ax, 1
    shl bx, 1
    add ax, bx
    mov bx, 8
    sub bx, ax
    mov i1, bx
    jmp f3

f3:
     mov ax, k          ; ������ � ax ���������� k
     cmp ax, 0          ; ������� k � 0
     jge f3_jge         ; k >= 0

                        ; ���� ��������� �����, �� k < 0 (jl)
     mov ax, i1         ; ������ � ax ���������� i1
     sub ax, i2         ; ax = i1 - i2

     cmp ax, 0          ; ������� i1 - i2 � �����
     jl f3_ABS          ; ���� i1 - i2 < 0, �� ����� ����� ������
     jmp f3_jl_result   ; ������� � f3_jl_result

f3_ABS:
     neg ax             ; ����� ������ i1 - i2

f3_jl_result:
     cmp ax, 2h         ; ������� |i1 - i2| � 2
     jge f3_jl_result_jge; ���� |i1 - i2| >= 2, ������������ � f3_jl_result_jge
     mov res, ax        ; |i1 - i2| < 2 => res = |i1 - i2|
     jmp end_f          ; ��������� ���������

f3_jl_result_jge:
     mov res, 2h        ; |i1 - i2| >= 2 => res = 2
     jmp end_f          ; ��������� ���������

f3_jge:                 ; k >= 0
     mov ax, i2         ; ������ � ax ���������� i2
     neg ax             ; ax = -ax
     cmp ax, -6h        ; ���������� ax, -6
     jle f3_jge_jle     ; ���� -i2 <= -6, ������������ � f3_jge_jle
     mov res, ax        ; -i2 > -6 => res = -i2
     jmp end_f          ; ��������� ���������

f3_jge_jle:
     mov res, -6h       ; -i2 <= -6 => res = -6

end_f:
     mov ah, 4ch        ; � ������� �������� ���������
     int 21h


Main      ENDP
CODE      ENDS
END Main				;ENDS CODE
