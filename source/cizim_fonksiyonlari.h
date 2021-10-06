#ifndef CIZIM_FONKSIYONLARI_H_INCLUDED
#define CIZIM_FONKSIYONLARI_H_INCLUDED
#include <math.h>
void noktalari_ciz(struct nokta n[])
{
    glColor3d(1.0,0.1,0.1);
    glEnable( GL_POINT_SMOOTH );
    glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
    glPointSize( 10.0 );
    glBegin(GL_POINTS);
    for(int i=0; i<nokta_sayisi; i++)
    {
        glVertex2d((1.0/koordinat_sayisi)*n[i].x, (1.0/koordinat_sayisi)*n[i].y);
    }
    glEnd();
}
void enkkc_ciz(struct cember_t cember)
{
    double birim_k = 1.0/koordinat_sayisi;
    double x,y;
    glColor3d(0.0,1.0,0.0);
    glEnable( GL_LINE_SMOOTH );
    glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
    glLineWidth(1.9);
    glBegin(GL_LINE_LOOP);
    struct nokta yaricap_cizgisi;
    for(int i=0; i<360; i++)
    {
        x=cember.koordinat.x + (cember.yaricap * cos(i *  2.0 * M_PI / 360));
        y=cember.koordinat.y + (cember.yaricap * sin(i *  2.0 * M_PI / 360));
        glVertex2d(x*birim_k,y*birim_k);
        if(i==180)
        {
            yaricap_cizgisi.x=x;
            yaricap_cizgisi.y=y;
        }
    }
    glEnd();
    glLineWidth(1.9);
    glBegin(GL_LINES);
    glVertex2d(birim_k*cember.koordinat.x,birim_k*cember.koordinat.y);
    glVertex2d(birim_k*yaricap_cizgisi.x,birim_k*yaricap_cizgisi.y);
    glEnd();
    glRasterPos2d(birim_k*((cember.koordinat.x+yaricap_cizgisi.x)/2), 0.005+birim_k*((cember.koordinat.y+yaricap_cizgisi.y)/2));
    char yaricapString[30];
    sprintf(yaricapString,"R=%.2f",cember.yaricap);
    glutBitmapString(GLUT_BITMAP_HELVETICA_10,yaricapString);
    glRasterPos2d(birim_k*cember.koordinat.x, birim_k*cember.koordinat.y);
    char merkezString[30];
    sprintf(merkezString,".M(%.1f,%.1f)",cember.koordinat.x,cember.koordinat.y);
    glutBitmapString(GLUT_BITMAP_HELVETICA_10,merkezString);
    glRasterPos2d(-1, 0.96);
    char bilgiString[30];
    sprintf(bilgiString,"Merkez X = %.3f \nMerkez Y = %.3f\nYaricap  = %.3f",cember.koordinat.x,cember.koordinat.y,cember.yaricap);
    glutBitmapString(GLUT_BITMAP_9_BY_15,bilgiString);
}
#endif // CIZIM_FONKSIYONLARI_H_INCLUDED
