cli
lgdt [gdtr]

mov eax, cr0
or eax, 1
mov cr0,eax

jmp 08h:main ; jump to main
