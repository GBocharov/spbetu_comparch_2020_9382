.586p
.model flat, c

.data
	SUPER_counter dd 0

.code
	public c single ;������������� �� ���������� ��������� �����
	single proc c main_arr:dword, main_len:byte, single_counter_arr:dword, min:byte
		push edi
		push esi
		push eax
		push ebx
		push ecx
		push edx
		
		mov eax, dword ptr min 		; ��������� ������ ������ �������� ����� � ��������,
		mov ecx, dword ptr main_len	; � ����� ����������� �������� � ����� ������� �����
		mov edi, main_arr
		mov esi, single_counter_arr
		
		counter:
			mov ebx,[edi]				; �������� ������� �����
			sub ebx,eax					; �������� �������� ������������ ������ �������� ( �������� - XMIN )
			mov edx,[esi+4*ebx]			; ���� �������� ��� ����� �����, ����������� � ��������
			inc edx						; ��������, ��� ����������� [���] ���� ���
			mov [esi+4*ebx],edx			; ���������� �������� � ������-�������
			add edi,4					; ��� � ���������� ��������
			loop counter

		pop edx
		pop ecx
		pop ebx
		pop eax
		pop esi
		pop edi
		
		ret
	single endp
	
	public c custom ;������������� �� ��������� ����������
	custom proc c single_counter_arr:dword, single_counter_len:byte, left_borders_arr:dword, custom_counter_arr:dword ,custom_counter_len:byte, min:byte
		push edi
		push esi
		push eax
		push ebx
		push ecx
		push edx
		
		mov ecx,dword ptr single_counter_len		; ������� ��� �����
		
		mov edi,dword ptr single_counter_len		; ��������� �� ��������� ������� �������-�������� ��������� ����� (��������� ��������� �����)
		dec edi
		shl edi,2
		add edi,single_counter_arr
		
		mov eax, dword ptr custom_counter_len 		; �������� ������������ ������ ���� �������� : ����� ������ � �������� ��������� � ��������
		dec eax
		shl eax,2
		
		push edi
		mov esi, left_borders_arr
		mov edi, custom_counter_arr
		add edi,eax
		add esi,eax						; ������ � ESI ��������� �� ��������� ������� ������� ����� ������
		mov SUPER_counter,edi			; � ������ � ������ ��������� �� ��������� ������� �������� ���������
		pop edi
		
		sub eax,eax
		mov eax, dword ptr min
		add eax, ecx					; ������ � EAX ����������� ���������� (� ������ ���������) �������� ������� ��������� �����
		dec eax
		mov ebx,[esi]					; ������ � EBX ������������ ����� �������
		
		counter:
			cmp eax,ebx					; ���� ����� ������ ����� �������, �� ...(��. [*])
			
			jl lower
				push eax
				push esi					; ���� �� ������ ��� �����, ��
				mov esi,SUPER_counter		; �������� � ESI ������� ��� �������
				mov edx,[esi]				; ������� ��� �������� � EDX
				mov eax,[edi]				; �������� ���������� ��������� � ���� ��������� �������� ������� �����
				add edx,eax					; ���������� ��� ����������
				mov [esi],edx				; ���������� ������� � ������� ��� ����������� ���������� ��, ��� �� ��������
				pop esi
				pop eax
				jmp to_previous
			
			lower:					; [*]
			sub esi,4					;  ...���� ������� ����� �������,
			sub SUPER_counter,4			; �������� �������, ������� ����� ������� ���������� ��������� ��� ��,
			mov ebx,[esi]				; ������� ����� ������� � EBX
			jmp counter

				to_previous:
				dec eax						; ����� ������ ��������� ��������������� ����� � ��������� �� ������� ��� ��������� ����������
				sub edi,4
				loop counter

		pop edx
		pop ecx
		pop ebx
		pop eax
		pop esi
		pop edi
		
		ret
	custom endp
end