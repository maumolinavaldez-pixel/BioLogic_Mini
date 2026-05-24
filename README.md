# BioLogic (v2.0.0-Local)

![Arduino Lint](https://img.shields.io/badge/Arduino-Compatible-00979D?style=for-the-badge&logo=arduino&logoColor=white)
![Platform](https://img.shields.io/badge/Platform-ESP32--C3-E7352C?style=for-the-badge&logo=espressif&logoColor=white)
![Version](https://img.shields.io/badge/Version-1.0.0--Local-blue?style=for-the-badge)

Librería nativa y optimizada para el control directo de las etapas de potencia de la placa **BioLogic** utilizando el microcontrolador **ESP32-C3**.

Esta versión elimina por completo la dependencia del bus de comunicación I2C y la arquitectura esclava previa, ejecutando todas las tareas de conmutación de manera local y monolítica en el núcleo del ESP32-C3. Esto reduce críticamente la latencia, elimina los problemas de colisión en el bus y simplifica la infraestructura de firmware.

---

## Características Principales

* **Control Local Inmediato:** Configuración automatizada de hardware embebido al invocar un único método.
* **Mapeo de Pines Optimizado:** Enlace directo a los GPIOs físicos del ESP32-C3 para el control de potencia.
* **API Arduino-Compatible:** Conserva métodos estándar (`pinMode`, `digitalWrite`, `digitalRead`) adaptados a la abstracción de relés de BioLogic.
* **Funciones de Temporización Seguras:** Implementación nativa de conmutación por tiempo sin bloquear por completo hilos críticos del sistema.

---

## Arquitectura de Hardware (Mapeo de Pines)

En esta revisión de firmware, se han priorizado y mantenido exclusivamente las salidas de potencia principales (`r1` y `r2`) para un control directo y de alta velocidad:

| Pin Virtual BioLogic | Pin Físico ESP32-C3 | Descripción del Canal | Estado Inicial |
| :---: | :---: | :---: | :---: |
| `r1` | **GPIO 4** | Salida digital de potencia 1 / Relé 1 | `LOW` (Apagado) |
| `r2` | **GPIO 3** | Salida digital de potencia 2 / Relé 2 | `LOW` (Apagado) |

---

## Instalación

1. Descarga o clona este repositorio en tu máquina local.
2. Mueve la carpeta del proyecto al directorio de librerías de tu entorno de desarrollo (por defecto en Arduino IDE: `Documentos/Arduino/libraries/`).
3. Asegúrate de que la estructura de archivos interna sea la siguiente:
   ```text
   BioLogic/
   ├── BioLogic.cpp
   ├── BioLogic.h
   ├── keywords.txt
   └── library.properties
