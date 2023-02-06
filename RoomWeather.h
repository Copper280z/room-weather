#ifndef RoomWeather_h
#define RoomWeather_h

#define SUPPORTED_SENSOR_COUNT 2

#include <WiFi.h>
#include "RoomWeatherWifi.h"
#include "RW_HTU31D.h"
#include "RW_SGP30.h"
#include "SensorValues.h"

class RoomWeather
{
  public:
    SensorValues* Values;
    RoomWeather(String location);
    RoomWeather(String location, char ssid[], char password[]);
    void Detect();
    void Read();
    void ServeMetrics();
  private:
    RoomWeatherWifi *_wifi;
    RW_HTU31D * _htu31d;
    RW_SGP30 * _sgp30;
    Sensor* _sensors[SUPPORTED_SENSOR_COUNT];
    String _location;
    String BuildMetrics();
};

#endif