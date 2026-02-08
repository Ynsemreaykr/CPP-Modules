# CPP Module 00

**C++ Programlamaya Giriş - Namespace, Sınıflar, Üye Fonksiyonlar, stdio Streams, Başlatma Listeleri, Static, Const**

CPP Module 00, 42 okulu C++ müfredatının ilk modülüdür. Bu modül, C++'ın temel kavramlarını öğretir ve C dilinden C++'a geçişi kolaylaştırır.

## 📋 İçindekiler

- [Genel Bakış](#-genel-bakış)
- [Egzersizler](#-egzersizler)
- [Kurulum ve Derleme](#-kurulum-ve-derleme)
- [Kullanım](#-kullanım)
- [Öğrenilen Kavramlar](#-öğrenilen-kavramlar)
- [Teknik Detaylar](#-teknik-detaylar)

## 🎯 Genel Bakış

Bu modül, C++ programlamanın temellerini kapsar:
- **Namespace** kullanımı
- **Sınıf (Class)** yapıları
- **Encapsulation** (Kapsülleme)
- **Constructor** ve **Destructor**
- **Getter** ve **Setter** metodları
- **C++ I/O Streams** (iostream)
- **String** sınıfı kullanımı

## 📚 Egzersizler

### ex00: Megaphone

**Amaç:** Komut satırı argümanlarını büyük harfe çeviren basit bir program.

**Özellikler:**
- Tüm argümanları büyük harfe çevirir
- Argüman yoksa varsayılan mesaj gösterir
- C++ iostream ve cctype kütüphanelerini kullanır

**Dosyalar:**
- `megaphone.cpp`
- `Makefile`

### ex01: My Awesome PhoneBook

**Amaç:** Maksimum 8 kişi saklayabilen telefon rehberi uygulaması.

**Özellikler:**
- **ADD**: Yeni kişi ekleme
- **SEARCH**: Kişi arama ve görüntüleme
- **EXIT**: Programdan çıkış
- FIFO (First In First Out) mantığı
- Tablo formatında liste görüntüleme
- Veri validasyonu (boş alan kabul edilmez)

**Dosyalar:**
- `main.cpp`: Program giriş noktası
- `PhoneBook.hpp/cpp`: PhoneBook sınıfı
- `Contact.hpp/cpp`: Contact sınıfı
- `Makefile`

**Sınıf Yapısı:**

```cpp
Contact Sınıfı:
- Private üye değişkenler: ad, soyad, takma ad, telefon, sır
- Public getter/setter metodları

PhoneBook Sınıfı:
- 8 Contact dizisi
- Kişi sayacı ve FIFO indeksi
- Ekleme, arama, listeleme metodları
```

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
```

### Temizleme

```bash
make clean   # Object dosyalarını siler
make fclean  # Tüm derleme çıktılarını siler
make re      # Temizler ve yeniden derler
```

## 🎮 Kullanım

### ex00: Megaphone

```bash
# Derleme
cd ex00
make

# Kullanım örnekleri
./megaphone "shhhhh... I think the students are asleep..."
# Çıktı: SHHHHH... I THINK THE STUDENTS ARE ASLEEP...

./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
# Çıktı: DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.

./megaphone
# Çıktı: * LOUD AND UNBEARABLE FEEDBACK NOISE *
```

### ex01: PhoneBook

```bash
# Derleme
cd ex01
make

# Çalıştırma
./phonebook
```

**Komutlar:**

1. **ADD** - Yeni kişi ekle
   ```
   > ADD
   First name: Ahmet
   Last name: Yılmaz
   Nickname: Ahmo
   Phone number: 5551234567
   Darkest secret: Kahve bağımlısı
   Contact added successfully!
   ```

2. **SEARCH** - Kişi ara
   ```
   > SEARCH
        Index|First Name| Last Name|  Nickname
            0|     Ahmet|    Yılmaz|      Ahmo
            1|     Mehmet|     Demir|     Memo
   Enter index: 0
   First name: Ahmet
   Last name: Yılmaz
   Nickname: Ahmo
   Phone number: 5551234567
   Darkest secret: Kahve bağımlısı
   ```

3. **EXIT** - Çıkış
   ```
   > EXIT
   ```

**Önemli Notlar:**
- Maksimum 8 kişi saklanabilir
- 9. kişi eklendiğinde en eski kişi silinir (FIFO)
- Tüm alanlar zorunludur (boş bırakılamaz)
- 10 karakterden uzun metinler tabloda kırpılır ve '.' ile biter

## 🧠 Öğrenilen Kavramlar

### 1. Sınıflar ve Nesneler (Classes & Objects)

```cpp
class Contact {
private:
    std::string _firstName;  // Private üye değişken
public:
    std::string getFirstName() const;  // Getter
    void setFirstName(const std::string& name);  // Setter
};
```

### 2. Encapsulation (Kapsülleme)

- Üye değişkenler `private` olarak tanımlanır
- Getter/Setter metodları ile erişim sağlanır
- Veri gizliliği ve kontrollü erişim

### 3. Constructor (Yapıcı Fonksiyon)

```cpp
PhoneBook::PhoneBook() : _contactCount(0), _oldestIndex(0) {
    // Başlatma listesi ile üye değişkenler initialize edilir
}
```

### 4. Const Correctness

```cpp
std::string getFirstName() const;  // Bu metod nesneyi değiştirmez
void searchContact() const;        // Read-only metod
```

### 5. C++ I/O Streams

```cpp
std::cout << "Mesaj";           // Çıktı
std::cin >> degisken;           // Girdi
std::getline(std::cin, str);    // Satır okuma
```

### 6. String Sınıfı

```cpp
std::string name;
name.length();              // Uzunluk
name.substr(0, 9);         // Alt string
name.empty();              // Boş mu?
```

## 🔍 Teknik Detaylar

### C++98 Standardı

Bu proje C++98 standardına uygun yazılmıştır:
- Modern C++ özellikleri (C++11 ve sonrası) kullanılmamıştır
- `nullptr` yerine `NULL` kullanılabilir
- Range-based for loops kullanılmaz
- Auto keyword kullanılmaz

### Derleme Bayrakları

```makefile
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
```

- `-Wall`: Tüm uyarıları göster
- `-Wextra`: Ekstra uyarılar
- `-Werror`: Uyarıları hata olarak say
- `-std=c++98`: C++98 standardını kullan

### Bellek Yönetimi

- Stack allocation kullanılır (dinamik bellek yok)
- RAII prensibi (Resource Acquisition Is Initialization)
- Destructor'lar otomatik çağrılır

### FIFO Mantığı (ex01)

```cpp
if (_contactCount < 8) {
    _contacts[_contactCount] = newContact;
    _contactCount++;
} else {
    _contacts[_oldestIndex] = newContact;
    _oldestIndex = (_oldestIndex + 1) % 8;  // Circular buffer
}
```

## 📝 Proje Yapısı

```
cpp00/
├── ex00/
│   ├── Makefile
│   └── megaphone.cpp
├── ex01/
│   ├── Makefile
│   ├── main.cpp
│   ├── Contact.hpp
│   ├── Contact.cpp
│   ├── PhoneBook.hpp
│   └── PhoneBook.cpp
├── en_subject.pdf
└── README.md
```

## 💡 İpuçları

1. **Encapsulation**: Tüm üye değişkenleri private yapın
2. **Const Correctness**: Değiştirmeyen metodları const yapın
3. **Initialization Lists**: Constructor'larda başlatma listesi kullanın
4. **Input Validation**: Kullanıcı girdilerini her zaman kontrol edin
5. **EOF Handling**: `std::getline` dönüş değerini kontrol edin

## 🐛 Yaygın Hatalar ve Çözümler

### Problem: EOF (Ctrl+D) sonrası sonsuz döngü
```cpp
// Yanlış
std::getline(std::cin, input);

// Doğru
if (!std::getline(std::cin, input))
    break;  // veya return
```

### Problem: 10 karakterden uzun string'ler
```cpp
if (str.length() > 10)
    str = str.substr(0, 9) + ".";
```

## 📚 Kaynaklar

- [C++ Reference](https://en.cppreference.com/)
- [LearnCpp.com](https://www.learncpp.com/)
- [C++98 Standard](https://www.open-std.org/jtc1/sc22/wg21/)

## 🙏 Teşekkürler

Bu proje 42 okulu müfredatının bir parçasıdır ve eğitim amaçlıdır.

---

**Not**: Bu modül C++ programlamanın temellerini öğretir. Sonraki modüllerde daha ileri konular işlenecektir (kalıtım, polimorfizm, operatör overloading, vb.).
