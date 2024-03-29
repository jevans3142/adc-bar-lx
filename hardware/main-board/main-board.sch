EESchema Schematic File Version 4
LIBS:main-board-cache
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Relay:FINDER-40.52 K1
U 1 1 5E3DC26E
P 9450 1650
F 0 "K1" V 10217 1650 50  0000 C CNN
F 1 "DPDT Relay" V 10126 1650 50  0000 C CNN
F 2 "Relay_THT:Relay_DPDT_Finder_40.52" H 10800 1620 50  0001 C CNN
F 3 "http://gfinder.findernet.com/assets/Series/353/S40EN.pdf" H 9250 1650 50  0001 C CNN
	1    9450 1650
	0    -1   -1   0   
$EndComp
$Comp
L Relay:FINDER-40.52 K2
U 1 1 5E3E280D
P 9450 3250
F 0 "K2" V 10217 3250 50  0000 C CNN
F 1 "DPDT Relay" V 10126 3250 50  0000 C CNN
F 2 "Relay_THT:Relay_DPDT_Finder_40.52" H 10800 3220 50  0001 C CNN
F 3 "http://gfinder.findernet.com/assets/Series/353/S40EN.pdf" H 9250 3250 50  0001 C CNN
	1    9450 3250
	0    -1   -1   0   
$EndComp
Wire Wire Line
	8900 2950 9150 2950
Wire Wire Line
	9150 3350 8800 3350
Wire Wire Line
	9950 1650 9750 1650
$Comp
L Interface_UART:MAX481E U3
U 1 1 5E3F2BBA
P 7850 1300
F 0 "U3" H 7600 1750 50  0000 C CNN
F 1 "MAX481E" H 8050 1750 50  0000 C CNN
F 2 "Package_DIP:DIP-8_W7.62mm_Socket" H 7850 600 50  0001 C CNN
F 3 "https://datasheets.maximintegrated.com/en/ds/MAX1487E-MAX491E.pdf" H 7850 1350 50  0001 C CNN
	1    7850 1300
	1    0    0    -1  
$EndComp
Wire Wire Line
	8250 1150 8250 1200
Wire Wire Line
	8250 1550 8250 1500
$Comp
L Interface_UART:MAX481E U4
U 1 1 5E3FDA96
P 7850 2900
F 0 "U4" H 7600 3350 50  0000 C CNN
F 1 "MAX481E" H 8050 3350 50  0000 C CNN
F 2 "Package_DIP:DIP-8_W7.62mm_Socket" H 7850 2200 50  0001 C CNN
F 3 "https://datasheets.maximintegrated.com/en/ds/MAX1487E-MAX491E.pdf" H 7850 2950 50  0001 C CNN
	1    7850 2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	9150 2750 8450 2750
Wire Wire Line
	8250 2750 8250 2800
Wire Wire Line
	9150 3150 8450 3150
Wire Wire Line
	8250 3150 8250 3100
Wire Wire Line
	9950 2850 9750 2850
NoConn ~ 7450 1500
NoConn ~ 7450 2800
$Comp
L power:GNDD #PWR0102
U 1 1 5E405312
P 7850 1900
F 0 "#PWR0102" H 7850 1650 50  0001 C CNN
F 1 "GNDD" H 7854 1745 50  0000 C CNN
F 2 "" H 7850 1900 50  0001 C CNN
F 3 "" H 7850 1900 50  0001 C CNN
	1    7850 1900
	1    0    0    -1  
$EndComp
$Comp
L power:+5VD #PWR0103
U 1 1 5E4060C7
P 7850 800
F 0 "#PWR0103" H 7850 650 50  0001 C CNN
F 1 "+5VD" H 7865 973 50  0000 C CNN
F 2 "" H 7850 800 50  0001 C CNN
F 3 "" H 7850 800 50  0001 C CNN
	1    7850 800 
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR0106
U 1 1 5E40D9EE
P 10250 2050
F 0 "#PWR0106" H 10250 1800 50  0001 C CNN
F 1 "GNDD" H 10254 1895 50  0000 C CNN
F 2 "" H 10250 2050 50  0001 C CNN
F 3 "" H 10250 2050 50  0001 C CNN
	1    10250 2050
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0107
U 1 1 5E931A23
P 3600 4650
F 0 "#PWR0107" H 3600 4500 50  0001 C CNN
F 1 "+5V" H 3615 4823 50  0000 C CNN
F 2 "" H 3600 4650 50  0001 C CNN
F 3 "" H 3600 4650 50  0001 C CNN
	1    3600 4650
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x04_Male J4
U 1 1 5E934C0F
P 1100 4750
F 0 "J4" H 1208 5031 50  0000 C CNN
F 1 "Display_Connector" H 1208 4940 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:Molex_KK254_1x04Vertical" H 1100 4750 50  0001 C CNN
F 3 "~" H 1100 4750 50  0001 C CNN
	1    1100 4750
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x04_Male J6
U 1 1 5E937FB0
P 1100 5400
F 0 "J6" H 1208 5681 50  0000 C CNN
F 1 "S2L_Board_Connector" H 1208 5590 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:Molex_KK254_1x04Vertical" H 1100 5400 50  0001 C CNN
F 3 "~" H 1100 5400 50  0001 C CNN
	1    1100 5400
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0109
U 1 1 5E939E24
P 2150 4650
F 0 "#PWR0109" H 2150 4500 50  0001 C CNN
F 1 "+5V" H 2165 4823 50  0000 C CNN
F 2 "" H 2150 4650 50  0001 C CNN
F 3 "" H 2150 4650 50  0001 C CNN
	1    2150 4650
	1    0    0    -1  
