#include <Arduino.h>
#include <WiFi.h>
#include <WiFiUtils.cpp>
#include <config.h>
#include <TFT_eSPI.h>
#include <TFTUtils.cpp>

void setup()
{
    // Activar el uso de bateria
    pinMode(15, OUTPUT);
    digitalWrite(15, 1);

    pinMode(0, INPUT_PULLUP);
    pinMode(14, INPUT_PULLUP);

    Serial.begin(115200);
    ConnectWiFi_STA();
    
    

    initDisplay();
    displayBattery();
    
    prev_time = millis();
    prev_time2 = millis();


    ledcSetup(0, 10000, 8);
    ledcAttachPin(38, 0);
    ledcWrite(0, brightness);
}

void loop()
{
    current_time = millis();
    current_time2 = millis();

    if (current_time - prev_time > dt_ms)
    {
        prev_time = current_time;
        
        displayInterface();


    }
    if (current_time2 - prev_time2 > bt_ms)
    {
        prev_time2 = current_time2;
        
        displayBattery();


    }
    reconectar();

    // if (digitalRead(14) == 0 && brightness < 240)
    //{
    //    brightness++;
    //    ledcSetup(0, 10000, 8);
    //    ledcAttachPin(38, 0);

    //    ledcWrite(0, brightness);
    //}

    // if (digitalRead(0) == 0 && brightness > 50)
    //{
    //     brightness--;
    //     ledcSetup(0, 10000, 8);
    //     ledcAttachPin(38, 0);

    //    ledcWrite(0, brightness);
    //}

    
}