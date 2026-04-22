# C++ Module 03 - Kalıtım (Inheritance)

> **42 Okulu C++ Modülleri** | yayiker@student.42.fr

---

## 📋 Proje Hakkında

C++ Module 03, **kalıtım (inheritance)** konusuna odaklanır. Temel sınıftan türetilmiş sınıflar, constructor/destructor zinciri ve metod override kavramları öğrenilmektedir.

### Kullanılan Standart
**C++98** — `std=c++98` derleyici bayrağı ile derlenir.

---

## 📁 Proje Yapısı

```
cpp03/
├── ex00/                    → ClapTrap (Temel Savaş Robotu)
│   ├── ClapTrap.hpp / ClapTrap.cpp
│   ├── main.cpp
│   └── Makefile
│
├── ex01/                    → ScavTrap (ClapTrap'tan Türetilmiş)
│   ├── ClapTrap.hpp / ClapTrap.cpp
│   ├── ScavTrap.hpp / ScavTrap.cpp
│   ├── main.cpp
│   └── Makefile
│
└── ex02/                    → FragTrap (ClapTrap'tan Türetilmiş)
    ├── ClapTrap.hpp / ClapTrap.cpp
    ├── ScavTrap.hpp / ScavTrap.cpp
    ├── FragTrap.hpp / FragTrap.cpp
    ├── main.cpp
    └── Makefile
```

---

## 🧩 Egzersizler

### ex00 — ClapTrap (Temel Sınıf)
Savaş robotunun temel sınıfı. Attack, takeDamage ve beRepaired metodları.

**Başlangıç Değerleri:**
| Özellik | Değer |
|---------|-------|
| Hit Points | 10 |
| Energy Points | 10 |
| Attack Damage | 0 |

**Metodlar:**
- `attack(target)` → 1 enerji harcar, _attackDamage hasar verir
- `takeDamage(amount)` → HP azaltır
- `beRepaired(amount)` → 1 enerji harcar, HP artırır

---

### ex01 — ScavTrap (ClapTrap'tan Türetilmiş)
`class ScavTrap : public ClapTrap`

**Başlangıç Değerleri:**
| Özellik | ClapTrap | ScavTrap |
|---------|----------|----------|
| Hit Points | 10 | 100 |
| Energy Points | 10 | 50 |
| Attack Damage | 0 | 20 |

**Özel Yetenek:** `guardGate()` — Kapı bekçisi modu

**Constructor/Destructor Sırası:**
```
ClapTrap constructor → ScavTrap constructor    (oluşturma)
ScavTrap destructor  → ClapTrap destructor     (yıkım)
```

---

### ex02 — FragTrap (ClapTrap'tan Türetilmiş)
`class FragTrap : public ClapTrap`

**Başlangıç Değerleri:**
| Özellik | ClapTrap | FragTrap |
|---------|----------|----------|
| Hit Points | 10 | 100 |
| Energy Points | 10 | 100 |
| Attack Damage | 0 | 30 |

**Özel Yetenek:** `highFivesGuys()` — Pozitif çak beşlik isteği

---

## ⚙️ Derleme

```bash
cd ex<N>
make
./claptrap   # veya ./scavtrap, ./fragtrap
```

---

## 📚 Öğrenilen C++ Kavramları

| Kavram | Açıklama |
|--------|----------|
| `class B : public A` | Public kalıtım |
| Constructor zinciri | Temel sınıf constructorı önce çağrılır |
| Destructor zinciri | Türetilmiş sınıf destructorı önce çağrılır |
| Metod Override | Türetilmiş sınıf aynı isimle metod tanımlar |
| `protected` | Alt sınıflara erişilebilir private |

---

## 🔗 Kalıtım Hiyerarşisi

```
ClapTrap (temel)
    ├── ScavTrap (attack override, guardGate özelliği)
    └── FragTrap (highFivesGuys özelliği)
```

---

*42 Okulu — Ecole 42 C++ Modülleri*
