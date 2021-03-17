;Min Huynh
;CS4301
;lab11
%INCLUDE "Along32.inc"
%INCLUDE "Macros_Along.inc"

SECTION .text
global  _start

_start:
	;input X 
	call ReadInt 
	mov [x],eax
	
	;CALCULATE REMAINDER a
	;Firstly by using DIV or IDIV, where the remainder will be put into EDX
	; need to zero EDX first 
	xor edx, edx;Clear the destinations for outputs. this stops the garbage remainder
	;Operand Size -----------| Dividend | Divisor | Quotient | Remainder
	;Quadword/doubleword     | EDX:EAX  |  r/m32  |   EAX    |   EDX. 
	mov ebx,19 
	div ebx  
	mov [a], edx ; got remainder a
	
	;CALCULATE quotient b = x/ 100 and remainder c
	;EAX NOW IS QUOTIENT from x / 19 from readInt

	;EAX for divisor  -> eax : ebx ==  x / 100
	;EBX for dividend
	mov eax,[x] ; now eax is x for div  
	xor EDX, EDX;;Clear the destinations for outputs.
	mov ebx,100
	div ebx
	mov [b],eax ; save quotient in b
	mov [c],edx ; save remainder in c
	
	;Calculate quotient d = b/4 == eax : ebx
	;calculate remainder e
	mov eax, [b]
	
	xor EDX, EDX;;Clear the destinations for outputs.
	mov ebx,4
	div ebx
	mov [d], eax; save quotient in d 
	mov [e], edx; save remainder in e 
	
	;Calulate quotient f =( b+ 8 ) /25
	mov eax, [b]
	add eax, 8
	xor EDX, EDX
	mov ebx,25
	div ebx
	mov [f], eax
	
	;Calculate quotient g= (b-f+1) /3 
	mov eax, [b]
	add eax , 1
	sub eax, [f]
	
	xor edx,edx
	mov ebx , 3
	div ebx
	
	mov [g], eax ;save quotient in g
	
	;calculate remainder h = (19a + b -d -g + 15 )/ 30
	mov eax, [a]
	mov ebx, 19
	mul ebx ; 19a in eax 
 
	add eax,[b] ; 19a+b
	sub eax, [d]
	sub eax , [g]
	add eax , 15 
	 
	xor edx, edx
	
	mov ebx , 30
	div ebx 
	mov [h],edx ; save remainder in h 
	
	;calculate quotient i = c / 4
	;and remainder k
	mov eax, [c]
	mov ebx , 4
	
	xor edx, edx
	div ebx
	mov [i], eax
	mov [k] , edx 
	
	;calculate remainder l = 32 + 2e + 2i - h - k % 7
	mov ecx, 32
	mov eax, [e]
	mov ebx,2
	mul ebx       ;2e
	add ecx , eax ; 2e + 32
	
	mov eax, [i]
	mov ebx, 2
	mul ebx 
	add eax ,ecx ; 2e + 32 + 2i 
	
	sub eax,[h]
	sub eax ,[k]
	
	xor edx, edx
	mov ebx, 7
	div ebx
	mov [l], edx ; save remainder on l 
	
	;calculate quotient m 
	mov      eax,[h]
	mov      ebx,11
	mul      ebx
	mov      ecx,eax ;11h in ecx
	mov      eax,[l]
	mov      ebx,22
	mul      ebx
	add      eax,ecx ; 22l + 11h
	add      eax,[a] ; 22l + 11h + a
	xor      edx,edx
	mov      ecx,451
	div      ecx
	mov      [m],eax ; save quotient m32
	
	;calculate quotient n = h + l - 7m + 114 / 31
	;and remainder p 
	
	mov      eax,[m]
	mov      ebx,7
	mul      ebx
	mov      ecx,eax
	mov      eax,[h]
	add      eax,[l]
	sub      eax,ecx
	add      eax,114
	xor      edx,edx
	mov      ecx,31
	div      ecx
	mov      [n],eax
	mov      [p],edx ; p is the E day 
	
	;Now  print out the message for input
	mov edx, msg1
	call WriteString
	
	;
	mov eax, [n]
	cmp eax , 4 ;compare n and 4
	;if it equal then is April 
	je isApril ;jupm to function isApril 
	
	;else 
	mov edx, march
	call WriteString
	;jump to function writeDay 
	jmp writeDay
	
	;condition for April
	isApril:
	mov edx, april
	call WriteString
	
	
	writeDay:
	mov eax, [p]
	add eax ,1
	call WriteDec
	
	mov edx, msg2
	call WriteString
	mov eax,[x]
		
	call WriteDec
	call Crlf
	  
	
	Exit{0}
section .data
msg1      db       'Easter Sunday:   ',0
msg2      db       ', ',0
april     db       'April ',0
march     db       'March ',0

section .bss 
x resd 1; input Int 

a	resd 1; remainder 
b	resd 1; quotient
c	resd 1;remainder
d	resd 1;	quotient
e	resd 1; remainder
f	resd 1; quotient
g	resd 1; quotient
h	resd 1; remainder
i 	resd 1; quotient
k	resd 1; remainder
l  	resd 1; remainder
m 	resd 1; quotient
n 	resd 1; quotient
p 	resd 1; remainder
