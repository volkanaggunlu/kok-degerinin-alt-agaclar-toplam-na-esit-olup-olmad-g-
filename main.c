#include <stdio.h>
#include <stdlib.h>

// �kili a�a� yap�s� bu �ekilde olu�turuldu.
struct agac {
    int dal_toplam; //sa� ve sol daldaki say�lar�n toplam� i�in kullan�lacak olan int verisi.
    struct agac* sol_dal;
    struct agac* sag_dal;
};

// Yeni bir d���m olu�turur ve geri d�nd�r�r
struct agac* ikinci_agac(int dal_toplam) {
    struct agac* agac = (struct agac*) malloc(sizeof(struct agac));
    agac->dal_toplam = dal_toplam;
    agac->sol_dal = NULL;
    agac->sag_dal = NULL;
    return(agac);
}

// K�k de�erinin alt d���mlerin toplam� olup olmad���n� kontrol eden fonksiyon
int toplam_degerine_esit_mi(struct agac* root) {
    // K�k d���m null ise, alt d���m yoktur ve ko�ul do�rudur
    if (root == NULL)
        return 1;
    
    // K�k�n sol ve sa� alt d���mlerinin toplam�n� hesapla
    int sol_sayi = 0;
	int sag_sayi = 0;
    if (root->sol_dal != NULL)
        sol_sayi = root->sol_dal->dal_toplam;
    if (root->sag_dal != NULL)
        sag_sayi = root->sag_dal->dal_toplam;
    
    // Sol ve sa� alt a�a�lar�n toplam� ile k�k de�erini kar��la�t�r
    if (root->dal_toplam == sol_sayi + sag_sayi)
        return 1;
    else
        return 0;
}

// Test i�levi
int main() {
    struct agac* root = ikinci_agac(100);//k�k i�in de�er 100
    root->sol_dal = ikinci_agac(77);// sol dal i�in de�er 77
    root->sag_dal = ikinci_agac(23);// sa� dal i�in de�er 23

    int result = toplam_degerine_esit_mi(root);//Fonksiyon �al��t�r�l�r ve k�k de�eri dallar�n toplam� oldu�u i�in sonu� (result 1 ve do�ru olacakt�r.)
    if (result == 1)
        printf("sol ve sag alt agaclarin toplam� kok degerine esittir.");
    else
        printf("sol ve sag alt aga�larin toplami kok degerine esit degildir.");

    return 0;
}