$EndComp
Wire Wire Line
	2600 5100 1900 5100
Wire Wire Line
	1900 4950 1300 4950
Wire Wire Line
	1300 4850 2000 4850
Wire Wire Line
	2000 5000 2600 5000
Wire Wire Line
	1300 4750 2150 4750
$Comp
L power:GND #PWR0110
U 1 1 5E93D532
P 2150 4750
F 0 "#PWR0110" H 2150 4500 50  0001 C CNN
F 1 "GND" H 2155 4577 50  0000 C CNN
F 2 "" H 2150 4750 50  0001 C CNN
F 3 "" H 2150 4750 50  0001 C CNN
	1    2150 4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	1300 4650 2150 4650
Wire Wire Line
	2000 4850 2000 5000
Wire Wire Line
	1900 4950 1900 5100
Wire Wire Line
	1300 5300 2600 5300
Wire Wire Line
	1300 5400 2600 5400
Wire Wire Line
	1300 5500 2600 5500
Wire Wire Line
	1300 5600 2600 5600
$Comp
L power:+5V #PWR0111
U 1 1 5E949DBC
P 1800 3900
F 0 "#PWR0111" H 1800 3750 50  0001 C CNN
F 1 "+5V" H 1815 4073 50  0000 C CNN
F 2 "" H 1800 3900 50  0001 C CNN
F 3 "" H 1800 3900 50  0001 C CNN
	1    1800 3900
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0112
U 1 1 5E94D953
P 1800 4000
F 0 "#PWR0112" H 1800 3750 50  0001 C CNN
F 1 "GND" H 1805 3827 50  0000 C CNN
F 2 "" H 1800 4000 50  0001 C CNN
F 3 "" H 1800 4000 50  0001 C CNN
	1    1800 4000
	1    0    0    -1  
$EndComp
NoConn ~ 1300 3700
$Comp
L Connector:Conn_01x04_Male J3
U 1 1 5E939902
P 1100 3800
F 0 "J3" H 1208 4081 50  0000 C CNN
F 1 "PSU_Connector" H 1208 3990 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:Molex_KK254_1x04Vertical" H 1100 3800 50  0001 C CNN
F 3 "~" H 1100 3800 50  0001 C CNN
	1    1100 3800
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR0113
U 1 1 5E954D46
P 1650 3800
F 0 "#PWR0113" H 1650 3650 50  0001 C CNN
F 1 "+12V" H 1665 3973 50  0000 C CNN
F 2 "" H 1650 3800 50  0001 C CNN
F 3 "" H 1650 3800 50  0001 C CNN
	1    1650 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	1300 3800 1650 3800
Wire Wire Line
	1300 3900 1800 3900
Wire Wire Line
	1300 4000 1800 4000
Text Label 2250 5000 0    50   ~ 0
I2C_SCL
Text Label 2250 5100 0    50   ~ 0
I2C_SDA
Text Label 2200 5300 0    50   ~ 0
ADC_CH_1
Text Label 2200 5400 0    50   ~ 0
ADC_CH_2
Text Label 2200 5500 0    50   ~ 0
ADC_CH_3
Text Label 2200 5600 0    50   ~ 0
ADC_CH_4
Wire Wire Line
	4400 5000 4950 5000
Wire Wire Line
	4950 5100 4400 5100
Wire Wire Line
	4400 5200 4950 5200
Wire Wire Line
	4400 5300 4950 5300
Wire Wire Line
	4400 5400 4950 5400
Wire Wire Line
	4950 5500 4400 5500
$Comp
L power:GND #PWR0114
U 1 1 5E972FC0
P 4650 4700
F 0 "#PWR0114" H 4650 4450 50  0001 C CNN
F 1 "GND" H 4655 4527 50  0000 C CNN
F 2 "" H 4650 4700 50  0001 C CNN
F 3 "" H 4650 4700 50  0001 C CNN
	1    4650 4700
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR0115
U 1 1 5E9738F5
P 4650 5750
F 0 "#PWR0115" H 4650 5600 50  0001 C CNN
F 1 "+12V" H 4665 5923 50  0000 C CNN
F 2 "" H 4650 5750 50  0001 C CNN
F 3 "" H 4650 5750 50  0001 C CNN
	1    4650 5750
	1    0    0    -1  
