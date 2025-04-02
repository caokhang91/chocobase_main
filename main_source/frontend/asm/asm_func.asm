global call_asm

section .text
call_asm:
    mov rax, 0x2000004     ; write syscall on macOS
    mov rdi, 1             ; stdout
    mov rsi, msg
    mov rdx, msglen
    syscall
    ret

section .data
msg db ">> [ASM] called from SDL2 frontend!", 0xA
msglen equ $ - msg
