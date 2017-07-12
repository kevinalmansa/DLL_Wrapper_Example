
;; print_hello_bridge
function_index equ	 0			 ;; index of function to call

IFDEF RAX
;; 64 bit assembly

;; EXTERNs here
;; EXTERN MessageBoxA: PROC
EXTERN c_ext_intercepts: QWORD	 ;; array of function pointers.

.DATA
.CODE

PUBLIC print_hello_bridge
print_hello_bridge PROC

	;; jmp to value at index value of r10 * sizeof(qword)
	LEA	RAX, c_ext_intercepts
	MOV RAX, [RAX + function_index * 8]
	jmp	QWORD PTR RAX

print_hello_bridge ENDP

ELSE
;; 32 bit assembly

.586
.MODEL FLAT, C
.STACK
.DATA
.CODE

;; EXTERNs here
EXTERN c_ext_intercepts: DWORD	;; array of function pointers

PUBLIC print_hello_bridge
print_hello_bridge PROC

	LEA		EAX, c_ext_intercepts
	MOV		EAX, [EAX + function_index * 4]
	jmp		DWORD PTR EAX

print_hello_bridge ENDP

ENDIF
END

