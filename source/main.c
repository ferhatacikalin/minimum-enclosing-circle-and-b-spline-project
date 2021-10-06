#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/freeglut.h>
#include "global_tanimlamalar.h"
#include "koordinat.h"
#include "dosya_islemleri.h"
#include "cizim_algoritmalari.h"
#include "cizim_fonksiyonlari.h"
#include "egri_cizdirme_algoritmalari.h"
#include "egri_cizdirme_fonksiyonlari.h"
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    koordinat_duzlemi_ciz();
    noktalari_ciz(noktalar);
    enkkc_ciz(cizilen_cember);
    egri_ciz(egri_noktalari);
    glutSwapBuffers();

}
void resizer(int w, int h)
{
    glutReshapeWindow( h, h);
    glViewport(0,0,h,h);
}
int main(int argc, char **argv)
{
    dosya_oku();
    cizilen_cember=en_kucuk_kapsayan_cember(noktalar);
    egri_hesaplama(noktalar);
    printf("x:%f y:%f r:%f \n",cizilen_cember.koordinat.x,cizilen_cember.koordinat.y,cizilen_cember.yaricap);
    glutInit(&argc, argv);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition (0, 0);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Minimum Enclosing Circle/Pro. Lab-1");
    glutDisplayFunc(display);
    glutReshapeFunc(resizer);
    glClearColor(0, 0, 0, 0);
    glutMainLoop();
}
