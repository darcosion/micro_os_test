global loader                      ; le symbole d'entrée pour ELF


NOMBRE_MAGIQUE equ 0x1BADB002      ; définit la constante nombre magique
DRAPEAUX       equ 0x0             ; drapeaux multiboot
CHECKSUM       equ -NOMBRE_MAGIQUE ; calcule la somme de contrôle
                                   ; (nombre magique + somme de contrôle + drapeaux doit être égal à 0)
KERNEL_STACK_SIZE equ 4096         ; taille de la pile en octet

section .text:                     ; début de la section texte (code)
align 4                            ; le code doit être aligné à 4 octets
    dd NOMBRE_MAGIQUE              ; écrit le nombre magique en code machine,
    dd DRAPEAUX                    ; les drapeaux,
    dd CHECKSUM                    ; et la somme de contrôle
section .bss:
align 4                           ; alignement à 4 octets
kernel_stack:                     ; étiquette pointant vers le début de la mémoire
    resb KERNEL_STACK_SIZE        ; réserve la pile pour le noyau
loader:                            ; l'étiquette du chargeur (définie comme point d'entrée dans le script de l'éditeur de liens)
    mov esp, kernel_stack + KERNEL_STACK_SIZE
    extern titre
    call titre ;affiche le titre
    extern somme_de_trois
    push dword 1
    push dword 1
    push dword 1
    call somme_de_trois ; on retrouve la somme final dans EAX
    mov edx, eax
    mov eax, 0x0000DEAD            ; place le nombre 0xDEAD00000 dans le registre eax

.loop:
    jmp .loop                      ; boucle infinie
