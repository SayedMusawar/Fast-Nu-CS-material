[org 0x0100]

mov ax, 0          
mov bx, 0          
mov cx, 7          
loop_start:
    add ax, [data + bx]
    add bx, 2          
    dec cx             
    jnz loop_start     
mov [result], ax
mov ax, 0x4c00
int 0x21

data: dw 10, 20, 30, 40, 50, 60, 70 
result: dw 0