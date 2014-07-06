Systemy Operacyjne - Laboratorium 4 - Monitory
==============================================

Projekt wykonany w ramach laboratorium SOI (Systemy Operacyjne) w semestrze 2014L (4 semestr),
na kierunku Informatyka na Wydziale Elektroniki i Technik Informacyjnych (EiTI) Politechniki Warszawskiej.

### Ćwiczenie

Ćwiczenie polega na konstrukcji stosu przechowującego liczby naturalne, obsługiwanego przez dwa procesy producentów i dwa procesy konsumentów.
Założenia ćwiczenia:
- Stos ma pojemność na maksymalnie 9 elementów
- Producent A może położyć element na stosie, gdy suma elementów na stosie jest mniejsza niż 20
- Konsument B może zdjąć element ze stosu, gdy liczba elementów na stosie jest większa niż 3
- Należy uniemożliwić odczyt z pustego stosu
- Należy uniemożliwić zapis na pełny stos
- Należy zadbać o "nie przeszkadzanie sobie" procesów zapisujących do bufora i procesów czytających z bufora

### Wymagania implementacyjne

- Implementacja w języku C/C++
- Implementacja pod dowolnym systemem z rodziny Linux
- Wykorzystanie monitorów

### Kompilacja i uruchamianie

- Kompilacja: ```make```
- Uruchamianie: ```./build/run```

### Działanie testowane na:

- Ubuntu 14.04 LTS
  - g++ 4.8.2
  - clang 3.4
- Ubuntu 13.10
  - g++ 4.8.1
  - clang 3.2
