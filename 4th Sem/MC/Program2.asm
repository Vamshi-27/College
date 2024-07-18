; ALP for Data Transfer,Arithematic and Logical Operations

    AREA Pgm2,CODE,READONLY
ENTRY
    LDR R0,=5
    LDR R1,=3

    ADD R2,R0,R1
    SUB R3,R0,R1
    MUL R4,R0,R1

    AND R5,R0,R1
    ORR R6,R0,R1
    EOR R7,R0,R1
XS  B   XS
    END