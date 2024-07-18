; Enabling and Disabling the Interrupts in ARM

TIL program to enable I interrupt

    AREA Interrupt, CODE, READONLY
ENTRY
    MOV R0,CPSR
    BIC R0,R0,#0x80
    MOV CPSR_c,R1
XS  B   XS
    END