[org 0x0100]

jmp start

number_to_check:  dw 153          
result:           db 0             

start:
    mov  ax, [number_to_check]    
    mov  bx, 0
    mov  cx, 3                   

extract_loop:
    mov  dx, 0
    mov  si, 10                  
    div  si

    
    push dx 

    
    mov  ax, dx
    mul  ax     
    mov  dx, ax
    mov  ax, dx
    mul  dx    
    add  bx, ax 

    mov  ax, [number_to_check]
    mov  dx, 0
    div  si
    mov  [number_to_check], ax
    dec  cx
    jnz  extract_loop

    mov  ax, [number_to_check]
    mov  ax, 153              
    cmp  bx, ax
    je   is_armstrong

    mov  byte [result], 1      
    jmp  done

is_armstrong:
    mov  byte [result], 0      

done:
    mov  ax, 0x4c00
    int  0x21