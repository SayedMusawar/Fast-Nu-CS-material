; Zero flag
[org 0x0100]

;mov ax, 5
;cmp ax, 5          

;mov ax, 7
;cmp ax, 5          

;mov ax, 0x4c00
;int 0x21


;Sign flag
;[org 0x0100]

;mov ax, 3
;cmp ax, 8      
;mov ax, 10
;cmp ax, 4

;mov ax, 0x4c00
;int 0x21



;Carry flag
; [org 0x0100]

; mov al, 5
; cmp al, 10 
; mov al, 15
; cmp al, 8

; mov ax, 0x4c00
; int 0x21



;Overfloww flag
; [org 0x0100]

 ;mov al, 127        
; add al, 1          

 ;mov al, 50
; add al, 20

 ;mov ax, 0x4c00
; int 0x21

;Parity flag

; [org 0x0100]

 ;mov al, 3          
;test al, al


 ;mov al, 7          
; test al, al        

 ;mov ax, 0x4c00
; int 0x21

; Auxilary carry flag

; [org 0x0100]

 mov al, 0x0F
 add al, 1
 mov al, 5
 add al, 2
mov ax, 0x4c00
int 0x21