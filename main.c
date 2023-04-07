#include <stdio.h>
#include <stdlib.h>

// Ýkili aðaç yapýsý bu þekilde oluþturuldu.
struct agac {
    int dal_toplam; //sað ve sol daldaki sayýlarýn toplamý için kullanýlacak olan int verisi.
    struct agac* sol_dal;
    struct agac* sag_dal;
};

// Yeni bir düðüm oluþturur ve geri döndürür
struct agac* ikinci_agac(int dal_toplam) {
    struct agac* agac = (struct agac*) malloc(sizeof(struct agac));
    agac->dal_toplam = dal_toplam;
    agac->sol_dal = NULL;
    agac->sag_dal = NULL;
    return(agac);
}

// Kök deðerinin alt düðümlerin toplamý olup olmadýðýný kontrol eden fonksiyon
int toplam_degerine_esit_mi(struct agac* root) {
    // Kök düðüm null ise, alt düðüm yoktur ve koþul doðrudur
    if (root == NULL)
        return 1;
    
    // Kökün sol ve sað alt düðümlerinin toplamýný hesapla
    int sol_sayi = 0;
	int sag_sayi = 0;
    if (root->sol_dal != NULL)
        sol_sayi = root->sol_dal->dal_toplam;
    if (root->sag_dal != NULL)
        sag_sayi = root->sag_dal->dal_toplam;
    
    // Sol ve sað alt aðaçlarýn toplamý ile kök deðerini karþýlaþtýr
    if (root->dal_toplam == sol_sayi + sag_sayi)
        return 1;
    else
        return 0;
}

// Test iþlevi
int main() {
    struct agac* root = ikinci_agac(100);//kök için deðer 100
    root->sol_dal = ikinci_agac(77);// sol dal için deðer 77
    root->sag_dal = ikinci_agac(23);// sað dal için deðer 23

    int result = toplam_degerine_esit_mi(root);//Fonksiyon çalýþtýrýlýr ve kök deðeri dallarýn toplamý olduðu için sonuç (result 1 ve doðru olacaktýr.)
    if (result == 1)
        printf("sol ve sag alt agaclarin toplamý kok degerine esittir.");
    else
        printf("sol ve sag alt agaçlarin toplami kok degerine esit degildir.");

    return 0;
}








