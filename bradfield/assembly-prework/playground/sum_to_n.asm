        global      _main

        section     .text
_main:  mov         rax, 0x02000004             ; system call for write
        mov         rdi, 1                      ; file handle 1 is stdout
        mov         rsi,                        ; address of string to output
        mov         rdx, 1                      ; number of bytes
        syscall                                 ; invoke os to do write


        mov         rax, 0x02000001             ; syscall for exit
        xor         rdi, rdi                    ; exit code 0
        syscall                                 ; invoke exit syscall

        section     .data
msg:    db          "Hello, World", 10          ; note newline at the end
a:      db          0x61, 10
n:      db          0x34, 10
three:  db          3
