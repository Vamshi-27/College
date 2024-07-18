; Enabling and Disabling the Interrupts in ARM
	TTL program to enable I interrupt
	AREA Interrupt, CODE, READONLY
ENTRY
    MRS R1,CPSR
    BIC R1,R1,#0x80
    MSR CPSR_c,R1
XS  B   XS
    END