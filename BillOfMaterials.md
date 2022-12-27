# Bill of Materials - ADC Bar LX Controller

## Central Controller 
Unit is a 1U rackmount case with various PCBs inside, connectors on rear, display and user interface on front.

### Power Supply PCB

### Main PCB

### Sound-to-light PCB

### Buttons PCB

### Case and connectors

### Other
- 1x SD card (>1MB free)
- Equipment wire and heatshrink for internal wiring
- 1.5mm Cu wiring for link from Powercon to PSU
- Crimp lugs for earthing of case and rear panel
- 1x Powercon power cable
- 1x 30cm USB-A to mini-USB cable for programming port on ESP32 link to case 

## Control Panel
1x Control panel for remote control of scene states - technically this is optional
### PCB 
|References|Item                              |Package           |Quantity|Value           |Supplier and ref|
|----------|----------------------------------|------------------|--------|--ø--------------|----------------|
|J1        |8P8C connector                    |                  |1       |8P8C            |RS 331-6443     |
|SW1-SW7   |4 pin 2.54mm pitch keyed connector|2.54mm pitch      |7       |Molex KK254 1x04|RS 792-2881     |
|Q1-Q7     |NPN transistor - KSP43BU          |TO-92             |7       |                |RS 806-4620     |
|R1-R15    |0.25W resistor                    |DIN0207 axial lead|15      |4.7Kohm         |Generic         |
|C1        |Capacitor - Unpolarised           |5mm pitch         |1       |100nF           |Generic         |
|C2        |Capacitor - Electrolytic/Polarised|2mm pitch         |1       |10uF            |Generic         |
|U1        |BCD-to-decimal decoder            |DIP-16            |1       |CD4028BEE4      |RS 145-0465     |
|U2        |8 line to 3 line priority encoder |DIP-16            |1       |SN74HC148       |RS 443-053      |
|U3        |3.3V voltage regulator            |TO-220            |1       |LF33CV          |RS 355-4128     |
|-         |16 pin DIP socket                 |DIP-16            |2       |                |RS 674-2432     |
### Other
- 7x RS Pro LED pushbuttons, panel mount, chrome, white LED - RS 111-6533
- 7x 4 pin 2.54mm pitch keyed plugs to mate with PCB - Molex KK254 - RS 679-5388
- 28x crimp contacts for connectors - Molex KK254 - RS 172-9178
- 1x Front panel - See Front Panel Designer file in hardware/control-panel-frontplate
- 4x M3x6mm panhead mouting screws (PCB to panel) 
- 2x M3.5x50mm flathead mounting screws (panel to backbox)
- Equipment wire & heatshrink for wiring of buttons to connectors
- 1 UK standard double gang backbox (in wall)
- 8P8C/RJ45 plugs and CAT5e twisted pair installation cable for link between panel and controller

## Specific spares for ADC
A number of key spares are held by John Evans for use at the ADC if required: 
- ESP32 'DOIT' dev boards of correct type
- OLED screen for controller
- All bare/upopulated PCBs 
- Various ICs: op-amps, encoder/decoders,RS485 transceivers and optoisolators 
- Relays
- SD card holder 
