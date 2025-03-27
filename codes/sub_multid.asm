%macro write 2
	mov eax,4
	mov ebx,1
	mov ecx,%1
	mov edx, %2
	int 80h
%endmacro

%macro read 2
	mov eax,3
	mov ebx,2
	mov ecx,%1
	mov edx,%2
	int 80h
%endmacro

section .data
	input db 'Enter the number - '
	i_len equ $-input

	text1 db 'Difference of 2 numbers - '
	len1 equ $-text1

section .bss
	num1 resb 5
	num2 resb 5
	diff resb 5

section .text
	global _start

_start:
	write input,i_len
	read num1,5

	write input,i_len
	read num2,5

	mov esi,1
	mov ecx,3

	clc
	sub_loop:
	mov al,[num1+esi]
	sbb al,[num2+esi]
	aas
	pushf
	or al,30h
	popf

	mov[diff +esi],al
	dec esi
	loop sub_loop

	write text1,len1
	write diff,5

mov eax,1
mov ebx,0
int 80h
