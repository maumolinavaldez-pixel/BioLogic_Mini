#ifndef BIOLOGIC_H
#define BIOLOGIC_H

#include "Arduino.h"
#include "WiFi.h"

// Pines físicos asignados localmente en el ESP32-C3
#define r1_PIN  4
#define r2_PIN  3

// Índices virtuales para mantener compatibilidad con la lógica previa
#define r1  0
#define r2  1

class BioLogic {
private:
    bool _initialized;

public:
    BioLogic();
    void begin();
    void pinMode(uint8_t pin, uint8_t mode);
    void digitalWrite(uint8_t pin, uint8_t value);
    uint8_t digitalRead(uint8_t pin);
    void relayOn(uint8_t relayNum);
    void relayOff(uint8_t relayNum);
    void relayToggle(uint8_t relayNum);
    void relayTimed(uint8_t relayNum, uint32_t durationMs);
};

#endif // BIOLOGIC_H
