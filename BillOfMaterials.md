# Bill of Materials - ADC Bar LX Controller

## Central Controller 
Unit is a 1U rackmount case with various PCBs inside, connectors on rear, display and user interface on front.

### Power Supply PCB
KiCAD PCB files found in hardware/psu-board
|References        |Item                                |Package      |Quantity|Value           |Supplier and ref         |
|------------------|------------------------------------|-------------|--------|----------------|-------------------------|
|PS1               |10W Switch mode PSU 230V->15V       |             |1       |RAC10-15DK/277  |RS 165-5098              |
|U1                |Switching regulator, 12V output     |             |1       |R-78E12-0.5     |RS 122-8230              |
|U2                |Switching regulator, 5V output      |             |1       |R-78E5.0-0.5    |RS 757-7239              |
|J1-J4             |4 pin 2.54mm pitch keyed connector  |2.54mm pitch |5       |Molex KK254 1x04|RS 792-2881              |
|C1,C2             |Capacitor - Electrolytic/Polarised  |2.5mm pitch  |2       |10uF            |Generic                  |
### Main PCB
KiCAD PCB files found in hardware/main-board
|References        |Item                                |Package      |Quantity|Value           |Supplier and ref         |
|------------------|------------------------------------|-------------|--------|----------------|-------------------------|
|U7                |ESP32 dev board - ‘DOIT’ 30 pin type|             |1       |                |eBay - happybuddhatrading|
|J1, J2, J5x2      |Krone 4 pole IDC terminal           |             |4       |                |Rapid 24-0610            |
|U3,U4             |Line Transceiver RS-422             |DIP-8        |2       |MAX485          |RS 540-2243              |
|C1,C2             |Capacitor - Unpolarised             |5mm pitch    |2       |470nF           |Generic                  |
|C3                |Capacitor - Electrolytic/Polarised  |2.5mm pitch  |1       |10uF            |Generic                  |
|J3, J4, J6, J7, J9|4 pin 2.54mm pitch keyed connector  |2.54mm pitch |5       |Molex KK254 1x04|RS 792-2881              |
|J8                |5 pin 2.54mm pitch keyed connector  |2.54mm pitch |1       |Molex KK254 1x04|RS 679-5599              |
|K1,K2             |DPDT Relay - 12V coil, non-latching |             |2       |                |RS 800-4441              |
|R1,R7             |0.25W resistor                      |10.16mm pitch|2       |470R            |Generic                  |
|R2,R4,R5          |0.25W resistor                      |10.16mm pitch|3       |4.7Kohm         |Generic                  |
|R3,R6             |0.25W resistor                      |10.16mm pitch|2       |120R            |Generic                  |
|R8                |0.25W resistor                      |10.16mm pitch|1       |10Kohm          |Generic                  |
|U1, U5            |DC-DC isolator 5V 1W                |             |2       |                |RS 191-4922              |
|U2,U6             |Transistor output Optocoupler       |             |2       |6N137(F)        |RS 625-7909              |
|-                 |8 pin DIP socket                    |             |4       |                |RS 674-2435              |
|-                 |15 pin socket (for dev board)       |             |2       |                |RS 180-0452              |
### Sound-to-light PCB
KiCAD PCB files found in hardware/s2l-board
|References            |Item                               |Package      |Quantity|Value           |Supplier and ref|
|----------------------|-----------------------------------|-------------|--------|----------------|----------------|
|C1,C2,C7,C11,C15      |Capacitor - Unpolarised            |5mm pitch    |5       |100nF           |Generic         |
|C3                    |Capacitor - Unpolarised            |2.5mm pitch  |1       |220pF           |Generic         |
|C4,C8,C12,C16         |Capacitor - Electrolytic/Polarised |1.5mm pitch  |4       |47uF            |Generic         |
|C5                    |Capacitor - Unpolarised            |5mm pitch    |1       |10nF            |Generic         |
|C6                    |Capacitor - Unpolarised            |5mm pitch    |1       |20nF            |Generic         |
|C9,C10,C13,C14,C17,C18|Capacitor - Unpolarised            |5mm pitch    |6       |100nF           |Generic         |
|D1,D3,D5,D7           |Signal diode                       |DO-35        |4       |1N4148          |Generic         |
|D2,D4,D6,D8           |3V Zener Diode                     |DO-35        |4       |BZX79C3V0       |RS 544-3525     |
|J1-J3                 |4 pin 2.54mm pitch keyed connector |2.54mm pitch |3       |Molex KK254 1x04|RS 792-2881     |
|R1,R8,R11,R12,R18,R27 |0.25W resistor                     |10.16mm pitch|6       |10Kohm          |Generic         |
|R2,R9                 |0.25W resistor                     |10.16mm pitch|2       |6.8Kohm         |Generic         |
|R3                    |0.25W resistor                     |10.16mm pitch|1       |3.3Kohm         |Generic         |
|R4                    |0.25W resistor                     |10.16mm pitch|1       |100R            |Generic         |
|R5,R6                 |0.25W resistor                     |10.16mm pitch|2       |100k            |Generic         |
|R7,R14,R15,R20,R25    |0.25W resistor                     |10.16mm pitch|5       |1Kohm           |Generic         |
|R10,R16,R21,R26       |0.25W resistor                     |10.16mm pitch|4       |2.2Kohm         |Generic         |
|R13,R22               |0.25W resistor                     |10.16mm pitch|2       |22Kohm          |Generic         |
|R17                   |0.25W resistor                     |10.16mm pitch|1       |47Kohm          |Generic         |
|R19                   |0.25W resistor                     |10.16mm pitch|1       |320R            |Generic         |
|R23                   |0.25W resistor                     |10.16mm pitch|1       |4.7Kohm         |Generic         |
|R24                   |0.25W resistor                     |10.16mm pitch|1       |220R            |Generic         |
|U1-U5                 |Single audio op-amp                |DIP-8        |5       |UA741CP         |RS 305-311      |
|-                     |8 pin DIP socket                   |             |5       |                |RS 674-2435     |

