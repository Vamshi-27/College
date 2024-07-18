; Enabling and Disabling of fast interrupts in ARM

    AREA FInterrupt, CODE, READONLY
ENTRY
    MRS R1,CPSR
    BIC R1,R1,#0x40
    MSR CPSR_c,R1
XS  B   XS
    END