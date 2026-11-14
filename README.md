# mars_colony_life_simulator
# Mars Kolonisi Yaşam Destek Simülatörü (C ile Metin Tabanlı Oyun)

Bu proje, C programlama dilinin temel yapıları kullanılarak geliştirilmiş metin tabanlı bir **Mars Kolonisi Yaşam Destek Simülatörü** uygulamasıdır. Oyuncu, Mars'taki bir araştırma istasyonunda yalnız kalan bir mühendisi yönetir ve kurtarma ekibi gelene kadar 15 gün hayatta kalmaya çalışır.

##  Proje Özellikleri ve Teknik Detaylar

- **Komut Sistemi (`switch-case` ve Fall-through):** Büyük/küçük harf duyarsız komut yönetimi `case` yapısının esnek kullanımıyla sağlanmıştır.
- **Zorluk Seviyeleri:** Kolay (`K`), Normal (`N`) ve Zor (`Z`) olmak üzere başlangıç kaynaklarını ve fırtına sürelerini değiştiren dinamik zorluk algoritması.
- **Rastgele Olaylar ve Zar Mekanizmaları:** `srand(time(NULL))` ve `rand() % 100` yardımıyla keşif ve fırtına anındaki riskler hesaplanmıştır.
- **Kum Fırtınası Simülasyonu (`for` döngüsü):** Zorluk derecesine bağlı tur sayısı, `mod (%)` operatörü ile şiddetli turların tespiti ve `continue` / `break` yapıları.
- **Hava Kilidi Şifre Mekanizması (`do-while` döngüsü):** Gün sayısına bağlı dinamik şifre üretimi ve sınırlı deneme hakkı (`3 hak`).
- **Zaman Akışı ve Sınırlandırmalar:** Her 3 turda bir (`tur % 3 == 0`) yeni güne geçiş, istatistiklerin `0-100` aralığında sınırlandırılması ve oyun sonu puan hesaplaması.

## 🛠️ Derleme ve Çalıştırma

Kodunu herhangi bir C derleyicisinde (GCC, Dev-C++, VS Code vb.) kolayca derleyip çalıştırabilirsiniz:

```bash
gcc mars_simulatoru.c -o mars_simulatoru
./mars_simulatoru
