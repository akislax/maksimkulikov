default rel

section .data
    promptN    db "Введите N: ", 0
    promptNums db "Введите числа: ", 10, 0
    resMsg     db "Результат: %d", 10, 0
    fmtIn      db "%d", 0

section .bss
    n       resd 1
    array   resd 100

section .text
    global main
    extern printf, scanf

main:
    push rbp
    mov rbp, rsp
    push rbx
    push r12

    lea rdi, [promptN]
    xor eax, eax
    call printf

    lea rdi, [fmtIn]
    lea rsi, [n]
    xor eax, eax
    call scanf

    lea rdi, [promptNums]
    xor eax, eax
    call printf

    xor rbx, rbx
input_loop:
    movsxd rax, dword [n]
    cmp rbx, rax
    jge start_counting

    lea rdi, [fmtIn]
    lea rsi, [array + rbx*4]
    xor eax, eax
    call scanf

    inc rbx
    jmp input_loop

start_counting:
    xor r12, r12
    mov rbx, 1
count_loop:
    movsxd rax, dword [n]
    cmp rbx, rax
    jge print_result

    mov eax, [array + rbx*4]
    mov ecx, [array + rbx*4 - 4]

    cmp eax, ecx
    jne next_iter
    inc r12

next_iter:
    inc rbx
    jmp count_loop

print_result:
    lea rdi, [resMsg]
    mov rsi, r12
    xor eax, eax
    call printf

    pop r12
    pop rbx
    pop rbp
    xor eax, eax
    ret
