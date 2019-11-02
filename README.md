# adc-bar-lx

This repository hosts the software and hardware design for the ADC Theatre's new bar lighting scene controller. The system is based around an ESP32 chip (using a development board typicaly found online as the DOIT board - 30 pin version, though as we are not using WiFi or Bluetooth etc the hardware could be easily adapted to another chip version) with DMX IO, audio input for sound-to-light mode, and a remote scene set control panel.

# Build

Using esp-idf FreeRTOS toolchain, currently building on the 'latest' branch ie. v4.0 or above - default build settings. 