$EndComp
Wire Wire Line
	4650 4700 4850 4700
Wire Wire Line
	4850 4700 4850 4900
Wire Wire Line
	4850 4900 4950 4900
Wire Wire Line
	4950 5600 4850 5600
Wire Wire Line
	4850 5600 4850 5750
Wire Wire Line
	4850 5750 4650 5750
$Comp
L Connector:8P8C J5
U 1 1 5E97BB72
P 5350 5200
F 0 "J5" H 5020 5204 50  0000 R CNN
F 1 "Remote_Panel _Connector" H 5020 5295 50  0000 R CNN
F 2 "Connector_RJ:Krone_split_termials" V 5350 5225 50  0001 C CNN
F 3 "~" V 5350 5225 50  0001 C CNN
	1    5350 5200
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x05_Female J8
U 1 1 5E982860
P 5300 6150
F 0 "J8" H 5328 6176 50  0000 L CNN
F 1 "Buttons_Connector" H 5328 6085 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:Molex_KK254_1x05Vertical" H 5300 6150 50  0001 C CNN
F 3 "~" H 5300 6150 50  0001 C CNN
	1    5300 6150
	1    0    0    -1  
$EndComp
Wire Wire Line
	4400 5950 5100 5950
Wire Wire Line
	4400 6050 5100 6050
Wire Wire Line
	5100 6150 4400 6150
Wire Wire Line
	4400 6250 5100 6250
$Comp
L power:GND #PWR0116
U 1 1 5E98BB00
P 5000 6350
F 0 "#PWR0116" H 5000 6100 50  0001 C CNN
F 1 "GND" H 5005 6177 50  0000 C CNN
F 2 "" H 5000 6350 50  0001 C CNN
F 3 "" H 5000 6350 50  0001 C CNN
	1    5000 6350
	1    0    0    -1  
$EndComp
Wire Wire Line
	5000 6350 5100 6350
Wire Wire Line
	4400 6450 4750 6450
Wire Wire Line
	4400 6550 4750 6550
Text Label 4450 6450 0    50   ~ 0
DMX_RX
Text Label 4450 6550 0    50   ~ 0
DMX_TX
$Comp
L MCU_Espressif:ESP32 U7
U 1 1 5E92C2AC
P 3500 5700
F 0 "U7" H 2750 6650 50  0000 C CNN
F 1 "ESP32" H 4150 6650 50  0000 C CNN
F 2 "Module:ESP32_DOIT30" H 3500 4400 50  0001 C CNN
F 3 "http://espressif.com/sites/default/files/documentation/0a-esp8266ex_datasheet_en.pdf" H 3550 4400 50  0001 C CNN
	1    3500 5700
	1    0    0    -1  
$EndComp
NoConn ~ 2600 6450
NoConn ~ 2600 6550
$Comp
L Regulator_Switching:TMA_0505S U1
U 1 1 5E9BA76B
P 3200 1300
F 0 "U1" H 3200 1767 50  0000 C CNN
F 1 "DMX Input 5V Isolation" H 3200 1676 50  0000 C CNN
F 2 "Converter_DCDC:Traco_TMA_DCDCsingle" H 3200 950 50  0001 C CNN
F 3 "http://assets.tracopower.com/TMR1/documents/tmr1-datasheet.pdf" H 3200 800 50  0001 C CNN
	1    3200 1300
	1    0    0    -1  
$EndComp
$Comp
L Regulator_Switching:TMA_0505S U5
U 1 1 5E9BC0CB
P 3200 2950
F 0 "U5" H 3200 3417 50  0000 C CNN
F 1 "DMX Output 5V Isolation" H 3200 3326 50  0000 C CNN
F 2 "Converter_DCDC:Traco_TMA_DCDCsingle" H 3200 2600 50  0001 C CNN
F 3 "http://assets.tracopower.com/TMR1/documents/tmr1-datasheet.pdf" H 3200 2450 50  0001 C CNN
	1    3200 2950
	1    0    0    -1  
$EndComp
$Comp
L Isolator:6N136 U2
U 1 1 5E9BE7CA
P 6050 1300
F 0 "U2" H 6050 1725 50  0000 C CNN
F 1 "6N136" H 6050 1634 50  0000 C CNN
F 2 "Package_DIP:DIP-8_W7.62mm_Socket" H 5850 1000 50  0001 L CIN
F 3 "https://optoelectronics.liteon.com/upload/download/DS70-2008-0032/6N135-L%206N136-L%20series.pdf" H 6050 1300 50  0001 L CNN
	1    6050 1300
	-1   0    0    1   
$EndComp
NoConn ~ 2600 6650
Wire Wire Line
	3450 6950 3450 7050
Wire Wire Line
	3450 7050 3500 7050
Wire Wire Line
	3550 7050 3550 6950
