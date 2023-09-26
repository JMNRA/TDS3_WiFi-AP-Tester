#include <Arduino.h>
#include <WiFi.h>
#include <TFT_eSPI.h>
#include <config.h>

void ConnectWiFi_STA(bool useStaticIP = false)
{
    Serial.println("");
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    if (useStaticIP){
        WiFi.config(ip, gateway, subnet);
    }
    Serial.println("");
    Serial.print("Iniciado STA:\t");
    Serial.println(ssid);
    Serial.print("IP address:\t");
    Serial.println(WiFi.localIP());
    

    
  



}

void ConnectWiFi_AP(bool useStaticIP = false)
{
    Serial.println("");
    WiFi.mode(WIFI_AP);
    while (!WiFi.softAP(ssid, password))
    {
        Serial.println(".");
        delay(100);
    }
    if (useStaticIP)
        WiFi.softAPConfig(ip, gateway, subnet);

    Serial.println("");
    Serial.print("Iniciado AP:\t");
    Serial.println(ssid);
    Serial.print("IP address:\t");
    Serial.println(WiFi.softAPIP());
}

