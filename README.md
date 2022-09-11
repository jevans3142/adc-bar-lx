# adc-bar-lx

This repository hosts the software and hardware design for the ADC Theatre's new bar lighting scene controller. The system is based around an ESP32 chip (using a development board typicaly found online as the DOIT board - 30 pin version, though as we are not using WiFi or Bluetooth etc the hardware could be easily adapted to another chip version) with DMX IO, audio input for sound-to-light mode, and a remote scene set control panel.

# Build

Using esp-idf FreeRTOS toolchain, currently building v4.4.2 as a stable version with the configuration included in the src folder (ie. when building do not run the idf.py set-target esp32 command as directed in the esp-idf Getting Started instructions to set up the default build config)
