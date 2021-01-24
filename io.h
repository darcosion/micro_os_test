#ifndef INCLUDE_IO_H
#define INCLUDE_IO_H

/** outb:
 *  Envoie les données vers le port E/S donné. Défini en io.s
 *
 *  @param port Le port E/S vers lequel envoyer les données
 *  @param data Les données à envoyer vers le port E/S
 */
void outb(unsigned short port, unsigned char data);

int somme_de_trois(int arg1, int arg2, int arg3);

void tt_ecrire_cellule(char c, unsigned char fg, unsigned char bg);

void ligneverte(unsigned char fg, unsigned char bg);

void ajoutligneverte(int t, unsigned char fg, unsigned char bg);

int write(char *buf, int len);

void titre();

void tt_deplace_curseur(unsigned short pos);

#endif /* INCLUDE_IO_H */
