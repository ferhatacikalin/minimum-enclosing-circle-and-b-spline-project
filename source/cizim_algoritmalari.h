#ifndef CIZIM_ALGORITMALARI_H_INCLUDED
#define CIZIM_ALGORITMALARI_H_INCLUDED
#define INF 1e18

double uzaklik(struct nokta n1,struct nokta n2)
{

    return sqrt(pow(n1.x-n2.x,2)+pow(n1.y-n2.y,2));

}
int gecerli_cember(struct cember_t cember, struct nokta n[])
{
    for(int i=0; i<nokta_sayisi; i++)
    {
        if(uzaklik(n[i],cember.koordinat)>cember.yaricap)
        {
            //printf("%f > %f \n",uzaklik(n[i],cember.koordinat),cember.yaricap);
            return 0;
        }
    }
    return 1;
}
struct cember_t iki_noktadan_cember(struct nokta n1,struct nokta n2)
{
    struct nokta merkez;
    struct cember_t cember;
    merkez.x=(n1.x+n2.x)/2.0;
    merkez.y=(n1.y+n2.y)/2.0;
    cember.koordinat=merkez;
    cember.yaricap=uzaklik(n1,merkez);
    //printf("x: %f", merkez.x);
    //printf("y: %f", merkez.y);
    return cember;

};
struct cember_t uc_noktadan_cember(struct nokta n1, struct nokta n2, struct nokta n3)
{
    struct nokta merkez;
    struct cember_t cember;
    double m1=(n2.y-n1.y)/(n2.x-n1.x);
    double m2=(n3.y-n2.y)/(n3.x-n2.x);
    double ortanoktax12=(n1.x+n2.x)/2.0;
    double ortanoktay12=(n1.y+n2.y)/2.0;
    merkez.x= ((m1*m2)*(n1.y-n3.y)+ m2*(n1.x+n2.x) - m1*(n2.x+n3.x))/(2*(m2-m1));
    merkez.y= (-1/m1)*(merkez.x-ortanoktax12)+ortanoktay12;
    //printf("x: %f", merkez.x);
    //printf("y: %f", merkez.y);

    cember.koordinat = merkez;
    cember.yaricap = uzaklik(n1,merkez);
    return cember;


}
struct cember_t en_kucuk_kapsayan_cember(struct nokta n[])
{
    struct cember_t enkkc;
    enkkc.koordinat.x=0;
    enkkc.koordinat.y=0;
    enkkc.yaricap=INFINITY;

//ikili noktalarý kontrol et

    for(int i=0; i<nokta_sayisi; i++)
    {
        for(int j=i+1; j<nokta_sayisi; j++)
        {
            struct cember_t temp;
            temp=iki_noktadan_cember(n[i],n[j]);
            if(temp.yaricap<=enkkc.yaricap && gecerli_cember(temp,n))
            {
                enkkc=temp;
            }

        }
    }

// uclu noktalarý kontrol et

    for(int i=0; i<nokta_sayisi; i++)
    {
        for(int j=i+1; j<nokta_sayisi; j++)
        {
            for(int k=j+1; k<nokta_sayisi; k++)
            {
                struct cember_t temp;
                temp = uc_noktadan_cember(n[i],n[j],n[k]);
                if(temp.yaricap<=enkkc.yaricap && gecerli_cember(temp,n))
                {
                    enkkc=temp;
                }
                // sadece 3 nokta var ise 0-0 2-5 5-0
                if(nokta_sayisi==3)
                {
                    temp = uc_noktadan_cember(n[k],n[i],n[j]);
                    if(temp.yaricap<enkkc.yaricap && gecerli_cember(temp,n))
                    {
                        enkkc=temp;
                    }

                    temp = uc_noktadan_cember(n[j],n[k],n[i]);
                    if(temp.yaricap<enkkc.yaricap && gecerli_cember(temp,n))
                    {
                        enkkc=temp;
                    }



                }
            }

        }

    }
    return enkkc;
};

#endif // CIZIM_ALGORITMALARI_H_INCLUDED
