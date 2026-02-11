# CPP Module 01

**Bellek Yönetimi, Pointerlar, Referanslar, Switch Statement**

CPP Module 01, C++'da bellek yönetimi, pointer ve referans kullanımı konularını kapsar. Bu modül, dinamik bellek allocation, Stack vs Heap farkları ve dosya işlemlerini öğretir.

## 📋 İçindekiler

- [Genel Bakış](#-genel-bakış)
- [Egzersizler](#-egzersizler)
- [Kurulum ve Derleme](#-kurulum-ve-derleme)
- [Kullanım](#-kullanım)
- [Öğrenilen Kavramlar](#-öğrenilen-kavramlar)
- [Teknik Detaylar](#-teknik-detaylar)

## 🎯 Genel Bakış

Bu modül, C++'da bellek yönetiminin temellerini kapsar:
- **new** ve **delete** operatörleri
- **Stack** vs **Heap** allocation
- **Pointer** ve **Reference** farkları
- **File streams** (ifstream, ofstream)
- **Member function pointers**

## 📚 Egzersizler

### ex00: BrainZ

**Amaç:** Stack ve Heap allocation farklarını anlamak.

**Özellikler:**
- Zombie sınıfı implementasyonu
- `newZombie()`: Heap'te zombie oluşturma (new)
- `randomChump()`: Stack'te zombie oluşturma
- Destructor çağrılma zamanlarını gözlemleme

**Dosyalar:**
- `Zombie.hpp/cpp`: Zombie sınıfı
- `newZombie.cpp`: Heap allocation
- `randomChump.cpp`: Stack allocation
- `main.cpp`: Test programı

**Öğrenilen:** Stack'teki nesneler fonksiyon bitince otomatik yok edilir, Heap'tekiler manuel delete gerektirir.

### ex01: Moar brainz!

**Amaç:** Dinamik dizi allocation.

**Özellikler:**
- Zombie dizisi oluşturma
- `zombieHorde()`: N adet zombie'den oluşan dizi
- Default constructor kullanımı
- `setName()` metodu ile isimlendirme

**Dosyalar:**
- `Zombie.hpp/cpp`: Default constructor eklenmiş Zombie
- `zombieHorde.cpp`: Dizi allocation fonksiyonu
- `main.cpp`: Horde testi

**Öğrenilen:** `new[]` ile dizi allocation, `delete[]` ile temizleme.

### ex02: HI THIS IS BRAIN

**Amaç:** Pointer ve Reference kavramlarını anlamak.

**Özellikler:**
- String, pointer ve reference karşılaştırması
- Bellek adresi gösterimi
- Değer erişimi farklarını gösterme

**Dosyalar:**
- `main.cpp`: Pointer vs Reference demonstration

**Çıktı Örneği:**
```
string:    0x7ffeeb8b4a40
stringPTR: 0x7ffeeb8b4a40
stringREF: 0x7ffeeb8b4a40

string:    HI THIS IS BRAIN
stringPTR: HI THIS IS BRAIN
stringREF: HI THIS IS BRAIN
```

**Öğrenilen:** Pointer ve Reference aynı bellek adresini gösterir, ancak kullanım syntax'ı farklıdır.

### ex03: Unnecessary violence

**Amaç:** Reference ve Pointer kullanım durumlarını anlamak.

**Özellikler:**
- `Weapon` sınıfı
- `HumanA`: Reference ile silah tutar (her zaman silahlı)
- `HumanB`: Pointer ile silah tutar (silahsız olabilir)
- `attack()` metodları

**Dosyalar:**
- `Weapon.hpp/cpp`: Silah sınıfı
- `HumanA.hpp/cpp`: Reference kullanan insan
- `HumanB.hpp/cpp`: Pointer kullanan insan
- `main.cpp`: Test senaryoları

**Öğrenilen:** 
- Reference: Değişmez, NULL olamaz, başlatılması zorunlu
- Pointer: Değişebilir, NULL olabilir, opsiyonel

### ex04: Sed is for losers

**Amaç:** Dosya işlemleri ve string manipülasyonu.

**Özellikler:**
- Dosya okuma (ifstream)
- Dosya yazma (ofstream)
- String'de tüm s1'leri s2 ile değiştirme
- `.replace` uzantılı yeni dosya oluşturma

**Kullanım:**
```bash
./sed_is_for_losers filename s1 s2
```

**Dosyalar:**
- `main.cpp`: Dosya işleme programı

**Öğrenilen:** File streams, string::find(), string::substr() kullanımı.

### ex05: Harl 2.0

**Amaç:** Member function pointers kullanımı.

**Özellikler:**
- `Harl` sınıfı
- 4 seviye: DEBUG, INFO, WARNING, ERROR
- `complain()` metodu ile dinamik metod çağırma
- Function pointer array

**Dosyalar:**
- `Harl.hpp/cpp`: Harl sınıfı
- `main.cpp`: Seviye testleri

**Öğrenilen:** Member function pointer syntax ve kullanımı.

## 🔧 Kurulum ve Derleme

### Gereksinimler

- C++ derleyici (g++ veya clang++)
- Make
- C++98 standardı desteği

### Derleme

Her egzersiz kendi dizininde derlenmelidir:

```bash
# ex00 için
cd ex00
make

# ex01 için
cd ex01
make

# Diğer egzersizler için benzer şekilde
cd ex0X
make
```

### Temizleme

```bash
make clean   # Object dosyalarını siler
make fclean  # Tüm derleme çıktılarını siler
make re      # Temizler ve yeniden derler
```

## 🎮 Kullanım

### ex00: BrainZ

```bash
cd ex00
make
./zombie

# Çıktı:
# HeapZombie: BraiiiiiiinnnzzzZ...
# HeapZombie has been destroyed
#
# StackZombie: BraiiiiiiinnnzzzZ...
# StackZombie has been destroyed
```

### ex01: Moar brainz!

```bash
cd ex01
make
./moar_brainz

# Çıktı: N adet zombie oluşturulur ve duyurulur
```

### ex02: HI THIS IS BRAIN

```bash
cd ex02
make
./brain

# Pointer ve Reference karşılaştırması gösterilir
```

### ex03: Unnecessary violence

```bash
cd ex03
make
./violence

# HumanA ve HumanB saldırı senaryoları test edilir
```

### ex04: Sed is for losers

```bash
cd ex04
make
./sed_is_for_losers test.txt "hello" "hi"

# test.txt.replace dosyası oluşturulur
# İçindeki tüm "hello" kelimeleri "hi" ile değiştirilir
```

### ex05: Harl 2.0

```bash
cd ex05
make
./harl

# DEBUG, INFO, WARNING, ERROR mesajları gösterilir
```

## 🧠 Öğrenilen Kavramlar

### 1. new ve delete Operatörleri

```cpp
// Heap'te tek nesne
Zombie* z = new Zombie("Foo");
delete z;

// Heap'te dizi
Zombie* horde = new Zombie[10];
delete[] horde;
```

### 2. Stack vs Heap

**Stack:**
- Otomatik bellek yönetimi
- Fonksiyon bitince otomatik temizlenir
- Hızlı
- Sınırlı boyut

```cpp
void func() {
    Zombie z("Stack");  // Stack'te
}  // Burada otomatik yok edilir
```

**Heap:**
- Manuel bellek yönetimi
- delete ile temizlenmeli
- Yavaş
- Büyük boyutlar için uygun

```cpp
Zombie* z = new Zombie("Heap");  // Heap'te
delete z;  // Manuel temizleme gerekli
```

### 3. Pointer vs Reference

**Pointer:**
```cpp
std::string* ptr = &str;  // Adres tutar
*ptr = "new value";       // Dereference ile erişim
ptr = NULL;               // NULL olabilir
ptr = &other;             // Değiştirilebilir
```

**Reference:**
```cpp
std::string& ref = str;   // Alias (takma ad)
ref = "new value";        // Direkt erişim
// ref = NULL;            // NULL olamaz
// ref = other;           // Değiştirilemez
```

### 4. File Streams

```cpp
// Okuma
std::ifstream infile("input.txt");
std::string line;
std::getline(infile, line);
infile.close();

// Yazma
std::ofstream outfile("output.txt");
outfile << "Hello" << std::endl;
outfile.close();
```

### 5. Member Function Pointers

```cpp
class Harl {
private:
    void debug(void);
    void (Harl::*functions[4])(void);  // Function pointer array
    
public:
    void complain(std::string level) {
        (this->*functions[index])();  // Dinamik çağrı
    }
};
```

## 🔍 Teknik Detaylar

### C++98 Standardı

Bu proje C++98 standardına uygun yazılmıştır:
- `new`/`delete` kullanımı
- `nullptr` yerine `NULL`
- C-style string'ler için `.c_str()`

### Derleme Bayrakları

```makefile
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
```

### Bellek Yönetimi

**Önemli Kurallar:**
1. Her `new` için bir `delete`
2. Her `new[]` için bir `delete[]`
3. Destructor'da dinamik belleği temizle
4. Memory leak'i önle

**Memory Leak Kontrolü:**
```bash
valgrind ./program
```

### Stack vs Heap Karar Ağacı

```
Nesne ne kadar yaşamalı?
├─ Sadece fonksiyon içinde → Stack
└─ Fonksiyon dışında da → Heap

Boyut belli mi?
├─ Evet ve küçük → Stack
└─ Hayır veya büyük → Heap

Performans kritik mi?
├─ Evet → Stack (daha hızlı)
└─ Hayır → Heap (daha esnek)
```

### Pointer vs Reference Seçimi

**Reference kullan:**
- NULL olmamalı
- Değişmemeli
- Her zaman geçerli olmalı

**Pointer kullan:**
- NULL olabilir
- Değişebilir
- Opsiyonel parametre

## 📝 Proje Yapısı

```
cpp01/
├── ex00/
│   ├── Makefile
│   ├── Zombie.hpp
│   ├── Zombie.cpp
│   ├── newZombie.cpp
│   ├── randomChump.cpp
│   └── main.cpp
├── ex01/
│   ├── Makefile
│   ├── Zombie.hpp
│   ├── Zombie.cpp
│   ├── zombieHorde.cpp
│   └── main.cpp
├── ex02/
│   ├── Makefile
│   └── main.cpp
├── ex03/
│   ├── Makefile
│   ├── Weapon.hpp
│   ├── Weapon.cpp
│   ├── HumanA.hpp
│   ├── HumanA.cpp
│   ├── HumanB.hpp
│   ├── HumanB.cpp
│   └── main.cpp
├── ex04/
│   ├── Makefile
│   └── main.cpp
├── ex05/
│   ├── Makefile
│   ├── Harl.hpp
│   ├── Harl.cpp
│   └── main.cpp
├── en_subject.pdf
└── README.md
```

## 💡 İpuçları

1. **Memory Management**: Her new için delete yazmayı unutma
2. **Array Deletion**: `delete[]` kullanmayı unutma
3. **Reference Initialization**: Reference'lar başlatılmalı
4. **NULL Checks**: Pointer kullanırken NULL kontrolü yap
5. **File Closing**: Dosyaları kullandıktan sonra kapat

## 🐛 Yaygın Hatalar ve Çözümler

### Problem: Memory Leak
```cpp
// Yanlış
Zombie* z = new Zombie("Foo");
// delete unutuldu!

// Doğru
Zombie* z = new Zombie("Foo");
delete z;
```

### Problem: Dizi silme hatası
```cpp
// Yanlış
Zombie* horde = new Zombie[10];
delete horde;  // Sadece ilk eleman silinir!

// Doğru
Zombie* horde = new Zombie[10];
delete[] horde;  // Tüm dizi silinir
```

### Problem: Dangling pointer
```cpp
// Yanlış
Zombie* getZombie() {
    Zombie z("Local");
    return &z;  // Stack'teki nesnenin adresi!
}

// Doğru
Zombie* getZombie() {
    return new Zombie("Heap");  // Heap'te oluştur
}
```

### Problem: Reference NULL olamaz
```cpp
// Yanlış
std::string& ref = NULL;  // Hata!

// Doğru
std::string* ptr = NULL;  // Pointer NULL olabilir
```

## 📚 Kaynaklar

- [C++ Reference](https://en.cppreference.com/)
- [LearnCpp.com - Dynamic Memory](https://www.learncpp.com/cpp-tutorial/dynamic-memory-allocation-with-new-and-delete/)
- [Pointers vs References](https://www.geeksforgeeks.org/pointers-vs-references-cpp/)

## 🙏 Teşekkürler

Bu proje 42 okulu müfredatının bir parçasıdır ve eğitim amaçlıdır.

---

**Not**: Bu modül bellek yönetiminin temellerini öğretir. Sonraki modüllerde daha ileri konular işlenecektir (operator overloading, inheritance, polymorphism, vb.).