$Comp
L power:GND #PWR0101
U 1 1 5EDE749C
P 3500 7050
F 0 "#PWR0101" H 3500 6800 50  0001 C CNN
F 1 "GND" H 3505 6877 50  0000 C CNN
F 2 "" H 3500 7050 50  0001 C CNN
F 3 "" H 3500 7050 50  0001 C CNN
	1    3500 7050
	1    0    0    -1  
$EndComp
Connection ~ 3500 7050
Wire Wire Line
	3500 7050 3550 7050
$Comp
L power:+3.3V #PWR0104
U 1 1 5EDE7A4B
P 3400 4650
F 0 "#PWR0104" H 3400 4500 50  0001 C CNN
F 1 "+3.3V" H 3415 4823 50  0000 C CNN
F 2 "" H 3400 4650 50  0001 C CNN
F 3 "" H 3400 4650 50  0001 C CNN
	1    3400 4650
	1    0    0    -1  
$EndComp
Wire Wire Line
	3600 4650 3600 4700
Wire Wire Line
	3600 4700 3550 4700
Wire Wire Line
	3450 4700 3400 4700
Wire Wire Line
	3400 4700 3400 4650
$Comp
L Isolator:6N136 U6
U 1 1 5EDEE18C
P 5900 3000
F 0 "U6" H 5900 3425 50  0000 C CNN
F 1 "6N136" H 5900 3334 50  0000 C CNN
F 2 "Package_DIP:DIP-8_W7.62mm_Socket" H 5700 2700 50  0001 L CIN
F 3 "https://optoelectronics.liteon.com/upload/download/DS70-2008-0032/6N135-L%206N136-L%20series.pdf" H 5900 3000 50  0001 L CNN
	1    5900 3000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0105
U 1 1 5EDFCAA1
P 7850 3500
F 0 "#PWR0105" H 7850 3250 50  0001 C CNN
F 1 "GND" H 7855 3327 50  0000 C CNN
F 2 "" H 7850 3500 50  0001 C CNN
F 3 "" H 7850 3500 50  0001 C CNN
	1    7850 3500
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0108
U 1 1 5EDFD427
P 10150 3650
F 0 "#PWR0108" H 10150 3400 50  0001 C CNN
F 1 "GND" H 10155 3477 50  0000 C CNN
F 2 "" H 10150 3650 50  0001 C CNN
F 3 "" H 10150 3650 50  0001 C CNN
	1    10150 3650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0117
U 1 1 5EDFD67B
P 9850 3700
F 0 "#PWR0117" H 9850 3450 50  0001 C CNN
F 1 "GND" H 9855 3527 50  0000 C CNN
F 2 "" H 9850 3700 50  0001 C CNN
F 3 "" H 9850 3700 50  0001 C CNN
	1    9850 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	9850 3650 9850 3700
Wire Wire Line
	9750 3650 9850 3650
$Comp
L power:+12V #PWR0118
U 1 1 5EE06607
P 9050 2050
F 0 "#PWR0118" H 9050 1900 50  0001 C CNN
F 1 "+12V" H 9065 2223 50  0000 C CNN
F 2 "" H 9050 2050 50  0001 C CNN
F 3 "" H 9050 2050 50  0001 C CNN
	1    9050 2050
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR0119
U 1 1 5EE06FA7
P 9050 3650
F 0 "#PWR0119" H 9050 3500 50  0001 C CNN
F 1 "+12V" H 9065 3823 50  0000 C CNN
F 2 "" H 9050 3650 50  0001 C CNN
F 3 "" H 9050 3650 50  0001 C CNN
	1    9050 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	9050 3650 9150 3650
Wire Wire Line
	9050 2050 9150 2050
$Comp
L power:GND #PWR0120
U 1 1 5EE0BF8B
P 9850 2100
F 0 "#PWR0120" H 9850 1850 50  0001 C CNN
F 1 "GND" H 9855 1927 50  0000 C CNN
F 2 "" H 9850 2100 50  0001 C CNN
F 3 "" H 9850 2100 50  0001 C CNN
	1    9850 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	9850 2050 9850 2100
Wire Wire Line
	9850 2050 9750 2050
$Comp
L power:+5VL #PWR0121
U 1 1 5EE11387
P 7850 2400
F 0 "#PWR0121" H 7850 2250 50  0001 C CNN
F 1 "+5VL" H 7865 2573 50  0000 C CNN
F 2 "" H 7850 2400 50  0001 C CNN
F 3 "" H 7850 2400 50  0001 C CNN
	1    7850 2400
	1    0    0    -1  
$EndComp
$Comp
L power:+5VL #PWR0122
U 1 1 5EE11C0C
P 3850 2700
F 0 "#PWR0122" H 3850 2550 50  0001 C CNN
F 1 "+5VL" H 3865 2873 50  0000 C CNN
F 2 "" H 3850 2700 50  0001 C CNN
F 3 "" H 3850 2700 50  0001 C CNN
	1    3850 2700
	1    0    0    -1  
