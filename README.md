
# Kryptografische Algorithmen

## Überblick
Dieses Projekt implementiert verschiedene kryptografische Algorithmen und mathematische Methoden, die häufig in der IT-Sicherheit eingesetzt werden. Es handelt sich um effiziente und optimierte Implementierungen mit Testfällen und Zeitmessung, um die Leistungsfähigkeit zu überprüfen.

## Funktionen

### 1. Schnelle Exponentiation
Ein effizienter Algorithmus zur Berechnung von $a^b \mod m$.
- **Datei**: `algorithmen.c`
- **Methode**: `schnelle_exponentation`
- **Verwendung**:
  ```c
  int64 result = schnelle_exponentation(basis, exponent, mod);
  ```

### 2. Miller-Rabin-Test
Ein Primzahltest, um zu bestimmen, ob eine Zahl wahrscheinlich eine Primzahl ist.
- **Datei**: `algorithmen.c`
- **Methoden**:
  - `miller_rabin_test`
  - `is_prime`
  - `miller_rabin`
- **Verwendung**:
  ```c
  bool istPrim = is_prime(zahl, iterationen);
  ```

### 3. (Erweiterter) Euklidischer Algorithmus
Berechnung des größten gemeinsamen Teilers (ggT) und der Koeffizienten zur Lösung der diophantischen Gleichung $ax + by = ggT(a, b)$.
- **Datei**: `algorithmen.c`
- **Methoden**:
  - `ggt`
  - `erweiterter_ggt`
- **Verwendung**:
  ```c
  int64 x, y;
  int64 ggT = erweiterter_ggt(a, b, &x, &y);
  ```

## Dateien

### 1. `algorithmen.c`
Enthält die Implementierung der kryptografischen Algorithmen.

### 2. `algorithmen.h`
Header-Datei mit den Funktionsdeklarationen und Typdefinitionen.

### 3. `algorithmen_test.c`
Implementiert Testfälle für die Algorithmen. Die Ergebnisse werden validiert und mit Zeitmessungen dargestellt.

### 4. `algorithmen_test.h`
Header-Datei für die Testimplementierung.

## Kompilierung und Ausführung

### Voraussetzungen
- GCC oder ein anderer C-Compiler
- Standardbibliotheken

### Kompilierung
Verwenden den folgenden Befehl:
```bash
gcc -o algorithmen algorithmen.c algorithmen_test.c -lm
```

### Ausführung
Führen das kompilierten Programm aus:
```bash
./algorithmen
```

## Testfälle

Das Projekt enthält eine umfassende Sammlung von Testfällen zur Überprüfung der Algorithmen:
- **Grenzwerttests**: Sehr große Zahlen, kleine Zahlen, und Spezialfälle (z. B. Modulo 0).
- **Leistungsvergleiche**: Zeitmessungen für verschiedene Szenarien.

### Beispielausgabe für `test_schnelle_exponentation`
```bash
1. Grenzwerttest: Sehr große Basis erfolgreich! Benötigte Zeit: 0.0001 ms
2. Grenzwerttest: Sehr großer Exponent erfolgreich! Benötigte Zeit: 0.0005 ms
```

## Autoren
- **yalmn**
  - Version: `v0.0.1`
  - Beschreibung: Kryptografische Algorithmen

## Lizenz
Aktuell keine Lizenz definiert.
