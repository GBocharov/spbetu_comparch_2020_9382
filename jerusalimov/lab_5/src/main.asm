STACKSG SEGMENT  PARA STACK 'Stack'
        DW       1024 DUP(?)
STACKSG	ENDS

DATA      SEGMENT			                        ;SEG DATA
	KEEP_CS DW 0 ; ��� �������� ��������
	KEEP_IP DW 0 ; � �������� ������� ����������
	message DB 'Jerusalimov Nikita 9382  $';,10,13,'$' ;������ ��� ���������

DATA	ENDS						        ;ENDS DATA

CODE      SEGMENT   						;SEG CODE
ASSUME CS:CODE, DS:DATA, SS:STACKSG

WRITE_MSG  PROC FAR

	PUSH AX ; ������ ��������, ������� ����� ������
	PUSH DX ; � ���� ����
	
	MOV AH, 9H ; ���������� ��� ������
	MOV DX, OFFSET message ; �������� � DX �������� �� ���������
	INT 21H ; �������� ���������� � AH

	POP DX ; ����������� ��������, ������� ���������
	POP AX ; 
	MOV AL, 20H
	OUT 20H, AL

	IRET ; ����� ����������
WRITE_MSG ENDP ; ����� ���������

Main    PROC  FAR
   	PUSH DS
	SUB AX, AX
	PUSH AX
	MOV AX, DATA
	MOV DS, AX 

	MOV  AH, 35H   ; ������� ��������� �������� �������� ������� ����������
	MOV  AL, 60H   ; ����� �������
	INT  21H
	MOV  KEEP_IP, BX  ; ����������� ��������
	MOV  KEEP_CS, ES  ; � �������� ������� ����������

	;CLI
	PUSH DS
	MOV  DX, OFFSET WRITE_MSG ; �������� �� ���������
	MOV  AX, SEG WRITE_MSG    ; ������� ���������
	MOV  DS, AX               ; �������� � DS
	MOV  AH, 25H              ; ������� ��������� �������
	MOV  AL, 60H              ; ����� �������
	INT  21H                  ; ������ ����������
	POP  DS
	;STI		          ; ���������� ���� ����������
	
	int 60h;
	
	mov ah, 4Ch
	int 21h
	
 	RET
Main      ENDP
CODE      ENDS
END Main	