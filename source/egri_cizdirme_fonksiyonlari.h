#ifndef EGRI_CIZDIRME_FONKSIYONLARI_H_INCLUDED
#define EGRI_CIZDIRME_FONKSIYONLARI_H_INCLUDED

void egri_ciz(struct nokta n[])
{
    glColor3f(0.0,0.0,1.0);
    glPointSize(5.0);
    glLineWidth(1.1);
    glEnable(GL_BLEND);
    glEnable(GL_LINE_SMOOTH);

    glBegin(GL_LINES);
    for(int i=0; i<1000; i++)
    {
        glVertex2d((1.0/koordinat_sayisi)*egri_noktalari[i].x,(1.0/koordinat_sayisi)*egri_noktalari[i].y);
    }

    glEnd();
}
#endif // EGRI_CIZDIRME_FONKSIYONLARI_H_INCLUDED