### Buttons PCB
KiCAD PCB files found in hardware/menu-buttons
|References|Item                              |Package           |Quantity|Value           |Supplier and ref|
|----------|----------------------------------|------------------|--------|----------------|----------------|
|SW1-SW4   |Tactile buttons,6x6mm,13mm high   |                  |4       |                |RS 479-1457     |
|J1        |5 pin 2.54mm pitch keyed connector|2.54mm pitch      |1       |Molex KK254 1x05|RS 679-5599     |

Note that J1 is optional - wires can be soldered directly to the PCB to create a wiring harness. If so qty of 5 pin 2.54mm headers listed in 'Other' below is 1 not 2. 

### Case
The case was ordered using Front Panel Designer/Schaeffer AG. There are a number of source files for the Front Panel Designer software in hardware/case; in addition some hardware and side profile extrusions were ordered from Schaeffer at the same time. The part numbers given here are for Schaeffer's hardware parts.
- 1x Front panel (see FPD file)
- 1x Back panel (see FPD file)
- 1x Top panel (see FPD file)
- 1x Bottom panel (see FPD file)
- 2x GLGP1013 Side profiles (black anodised) - 195mm length
- 1x GGMS1122 Assembly kit ISP/B3.0-SW DIN7982 - black - consists of 8x CSK head screw 2.9mm diax9.5mm length and four rubber feet
- 1x GGWS0112 Housing bracket pack - consists of 8 L brackets
- 1x GGRB3306 Screw packet - M3x6mm CSK head machine screws 
Note that this ended up being a very, very expensive way of creating a case. There's likely some significant changes that could be made here.

### Connectors
- 1x 3D printed SD card holder - see 3dm file at hardware/sd-card-3dprint
- 1x SD card slot module - https://proto-pic.co.uk/product/sd-mmc-card-breakout-board
- 1x OLED screen module - 1.3" 128x64 OLED display I2C - eBay - karens_e-shop - https://www.ebay.co.uk/itm/282358769160
- 1x 3D printed SD card holder - see 3dm file at hardware/screen-holder-3dprint
- 1x Neutrik Powercon 20A inlet - NAC3MPXXA
- 1x Neutrik XLR-3F - NC3FDM3-L-1
- 3x 8P8C/RJ45 D type connectors - TUK D-SERIES KEYSTONE RJ45 IDC SOCKET Cat5E, tool-less, black - Canford 44-9121
- 1X USB passthrough D type - Neutrik NAUSB-W

### Other
- 1x SD card (>1MB free)
- Equipment wire and heatshrink for internal wiring
- 1.5mm Cu wiring and heatshrink for link from Powercon to PSU
- Crimp lugs for earthing of case and rear panel
- 1x Fuseholder - RS 563-784
- 1x Fuse - F0.5A LBC 5x20mm eg. RS 563-463
- 1x Powercon power cable
- Short length of audio cable (eg. Canford FST) for link from XLR to PCB
- 3x Short lengths of CAT5e cable for link from rear panel connectors to PCB
- 1x 30cm USB-A to mini-USB cable for programming port on ESP32 link to case 
- 9x 4 pin 2.54mm pitch keyed plugs to mate with PCB - Molex KK254 - RS 679-5388
- 1/2x 5 pin 2.54mm pitch keyed plugs to mate with PCB - Molex KK254 - 679-5385
- 44x (approx)  crimp contacts for connectors - Molex KK254 - RS 172-9178

## Control Panel
1x Control panel for remote control of scene states - technically this is optional
### PCB

KiCAD PCB files found in hardware/control-panel
 
|References|Item                              |Package           |Quantity|Value           |Supplier and ref|
|----------|----------------------------------|------------------|--------|----------------|----------------|
|J1        |8P8C connector                    |                  |1       |8P8C            |RS 331-6443     |
|SW1-SW7   |4 pin 2.54mm pitch keyed connector|2.54mm pitch      |7       |Molex KK254 1x04|RS 792-2881     |
|Q1-Q7     |NPN transistor - KSP43BU          |TO-92             |7       |                |RS 806-4620     |
|R1-R15    |0.25W resistor                    |10.16mm pitch     |15      |4.7Kohm         |Generic         |
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
