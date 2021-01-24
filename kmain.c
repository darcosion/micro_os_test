#include "io.h"


/* Les ports d'E/S */
#define TT_PORT_COMMANDE        0x3D4
#define TT_PORT_DATA            0x3D5

/* Les commandes du port d'E/S */
#define TT_COMMANDE_OCTET_SUP    14
#define TT_COMMANDE_OCTET_INF    15

/* Couleur par défaut des caractères */
#define TT_VERT       2
#define TT_GRIS_FONCE 8

void kmain(){

}

int somme_de_trois(int arg1, int arg2, int arg3)
{
    return arg1 + arg2 + arg3;
}

/** tt_deplace_curseur:
 *  Déplace le curseur du tampon de trame à la position donnée
 *
 *  @param pos La nouvelle position du curseur
 */

void tt_deplace_curseur(unsigned short pos)
{
    outb(TT_PORT_COMMANDE, TT_COMMANDE_OCTET_SUP);
    outb(TT_PORT_DATA,    ((pos >> 8) & 0x00FF));
    outb(TT_PORT_COMMANDE, TT_COMMANDE_OCTET_INF);
    outb(TT_PORT_DATA,    pos & 0x00FF);
}

/** tt_ecrire_cellule :
*  Écrit un caractère avec l'avant-plan et l'arrière-plan donnés à la position i
*  dans le tampon de trame.
*
*  @param i  L'emplacement dans le tampon de trame
*  @param c  Le caractère
*  @param fg La couleur de l'avant-plan
*  @param bg La couleur de l'arrière-plan
*/

char *tt = (char *) 0x000B8000;

int i = 0;

void tt_ecrire_cellule(char c, unsigned char fg, unsigned char bg)
{
    tt[i] = c;
    tt[i + 1] = ((fg & 0x0F) << 4) | (bg & 0x0F);
    i = i + 2;
}

void ligneverte(unsigned char fg, unsigned char bg) {
    int e = 0;
    while(e < 80) {
	tt_ecrire_cellule(' ', TT_VERT, TT_GRIS_FONCE);
	tt_deplace_curseur(i);
	e++;
    }
}

void ajoutligneverte(int t, unsigned char fg, unsigned char bg) {
    int e = 0;
    while(e < t) {
	tt_ecrire_cellule(' ', TT_VERT, TT_GRIS_FONCE);
	tt_deplace_curseur(i);
	e++;
    }
}


int write(char *buf, int len) {
	int i;
	for(i = 0; i < len; i++) {
		tt_ecrire_cellule(buf[i], TT_VERT+1, TT_GRIS_FONCE);
	}
	return 0;
}

void titre()
{
    ligneverte(TT_VERT, TT_GRIS_FONCE);
    ajoutligneverte(36, TT_VERT, TT_GRIS_FONCE);
    tt_ecrire_cellule('D', TT_VERT, TT_GRIS_FONCE);
    tt_ecrire_cellule('E', TT_VERT, TT_GRIS_FONCE);
    tt_ecrire_cellule('A', TT_VERT, TT_GRIS_FONCE);
    tt_ecrire_cellule('D', TT_VERT, TT_GRIS_FONCE);
    tt_ecrire_cellule('B', TT_VERT, TT_GRIS_FONCE);
    tt_ecrire_cellule('O', TT_VERT, TT_GRIS_FONCE);
    tt_ecrire_cellule('O', TT_VERT, TT_GRIS_FONCE);
    tt_ecrire_cellule('T', TT_VERT, TT_GRIS_FONCE);
    ajoutligneverte(36, TT_VERT, TT_GRIS_FONCE);
    ligneverte(TT_VERT, TT_GRIS_FONCE);
    write("engagelejeuquejelegagne", 23);
    write("  lol  ", 7);
}
