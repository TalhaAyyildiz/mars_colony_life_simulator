#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int saglik = 100;
    int enerji = 100;
    int oksijen = 100;
    int su = 50;
    int yedekParca = 5;
    int modulHasari = 0;
    int kilitMuhurlu = 0;
    int gun = 1;
    int tur = 0;
    
    int firtinaSuresi = 5;
    char zorluk;
    char komut;
    int oyunBitti = 0;

    printf("---- MARS KOLONISI BASIT SIMULATOR ----\n");

    do {
        printf("Zorluk Seciniz (K: Kolay  |  N: Normal  |  Z: Zor): ");
        scanf(" %c", &zorluk);

        switch (zorluk) {
            case 'k':
            case 'K':
                su = 70;
                yedekParca = 7;
                firtinaSuresi = 3;
                break;
            case 'n':
            case 'N':
                su = 50;
                yedekParca = 5;
                firtinaSuresi = 5;
                break;
            case 'z':
            case 'Z':
                su = 30;
                yedekParca = 3;
                firtinaSuresi = 7;
                break;
            default:
                printf("Gecersiz secim! Tekrar deneyin.\n");
                zorluk = '\0';
        }
    } while (zorluk == '\0');

    do {
        if (saglik <= 0 || oksijen <= 0) {
            oyunBitti = -1;
            break;
        }
        if (gun > 15) {
            oyunBitti = 1;
            break;
        }

        printf("\n-----------------------------------------\n");
        printf("GUN: %d | Saglik: %d | Enerji: %d | Oksijen: %d\n", gun, saglik, enerji, oksijen);
        printf("Komutlar: [G]kesif | [O]oksijen | [T]tamir | [D]durum | [U]uyu | [K]kum Firtinasi | [H]hava Kilidi | [Q]Cikis\n");
        printf("Komut giriniz: ");
        scanf(" %c", &komut);

        int turGecerli = 1;

        switch (komut) {
            case 'g':
            case 'G':
                if (enerji <15||oksijen < 10) {
                    printf("Yetersiz enerji veya oksijen!\n");
                    turGecerli = 0;
                    break;
                }
                enerji -= 15;
                oksijen -= 10;
                
                {
                    int zar = rand() % 100;
                    printf("Zar: %d -> ", zar);
                    if (zar < 20) {
                        saglik -= 15;
                        printf("Yaralandiniz!\n");
                    } else {
                        su += 5;
                        printf("Guvenli, 5 birim su bulundu.\n");
                    }
                }
                break;

            case 'o':
            case 'O':
                if (enerji < 10 ||su < 2) {
                    printf("Enerji veya su yetersiz!\n");
                    turGecerli = 0;
                    break;
                }
                enerji -= 10;
                su -= 2;
                oksijen += 3;
                printf("3 birim oksijen uretildi.\n");
                break;

            case 't':
            case 'T':
                if (yedekParca <=0 || modulHasari== 0) {
                    printf("Yedek parca yok veya modul saglam!\n");
                    turGecerli = 0;
                    break;
                }
                yedekParca--;
                modulHasari -= 25;
                printf("Modul tamir edildi.\n");
                break;

            case 'd':
            case 'D':
                turGecerli = 0;
                printf("Su: %d | Yedek Parca: %d | Modul Hasari: %d\n", su, yedekParca, modulHasari);
                if (oksijen >= 25 && saglik >= 30 && modulHasari <= 70) {
                    printf("TUM SISTEMLER NORMAL\n");
                }
                break;

            case 'u':
            case 'U':
                enerji += 25;
                saglik += 10;
                printf("Dinlenildi, enerji ve saglik artti.\n");
                break;

            case 'k':
            case 'K':
                printf("Kum firtinasi basladi!\n");
                for (int i = 1; i <= firtinaSuresi; i++) {
                    int zar = rand() % 100;
                    
                    if (kilitMuhurlu == 1 && zar < 40) {
                        printf("Tur %d: Kilit muhurlu oldugu icin firtina etkisi atlandi.\n", i);
                        continue;
                    }

                    if (i % 2 == 0) {
                        saglik -= 10;
                        printf("Tur %d (Siddetli): Can kaybi!\n", i);
                    } else {
                        modulHasari += 10;
                        printf("Tur %d: Modul hasar aldi.\n", i);
                    }

                    if (saglik <= 0) {
                        break;
                    }
                }
                break;

            case 'h':
            case 'H':
                {
                    char dogruSifre = 'A' + (gun % 26);
                    int deneme = 3;
                    char tahmin;

                    printf("Hava Kilidi Sifre Ekrani (IPUCU: A'dan gun sayisi kadar ilerde)\n");
                    do {
                        printf("Harf giriniz (Kalan hak %d): ", deneme);
                        scanf(" %c", &tahmin);

                        if (tahmin == dogruSifre || tahmin == dogruSifre + 32) {
                            kilitMuhurlu = 1;
                            printf("Dogru! Hava kilidi muhurlendi.\n");
                            break;
                        }
                        deneme--;
                        printf("Yanlis!\n");
                    } while (deneme > 0);
                }
                break;

            case 'q':
            case 'Q':
                oyunBitti = -2;
                break;

            default:
                printf("Gecersiz komut!\n");
                turGecerli = 0;
        }

        if (saglik > 100) saglik = 100;
        if (saglik < 0) saglik = 0;
        if (enerji > 100) enerji = 100;
        if (enerji < 0) enerji = 0;
        if (oksijen > 100) oksijen = 100;
        if (oksijen < 0) oksijen = 0;
        if (modulHasari > 100) modulHasari = 100;
        if (modulHasari < 0) modulHasari = 0;

        if (turGecerli) {
            tur++;
            if (tur % 3 == 0) {
                gun++;
                oksijen -= 5;
                printf("\n--- Yeni Gun Basladi (Gun %d) ---\n", gun);
            }
        }
        if (oyunBitti != 0) break;

    } while (oyunBitti == 0);

    printf("\n--------------------------------------------------\n");
    printf("            OYUN SONU RAPORU             \n");
    printf("--------------------------------------------------\n");
    if (oyunBitti == 1) {
        printf("TEBRIKLER! 15 gunu tamamladiniz.\n");
    } else {
        printf("OYUN BITTI.\n");
    }

    int puan = (gun * 100) + saglik + oksijen - modulHasari;
    printf("Hayatta Kalinan Gun : %d\n", gun);
    printf("TOPLAM PUAN         : %d\n", puan);
    printf("---------------------------------------------------------------------\n");

    return 0;
}