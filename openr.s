.section .text
.global openr

openr:
    # Save callee-saved registers
    push %rbp
    mov %rsp, %rbp

    # Set up arguments for the open system call
    mov %rdi, %rdi # @param pathname
    mov   $0, %rsi # @param flags (O_RDONLY)
    mov   $0, %rdx # @param mode (no mode I think)

    # Open syscall # is 2
    mov $2, %rax
    syscall # Call 2

    # Restore stack back to what it was, just in case.
    mov %rbp, %rsp
    pop %rbp

    # Return the result of the system call (file descriptor or error code)
    mov %rax, %rax # @ret return code
    ret
