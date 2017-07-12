
;; add_numbers_bridge
function_index equ	 1			 ;; index of function to call

IFDEF RAX
;; 64 bit assembly

;; EXTERNs here
;; EXTERN MessageBoxA: PROC
EXTERN c_ext_intercepts: QWORD	 ;; array of function pointers.

.DATA
.CODE

PUBLIC add_numbers_bridge
add_numbers_bridge PROC

	;; jmp to value at index value of r10 * sizeof(qword)
	LEA	RAX, c_ext_intercepts
	MOV RAX, [RAX + function_index * 8]
	jmp	QWORD PTR RAX

add_numbers_bridge ENDP

ELSE
;; 32 bit assembly

.586
.MODEL FLAT, C
.STACK
.DATA
.CODE

;; EXTERNs here
EXTERN c_ext_intercepts: DWORD	;; array of function pointers

PUBLIC add_numbers_bridge
add_numbers_bridge PROC

	LEA		EAX, c_ext_intercepts
	MOV		EAX, [EAX + function_index * 4]
	jmp		DWORD PTR EAX

add_numbers_bridge ENDP

ENDIF
END

