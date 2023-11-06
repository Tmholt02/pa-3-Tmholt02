.section .text
.global openr

openr:

    # Set up arguments for the open system call
    mov %rdi, %rdi # @param pathname
    mov   $0, %rsi # @param flags (O_RDONLY)
    mov   $0, %rdx # @param mode (no mode I think)

    # Open syscall # is 2
    mov $2, %rax
    syscall # Call 2

    # Return the result of the system call (file descriptor or error code)
    mov %rax, %rax # @ret return code
    ret