$EndComp
$Comp
L power:+5VD #PWR0123
U 1 1 5EE12407
P 3850 1050
F 0 "#PWR0123" H 3850 900 50  0001 C CNN
F 1 "+5VD" H 3865 1223 50  0000 C CNN
F 2 "" H 3850 1050 50  0001 C CNN
F 3 "" H 3850 1050 50  0001 C CNN
	1    3850 1050
	1    0    0    -1  
$EndComp
Wire Wire Line
	3850 1050 3850 1100
Wire Wire Line
	3850 1100 3700 1100
Wire Wire Line
	3850 2700 3850 2750
Wire Wire Line
	3850 2750 3700 2750
$Comp
L power:GND #PWR0124
U 1 1 5EE1F2AA
P 3850 3200
F 0 "#PWR0124" H 3850 2950 50  0001 C CNN
F 1 "GND" H 3855 3027 50  0000 C CNN
F 2 "" H 3850 3200 50  0001 C CNN
F 3 "" H 3850 3200 50  0001 C CNN
	1    3850 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	3700 3150 3850 3150
Wire Wire Line
	3850 3150 3850 3200
$Comp
L power:GNDD #PWR0125
U 1 1 5EE221FE
P 3850 1550
F 0 "#PWR0125" H 3850 1300 50  0001 C CNN
F 1 "GNDD" H 3854 1395 50  0000 C CNN
F 2 "" H 3850 1550 50  0001 C CNN
F 3 "" H 3850 1550 50  0001 C CNN
	1    3850 1550
	1    0    0    -1  
$EndComp
Wire Wire Line
	3700 1500 3850 1500
Wire Wire Line
	3850 1500 3850 1550
$Comp
L power:GND #PWR0126
U 1 1 5EE25444
P 2550 3200
F 0 "#PWR0126" H 2550 2950 50  0001 C CNN
F 1 "GND" H 2555 3027 50  0000 C CNN
F 2 "" H 2550 3200 50  0001 C CNN
F 3 "" H 2550 3200 50  0001 C CNN
	1    2550 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	2550 3200 2550 3150
Wire Wire Line
	2550 3150 2700 3150
$Comp
L power:+5V #PWR0127
U 1 1 5EE285BA
P 2550 2700
F 0 "#PWR0127" H 2550 2550 50  0001 C CNN
F 1 "+5V" H 2565 2873 50  0000 C CNN
F 2 "" H 2550 2700 50  0001 C CNN
F 3 "" H 2550 2700 50  0001 C CNN
	1    2550 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	2550 2750 2550 2700
Wire Wire Line
	2550 2750 2700 2750
$Comp
L power:+5V #PWR0128
U 1 1 5EE2EA21
P 2550 1050
F 0 "#PWR0128" H 2550 900 50  0001 C CNN
F 1 "+5V" H 2565 1223 50  0000 C CNN
F 2 "" H 2550 1050 50  0001 C CNN
F 3 "" H 2550 1050 50  0001 C CNN
	1    2550 1050
	1    0    0    -1  
$EndComp
Wire Wire Line
	2550 1050 2550 1100
Wire Wire Line
	2550 1100 2700 1100
$Comp
L power:GND #PWR0129
U 1 1 5EE3271E
P 2550 1550
F 0 "#PWR0129" H 2550 1300 50  0001 C CNN
F 1 "GND" H 2555 1377 50  0000 C CNN
F 2 "" H 2550 1550 50  0001 C CNN
F 3 "" H 2550 1550 50  0001 C CNN
	1    2550 1550
	1    0    0    -1  
$EndComp
Wire Wire Line
	2550 1550 2550 1500
Wire Wire Line
	2550 1500 2700 1500
Wire Wire Line
	8450 2800 8450 2750
Connection ~ 8450 2750
Wire Wire Line
	8450 2750 8250 2750
Wire Wire Line
	8450 3100 8450 3150
Connection ~ 8450 3150
Wire Wire Line
	8450 3150 8250 3150
$Comp
L Device:R R3
U 1 1 5EE3EAAF
P 8450 1350
F 0 "R3" H 8520 1396 50  0000 L CNN
F 1 "120R" H 8520 1305 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 8380 1350 50  0001 C CNN
F 3 "~" H 8450 1350 50  0001 C CNN
	1    8450 1350
	1    0    0    -1  
$EndComp
Wire Wire Line
	8450 1500 8450 1550
Wire Wire Line
	8450 1550 8250 1550
Wire Wire Line
	8450 1200 8450 1150
Wire Wire Line
	8450 1150 8250 1150
$Comp
L Device:R R6
U 1 1 5EE37A94
P 8450 2950
F 0 "R6" H 8520 2996 50  0000 L CNN
F 1 "120R" H 8520 2905 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 8380 2950 50  0001 C CNN
F 3 "~" H 8450 2950 50  0001 C CNN
	1    8450 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	7450 2900 7400 2900
Wire Wire Line
	7400 2900 7400 2950
Wire Wire Line
	7400 3000 7450 3000
