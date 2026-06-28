# CPP_MODULES

Bu proje serisi, C programlama dilinin prosedürel dünyasından C++'ın Nesne Yönelimli Programlama (OOP) paradigmasına geçişi ve C++98 standardı çerçevesinde yazılım geliştirmeyi hedefler. Modüller, temel sınıf tasarımlarından başlayarak karmaşık bellek yönetimi, operatör aşırı yükleme, kalıtım ve polimorfizm kavramlarını derinlemesine öğretmeyi amaçlar.

---

## 📁 Proje Klasör Yapısı

Depo yapısı, her bir C++ kavram kategorisine ayrılmış bağımsız modüllerden oluşmaktadır:

```text
CPP_MODULES/
├── cpp00/
├── cpp01/
├── cpp02/
├── cpp03/
├── cpp04/
└── README.md
```

---

## 🧠 Modüllerin Amacı, Öğrettikleri ve Kazandırdıkları

### 1. [CPP Module 00](file:///c:/Users/emrea/OneDrive/Masaüstü/cppyedek/cpp00) - Nesne Yönelimli Programlamaya Giriş
* **Amacı**: C dilinin prosedürel alışkanlıklarından sıyrılarak Nesne Yönelimli Programlama (OOP) düşünce yapısına adapte olmak ve C++ dilinin temel sözdizimini (syntax) kavramak.
* **Neler Öğretir / Kazandırır**:
  * İsim çakışmalarını önlemek için ad uzaylarını (`namespace`) etkin kullanmayı.
  * Veri gizleme (Encapsulation) ilkesini koruyarak sınıfları (`class`) kurmayı ve erişim belirteçlerini (`private`, `public`) yönetmeyi.
  * Nesne ömrünü (object lifetime) denetleyen Yapıcı (`Constructor`) ve Yıkıcı (`Destructor`) fonksiyonların mantığını.
  * Constructor Başlatma Listeleri (`Initialization Lists`) sayesinde üye değişkenleri daha verimli şekilde ilklendirmeyi.
  * C++ girdi/çıktı akışlarını (`std::cout`, `std::cin`) kullanmayı ve girdi akışının sonlandırılması (EOF - Ctrl+D) gibi kritik uç durumları (edge cases) kontrol etmeyi.
  * `const` ve `static` anahtar kelimelerinin üye fonksiyonlar ve değişkenler üzerindeki rollerini.

### 2. [CPP Module 01](file:///c:/Users/emrea/OneDrive/Masaüstü/cppyedek/cpp01) - Bellek Yönetimi ve Adresleme
* **Amacı**: C++ dilinde bellek yönetiminin temel taşlarını (Stack vs Heap), bellek tahsis yöntemlerini, referansları ve dosya akışlarını kavramak.
* **Neler Öğretir / Kazandırır**:
  * Dinamik bellek yönetimini C++ tarzında (`new` ve `delete` / `new[]` ve `delete[]`) gerçekleştirmeyi ve bellek sızıntılarını (memory leaks) tamamen önlemeyi.
  * Değişken takma adları olan Referans (`Reference`) kavramını, pointerlar ile farklarını ve hangi durumlarda hangisinin tercih edilmesi gerektiğini.
  * Dosya akış kütüphaneleri (`std::ifstream`, `std::ofstream`) ile güvenli şekilde dosya okuma ve yazma operasyonları gerçekleştirmeyi.
  * Sınıf üye fonksiyon pointerlarını (Member Function Pointers) dizi yapılarıyla kullanarak dinamik metod yönlendirmesi yapabilmeyi (böylece karmaşık switch-case yapılarını temizlemeyi).

