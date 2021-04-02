#include <stdlib.h>
#include <locale.h>

int plakaKodu,vekilKonteyjani,i,oySayisi,temp,tut=0,oy=0,j,value=0;
int turkiyeGeneliOySayisi[81][8]= {0};
int turkiyeGeneliVekilSayisi[81][8]= {0};
int toplamOy=0,toplamVekil=0;
float oyYuzdesi=0.3;
int deneme =0;
char tutma ;
int secim;
int partiIlOySayisi[81][8]= {0},ilToplamOySayisi[81][1]= {0},tempMatris[81][8]= {0};
char partiler[8]= {'A','B','C','D','E','F','G','H'};


void TurkiyeSonuclari()
{

    int partiToplamVekil[8]= {0},partiToplamOy[8]= {0};
    printf("TURKIYE SONUCLARI \n");



    for(i=0; i<81; i++)
    {

        for(j=0; j<8; j++)
        {
            toplamOy += turkiyeGeneliOySayisi[i][j];
            toplamVekil += turkiyeGeneliVekilSayisi[i][j];
        }
    }

    printf("Ulkenýn toplam oy sayisi %d toplam vekil sayisi %d ",toplamOy,toplamVekil);

    toplamOy =0;
    toplamVekil = 0;

}



void SiralamaAlgoritmasi()
{
    for(temp=0; temp<8; temp++)
    {
        for (i=0; i<8; i++)
        {
            if (partiIlOySayisi[plakaKodu][i]<partiIlOySayisi[plakaKodu][i+1])
            {
                tut=partiIlOySayisi[plakaKodu][i];
                partiIlOySayisi[plakaKodu][i]=partiIlOySayisi[plakaKodu][i+1];
                partiIlOySayisi[plakaKodu][i+1]=tut;

                tempMatris[plakaKodu][i] = partiIlOySayisi[plakaKodu][i+1];
                tempMatris[plakaKodu][i+1] = tut;

                tutma = partiler[i];
                partiler[i] = partiler[i+1];
                partiler[i+1]=tutma;
            }
        }
    }
}
void VerileriListele()
{
    int vekilSayisi [8]= {0,0,0,0,0,0,0};
    oyYuzdesi=0.2;
    SiralamaAlgoritmasi();
    for(j=0; j<vekilKonteyjani; j++)
    {
        for (temp =0; temp<8; temp++)
        {
            for (i=0; i<8; i++)
            {
                if (tempMatris[plakaKodu][i]<tempMatris[plakaKodu][i+1])
                {
                    tut=tempMatris[plakaKodu][i];
                    tempMatris[plakaKodu][i]=tempMatris[plakaKodu][i+1];
                    tempMatris[plakaKodu][i+1]=tut;
                    value = vekilSayisi[i];
                    vekilSayisi[i]=vekilSayisi[i+1];
                    vekilSayisi[i+1]=value;
                }

            }

        }

        tempMatris[plakaKodu][0] = tempMatris[plakaKodu][0] / 2 ;



        vekilSayisi[0] += 1;
    }
    for(temp =0; temp<8; temp++)
    {
        for(i =0; i<8; i++)
        {

            if(vekilSayisi[i]<vekilSayisi[i+1])
            {
                tut = vekilSayisi[i];
                vekilSayisi[i] = vekilSayisi[i+1];
                vekilSayisi[i+1]=tut;
            }


        }
    }


    printf("\t \t \t Oy Sayisi \t Oy Yuzdesi \t MV Sayisi \n");
    printf("\t \t \t --------- \t ---------- \t --------- \n");
    for(i=0; i<8; i++)
    {
        oyYuzdesi = (partiIlOySayisi[plakaKodu][i]*100);
        oyYuzdesi = oyYuzdesi / ilToplamOySayisi[plakaKodu][0] ;
        if(partiler[i]=='A')
        {
            turkiyeGeneliVekilSayisi[plakaKodu][0]=vekilSayisi[i];
        }
        if(partiler[i]=='B')
        {
            turkiyeGeneliVekilSayisi[plakaKodu][1]=vekilSayisi[i];

        }
        if(partiler[i]=='C')
        {
            turkiyeGeneliVekilSayisi[plakaKodu][2]=vekilSayisi[i];

        }
        if(partiler[i]=='D')
        {
            turkiyeGeneliVekilSayisi[plakaKodu][3]=vekilSayisi[i];

        }
        if(partiler[i]=='E')
        {
            turkiyeGeneliVekilSayisi[plakaKodu][4]=vekilSayisi[i];

        }
        if(partiler[i]=='F')
        {
            turkiyeGeneliVekilSayisi[plakaKodu][5]=vekilSayisi[i];

        }
        if(partiler[i]=='G')
        {
            turkiyeGeneliVekilSayisi[plakaKodu][6]=vekilSayisi[i];

        }
        if(partiler[i]=='H')
        {
            turkiyeGeneliVekilSayisi[plakaKodu][7]=vekilSayisi[i];

        }
        printf("%c partisi \t \t %d \t \t %.2f \t \t %d \n ",partiler[i],partiIlOySayisi[plakaKodu][i],oyYuzdesi,vekilSayisi[i]);
    }
    do
    {
        printf(" \n \n *--*--*--*--*--*--*--*--*--*\n");
        printf("Ana Menuye Donmek Icýn - 1 \n ");
        printf("Tekrar Sehir Girmek Icin -2 \n ");
        printf("Ulke Islemleri Icin -3 \n ");
        printf("Cikmak Icin -4 \n ");
        scanf("%d",&secim);


    }
    while(secim<0||secim>5);

    if(secim==1)
    {
        system("clear");
        main();
    }
    if(secim==2)
    {

        system("clear");
        VerileriGirdir();
        VerileriListele();
    }
    if(secim ==3)
    {
        system("clear");
        TurkiyeSonuclari();
    }
    if(secim==4)
    {
        exit(1);
    }

}
void VerileriGirdir()
{
    do
    {
        printf("Plaka kodunu giriniz : ");
        scanf("%d",&plakaKodu);
    }
    while(plakaKodu<=0 || plakaKodu>81);
    do
    {
        printf("Millet vekili konteyjanini giriniz");
        scanf("%d",&vekilKonteyjani);
    }
    while(vekilKonteyjani<=0);
    for(i=0; i<8; i++)
    {
        do
        {
            printf("%c partinin oy sayisini giriniz = ",partiler[i]);
            scanf("%d",&oySayisi);
        }
        while(oySayisi<=0);
        partiIlOySayisi[plakaKodu][i]=oySayisi;
        turkiyeGeneliOySayisi[plakaKodu][i]+=oySayisi;
        tempMatris[plakaKodu][i]=oySayisi;
        ilToplamOySayisi[plakaKodu][0] = oySayisi + ilToplamOySayisi[plakaKodu][0];
        oySayisi = 0;
    }
}
int main()
{
    do
    {
        printf("\n \n \n \n");
        printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-* \n \n \n \n");
        printf("-----------\t SEHIR OY TAKIP ICIN - 1 ' i tuslayin \t \t ------------  \n");

        printf("-----------\t ULKE OY TAKIP ICIN - 2  'yi tuslayin \t \t ------------ \n");

        printf("-----------\t CIKMAK ICIN - 3 'u tuslayin \t \t \t ------------ \n \n \n \n");

        printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-* \n \n \n \n");
        scanf("%d",&secim);

        system("clear");

    }
    while(secim<0||secim>3);
    if(secim == 1)
    {
        system("clear");
        VerileriGirdir();
        VerileriListele();
    }
    if(secim == 2)
    {
        system("clear");
        TurkiyeSonuclari();

    }
    if(secim == 3)
    {
        exit(EXIT_SUCCESS);

    }

}


