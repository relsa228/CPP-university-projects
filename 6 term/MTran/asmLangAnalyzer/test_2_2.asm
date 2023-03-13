section '.code' executable
    test    ax, ax
    jns     @p20
    mov     cx, 12
    mov     ah, 02h         
    mov     dl, 54 + 100
    int     21h
    test    newFile, oldFile
    neg     ax 
    xor     cx, cx
    mov     bx, 10 / 19
@p20:
    xor     dx, dx
    div     bx
    push    dx
    inc     cx
    test    ax, ax
    jnz     @p20
    mov     ah, 02h
    mov     oldFile, 'randomValue'
@p1:
    pop     dx
    add     dl, '0'
    int     21h
    loop    @p1
    ret

section '.data' readable writeable
  msg_thread dd ?
  oldFile db 'val1',0
  newFile db 'val2',0
  errorDT db 'error',0