Wire Wire Line
	7450 1300 7400 1300
Wire Wire Line
	7400 1300 7400 1350
Wire Wire Line
	7400 1400 7450 1400
$Comp
L Device:R R4
U 1 1 5EE4FC45
P 7050 2800
F 0 "R4" H 7120 2846 50  0000 L CNN
F 1 "4.7k" H 7120 2755 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 6980 2800 50  0001 C CNN
F 3 "~" H 7050 2800 50  0001 C CNN
	1    7050 2800
	1    0    0    -1  
$EndComp
$Comp
L power:+5VL #PWR0130
U 1 1 5EE50344
P 7050 2650
F 0 "#PWR0130" H 7050 2500 50  0001 C CNN
F 1 "+5VL" H 7065 2823 50  0000 C CNN
F 2 "" H 7050 2650 50  0001 C CNN
F 3 "" H 7050 2650 50  0001 C CNN
	1    7050 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	7050 2950 7400 2950
Connection ~ 7400 2950
Wire Wire Line
	7400 2950 7400 3000
$Comp
L power:GND #PWR0131
U 1 1 5EE5530D
P 6300 3200
F 0 "#PWR0131" H 6300 2950 50  0001 C CNN
F 1 "GND" H 6305 3027 50  0000 C CNN
F 2 "" H 6300 3200 50  0001 C CNN
F 3 "" H 6300 3200 50  0001 C CNN
	1    6300 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	6200 3200 6300 3200
Wire Wire Line
	6200 3100 6650 3100
NoConn ~ 6200 2900
$Comp
L power:+5VL #PWR0132
U 1 1 5EE66583
P 6300 2750
F 0 "#PWR0132" H 6300 2600 50  0001 C CNN
F 1 "+5VL" H 6315 2923 50  0000 C CNN
F 2 "" H 6300 2750 50  0001 C CNN
F 3 "" H 6300 2750 50  0001 C CNN
	1    6300 2750
	1    0    0    -1  
$EndComp
Wire Wire Line
	6300 2750 6300 2800
Wire Wire Line
	6300 2800 6200 2800
$Comp
L Device:R R5
U 1 1 5EE75D3F
P 6650 2950
F 0 "R5" H 6720 2996 50  0000 L CNN
F 1 "4.7k" H 6720 2905 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 6580 2950 50  0001 C CNN
F 3 "~" H 6650 2950 50  0001 C CNN
	1    6650 2950
	1    0    0    -1  
$EndComp
Connection ~ 6650 3100
Wire Wire Line
	6650 3100 7450 3100
Wire Wire Line
	6300 2800 6650 2800
Connection ~ 6300 2800
$Comp
L power:+5V #PWR0133
U 1 1 5EE7A998
P 5500 2850
F 0 "#PWR0133" H 5500 2700 50  0001 C CNN
F 1 "+5V" H 5515 3023 50  0000 C CNN
F 2 "" H 5500 2850 50  0001 C CNN
F 3 "" H 5500 2850 50  0001 C CNN
	1    5500 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	5500 2850 5500 2900
Wire Wire Line
	5500 2900 5600 2900
$Comp
L Device:R R7
U 1 1 5EE7FF0B
P 5200 3100
F 0 "R7" V 5400 3050 50  0000 L CNN
F 1 "470R" V 5300 3000 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 5130 3100 50  0001 C CNN
F 3 "~" H 5200 3100 50  0001 C CNN
	1    5200 3100
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5350 3100 5600 3100
Text Label 4600 3100 0    50   ~ 0
DMX_TX
Wire Wire Line
	4600 3100 5050 3100
NoConn ~ 5750 1400
$Comp
L power:GNDD #PWR0134
U 1 1 5ED0C11D
P 7200 1450
F 0 "#PWR0134" H 7200 1200 50  0001 C CNN
F 1 "GNDD" H 7204 1295 50  0000 C CNN
F 2 "" H 7200 1450 50  0001 C CNN
F 3 "" H 7200 1450 50  0001 C CNN
	1    7200 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	7200 1450 7200 1350
Wire Wire Line
	7200 1350 7400 1350
Connection ~ 7400 1350
Wire Wire Line
	7400 1350 7400 1400
$Comp
L Device:R R1
U 1 1 5ED11E49
P 7050 1200
F 0 "R1" V 7250 1150 50  0000 L CNN
F 1 "470R" V 7150 1100 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 6980 1200 50  0001 C CNN
F 3 "~" H 7050 1200 50  0001 C CNN
	1    7050 1200
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7200 1200 7450 1200
$Comp
L power:+5VD #PWR0135
U 1 1 5ED1D092
P 6600 1600
F 0 "#PWR0135" H 6600 1450 50  0001 C CNN
F 1 "+5VD" H 6615 1773 50  0000 C CNN
F 2 "" H 6600 1600 50  0001 C CNN
F 3 "" H 6600 1600 50  0001 C CNN
	1    6600 1600
	1    0    0    -1  
