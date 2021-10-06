#ifndef EGRI_CIZDIRME_ALGORITMALARI_H_INCLUDED
#define EGRI_CIZDIRME_ALGORITMALARI_H_INCLUDED

int comb(int n, int r){

 int s = 1;

    for (int i=0; i<r; i++){
        s *= (n-i);
        s /= (i+1);
    }
    return s;

}

void egri_hesaplama(struct nokta nok[])
{
    double x,y;
    int i=0;
    for(double t=0.0; t<1.0; t=t+0.001)

    {
        x=0;
        y=0;
        double n=nokta_sayisi-1;
        for( int i =0 ; i<nokta_sayisi; i++)
        {
            x=x+(comb(n,i)*pow(1-t,n-i)*pow(t,i)*nok[i].x);
            y=y+(comb(n,i)*pow(1-t,n-i)*pow(t,i)*nok[i].y);
        }
        egri_noktalari[i].x=x;
        egri_noktalari[i].y=y;
        i++;
    }
}



#endif // EGRI_CIZDIRME_ALGORITMALARI_H_INCLUDED
