#ifndef GLOBAL_TANIMLAMALAR_H_INCLUDED
#define GLOBAL_TANIMLAMALAR_H_INCLUDED
struct nokta
{
    double x;
    double y;
};
struct cember_t
{

    struct nokta koordinat;
    double yaricap;

};
int nokta_sayisi=0;
struct nokta noktalar[1000];
struct cember_t cizilen_cember;
struct nokta egri_noktalari[1000];

#endif // GLOBAL_TANIMLAMALAR_H_INCLUDED
