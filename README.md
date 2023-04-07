Algoritmanın çalışma şekli şöyledir:

Verilen kök kontrol edilir. NULL durumunda, alt düğüm bulunmaz ve koşul doğrudur. Bu durumda, işlem sonlandırılır ve 1 değeri döndürülür.
Eğer kök NULL değilse, sol ve sağ alt ağaçlardaki değerler hesaplanır. Bunun için, sol ve sağ alt düğümlerin değerleri kontrol edilir.
Eğer düğüm null ise, alt ağaç yok demektir, yanialt ağaç değeri sıfır olacakır.
Sol ve sağ alt ağaçların Hesaplanan  değerleri, kök düğümün değeri ile karşılaştırılır. Eğer eşitlik sağlanıyorsa, koşul doğrudur ve 1 değeri döndürülür.
Eğer eşitlik sağlanmıyorsa, koşul yanlıştır ve 0 değeri döndürülür.

Algoritma, kök düğümün sol ve sağ alt düğümlerine tekrar uygulanır. Bu şekilde, alt ağaçlar da tek tek kontrol edilir.
Sonuç olarak, kök düğümün alt ağaçlarının toplamı, kök düğümün değerine eşitse 1 değeri, değilse 0 değeri döndürülür.
Bu algoritma, özellikle bir ikili ağaç yapısındaki her düğümün sol ve sağ alt düğümlerinin değerlerini hesaplamak için iş görecektir.
Algoritma, bir düğümün alt ağaçlarının toplamını hesaplamak için her alt düğüme ayrı ayrı bakar.
Hesaplanan toplam değeri, kök düğümün değeri ile karşılaştırılır ve eşitse , kök düğümün alt ağaçları toplamı kök düğümün değerine eşittir.
Bu şekilde, algoritma bir ikili ağaç yapısında dolaşarak, her düğümün alt ağaçlarının toplamını hesaplayabilir ve bu toplamların doğruluğunu kontrol edebilir.

Bu algoritmanın amacıysa, verilen bir kök düğümün alt ağaçlarının değerlerinin toplamının, kök düğümün değerine eşit olup olmadığını kontrol etmektir.
 Bunu da ikili ağacı ve içindeki kök ve alt dalların değerlerini kontrol ederek yapar.

Kod Dev c++ üzerinden çalışan bir C programlama dili kodudur. derleyip çalıştırmanız kodun çalışması için yeterlidir.
