; ALP for sum of first 10 numbers

    AREA Sum,CODE,READONLY
ENTRY
    MOV R5,#10
    MOV R0,#0
    MOV R1,#1
REPEAT
    ADD R0,R0,R1
    ADD R1,#1
    SUBS R5,#1
    CMP R5,#0
    BNE REPEAT
    LDR R4,=RESULT
    STR R0,[R4];
XS  B   XS
    AREA DATA2,DATA,READWRITE
RESULT DCD 0X40000000
    END