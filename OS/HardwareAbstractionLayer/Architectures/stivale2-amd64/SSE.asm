global setupSSE
extern noSSE

setupSSE:
    MOV EAX, 0x1
    CPUID
    TEST EDX, 1<<25

    JZ failSSE

    ; we have SSE!
    ; time to enable it...

    MOV RAX, CR0

    AND AX, 0xFFFB ; yeet coproc emulation (CR0.EM)
    OR AX, 0x2 ; set coproc monitoring

    MOV CR0, RAX
    MOV RAX, CR4

    OR AX, 3 << 9 ; set CR4.OSFXSR and CR4.OSXMMEXCPT simultaneously
    MOV CR4, RAX

    RET

failSSE:
    ; idk
