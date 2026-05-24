#include "BioLogic_Mini.h"
#include <Arduino.h>
#include <WiFi.h>

BioLogic::BioLogic() {
    _initialized = false;
}

void BioLogic::begin() {
    ::pinMode(r1_PIN, OUTPUT);
    ::digitalWrite(r1_PIN, LOW);
    ::pinMode(r2_PIN, OUTPUT);
    ::digitalWrite(r2_PIN, LOW);
    _initialized = true;
}

void BioLogic::pinMode(uint8_t pin, uint8_t mode) {
    if (!_initialized) return;
    if (pin == r1) {
        ::pinMode(r1_PIN, mode);
    } else if (pin == r2) {
        ::pinMode(r2_PIN, mode);
    }
}

void BioLogic::digitalWrite(uint8_t pin, uint8_t value) {
    if (!_initialized) return;
    if (pin == r1) {
        ::digitalWrite(r1_PIN, value);
    } else if (pin == r2) {
        ::digitalWrite(r2_PIN, value);
    }
}

uint8_t BioLogic::digitalRead(uint8_t pin) {
    if (!_initialized) return LOW;
    
    if (pin == r1) {
        return ::digitalRead(r1_PIN);
    } else if (pin == r2) {
        return ::digitalRead(r2_PIN);
    }
    return LOW;
}

void BioLogic::relayOn(uint8_t relayNum) {
    if (relayNum == r1 || relayNum == r2) {
        digitalWrite(relayNum, HIGH);   
    } 
}

void BioLogic::relayOff(uint8_t relayNum) {
    if (relayNum == r1 || relayNum == r2) {
        digitalWrite(relayNum, LOW);
    } 
}

void BioLogic::relayToggle(uint8_t relayNum) {
    if (relayNum == r1 || relayNum == r2) {
        uint8_t currentState = digitalRead(relayNum);
        digitalWrite(relayNum, !currentState);
    }
}

void BioLogic::relayTimed(uint8_t relayNum, uint32_t durationMs) {
    if (relayNum == r1 || relayNum == r2) {
        relayOn(relayNum);
        uint32_t startTime = millis();
        while (millis() - startTime < durationMs) {
            // Mantiene el flujo de ejecución local respondiendo de manera segura
            delay(10); 
        }
        relayOff(relayNum);
    }
}
