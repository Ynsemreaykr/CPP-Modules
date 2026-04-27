# C++ Module 04 - Polimorfizm ve Soyut Sınıflar

> **42 Okulu C++ Modülleri** | yayiker@student.42.fr

---

## 📋 Proje Hakkında

C++ Module 04, **polimorfizm (polymorphism)**, **virtual fonksiyonlar**, **derin kopyalama (deep copy)** ve **soyut sınıflar (abstract classes)** konularına odaklanır.

### Kullanılan Standart
**C++98** — `std=c++98` derleyici bayrağı ile derlenir.

---

## 📁 Proje Yapısı

```
cpp04/
├── ex00/                    → Polimorfizm Temelleri (Virtual)
│   ├── Animal.hpp / Animal.cpp
│   ├── Cat.hpp / Cat.cpp
│   ├── Dog.hpp / Dog.cpp
│   ├── WrongAnimal.hpp / WrongAnimal.cpp
│   ├── WrongCat.hpp / WrongCat.cpp
│   ├── main.cpp
│   └── Makefile
│
├── ex01/                    → Brain ve Derin Kopyalama
│   ├── Animal.hpp / Animal.cpp
│   ├── Cat.hpp / Cat.cpp    → Brain* pointer tutar
│   ├── Dog.hpp / Dog.cpp    → Brain* pointer tutar
│   ├── Brain.hpp / Brain.cpp → 100 fikir saklayan sınıf
│   ├── main.cpp
│   └── Makefile
│
└── ex02/                    → Soyut Sınıf (Pure Virtual)
    ├── Animal.hpp / Animal.cpp  → makeSound() = 0
    ├── Cat.hpp / Cat.cpp
    ├── Dog.hpp / Dog.cpp
    ├── Brain.hpp / Brain.cpp
    ├── main.cpp
    └── Makefile
```

---

## 🧩 Egzersizler

### ex00 — Polimorfizm ve Virtual Fonksiyon
`virtual` anahtar kelimesi ile runtime polimorfizm sağlanır.

**Virtual vs Non-Virtual:**
```cpp
// Animal* pointer üzerinden:
const Animal* j = new Dog();
j->makeSound();  // Dog::makeSound() çalışır  ✅ (virtual)

// WrongAnimal* pointer üzerinden:
const WrongAnimal* w = new WrongCat();
w->makeSound();  // WrongAnimal::makeSound() çalışır ❌ (virtual yok)
```

**Virtual Destructor Zorunluluğu:**
```cpp
Animal* a = new Dog();
delete a;  // Dog::~Dog() çağrılır (virtual sayesinde) ✅
```

---

### ex01 — Brain ve Derin Kopyalama
`Cat` ve `Dog` nesneleri Heap'te `Brain*` pointer tutar.

**Derin Kopya vs Yüzeysel Kopya:**
```cpp
// Yüzeysel Kopya (YANLIŞ) - İki nesne aynı Brain'e işaret eder!
dog2.brain = dog1.brain;  // Tehlikeli!

// Derin Kopya (DOĞRU) - Bağımsız Brain nesnesi oluşturulur
dog2.brain = new Brain(*dog1.brain);  // Güvenli ✅
```

**Brain Sınıfı:**
- 100 string fikir dizisi (`std::string ideas[100]`)
- `setIdea(index, idea)` / `getIdea(index)` metodları
- Tam derin kopyalama desteği

---

### ex02 — Soyut Sınıf (Abstract Class)
`makeSound()` pure virtual yapılır: `virtual void makeSound() const = 0;`

```cpp
Animal a;        // DERLEME HATASI! (Soyut sınıf)
Animal* a = new Dog();  // Geçerli ✅ (pointer)
```

**Pure Virtual Fonksiyon Kuralları:**
- Soyut sınıf nesnesi OLUŞTURULAMAZ
- Alt sınıflar bu fonksiyonu IMPLEMENT ETMELİDİR
- Arayüz/sözleşme tanımlar

---

## ⚙️ Derleme

```bash
cd ex<N>
make
./animal
```

---

## 📚 Öğrenilen C++ Kavramları

| Kavram | Açıklama |
|--------|----------|
| `virtual` | Runtime polimorfizm |
| `virtual ~Destructor()` | Polimorfik silme için zorunlu |
| Pure Virtual (`= 0`) | Soyut sınıf tanımlar |
| Abstract Class | Nesne oluşturulamaz, arayüz sağlar |
| Deep Copy | Bağımsız bellek kopyası |
| Shallow Copy | Sadece adres kopyası (tehlikeli!) |

---

## 🔗 Sınıf Hiyerarşisi

```
Animal (virtual makeSound)          WrongAnimal (makeSound - virtual YOK)
    ├── Cat (override: "Meow!")          └── WrongCat (polimorfizm çalışmaz)
    └── Dog (override: "Woof!")

ex01/ex02: Dog ve Cat ayrıca Brain* tutar (derin kopya)
ex02: Animal soyut sınıf (makeSound = 0)
```

---

## 🧠 Polimorfizm Özeti

```
Pointer Türü    | Nesne Türü | makeSound() Çağrısı
----------------|------------|--------------------
Animal*         | Dog        | Dog::makeSound()    ✅ virtual var
Animal*         | Cat        | Cat::makeSound()    ✅ virtual var
WrongAnimal*    | WrongCat   | WrongAnimal::makeSound() ❌ virtual yok
```

---

*42 Okulu — Ecole 42 C++ Modülleri*