### 3. [CPP Module 02](file:///c:/Users/emrea/OneDrive/Masaüstü/cppyedek/cpp02) - Ad-hoc Polimorfizm, Operatör Aşırı Yükleme ve Kanonik Sınıf Formu
* **Amacı**: C++ sınıflarının güvenli kopyalama ve atama davranışlarını standartlaştırmak, operatörleri aşırı yükleyerek özel veri tiplerini doğal veri tipleri gibi kullanmak ve sabit noktalı sayı aritmetiğini sıfırdan geliştirmek.
* **Neler Öğretir / Kazandırır**:
  * C++'ın en önemli sınıf tasarım standartlarından biri olan **Ortodoks Kanonik Sınıf Formu'nu (Orthodox Canonical Class Form)** tüm kurallarıyla (Default Constructor, Copy Constructor, Copy Assignment Operator, Destructor) uygulamayı.
  * Nesnelerin kendi aralarında aritmetik (`+`, `-`, `*`, `/`), karşılaştırma (`>`, `<`, `>=`, `<=`, `==`, `!=`) ve artırma/azaltma (`++`, `--`) işlemlerini doğrudan yapabilmesi için operatör aşırı yüklemeyi (operator overloading).
  * Kayan noktalı (float) sayıların işlemci seviyesindeki temsilini anlamayı ve sabit noktalı (fixed-point) sayı aritmetiğini bit kaydırma (`<<`, `>>`) operatörleriyle sıfırdan kurmayı.

### 4. [CPP Module 03](file:///c:/Users/emrea/OneDrive/Masaüstü/cppyedek/cpp03) - Kalıtım (Inheritance)
* **Amacı**: Sınıflar arası hiyerarşik ilişkiler kurarak kod tekrarını önlemeyi, kalıtım mekanizmalarını ve çoklu kalıtım (multiple inheritance) problemlerini incelemek.
* **Neler Öğretir / Kazandırır**:
  * Sınıflar arasında "is-a" (bir nesnedir) ilişkisi kurarak ortak kod tabanını genişletmeyi ve kodun yeniden kullanılabilirliğini (reusability) artırmayı.
  * Üst Sınıf (Base Class) ve Alt Sınıf (Derived Class) arasındaki yapıcı ve yıkıcı fonksiyonların çağrılma sırasını.
  * Erişim belirteçlerinin kalıtım altındaki davranışlarını ve `protected` anahtar kelimesinin alt sınıflarla olan ilişkisini.
  * Çoklu kalıtımda ortaya çıkan ünlü "Diamond Problem" (Elmas Sorunu) karmaşasını çözmek için `virtual` kalıtım mekanizmasını kullanmayı.

### 5. [CPP Module 04](file:///c:/Users/emrea/OneDrive/Masaüstü/cppyedek/cpp04) - Alt Tip Polimorfizmi, Soyut Sınıflar ve Arayüzler
* **Amacı**: C++'ın en güçlü Nesne Yönelimli özelliklerinden biri olan Polimorfizmi (Çok Biçimlilik) anlamak, soyut sınıflar (Abstract Classes) ve arayüzler (Interfaces) ile yazılım şablonları tasarlamak.
* **Neler Öğretir / Kazandırır**:
  * Çalışma zamanı çok biçimliliğini (Runtime Polymorphism) ve `virtual` anahtar kelimesiyle sanal fonksiyonlar oluşturmayı.
  * Çok biçimli (polimorfik) nesne silme işlemlerinde bellek sızıntılarını engellemek için yıkıcıların neden mutlaka sanal yapılması gerektiğini (`virtual destructor`).
  * Saf sanal fonksiyonlar (`pure virtual functions`) kullanarak nesnesi doğrudan üretilemeyen ancak alt sınıflara standart getiren Soyut Sınıfları ve Arayüzleri tasarlamayı.
  * Dinamik bellek barındıran nesnelerin kopyalanmasında "Derin Kopyalama" (Deep Copy) ile "Yüzeysel Kopyalama" (Shallow Copy) arasındaki farkları ve bunların bellek yönetimindeki hayati önemini.

---

## 🛠️ Genel Kısıtlamalar ve Standartlar

Tüm modüller boyunca edinilen kazanımların yanı sıra, geliştiricinin uyması gereken katı teknik kurallar şunlardır:
* **Derleme Bayrakları**: Tüm egzersizler `-Wall -Wextra -Werror -std=c++98` bayraklarıyla derlenmek zorundadır. Uyarılar (warnings) hata olarak kabul edilir.
* **Standart Kütüphane Önceliği**: C++ standart kütüphanesinin sunduğu araçlar dışındaki harici kütüphaneler kullanılamaz.
* **Bellek Güvenliği**: Yazılan tüm kodlar bellek sızıntılarından (memory leaks) arındırılmış olmalı, tanımsız davranışlara (undefined behavior) geçit verilmemelidir.
