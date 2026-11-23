
#define IO_USERNAME "pauslo"
#define IO_KEY "TWOJ_KLUCZ_ADAFRUIT"

#define WIFI_SSID "NAZWA_WIFI"
#define WIFI_PASS "HASLO_WIFI"

#include "AdafruitIO_WiFi.h"

#if defined(USE_AIRLIFT) || defined(ADAFRUIT_METRO_M4_AIRLIFT_LITE) || \
    defined(ADAFRUIT_PYPORTAL)

  // Configure the pins used for the ESP32 connection
  #if !defined(SPIWIFI_SS)
    // Don't change the names of these #define's, they match the variant ones
    #define SPIWIFI SPI
    #define SPIWIFI_SS 10 // Chip select pin
    #define NINA_ACK 9 // a.k.a BUSY or READY pin
    #define NINA_RESETN 6 // Reset pin
    #define NINA_GPIO0 -1 // Not connected
  #endif

  AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS,
                     SPIWIFI_SS, NINA_ACK, NINA_RESETN, NINA_GPIO0, &SPIWIFI);
#else
  AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);
#endif
