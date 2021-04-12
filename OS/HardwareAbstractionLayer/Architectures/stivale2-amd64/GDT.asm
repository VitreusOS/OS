global reloadSegments

reloadSegments:
   PUSH 0x08
   PUSH reloadCS
   RETFQ

reloadCS:
   MOV   AX, 0x10
   MOV   DS, AX
   MOV   ES, AX
   MOV   FS, AX
   MOV   GS, AX
   MOV   SS, AX
   RET
