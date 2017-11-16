STACKSG SEGMENT PARA STACK 'Stack'
          DW    32 DUP(?)
STACKSG ENDS
DATASG SEGMENT PARA 'Data'
	a	DW 29,14,5
	c1	DW 35
	c2	DW 28
DATASG ENDS
CODESG SEGMENT PARA 'Code'
BEGIN  PROC    FAR
       ASSUME CS:CODESG,DS:DATASG,SS:STACKSG,ES:DATASG
	    PUSH DS;
		SUB  AX,AX;
		PUSH AX;
		MOV  AX,DATASG ;
		MOV DS,AX;
		MOV AX,a ; копіювати значення комірки пам'яті а до регістру АХ
		SUB AX,a+2 ; відняти від значення АХ, друге число комірки пам'яті а
				; значення зберегти в АХ
		MUL a+4 ; помножити АХ на значення третього числа комірки пам'яті а
				; значення зберегти в АХ	
		MOV BX,a 
		ADD BX,a+4 ; додати значення а(3) до значення регістру BX,
				; значення зберегти в ВХ
		MOV CX,c1
		ADD CX,c2
		MOV DX,a
		SAR DX,3 ; арифметичне зміщення вправо значення регістру DX
		NOT DX ; логічна операція інверсії всіх бітів регістра DX
cycle: 	test CX,1
		JNZ odd
		SUB BX,CX ; цей код ніколи не буде виконано, оскільки CX
				  ; завжди буде містити непарне число, тому,
				  ; за великим рахунком, можна не виконувати перевірку
		JMP cont
odd:	ADD BX,AX ; якщо число в CX непарне
cont:	cmp CX, 0FFFDh ; порівняти число в CX зі значенням -8
		JZ equal ; якщо число в CX != -8
		SUB CX,5
		JMP uneq
equal:	MOV CX,1 ; якщо число в CX == -8
uneq: 	LOOP cycle
		RET
BEGIN     ENDP
CODESG ENDS
END BEGIN 
