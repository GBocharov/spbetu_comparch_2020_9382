.686
.MODEL FLAT, C
.STACK
.DATA
.CODE
MAS_INTERVAL PROC C array_size:dword, arr:dword, left_boarders:dword, res_arr:dword
mov ecx, 0; ������� ��� ������� �� ������� �����
mov ebx, arr ; ebx ��������� �� ������ ������� �����
mov edi,left_boarders; edi ��������� �� ������ ������� ����� ������
traverse_numbers:
	mov eax,[ebx]; � eax ����� ������� �������
	push ebx; ��������� ��������� �� ������� �������
	mov ebx,0; �������� ���������

traverse_borders: ;����� ebx - ������� ������
	mov edx,ebx; � edx ����� �������� ������ ������� ������
	shl edx,2; ���� ������ �������� �� 4, �.�. ������ ������� �� 4 �����
	cmp eax,[edi+edx]; ���������� �������� ������� � �������� ����� �������� (left_boarders + 4*i), i -����� ��������
	jle matched_interval; ���� ����� ������ ���� ����� ����� �������, �� ���� � matched_interval
	
	inc ebx; �������������� ���������
	jmp traverse_borders; �.�. ���� ����� ������ ����� 

matched_interval:
	add edx,res_arr; edx - ����� ��� left_boarders, ����� �������� edx ��������� �� ������� � res_arr ������� ����� ����������������

	mov eax,[edx];������� ���������� ���������� ����� �������
	inc eax;���������� � ��� �������
	mov [edx],eax;��������� �� �������

	pop ebx;������� ������� ����� ��� ������� �����

	add ebx,4; ���������� ��������� �� ��������� ������� ������� �����
	inc ecx; �������������� ���������� ����������� ���������
	cmp ecx,array_size; �������, ����������� �� �� ��� ��������
	jl traverse_numbers; ���� ��� �� ���, �� ����������
ret
MAS_INTERVAL ENDP
END
