ENTRY(loader)                /* le nom de l'étiquette du point d'entrée */

SECTIONS {
    . = 0x00100000;          /* le code doit être chargé à 1 Mo */

    .text ALIGN (0x1000) :   /* alignement à 4 ko */
    {
        *(.text)             /* toutes les sections texte de tous les fichiers */
        *(.rodata)          /* added because of https://stackoverflow.com/questions/27939316/bochs-2-4-6-grub-0-97-error-13-invalid-or-unsupported-executable-format-wh */
    }

    .data ALIGN (0x1000) :   /* alignement à 4 ko */
    {
        *(.data)             /* toutes les sections de données, de tous les fichiers */
    }

    .bss ALIGN (0x1000) :    /* alignement à 4 ko */
    {
        *(COMMON)            /* toutes les sections COMMON de tous les fichiers */
        *(.bss)              /* toutes les sections bss de tous les fichiers */
    }
}