$EndComp
Wire Wire Line
	6350 1400 6350 1600
Wire Wire Line
	6350 1600 6600 1600
Wire Wire Line
	6350 1200 6900 1200
Wire Wire Line
	5500 900  5750 900 
Wire Wire Line
	5750 900  5750 1100
$Comp
L power:GND #PWR0136
U 1 1 5ED42044
P 5500 900
F 0 "#PWR0136" H 5500 650 50  0001 C CNN
F 1 "GND" H 5505 727 50  0000 C CNN
F 2 "" H 5500 900 50  0001 C CNN
F 3 "" H 5500 900 50  0001 C CNN
	1    5500 900 
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 5ED4239C
P 5200 1350
F 0 "R2" H 5270 1396 50  0000 L CNN
F 1 "4.7k" H 5270 1305 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 5130 1350 50  0001 C CNN
F 3 "~" H 5200 1350 50  0001 C CNN
	1    5200 1350
	1    0    0    -1  
$EndComp
Wire Wire Line
	5750 1200 5200 1200
Connection ~ 5200 1200
Wire Wire Line
	5200 1200 4600 1200
Text Label 4600 1200 0    50   ~ 0
DMX_RX
$Comp
L power:+5V #PWR0137
U 1 1 5ED4E51A
P 4950 1500
F 0 "#PWR0137" H 4950 1350 50  0001 C CNN
F 1 "+5V" H 4965 1673 50  0000 C CNN
F 2 "" H 4950 1500 50  0001 C CNN
F 3 "" H 4950 1500 50  0001 C CNN
	1    4950 1500
	1    0    0    -1  
$EndComp
Wire Wire Line
	4950 1500 5200 1500
Connection ~ 5200 1500
Wire Wire Line
	5200 1500 5750 1500
$Comp
L Device:CP C3
U 1 1 5ED5C732
P 4600 6950
F 0 "C3" H 4718 6996 50  0000 L CNN
F 1 "10uF" H 4718 6905 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D6.3mm_P2.50mm" H 4638 6800 50  0001 C CNN
F 3 "~" H 4600 6950 50  0001 C CNN
	1    4600 6950
	1    0    0    -1  
$EndComp
Wire Wire Line
	4400 6750 4600 6750
Wire Wire Line
	4600 6750 4600 6800
$Comp
L power:GND #PWR0138
U 1 1 5ED632E5
P 4600 7100
F 0 "#PWR0138" H 4600 6850 50  0001 C CNN
F 1 "GND" H 4605 6927 50  0000 C CNN
F 2 "" H 4600 7100 50  0001 C CNN
F 3 "" H 4600 7100 50  0001 C CNN
	1    4600 7100
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1
U 1 1 5ED64676
P 3850 1300
F 0 "C1" H 3965 1346 50  0000 L CNN
F 1 "470nF" H 3965 1255 50  0000 L CNN
F 2 "Capacitor_THT:C_Rect_L7.2mm_W5.5mm_P5.00mm_FKS2_FKP2_MKS2_MKP2" H 3888 1150 50  0001 C CNN
F 3 "~" H 3850 1300 50  0001 C CNN
	1    3850 1300
	1    0    0    -1  
$EndComp
Wire Wire Line
	3850 1100 3850 1150
Connection ~ 3850 1100
Wire Wire Line
	3850 1450 3850 1500
Connection ~ 3850 1500
$Comp
L Device:C C2
U 1 1 5ED71343
P 3850 2950
F 0 "C2" H 3965 2996 50  0000 L CNN
F 1 "470nF" H 3965 2905 50  0000 L CNN
F 2 "Capacitor_THT:C_Rect_L7.2mm_W5.5mm_P5.00mm_FKS2_FKP2_MKS2_MKP2" H 3888 2800 50  0001 C CNN
F 3 "~" H 3850 2950 50  0001 C CNN
	1    3850 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	3850 2800 3850 2750
Connection ~ 3850 2750
Wire Wire Line
	3850 3100 3850 3150
Connection ~ 3850 3150
Text Label 4450 5000 0    50   ~ 0
BUTTON_1
Text Label 4450 5100 0    50   ~ 0
BUTTON_2
Text Label 4450 5200 0    50   ~ 0
BUTTON_4
Text Label 4450 5300 0    50   ~ 0
LED_1
Text Label 4450 5400 0    50   ~ 0
LED_2
Text Label 4450 5500 0    50   ~ 0
LED_4
$Comp
L power:+3.3V #PWR0139
U 1 1 5EDA6188
P 1800 6550
F 0 "#PWR0139" H 1800 6400 50  0001 C CNN
F 1 "+3.3V" H 1815 6723 50  0000 C CNN
F 2 "" H 1800 6550 50  0001 C CNN
F 3 "" H 1800 6550 50  0001 C CNN
	1    1800 6550
	1    0    0    -1  
$EndComp
Wire Wire Line
	1800 6550 1300 6550
