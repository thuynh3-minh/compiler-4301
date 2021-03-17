; Minh Huynh
; CS 3304
; Lab 12

%INCLUDE "Along32.inc"
%INCLUDE "Macros_Along.inc"

SECTION .text
global  _start

_start: 
	mov     edx,buffer
        mov     ecx,buflen
	call    ReadString      ; read a line from stdin containing u & v
	
%if 0
	mov     esi,buffer      ; put address of memory area in esi
        mov     ecx,buflen      ; put length of area to display in ecx
        mov     ebx,1           ; 1 = byte, 2 = word, 4 = doubleword
        call    DumpMem
%endif

	mov     edx,buffer      ; find where the first integer begins
.L0:
        cmp     byte [edx],' '
        jne     .L1
        inc     edx
        jmp     .L0
.L1:
        mov     ecx,buflen
	call    ParseInteger32  ; parse buffer for the first integer
        mov     [u],eax         ; store first integer in u
.L2:                            ; find where the first integer ends
        cmp     byte [edx],' '
        je      .L3
        inc     edx
        jmp     .L2
.L3:
        mov     ecx,buflen      ; parse buffer for the second integer
	call    ParseInteger32
        mov     [v],eax         ; and store in v
        
  	mov	edx,umsg        ; write descriptive message & u to stdout
  	call	WriteString
        mov     eax,[u]
        call    WriteInt
        call    Crlf

  	mov	edx,vmsg        ; write descriptive message & v to stdout
  	call	WriteString
        mov     eax,[v]
        call    WriteInt
        call    Crlf
	
	

; put the rest of Lab 12 code here

		mov eax,[v]
		cmp eax, 0
		jge	checkU ;( if v >= 0 -> check u)
		;else v <= 0}
	mov ebx, -1
	mul ebx 
	mov [v],eax 
		
	checkU:
		mov eax,[u]
		cmp eax,0 
		jge doGCD ;if u >= 0 -> do GCD
		;else u <= 0 , convert to positive
	mov ebx, -1
	mul ebx 
	mov [u],eax  
		
	doGCD:
		mov eax, [v]
		mov ebx, [u]
		cmp eax, ebx 
		jg exchange ;if v > u then swap u and v 
		je outPutResult ; if u = v then gcd = u 
	
				mov eax,[v] ; check v = 0
				cmp eax , 0
				je outPutResult ; print out gcd = u 
				
				xor edx,edx 
				mov eax, [u]
				mov ebx, [v]
				div ebx 
				
				mov eax, [v]
				mov [u], eax  ;u = v 
				mov [v], edx ; v = remainder
				call doGCD 
			;}
		;}
	exchange:
		mov ecx,[v]
		mov ebx,[u]
		call DumpRegs
		mov [v],ebx
		mov [u], ecx 
		call doGCD
	
	outPutResult:
		mov 	edx, gcdmsg
		call 	WriteString	
		mov 	eax, [u]
		call 	WriteInt	
		call 	Crlf
	Exit    {0}


	Exit    {0}

SECTION .data
umsg    db      'u = ',0
vmsg    db      'v = ',0
gcdmsg  db      'gcd = ',0
buffer  times   50 db 0
buflen  equ     ($ - buffer)	

SECTION .bss
u       resd    1
v       resd    1
