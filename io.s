global outb           ; rend l'étiquette outb visible en dehors de ce fichier

; outb - envoie un octet vers un port E/S
; pile : [esp + 8] l'octet de données
;        [esp + 4] le port E/S
;        [esp    ] l'adresse de retour
outb:
    mov al, [esp + 8] ; déplace les données à envoyer dans le registre al
    mov dx, [esp + 4] ; déplace l'adresse du port E/S dans le registre dx 
    out dx, al        ; envoie les données vers le port E/S
    ret               ; retour vers la fonction appelante
