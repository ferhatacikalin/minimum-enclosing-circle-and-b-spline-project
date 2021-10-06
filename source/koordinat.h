#ifndef KOORDINAT_H_INCLUDED
#define KOORDINAT_H_INCLUDED
#define koordinat_sayisi 20
void eksenleri_ciz()
{
    // y-ekseni
    glColor3f(1,1,1);
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glVertex2d(0.0, 1.0);
    glVertex2d(0.0, -1.0);
    glEnd();

    // x-ekseni
    glColor3f(1,1,1);
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glVertex2d(-1.0, 0.0);
    glVertex2d(1.0, 0.0);
    glEnd();

}

void centik_ekle()
{
    glColor3f(1,1,1);
    for(int i=-koordinat_sayisi; i<=koordinat_sayisi; i++)
    {
        //x-ekseni
        glLineWidth(2.0);
        glBegin(GL_LINES);
        glVertex2d(0.0+(i*(1.0/koordinat_sayisi)), -0.01);
        glVertex2d(0.0+(i*(1.0/koordinat_sayisi)), 0.01);
        glEnd();
    }
    for(int i=-koordinat_sayisi; i<=koordinat_sayisi; i++)
    {
        //y-ekseni
        glLineWidth(2.0);
        glBegin(GL_LINES);
        glVertex2d( -0.01, 0+(i*(1.0/koordinat_sayisi)));
        glVertex2d( 0.01, 0+(i*(1.0/koordinat_sayisi)));
        glEnd();
    }

}

void koordinat_yazilari_ekle()
{
    for(int i=-20; i<=20; i++)
    {
        if(i==0) continue;
        // int to string
        char str[4];
        sprintf(str, "%d", i);
        // x-ekseni
        if(i==20)
        {
            glRasterPos2d(-0.02+(i*(1.0/koordinat_sayisi)),-0.04);

        }
        else
        {
            glRasterPos2d((i*(1.0/koordinat_sayisi)),-0.04);

        }
        glutBitmapString(GLUT_BITMAP_HELVETICA_10,str);
        // y-ekseni
        if(i==20)
        {
            glRasterPos2d(0.02,-0.02+(i*(1.0/koordinat_sayisi)));

        }
        else if (i== -20)
        {
            glRasterPos2d(0.02,+0.001+(i*(1.0/koordinat_sayisi)));
        }
        else
        {
            glRasterPos2d(0.02,-0.01+(i*(1.0/koordinat_sayisi)));

        }
        glutBitmapString(GLUT_BITMAP_HELVETICA_10,str);

    }


}

void koordinat_duzlemi_ciz()
{
    eksenleri_ciz();
    centik_ekle();
    koordinat_yazilari_ekle();
}
#endif // KOORDINAT_H_INCLUDED
