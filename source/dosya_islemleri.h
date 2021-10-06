#ifndef DOSYA_ISLEMLERI_H_INCLUDED
#define DOSYA_ISLEMLERI_H_INCLUDED
void dosya_oku()
{

    FILE *kaynak;

    kaynak = fopen("points.txt","r");
    if(kaynak==NULL)
    {
        printf("dosya error.");
    }

    double temp1,temp2;
    int i=0;
    while(fscanf(kaynak,"%lf %lf \n",&temp1,&temp2) != -1)
    {
        noktalar[i].x = temp1;
        noktalar[i].y = temp2;
        printf("%d.nokta: x=%f y=%f \n",i+1,noktalar[i].x,noktalar[i].y);
        nokta_sayisi++;
        i++;
        temp1=0.0;
        temp2=0.0;
    }

    fclose(kaynak);



}



#endif // DOSYA_ISLEMLERI_H_INCLUDED
