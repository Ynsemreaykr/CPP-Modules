# C++ Module 02 - Operatör Aşırı Yükleme ve Canonical Form

> **42 Okulu C++ Modülleri** | yayiker@student.42.fr

---

## 📋 Proje Hakkında

C++ Module 02, **sabit noktalı sayı (fixed-point number)** gösterimi, **operatör aşırı yükleme (operator overloading)** ve **Canonical Form** konularına odaklanır.

### Kullanılan Standart
**C++98** — `std=c++98` derleyici bayrağı ile derlenir.

---

## 📁 Proje Yapısı

```
cpp02/
├── ex00/                    → Temel Canonical Form
│   ├── Fixed.hpp / Fixed.cpp
│   ├── main.cpp
│   └── Makefile
│
├── ex01/                    → Int ve Float Dönüşümleri
│   ├── Fixed.hpp / Fixed.cpp
│   ├── main.cpp
│   └── Makefile
│
└── ex02/                    → Tam Operatör Aşırı Yükleme
    ├── Fixed.hpp / Fixed.cpp
    ├── main.cpp
    └── Makefile
```

---

## 🧩 Egzersizler

### ex00 — Orthodox Canonical Form (Temel)
`Fixed` sınıfının sadece 4 zorunlu canonical form üyesiyle oluşturulması.

**Orthodox Canonical Form:**
1. `Default Constructor` — Varsayılan constructor
2. `Copy Constructor` — Kopya constructor
3. `Copy Assignment Operator` — `operator=`
4. `Destructor` — Yıkıcı fonksiyon

```cpp
Fixed a;         // Default: 0
Fixed b(a);      // Copy
Fixed c;
c = b;           // Assignment
```

**Sabit Noktalı Sayı Sistemi:**
- 8 bit kesir kısmı (2⁸ = 256 hassasiyet)
- Ham değer (raw bits) olarak `int` saklanır
- Gerçek değer = ham / 256

---

### ex01 — Dönüşüm Constructorları
`int` ve `float` değerlerinden `Fixed` oluşturma. `toFloat()` ve `toInt()` dönüşüm metodları.

| Constructor | Dönüşüm |
|-------------|---------|
| `Fixed(int)` | `raw = int << 8` (int × 256) |
| `Fixed(float)` | `raw = roundf(float × 256)` |
| `toFloat()` | `raw / 256.0f` |
| `toInt()` | `raw >> 8` |

```cpp
Fixed a(10);         // a = 10.0
Fixed b(42.42f);     // b ≈ 42.4218
std::cout << a;      // << operatörü
```

---

### ex02 — Tam Operatör Aşırı Yükleme
Tüm karşılaştırma, aritmetik ve artırma operatörleri eklenir.

**Karşılaştırma:** `>`, `<`, `>=`, `<=`, `==`, `!=`

**Aritmetik:**
| Op | Açıklama | Formül |
|----|----------|--------|
| `+` | Toplama | `raw1 + raw2` |
| `-` | Çıkarma | `raw1 - raw2` |
| `*` | Çarpma | `(raw1 * raw2) >> 8` |
| `/` | Bölme | `(raw1 << 8) / raw2` |

**Artırma/Azaltma:**
- `++a` / `--a` → Ön: önce değiştir, sonra döndür
- `a++` / `a--` → Son: önce döndür, sonra değiştir

**Statik Fonksiyonlar:** `min()`, `max()` (const ve non-const versiyonlar)

```cpp
Fixed a;
Fixed b(5.05f * Fixed(2));
std::cout << Fixed::max(a, b);
```

---

## ⚙️ Derleme

```bash
cd ex<N>
make
./fixed
```

---

## 📚 Öğrenilen C++ Kavramları

| Kavram | Açıklama |
|--------|----------|
| Orthodox Canonical Form | 4 zorunlu sınıf üyesi |
| Sabit Noktalı Sayı | `int` ile ondalıklı sayı temsili |
| Operatör Aşırı Yükleme | `+`, `-`, `*`, `/`, `>`, `<` vb. |
| `roundf()` | Float yuvarlama (cmath) |
| Bit Kaydırma | `<<` ve `>>` ile çarpma/bölme |
| `static` fonksiyon | Nesneye değil sınıfa ait metod |

---

## 🔢 Sabit Noktalı Sayı Mantığı

```
Değer 3.14 → Ham = roundf(3.14 × 256) = 804
Ham 804  → Float = 804 / 256.0 = 3.140625
Ham 804  → Int   = 804 >> 8     = 3
```

---

*42 Okulu — Ecole 42 C++ Modülleri*
