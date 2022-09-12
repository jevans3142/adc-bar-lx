<img width="280" align="right" src="https://raw.githubusercontent.com/CHTJonas/roombooking/master/public/logo-long-black.svg?sanitize=true">

# ADC Theatre - Bar Lighting Controller

This repository hosts the software and hardware design for the [ADC Theatre's](https://www.adctheatre.com) bar lighting scene controller. The system is based around an ESP32 chip (using a development board typicaly found online as the DOIT board - 30 pin version, though as we are not using WiFi or Bluetooth etc the hardware could be easily adapted to another chip version) with DMX input and output, audio input for sound-to-light mode, and a remote scene set control panel.

## Features

* Provides seven reprogrammable scenes which can be faded between from the easy to use remote control panel
* DMX input for programming scenes with highest-takes-precedence merge function for operating a more complex show without recabling 
* Sound-to-light function for parties with four analogue filter channels to replicate an older system. Party functions can be enabled and disabled per scene
* Small OLED screen and menu system on the central rackmount controller for configuration
* In the event of power being disconnected the DMX input is directly connected to the output using relays to make bypass easy
* All scenes and settings are stored on an SD card

## Build

The microcontroller used is an ESP32. After standard installation of the esp-idf FreeRTOS toolchain, currently building on v4.4.2 as a stable version with the configuration included in the src folder (ie. when building do not run the idf.py set-target esp32 command as directed in the esp-idf Getting Started instructions to set up the default build config - just go straight to idf.py build)

## Hardware

PCB files in KiCAD format:
* Power supply
* Mainboard
* Sound-to-light
* Buttons (front panel)
* Remote control panel

In addition there are files for Schaeffer AG's FrontPanelDesigner application covering:
* Case including front and back panels
* Remote control panel

There are 3DM model files for two 3D printed elements: 
* A bracket to hold the OLED screen to the case frontpanel 
* A bracket to hold the SD card module to the case frontpanel

In addition to the standard components populating the PCBs one ESP32 'DOIT' style devboard, an SD card breakout module, and an OLED screen module are required, all purchased from eBay. Multiple spares are held of each item by John if required for the ADC.

## Copyright
Copyright (c) 2019-2022 John Evans and contributors.