#include <stdio.h>
#include <stdlib.h>

// İkili ağaç yapısı bu şekilde oluşturuldu.
struct agac {
    int dal_toplam; //sağ ve sol daldaki sayıların toplamı için kullanılacak olan int verisi.
    struct agac* sol_dal;
    struct agac* sag_dal; // sol ve sağ dal için pointerlar.
};

// Yeni bir düğüm oluşturur ve geri döndürür
struct agac* ikinci_agac(int dal_toplam) {
    struct agac* agac = (struct agac*) malloc(sizeof(struct agac));// agac adlı struct yapısındaki verilerin alanı kadar alan açmak için malloc fonksiyonu kullanılır.
    agac->dal_toplam = dal_toplam;
    agac->sol_dal = NULL; // sol düğüm null atanır.
    agac->sag_dal = NULL; // sağ düğüm null atanır.
    return(agac);
}

// Kök değerinin alt düğümlerin toplamı olup olmadığını kontrol eden fonksiyon
int toplam_degerine_esit_mi(struct agac* root) {
    // Kök düğüm null ise, alt düğüm yoktur ve koşul doğrudur
    if (root == NULL)
        return 1; // root değeri null olursa altındaki ağaçlardaki değerlerde 0 olur. Null değeri de 0 olduğundan 0+0=0 olacaktır ve sonuç doğru olacaktır.
    
    // Kökün sol ve sağ alt düğümlerinin toplamını hesapla
        int sol_sayi = 0;
	int sag_sayi = 0;
    if (root->sol_dal != NULL)// burada kök nulldan farklı bir değer olduğunda hemen altındaki satırdaki kodlar çalışır
        sol_sayi = root->sol_dal->dal_toplam;
    if (root->sag_dal != NULL)// burada kök nulldan farklı bir değer olduğunda hemen altındaki satırda kodlar çalışacaktır.
        sag_sayi = root->sag_dal->dal_toplam;
    
 
    if (root->dal_toplam == sol_sayi + sag_sayi) // Sol ve sağ alt ağaçların toplamı ile kök değerini karşılaştır
        return 1; 	
    else
        return 0;	// bu koşul kontrolde sonuç doğruysa 1 , değilse 0 olur.
}

// Test işlevi
int main() {
    struct agac* root = ikinci_agac(100);//kök için değer 100
    root->sol_dal = ikinci_agac(77);// sol dal için değer 77
    root->sag_dal = ikinci_agac(23);// sağ dal için değer 23
	
	/*
		100
	       /   \				 ÜÇ ELEMANLI İKİLİ AĞACIN GÖRÜNTÜSÜ ŞEKİLDEKİ GİBİDİR.
	     77     23
	
	
	*/
    int result = toplam_degerine_esit_mi(root);//Fonksiyon çalıştırılır ve kök değeri dalların toplamı olduğu için sonuç (result 1 ve doğru olacaktır.) (77+23=100)
    if (result == 1)
        printf("sol ve sag alt agaclarin toplamı kok degerine esittir.");
    else
        printf("sol ve sag alt agaçlarin toplami kok degerine esit degildir.");
 // koşul kontrole göre üstteki iki printf mesajından birisi ekrana yazırılacaktır.
    return 0;
}