$Comp
L power:GND #PWR0140
U 1 1 5EDAD547
P 1800 6650
F 0 "#PWR0140" H 1800 6400 50  0001 C CNN
F 1 "GND" H 1805 6477 50  0000 C CNN
F 2 "" H 1800 6650 50  0001 C CNN
F 3 "" H 1800 6650 50  0001 C CNN
	1    1800 6650
	1    0    0    -1  
$EndComp
Wire Wire Line
	1300 6650 1800 6650
Text Label 1500 6250 0    50   ~ 0
CS_D3
Text Label 1500 6150 0    50   ~ 0
CLK
Text Label 1500 6050 0    50   ~ 0
MOSI_CMD
Text Label 1500 5950 0    50   ~ 0
MISO_D0
Wire Wire Line
	1300 6250 2600 6250
Wire Wire Line
	1300 6150 2600 6150
Wire Wire Line
	1300 5950 2600 5950
Wire Wire Line
	1800 6550 2050 6550
Connection ~ 1800 6550
$Comp
L Device:R R8
U 1 1 5EDF8C69
P 2200 6550
F 0 "R8" V 1993 6550 50  0000 C CNN
F 1 "10k" V 2084 6550 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 2130 6550 50  0001 C CNN
F 3 "~" H 2200 6550 50  0001 C CNN
	1    2200 6550
	0    1    1    0   
$EndComp
$Comp
L Connector:Conn_01x04_Male J7
U 1 1 5EE11611
P 1100 6050
F 0 "J7" H 1200 6350 50  0000 C CNN
F 1 "SD_Card_Connector_1" H 1200 6250 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:Molex_KK254_1x04Vertical" H 1100 6050 50  0001 C CNN
F 3 "~" H 1100 6050 50  0001 C CNN
	1    1100 6050
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x04_Male J9
U 1 1 5EE11EF6
P 1100 6650
F 0 "J9" H 1200 6950 50  0000 C CNN
F 1 "SD_Card_Connector_2" H 1200 6850 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:Molex_KK254_1x04Vertical" H 1100 6650 50  0001 C CNN
F 3 "~" H 1100 6650 50  0001 C CNN
	1    1100 6650
	1    0    0    -1  
$EndComp
Wire Wire Line
	1300 6050 2400 6050
Connection ~ 2400 6050
Wire Wire Line
	2400 6050 2600 6050
Wire Wire Line
	2350 6550 2400 6550
Wire Wire Line
	2400 6050 2400 6550
NoConn ~ 1300 6750
NoConn ~ 1300 6850
$Comp
L Connector:Conn_01x04_Female J1
U 1 1 5EE67DEA
P 10500 1750
F 0 "J1" H 10528 1726 50  0000 L CNN
F 1 "DMX_In_Connector" H 10528 1635 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:Krone_4_Way_terminal" H 10500 1750 50  0001 C CNN
F 3 "~" H 10500 1750 50  0001 C CNN
	1    10500 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	10300 1850 10250 1850
Wire Wire Line
	10250 1850 10250 1950
Wire Wire Line
	10300 1950 10250 1950
Connection ~ 10250 1950
Wire Wire Line
	10250 1950 10250 2050
Wire Wire Line
	10300 1750 9950 1750
$Comp
L Connector:Conn_01x04_Female J2
U 1 1 5EEB468D
P 10450 3350
F 0 "J2" H 10478 3326 50  0000 L CNN
F 1 "DMX_Out_Connector" H 10478 3235 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:Krone_4_Way_terminal" H 10450 3350 50  0001 C CNN
F 3 "~" H 10450 3350 50  0001 C CNN
	1    10450 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	10150 3650 10150 3550
Wire Wire Line
	10150 3450 10250 3450
Wire Wire Line
	10250 3550 10150 3550
Connection ~ 10150 3550
Wire Wire Line
	10150 3550 10150 3450
Wire Wire Line
	10250 3350 9950 3350
Wire Wire Line
	9950 3350 9950 2850
Wire Wire Line
	9750 3250 10250 3250
Wire Wire Line
	9950 1650 9950 1750
Wire Wire Line
	9750 1250 10100 1250
Wire Wire Line
	10100 1250 10100 1650
Wire Wire Line
	10100 1650 10300 1650
Wire Wire Line
	8900 2950 8900 1750
Wire Wire Line
	8900 1750 9150 1750
Wire Wire Line
	8800 1350 9150 1350
Wire Wire Line
	8800 1350 8800 3350
Wire Wire Line
	8450 1150 9000 1150
Wire Wire Line
	9000 1150 9000 1550
Wire Wire Line
	9000 1550 9150 1550
Connection ~ 8450 1150
Wire Wire Line
	9150 1150 9100 1150
Wire Wire Line
	9100 1150 9100 1300
Wire Wire Line
	9100 1300 8750 1300
Wire Wire Line
	8750 1300 8750 1550
Wire Wire Line
	8750 1550 8450 1550
Connection ~ 8450 1550
$EndSCHEMATC
