[org 0x0100]

    xor ax, ax
    mov cx, 5
    mov si, data

sum:
    add ax, [si]
    add si, 2
    dec cx
    jnz sum

mov [result], ax

mov ax, 0x4c00
int 0x21

data:   dw 7, 12, 20, 35, 9
result: dw 0