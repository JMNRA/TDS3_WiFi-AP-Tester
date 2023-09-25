#include <Arduino.h>
#include <TFT_eSPI.h>
#include <config.h>
#include <WiFi.h>

TFT_eSPI tft = TFT_eSPI();
TFT_eSprite background = TFT_eSprite(&tft);
TFT_eSprite infoSprite = TFT_eSprite(&tft);
TFT_eSprite graphSprite = TFT_eSprite(&tft);

void initDisplay()
{
    tft.init();
    tft.setRotation(1);
    tft.setSwapBytes(true);
    tft.fillScreen(TFT_BLACK);

    background.createSprite(320, 170);
    infoSprite.createSprite(160, 130);
    graphSprite.createSprite(100, 130);


    // txtSprite.setTextColor(TFT_WHITE, TFT_BLACK);
}

void porcentaje (){
  strength = WiFi.RSSI();  
  for (int x = 0; x < 100; x = x + 1) {
      if (signal_dBM[x] == strength) {
        // Print the received signal strength in percentage
        percentage = signal_percent[x];
        
        break;
      }
    }

}

void displayInterface()
{
    
   
    background.fillSprite(TFT_BLACK);
    background.drawRoundRect(10, 20, 110, 130, 5, TFT_WHITE);
    background.drawRoundRect(130, 20, 170, 130, 5, TFT_WHITE);

    infoSprite.fillSprite(TFT_BLACK);
    infoSprite.setTextDatum(3);
    infoSprite.drawString(String("SSID: ") + ssid, 20, 20, 1);
    infoSprite.drawString(String("MAC: ")+ bssid, 20, 40, 1);
    infoSprite.drawString(String("IP: ") + local_ip, 20, 60, 1);
    infoSprite.drawString(String("BATERIA: ") + bat_percentage + " %", 20, 100, 1);


    // txtSprite.drawString(String(WiFi.RSSI()), 20, 20, 2);
    // txtSprite.drawString(String(bat_percentage) + " %", 40, 40);
    graphSprite.fillSprite(TFT_BLACK);

    graphSprite.setTextDatum(3);

    graphSprite.drawString("dBm", 60, 120, 1);
    rssi = String(strength);
    graphSprite.drawString(rssi, 40, 120, 1);
    graphSprite.pushToSprite(&background, 10, 20, TFT_BLACK);
    porcentaje();
    graphSprite.setTextDatum(1);
    graphSprite.drawString(String(percentage), 60, 40, 6);


    infoSprite.pushToSprite(&background, 130, 20, TFT_BLACK);
    graphSprite.pushToSprite(&background, 10, 20, TFT_BLACK);

    background.pushSprite(0, 0);
}

float mapfloat(float x, float in_min, float in_max, float out_min, float out_max)
{
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void displayBattery() {

    volt = (analogRead(4) * 2 * 3.3 * 1000) / 4096;
    bat_percentage = mapfloat(volt, 2800, 4200, 0, 100);

}


