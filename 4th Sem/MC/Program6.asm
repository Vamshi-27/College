; ALP to count thne no of 0's and 1's in two consecutive memoryh locations

    AREA OneZero,CODE,READONLY
ENTRY
    MOV R2,#0
    MOV R3,#0
    MOV R7,#2
    LDR R6,=VALUE
LOOP   
    MOV R1,#32
    LDR R0,[R6],#4
LOOP0
    MOVS R0,R0,ROR #1
    BHI ONES
ZEROS
    ADD R3,R3,#1
    B LOOP1
ONES
    ADD R2,R2,#1
LOOP1
    SUBS R1,R1,#1
    BNE LOOP0
    SUBS R7,R7,#1
    CMP R7,#0
    BNE LOOP
STOP    B   STOP
VALUE DCD 0X11112222,0X01948612
    END