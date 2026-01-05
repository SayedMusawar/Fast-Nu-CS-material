[org 0x0100]

mov bx, 0              
mov ax, [data + bx]    
add bx, 2              
mov cx, 6              

loop_start:
    cmp ax, [data + bx]
    jge skip_update
    mov ax, [data + bx] 
    
skip_update:
    add bx, 2
    dec cx
    jnz loop_start

mov [result], ax
mov ax, 0x4c00
int 0x21

data: dw 10, 85, 30, 40, 95, 60, 70
result: dw 0
