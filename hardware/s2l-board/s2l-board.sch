EESchema Schematic File Version 4
LIBS:s2l-board-cache
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
L Amplifier_Operational:LM741 U1
U 1 1 5EC4654D
P 3100 1300
F 0 "U1" H 3350 1200 50  0000 L CNN
F 1 "LM741" H 3350 1100 50  0000 L CNN
F 2 "Package_DIP:DIP-8_W7.62mm_Socket" H 3150 1350 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm741.pdf" H 3250 1450 50  0001 C CNN
	1    3100 1300
	1    0    0    -1  
$EndComp
NoConn ~ 3100 1600
NoConn ~ 3200 1600
$Comp
L power:+15V #PWR0101
U 1 1 5EC470F4
P 3000 1000
F 0 "#PWR0101" H 3000 850 50  0001 C CNN
F 1 "+15V" H 3015 1173 50  0000 C CNN
F 2 "" H 3000 1000 50  0001 C CNN
F 3 "" H 3000 1000 50  0001 C CNN
	1    3000 1000
	1    0    0    -1  
$EndComp
$Comp
L power:-15V #PWR0102
U 1 1 5EC478E0
P 3000 1600
F 0 "#PWR0102" H 3000 1700 50  0001 C CNN
F 1 "-15V" H 3015 1773 50  0000 C CNN
F 2 "" H 3000 1600 50  0001 C CNN
F 3 "" H 3000 1600 50  0001 C CNN
	1    3000 1600
	-1   0    0    1   
$EndComp
$Comp
L Device:C C1
U 1 1 5EC49670
P 3150 1000
F 0 "C1" V 3300 800 50  0000 C CNN
F 1 "100nF" V 3200 800 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D5.0mm_W2.5mm_P5.00mm" H 3188 850 50  0001 C CNN
F 3 "~" H 3150 1000 50  0001 C CNN
	1    3150 1000
	0    -1   -1   0   
$EndComp
Connection ~ 3000 1000
Wire Wire Line
	3000 1600 3050 1600
Wire Wire Line
	3050 1600 3050 1550
Wire Wire Line
	3050 1550 3300 1550
Wire Wire Line
	3300 1550 3300 1000
Connection ~ 3000 1600
$Comp
L Device:C C3
U 1 1 5EC4C4A5
P 2200 1300
F 0 "C3" H 2315 1346 50  0000 L CNN
F 1 "220pF" H 2315 1255 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D3.0mm_W2.0mm_P2.50mm" H 2238 1150 50  0001 C CNN
F 3 "~" H 2200 1300 50  0001 C CNN
	1    2200 1300
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 5EC4E27A
P 2350 1150
F 0 "R2" V 2143 1150 50  0000 C CNN
F 1 "6.8k" V 2234 1150 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 2280 1150 50  0001 C CNN
F 3 "~" H 2350 1150 50  0001 C CNN
	1    2350 1150
	0    1    1    0   
$EndComp
$Comp
L Device:R R1
U 1 1 5EC4ED68
P 2050 1150
F 0 "R1" V 1843 1150 50  0000 C CNN
F 1 "10k" V 1934 1150 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 1980 1150 50  0001 C CNN
F 3 "~" H 2050 1150 50  0001 C CNN
	1    2050 1150
	0    1    1    0   
$EndComp
Connection ~ 2200 1150
$Comp
L Device:R R3
U 1 1 5EC4F077
P 1900 1300
F 0 "R3" H 1970 1346 50  0000 L CNN
F 1 "3.3k" H 1970 1255 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 1830 1300 50  0001 C CNN
F 3 "~" H 1900 1300 50  0001 C CNN
	1    1900 1300
	1    0    0    -1  
$EndComp
$Comp
L Device:R R8
U 1 1 5EC4F7EE
P 2050 1450
F 0 "R8" V 1950 1450 50  0000 C CNN
F 1 "10k" V 1850 1450 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 1980 1450 50  0001 C CNN
F 3 "~" H 2050 1450 50  0001 C CNN
	1    2050 1450
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R9
U 1 1 5EC5008C
P 2350 1450
F 0 "R9" V 2250 1450 50  0000 C CNN
F 1 "6.8k" V 2150 1450 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 2280 1450 50  0001 C CNN
F 3 "~" H 2350 1450 50  0001 C CNN
	1    2350 1450
	0    -1   -1   0   
$EndComp
Connection ~ 2200 1450
$Comp
L Device:R R12
U 1 1 5EC51F7E
P 3400 1900
F 0 "R12" V 3193 1900 50  0000 C CNN
F 1 "10k" V 3284 1900 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 3330 1900 50  0001 C CNN
F 3 "~" H 3400 1900 50  0001 C CNN
	1    3400 1900
	0    1    1    0   
$EndComp
Wire Wire Line
	2500 1150 2600 1150
Wire Wire Line
	2800 1150 2800 1200
Wire Wire Line
	2800 1400 2800 1450
Wire Wire Line
	2800 1450 2500 1450
Wire Wire Line
	2800 1450 2800 1900
Wire Wire Line
	2800 1900 3250 1900
Connection ~ 2800 1450
$Comp
L Device:R R11
U 1 1 5EC540A4
P 2600 1750
F 0 "R11" H 2670 1796 50  0000 L CNN
F 1 "10k" H 2670 1705 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 2530 1750 50  0001 C CNN
F 3 "~" H 2600 1750 50  0001 C CNN
	1    2600 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	2600 1600 2600 1150
Connection ~ 2600 1150
Wire Wire Line
	2600 1150 2800 1150
Wire Wire Line
	2600 1900 2600 2050
$Comp
L power:GNDA #PWR0103
U 1 1 5EC55226
P 2600 2050
F 0 "#PWR0103" H 2600 1800 50  0001 C CNN
F 1 "GNDA" H 2605 1877 50  0000 C CNN
F 2 "" H 2600 2050 50  0001 C CNN
F 3 "" H 2600 2050 50  0001 C CNN
	1    2600 2050
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x04_Male J1
U 1 1 5EC559E4
P 900 1250
F 0 "J1" H 1000 1600 50  0000 C CNN
F 1 "To XLR3-M input" H 1000 1500 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:Molex_KK254_1x04Vertical" H 900 1250 50  0001 C CNN
F 3 "~" H 900 1250 50  0001 C CNN
	1    900  1250
	1    0    0    -1  
$EndComp
Wire Wire Line
	1900 1150 1600 1150
Wire Wire Line
	1600 1150 1600 1250
Wire Wire Line
	1600 1250 1100 1250
Connection ~ 1900 1150
Wire Wire Line
	1600 1350 1600 1450
Wire Wire Line
	1600 1450 1900 1450
Connection ~ 1900 1450
Wire Wire Line
	1100 1350 1600 1350
Wire Wire Line
	1100 1150 1400 1150
Wire Wire Line
	1400 1150 1400 1500
$Comp
L power:GNDA #PWR0104
U 1 1 5EC57A06
P 1400 1500
F 0 "#PWR0104" H 1400 1250 50  0001 C CNN
F 1 "GNDA" H 1405 1327 50  0000 C CNN
F 2 "" H 1400 1500 50  0001 C CNN
F 3 "" H 1400 1500 50  0001 C CNN
	1    1400 1500
	1    0    0    -1  
$EndComp
NoConn ~ 1100 1450
$Comp
L Device:R R4
U 1 1 5EC582B8
P 3900 1300
F 0 "R4" V 3693 1300 50  0000 C CNN
F 1 "100R" V 3784 1300 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 3830 1300 50  0001 C CNN
F 3 "~" H 3900 1300 50  0001 C CNN
	1    3900 1300
	0    1    1    0   
$EndComp
Wire Wire Line
	3400 1300 3650 1300
Wire Wire Line
	3550 1900 3650 1900
Wire Wire Line
	3650 1900 3650 1300
Connection ~ 3650 1300
Wire Wire Line
	3650 1300 3750 1300
$Comp
L Amplifier_Operational:LM741 U2
U 1 1 5EC5E339
P 6250 1400
F 0 "U2" H 6500 1300 50  0000 L CNN
F 1 "LM741" H 6500 1200 50  0000 L CNN
F 2 "Package_DIP:DIP-8_W7.62mm_Socket" H 6300 1450 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm741.pdf" H 6400 1550 50  0001 C CNN
	1    6250 1400
	1    0    0    -1  
$EndComp
NoConn ~ 6250 1700
NoConn ~ 6350 1700
$Comp
L Device:C C5
U 1 1 5EC612DC
P 5500 1700
F 0 "C5" H 5615 1746 50  0000 L CNN
F 1 "10nF" H 5615 1655 50  0000 L CNN
F 2 "Capacitor_THT:C_Rect_L7.0mm_W2.5mm_P5.00mm" H 5538 1550 50  0001 C CNN
F 3 "~" H 5500 1700 50  0001 C CNN
	1    5500 1700
	1    0    0    -1  
$EndComp
$Comp
L Device:R R6
U 1 1 5EC625F1
P 5350 1300
F 0 "R6" V 5143 1300 50  0000 C CNN
F 1 "100k" V 5234 1300 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 5280 1300 50  0001 C CNN
F 3 "~" H 5350 1300 50  0001 C CNN
	1    5350 1300
	0    1    1    0   
$EndComp
$Comp
L Device:R R5
U 1 1 5EC62D53
P 4950 1300
F 0 "R5" V 4743 1300 50  0000 C CNN
F 1 "100k" V 4834 1300 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 4880 1300 50  0001 C CNN
F 3 "~" H 4950 1300 50  0001 C CNN
	1    4950 1300
	0    1    1    0   
$EndComp
Wire Wire Line
	5500 1300 5500 1550
Wire Wire Line
	5500 1300 5950 1300
Connection ~ 5500 1300
$Comp
L power:GNDA #PWR0105
U 1 1 5EC64199
P 5500 1850
F 0 "#PWR0105" H 5500 1600 50  0001 C CNN
F 1 "GNDA" H 5505 1677 50  0000 C CNN
F 2 "" H 5500 1850 50  0001 C CNN
F 3 "" H 5500 1850 50  0001 C CNN
	1    5500 1850
	1    0    0    -1  
$EndComp
$Comp
L power:+15V #PWR0106
U 1 1 5EC6475B
P 6150 1100
F 0 "#PWR0106" H 6150 950 50  0001 C CNN
F 1 "+15V" H 6165 1273 50  0000 C CNN
F 2 "" H 6150 1100 50  0001 C CNN
F 3 "" H 6150 1100 50  0001 C CNN
	1    6150 1100
	1    0    0    -1  
$EndComp
$Comp
L power:-15V #PWR0107
U 1 1 5EC64EDC
P 6150 1700
F 0 "#PWR0107" H 6150 1800 50  0001 C CNN
F 1 "-15V" H 6165 1873 50  0000 C CNN
F 2 "" H 6150 1700 50  0001 C CNN
F 3 "" H 6150 1700 50  0001 C CNN
	1    6150 1700
	-1   0    0    1   
$EndComp
$Comp
L Device:C C2
U 1 1 5EC661AD
P 6300 1100
F 0 "C2" V 6450 900 50  0000 C CNN
F 1 "100nF" V 6350 900 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D5.0mm_W2.5mm_P5.00mm" H 6338 950 50  0001 C CNN
F 3 "~" H 6300 1100 50  0001 C CNN
	1    6300 1100
	0    -1   -1   0   
$EndComp
Connection ~ 6150 1100
Wire Wire Line
	6450 1100 6450 1650
Wire Wire Line
	6450 1650 6200 1650
Wire Wire Line
	6200 1650 6200 1700
Wire Wire Line
	6200 1700 6150 1700
Connection ~ 6150 1700
$Comp
L Device:C C6
U 1 1 5EC673FD
P 5800 2150
F 0 "C6" V 6052 2150 50  0000 C CNN
F 1 "20nF" V 5961 2150 50  0000 C CNN
F 2 "Capacitor_THT:C_Rect_L7.2mm_W2.5mm_P5.00mm_FKS2_FKP2_MKS2_MKP2" H 5838 2000 50  0001 C CNN
F 3 "~" H 5800 2150 50  0001 C CNN
	1    5800 2150
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5200 1300 5150 1300
Wire Wire Line
	5650 2150 5150 2150
Wire Wire Line
	5150 2150 5150 1300
Connection ~ 5150 1300
Wire Wire Line
	5150 1300 5100 1300
Wire Wire Line
	5950 1500 5950 2150
Wire Wire Line
	5950 2150 6800 2150
Wire Wire Line
	6800 2150 6800 1400
Wire Wire Line
	6800 1400 6550 1400
Connection ~ 5950 2150
$Comp
L Device:D D1
U 1 1 5EC6BC1F
P 6950 1400
F 0 "D1" H 6950 1184 50  0000 C CNN
F 1 "1N4148" H 6950 1275 50  0000 C CNN
F 2 "Diode_THT:D_DO-35_SOD27_P7.62mm_Horizontal" H 6950 1400 50  0001 C CNN
F 3 "~" H 6950 1400 50  0001 C CNN
	1    6950 1400
	-1   0    0    1   
$EndComp
Connection ~ 6800 1400
$Comp
L Device:CP C4
U 1 1 5EC6CBCF
P 7200 1650
F 0 "C4" H 7318 1696 50  0000 L CNN
F 1 "47uF" H 7318 1605 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D4.0mm_P1.50mm" H 7238 1500 50  0001 C CNN
F 3 "~" H 7200 1650 50  0001 C CNN
	1    7200 1650
	1    0    0    -1  
$EndComp
$Comp
L Device:R R10
U 1 1 5EC6D436
P 7600 1650
F 0 "R10" H 7530 1604 50  0000 R CNN
F 1 "2.2k" H 7530 1695 50  0000 R CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 7530 1650 50  0001 C CNN
F 3 "~" H 7600 1650 50  0001 C CNN
	1    7600 1650
	-1   0    0    1   
$EndComp
Wire Wire Line
	7200 1500 7400 1500
Wire Wire Line
	7100 1400 7400 1400
Wire Wire Line
	7400 1400 7400 1500
Connection ~ 7400 1500
Wire Wire Line
	7400 1500 7600 1500
Wire Wire Line
	7200 1800 7400 1800
$Comp
L power:GNDA #PWR0108
U 1 1 5EC6FCCB
P 7400 1800
F 0 "#PWR0108" H 7400 1550 50  0001 C CNN
F 1 "GNDA" H 7405 1627 50  0000 C CNN
F 2 "" H 7400 1800 50  0001 C CNN
F 3 "" H 7400 1800 50  0001 C CNN
	1    7400 1800
	1    0    0    -1  
$EndComp
Connection ~ 7400 1800
Wire Wire Line
	7400 1800 7600 1800
$Comp
L Device:R R7
U 1 1 5EC7007A
P 8000 1400
F 0 "R7" V 7793 1400 50  0000 C CNN
F 1 "1k" V 7884 1400 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 7930 1400 50  0001 C CNN
F 3 "~" H 8000 1400 50  0001 C CNN
	1    8000 1400
	0    1    1    0   
$EndComp
Wire Wire Line
	7400 1400 7850 1400
Connection ~ 7400 1400
$Comp
L Device:D_Zener D2
U 1 1 5EC71667
P 8250 1650
F 0 "D2" V 8204 1729 50  0000 L CNN
F 1 "D_Zener" V 8295 1729 50  0000 L CNN
F 2 "Diode_THT:D_DO-35_SOD27_P7.62mm_Horizontal" H 8250 1650 50  0001 C CNN
F 3 "~" H 8250 1650 50  0001 C CNN
	1    8250 1650
	0    1    1    0   
$EndComp
Wire Wire Line
	8150 1400 8250 1400
Wire Wire Line
	8250 1400 8250 1500
$Comp
L power:GNDA #PWR0109
U 1 1 5EC74695
P 8250 1800
F 0 "#PWR0109" H 8250 1550 50  0001 C CNN
F 1 "GNDA" H 8255 1627 50  0000 C CNN
F 2 "" H 8250 1800 50  0001 C CNN
F 3 "" H 8250 1800 50  0001 C CNN
	1    8250 1800
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:LM741 U3
U 1 1 5EC84581
P 6250 2800
F 0 "U3" H 6500 2700 50  0000 L CNN
F 1 "LM741" H 6500 2600 50  0000 L CNN
F 2 "Package_DIP:DIP-8_W7.62mm_Socket" H 6300 2850 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm741.pdf" H 6400 2950 50  0001 C CNN
	1    6250 2800
	1    0    0    -1  
$EndComp
NoConn ~ 6250 3100
NoConn ~ 6350 3100
$Comp
L Device:C C9
U 1 1 5EC84589
P 5400 3350
F 0 "C9" V 5148 3350 50  0000 C CNN
F 1 "100nF" V 5239 3350 50  0000 C CNN
F 2 "Capacitor_THT:C_Rect_L7.2mm_W4.5mm_P5.00mm_FKS2_FKP2_MKS2_MKP2" H 5438 3200 50  0001 C CNN
F 3 "~" H 5400 3350 50  0001 C CNN
	1    5400 3350
	0    1    1    0   
$EndComp
$Comp
L Device:R R14
U 1 1 5EC8458F
P 5350 2700
F 0 "R14" V 5143 2700 50  0000 C CNN
F 1 "1k" V 5234 2700 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 5280 2700 50  0001 C CNN
F 3 "~" H 5350 2700 50  0001 C CNN
	1    5350 2700
	0    1    1    0   
$EndComp
$Comp
L Device:R R13
U 1 1 5EC84595
P 4950 2700
F 0 "R13" V 4743 2700 50  0000 C CNN
F 1 "22k" V 4834 2700 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 4880 2700 50  0001 C CNN
F 3 "~" H 4950 2700 50  0001 C CNN
	1    4950 2700
	0    1    1    0   
$EndComp
$Comp
L power:GNDA #PWR0110
U 1 1 5EC8459E
P 5800 2800
F 0 "#PWR0110" H 5800 2550 50  0001 C CNN
F 1 "GNDA" H 5805 2627 50  0000 C CNN
F 2 "" H 5800 2800 50  0001 C CNN
F 3 "" H 5800 2800 50  0001 C CNN
	1    5800 2800
	1    0    0    -1  
$EndComp
$Comp
L power:+15V #PWR0111
U 1 1 5EC845A4
P 6150 2500
F 0 "#PWR0111" H 6150 2350 50  0001 C CNN
F 1 "+15V" H 6165 2673 50  0000 C CNN
F 2 "" H 6150 2500 50  0001 C CNN
F 3 "" H 6150 2500 50  0001 C CNN
	1    6150 2500
	1    0    0    -1  
$EndComp
$Comp
L power:-15V #PWR0112
U 1 1 5EC845AA
P 6150 3100
F 0 "#PWR0112" H 6150 3200 50  0001 C CNN
F 1 "-15V" H 6165 3273 50  0000 C CNN
F 2 "" H 6150 3100 50  0001 C CNN
F 3 "" H 6150 3100 50  0001 C CNN
	1    6150 3100
	-1   0    0    1   
$EndComp
$Comp
L Device:C C7
U 1 1 5EC845B0
P 6300 2500
F 0 "C7" V 6450 2300 50  0000 C CNN
F 1 "100nF" V 6350 2300 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D5.0mm_W2.5mm_P5.00mm" H 6338 2350 50  0001 C CNN
F 3 "~" H 6300 2500 50  0001 C CNN
	1    6300 2500
	0    -1   -1   0   
$EndComp
Connection ~ 6150 2500
Wire Wire Line
	6450 2500 6450 3050
Wire Wire Line
	6450 3050 6200 3050
Wire Wire Line
	6200 3050 6200 3100
Wire Wire Line
	6200 3100 6150 3100
Connection ~ 6150 3100
$Comp
L Device:C C10
U 1 1 5EC845BC
P 5750 3550
F 0 "C10" V 6002 3550 50  0000 C CNN
F 1 "100nF" V 5911 3550 50  0000 C CNN
F 2 "Capacitor_THT:C_Rect_L7.2mm_W4.5mm_P5.00mm_FKS2_FKP2_MKS2_MKP2" H 5788 3400 50  0001 C CNN
F 3 "~" H 5750 3550 50  0001 C CNN
	1    5750 3550
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5200 2700 5150 2700
Wire Wire Line
	5650 3550 5600 3550
Wire Wire Line
	5150 3550 5150 3350
Connection ~ 5150 2700
Wire Wire Line
	5150 2700 5100 2700
Wire Wire Line
	5950 2900 5950 3050
Wire Wire Line
	5950 3550 6800 3550
Wire Wire Line
	6800 3550 6800 2800
Wire Wire Line
	6800 2800 6550 2800
Connection ~ 5950 3550
$Comp
L Device:D D3
U 1 1 5EC845CC
P 6950 2800
F 0 "D3" H 6950 2584 50  0000 C CNN
F 1 "1N4148" H 6950 2675 50  0000 C CNN
F 2 "Diode_THT:D_DO-35_SOD27_P7.62mm_Horizontal" H 6950 2800 50  0001 C CNN
F 3 "~" H 6950 2800 50  0001 C CNN
	1    6950 2800
	-1   0    0    1   
$EndComp
Connection ~ 6800 2800
$Comp
L Device:CP C8
U 1 1 5EC845D3
P 7200 3050
F 0 "C8" H 7318 3096 50  0000 L CNN
F 1 "47uF" H 7318 3005 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D4.0mm_P1.50mm" H 7238 2900 50  0001 C CNN
F 3 "~" H 7200 3050 50  0001 C CNN
	1    7200 3050
	1    0    0    -1  
$EndComp
$Comp
L Device:R R16
U 1 1 5EC845D9
P 7600 3050
F 0 "R16" H 7530 3004 50  0000 R CNN
F 1 "2.2k" H 7530 3095 50  0000 R CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 7530 3050 50  0001 C CNN
F 3 "~" H 7600 3050 50  0001 C CNN
	1    7600 3050
	-1   0    0    1   
$EndComp
Wire Wire Line
	7200 2900 7400 2900
Wire Wire Line
	7100 2800 7400 2800
Wire Wire Line
	7400 2800 7400 2900
Connection ~ 7400 2900
Wire Wire Line
	7400 2900 7600 2900
Wire Wire Line
	7200 3200 7400 3200
$Comp
L power:GNDA #PWR0113
U 1 1 5EC845E5
P 7400 3200
F 0 "#PWR0113" H 7400 2950 50  0001 C CNN
F 1 "GNDA" H 7405 3027 50  0000 C CNN
F 2 "" H 7400 3200 50  0001 C CNN
F 3 "" H 7400 3200 50  0001 C CNN
	1    7400 3200
	1    0    0    -1  
$EndComp
Connection ~ 7400 3200
Wire Wire Line
	7400 3200 7600 3200
$Comp
L Device:R R15
U 1 1 5EC845ED
P 8000 2800
F 0 "R15" V 7793 2800 50  0000 C CNN
F 1 "1k" V 7884 2800 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 7930 2800 50  0001 C CNN
F 3 "~" H 8000 2800 50  0001 C CNN
	1    8000 2800
	0    1    1    0   
$EndComp
Wire Wire Line
	7400 2800 7850 2800
Connection ~ 7400 2800
$Comp
L Device:D_Zener D4
U 1 1 5EC845F5
P 8250 3050
F 0 "D4" V 8204 3129 50  0000 L CNN
F 1 "D_Zener" V 8295 3129 50  0000 L CNN
F 2 "Diode_THT:D_DO-35_SOD27_P7.62mm_Horizontal" H 8250 3050 50  0001 C CNN
F 3 "~" H 8250 3050 50  0001 C CNN
	1    8250 3050
	0    1    1    0   
$EndComp
Wire Wire Line
	8150 2800 8250 2800
Wire Wire Line
	8250 2800 8250 2900
$Comp
L power:GNDA #PWR0114
U 1 1 5EC845FD
P 8250 3200
F 0 "#PWR0114" H 8250 2950 50  0001 C CNN
F 1 "GNDA" H 8255 3027 50  0000 C CNN
F 2 "" H 8250 3200 50  0001 C CNN
F 3 "" H 8250 3200 50  0001 C CNN
	1    8250 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	5800 2800 5800 2700
Wire Wire Line
	5800 2700 5950 2700
$Comp
L power:GNDA #PWR0115
U 1 1 5EC87B5E
P 5550 2800
F 0 "#PWR0115" H 5550 2550 50  0001 C CNN
F 1 "GNDA" H 5555 2627 50  0000 C CNN
F 2 "" H 5550 2800 50  0001 C CNN
F 3 "" H 5550 2800 50  0001 C CNN
	1    5550 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	5550 2800 5550 2700
Wire Wire Line
	5550 2700 5500 2700
Wire Wire Line
	5250 3350 5150 3350
Connection ~ 5150 3350
Wire Wire Line
	5150 3350 5150 2700
Connection ~ 5950 3050
Wire Wire Line
	5950 3050 5950 3250
$Comp
L Device:R R17
U 1 1 5EC8D7E2
P 5950 3400
F 0 "R17" H 6020 3446 50  0000 L CNN
F 1 "47k" H 6020 3355 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 5880 3400 50  0001 C CNN
F 3 "~" H 5950 3400 50  0001 C CNN
	1    5950 3400
	1    0    0    -1  
$EndComp
Connection ~ 5600 3550
Wire Wire Line
	5600 3550 5150 3550
Wire Wire Line
	5900 3550 5950 3550
Wire Wire Line
	5600 3050 5600 3350
Wire Wire Line
	5600 3350 5550 3350
Wire Wire Line
	5600 3050 5950 3050
$Comp
L Amplifier_Operational:LM741 U4
U 1 1 5ECA4F2A
P 6250 4200
F 0 "U4" H 6500 4100 50  0000 L CNN
F 1 "LM741" H 6500 4000 50  0000 L CNN
F 2 "Package_DIP:DIP-8_W7.62mm_Socket" H 6300 4250 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm741.pdf" H 6400 4350 50  0001 C CNN
	1    6250 4200
	1    0    0    -1  
$EndComp
NoConn ~ 6250 4500
NoConn ~ 6350 4500
$Comp
L Device:C C13
U 1 1 5ECA4F32
P 5400 4750
F 0 "C13" V 5148 4750 50  0000 C CNN
F 1 "100nF" V 5239 4750 50  0000 C CNN
F 2 "Capacitor_THT:C_Rect_L7.2mm_W4.5mm_P5.00mm_FKS2_FKP2_MKS2_MKP2" H 5438 4600 50  0001 C CNN
F 3 "~" H 5400 4750 50  0001 C CNN
	1    5400 4750
	0    1    1    0   
$EndComp
$Comp
L Device:R R19
U 1 1 5ECA4F38
P 5350 4100
F 0 "R19" V 5143 4100 50  0000 C CNN
F 1 "320R" V 5234 4100 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 5280 4100 50  0001 C CNN
F 3 "~" H 5350 4100 50  0001 C CNN
	1    5350 4100
	0    1    1    0   
$EndComp
$Comp
L Device:R R18
U 1 1 5ECA4F3E
P 4950 4100
F 0 "R18" V 4743 4100 50  0000 C CNN
F 1 "10k" V 4834 4100 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 4880 4100 50  0001 C CNN
F 3 "~" H 4950 4100 50  0001 C CNN
	1    4950 4100
	0    1    1    0   
$EndComp
$Comp
L power:GNDA #PWR0116
U 1 1 5ECA4F44
P 5800 4200
F 0 "#PWR0116" H 5800 3950 50  0001 C CNN
F 1 "GNDA" H 5805 4027 50  0000 C CNN
F 2 "" H 5800 4200 50  0001 C CNN
F 3 "" H 5800 4200 50  0001 C CNN
	1    5800 4200
	1    0    0    -1  
$EndComp
$Comp
L power:+15V #PWR0117
U 1 1 5ECA4F4A
P 6150 3900
F 0 "#PWR0117" H 6150 3750 50  0001 C CNN
F 1 "+15V" H 6165 4073 50  0000 C CNN
F 2 "" H 6150 3900 50  0001 C CNN
F 3 "" H 6150 3900 50  0001 C CNN
	1    6150 3900
	1    0    0    -1  
$EndComp
$Comp
L power:-15V #PWR0118
U 1 1 5ECA4F50
P 6150 4500
F 0 "#PWR0118" H 6150 4600 50  0001 C CNN
F 1 "-15V" H 6165 4673 50  0000 C CNN
F 2 "" H 6150 4500 50  0001 C CNN
F 3 "" H 6150 4500 50  0001 C CNN
	1    6150 4500
	-1   0    0    1   
$EndComp
$Comp
L Device:C C11
U 1 1 5ECA4F56
P 6300 3900
F 0 "C11" V 6450 3700 50  0000 C CNN
F 1 "100nF" V 6350 3700 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D5.0mm_W2.5mm_P5.00mm" H 6338 3750 50  0001 C CNN
F 3 "~" H 6300 3900 50  0001 C CNN
	1    6300 3900
	0    -1   -1   0   
$EndComp
Connection ~ 6150 3900
Wire Wire Line
	6450 3900 6450 4450
Wire Wire Line
	6450 4450 6200 4450
Wire Wire Line
	6200 4450 6200 4500
Wire Wire Line
	6200 4500 6150 4500
Connection ~ 6150 4500
$Comp
L Device:C C14
U 1 1 5ECA4F62
P 5750 4950
F 0 "C14" V 6002 4950 50  0000 C CNN
F 1 "100nF" V 5911 4950 50  0000 C CNN
F 2 "Capacitor_THT:C_Rect_L7.2mm_W4.5mm_P5.00mm_FKS2_FKP2_MKS2_MKP2" H 5788 4800 50  0001 C CNN
F 3 "~" H 5750 4950 50  0001 C CNN
	1    5750 4950
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5200 4100 5150 4100
Wire Wire Line
	5650 4950 5600 4950
Wire Wire Line
	5150 4950 5150 4750
Connection ~ 5150 4100
Wire Wire Line
	5150 4100 5100 4100
Wire Wire Line
	5950 4300 5950 4450
Wire Wire Line
	5950 4950 6800 4950
Wire Wire Line
	6800 4950 6800 4200
Wire Wire Line
	6800 4200 6550 4200
Connection ~ 5950 4950
$Comp
L Device:D D5
U 1 1 5ECA4F72
P 6950 4200
F 0 "D5" H 6950 3984 50  0000 C CNN
F 1 "1N4148" H 6950 4075 50  0000 C CNN
F 2 "Diode_THT:D_DO-35_SOD27_P7.62mm_Horizontal" H 6950 4200 50  0001 C CNN
F 3 "~" H 6950 4200 50  0001 C CNN
	1    6950 4200
	-1   0    0    1   
$EndComp
Connection ~ 6800 4200
$Comp
L Device:CP C12
U 1 1 5ECA4F79
P 7200 4450
F 0 "C12" H 7318 4496 50  0000 L CNN
F 1 "47uF" H 7318 4405 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D4.0mm_P1.50mm" H 7238 4300 50  0001 C CNN
F 3 "~" H 7200 4450 50  0001 C CNN
	1    7200 4450
	1    0    0    -1  
$EndComp
$Comp
L Device:R R21
U 1 1 5ECA4F7F
P 7600 4450
F 0 "R21" H 7530 4404 50  0000 R CNN
F 1 "2.2k" H 7530 4495 50  0000 R CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 7530 4450 50  0001 C CNN
F 3 "~" H 7600 4450 50  0001 C CNN
	1    7600 4450
	-1   0    0    1   
$EndComp
Wire Wire Line
	7200 4300 7400 4300
Wire Wire Line
	7100 4200 7400 4200
Wire Wire Line
	7400 4200 7400 4300
Connection ~ 7400 4300
Wire Wire Line
	7400 4300 7600 4300
Wire Wire Line
	7200 4600 7400 4600
$Comp
L power:GNDA #PWR0119
U 1 1 5ECA4F8B
P 7400 4600
F 0 "#PWR0119" H 7400 4350 50  0001 C CNN
F 1 "GNDA" H 7405 4427 50  0000 C CNN
F 2 "" H 7400 4600 50  0001 C CNN
F 3 "" H 7400 4600 50  0001 C CNN
	1    7400 4600
	1    0    0    -1  
$EndComp
Connection ~ 7400 4600
Wire Wire Line
	7400 4600 7600 4600
$Comp
L Device:R R20
U 1 1 5ECA4F93
P 8000 4200
F 0 "R20" V 7793 4200 50  0000 C CNN
F 1 "1k" V 7884 4200 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 7930 4200 50  0001 C CNN
F 3 "~" H 8000 4200 50  0001 C CNN
	1    8000 4200
	0    1    1    0   
$EndComp
Wire Wire Line
	7400 4200 7850 4200
Connection ~ 7400 4200
$Comp
L Device:D_Zener D6
U 1 1 5ECA4F9B
P 8250 4450
F 0 "D6" V 8204 4529 50  0000 L CNN
F 1 "D_Zener" V 8295 4529 50  0000 L CNN
F 2 "Diode_THT:D_DO-35_SOD27_P7.62mm_Horizontal" H 8250 4450 50  0001 C CNN
F 3 "~" H 8250 4450 50  0001 C CNN
	1    8250 4450
	0    1    1    0   
$EndComp
Wire Wire Line
	8150 4200 8250 4200
Wire Wire Line
	8250 4200 8250 4300
$Comp
L power:GNDA #PWR0120
U 1 1 5ECA4FA3
P 8250 4600
F 0 "#PWR0120" H 8250 4350 50  0001 C CNN
F 1 "GNDA" H 8255 4427 50  0000 C CNN
F 2 "" H 8250 4600 50  0001 C CNN
F 3 "" H 8250 4600 50  0001 C CNN
	1    8250 4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	5800 4200 5800 4100
Wire Wire Line
	5800 4100 5950 4100
$Comp
L power:GNDA #PWR0121
U 1 1 5ECA4FAB
P 5550 4200
F 0 "#PWR0121" H 5550 3950 50  0001 C CNN
F 1 "GNDA" H 5555 4027 50  0000 C CNN
F 2 "" H 5550 4200 50  0001 C CNN
F 3 "" H 5550 4200 50  0001 C CNN
	1    5550 4200
	1    0    0    -1  
$EndComp
Wire Wire Line
	5550 4200 5550 4100
Wire Wire Line
	5550 4100 5500 4100
Wire Wire Line
	5250 4750 5150 4750
Connection ~ 5150 4750
Wire Wire Line
	5150 4750 5150 4100
Connection ~ 5950 4450
Wire Wire Line
	5950 4450 5950 4650
$Comp
L Device:R R22
U 1 1 5ECA4FB8
P 5950 4800
F 0 "R22" H 6020 4846 50  0000 L CNN
F 1 "22k" H 6020 4755 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 5880 4800 50  0001 C CNN
F 3 "~" H 5950 4800 50  0001 C CNN
	1    5950 4800
	1    0    0    -1  
$EndComp
Connection ~ 5600 4950
Wire Wire Line
	5600 4950 5150 4950
Wire Wire Line
	5900 4950 5950 4950
Wire Wire Line
	5600 4450 5600 4750
Wire Wire Line
	5600 4750 5550 4750
Wire Wire Line
	5600 4450 5950 4450
$Comp
L Amplifier_Operational:LM741 U5
U 1 1 5ECAED6D
P 6250 5600
F 0 "U5" H 6500 5500 50  0000 L CNN
F 1 "LM741" H 6500 5400 50  0000 L CNN
F 2 "Package_DIP:DIP-8_W7.62mm_Socket" H 6300 5650 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm741.pdf" H 6400 5750 50  0001 C CNN
	1    6250 5600
	1    0    0    -1  
$EndComp
NoConn ~ 6250 5900
NoConn ~ 6350 5900
$Comp
L Device:C C17
U 1 1 5ECAED75
P 5400 6150
F 0 "C17" V 5148 6150 50  0000 C CNN
F 1 "100nF" V 5239 6150 50  0000 C CNN
F 2 "Capacitor_THT:C_Rect_L7.2mm_W4.5mm_P5.00mm_FKS2_FKP2_MKS2_MKP2" H 5438 6000 50  0001 C CNN
F 3 "~" H 5400 6150 50  0001 C CNN
	1    5400 6150
	0    1    1    0   
$EndComp
$Comp
L Device:R R24
U 1 1 5ECAED7B
P 5350 5500
F 0 "R24" V 5143 5500 50  0000 C CNN
F 1 "220R" V 5234 5500 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 5280 5500 50  0001 C CNN
F 3 "~" H 5350 5500 50  0001 C CNN
	1    5350 5500
	0    1    1    0   
$EndComp
$Comp
L Device:R R23
U 1 1 5ECAED81
P 4950 5500
F 0 "R23" V 4743 5500 50  0000 C CNN
F 1 "4.7k" V 4834 5500 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 4880 5500 50  0001 C CNN
F 3 "~" H 4950 5500 50  0001 C CNN
	1    4950 5500
	0    1    1    0   
$EndComp
$Comp
L power:GNDA #PWR0122
U 1 1 5ECAED87
P 5800 5600
F 0 "#PWR0122" H 5800 5350 50  0001 C CNN
F 1 "GNDA" H 5805 5427 50  0000 C CNN
F 2 "" H 5800 5600 50  0001 C CNN
F 3 "" H 5800 5600 50  0001 C CNN
	1    5800 5600
	1    0    0    -1  
$EndComp
$Comp
L power:+15V #PWR0123
U 1 1 5ECAED8D
P 6150 5300
F 0 "#PWR0123" H 6150 5150 50  0001 C CNN
F 1 "+15V" H 6165 5473 50  0000 C CNN
F 2 "" H 6150 5300 50  0001 C CNN
F 3 "" H 6150 5300 50  0001 C CNN
	1    6150 5300
	1    0    0    -1  
$EndComp
$Comp
L power:-15V #PWR0124
U 1 1 5ECAED93
P 6150 5900
F 0 "#PWR0124" H 6150 6000 50  0001 C CNN
F 1 "-15V" H 6165 6073 50  0000 C CNN
F 2 "" H 6150 5900 50  0001 C CNN
F 3 "" H 6150 5900 50  0001 C CNN
	1    6150 5900
	-1   0    0    1   
$EndComp
$Comp
L Device:C C15
U 1 1 5ECAED99
P 6300 5300
F 0 "C15" V 6450 5100 50  0000 C CNN
F 1 "100nF" V 6350 5100 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D5.0mm_W2.5mm_P5.00mm" H 6338 5150 50  0001 C CNN
F 3 "~" H 6300 5300 50  0001 C CNN
	1    6300 5300
	0    -1   -1   0   
$EndComp
Connection ~ 6150 5300
Wire Wire Line
	6450 5300 6450 5850
Wire Wire Line
	6450 5850 6200 5850
Wire Wire Line
	6200 5850 6200 5900
Wire Wire Line
	6200 5900 6150 5900
Connection ~ 6150 5900
$Comp
L Device:C C18
U 1 1 5ECAEDA5
P 5750 6350
F 0 "C18" V 6002 6350 50  0000 C CNN
F 1 "100nF" V 5911 6350 50  0000 C CNN
F 2 "Capacitor_THT:C_Rect_L7.2mm_W4.5mm_P5.00mm_FKS2_FKP2_MKS2_MKP2" H 5788 6200 50  0001 C CNN
F 3 "~" H 5750 6350 50  0001 C CNN
	1    5750 6350
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5200 5500 5150 5500
Wire Wire Line
	5650 6350 5600 6350
Wire Wire Line
	5150 6350 5150 6150
Connection ~ 5150 5500
Wire Wire Line
	5150 5500 5100 5500
Wire Wire Line
	5950 5700 5950 5850
Wire Wire Line
	5950 6350 6800 6350
Wire Wire Line
	6800 6350 6800 5600
Wire Wire Line
	6800 5600 6550 5600
Connection ~ 5950 6350
$Comp
L Device:D D7
U 1 1 5ECAEDB5
P 6950 5600
F 0 "D7" H 6950 5384 50  0000 C CNN
F 1 "1N4148" H 6950 5475 50  0000 C CNN
F 2 "Diode_THT:D_DO-35_SOD27_P7.62mm_Horizontal" H 6950 5600 50  0001 C CNN
F 3 "~" H 6950 5600 50  0001 C CNN
	1    6950 5600
	-1   0    0    1   
$EndComp
Connection ~ 6800 5600
$Comp
L Device:CP C16
U 1 1 5ECAEDBC
P 7200 5850
F 0 "C16" H 7318 5896 50  0000 L CNN
F 1 "47uF" H 7318 5805 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D4.0mm_P1.50mm" H 7238 5700 50  0001 C CNN
F 3 "~" H 7200 5850 50  0001 C CNN
	1    7200 5850
	1    0    0    -1  
$EndComp
$Comp
L Device:R R26
U 1 1 5ECAEDC2
P 7600 5850
F 0 "R26" H 7530 5804 50  0000 R CNN
F 1 "2.2k" H 7530 5895 50  0000 R CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 7530 5850 50  0001 C CNN
F 3 "~" H 7600 5850 50  0001 C CNN
	1    7600 5850
	-1   0    0    1   
$EndComp
Wire Wire Line
	7200 5700 7400 5700
Wire Wire Line
	7100 5600 7400 5600
Wire Wire Line
	7400 5600 7400 5700
Connection ~ 7400 5700
Wire Wire Line
	7400 5700 7600 5700
Wire Wire Line
	7200 6000 7400 6000
$Comp
L power:GNDA #PWR0125
U 1 1 5ECAEDCE
P 7400 6000
F 0 "#PWR0125" H 7400 5750 50  0001 C CNN
F 1 "GNDA" H 7405 5827 50  0000 C CNN
F 2 "" H 7400 6000 50  0001 C CNN
F 3 "" H 7400 6000 50  0001 C CNN
	1    7400 6000
	1    0    0    -1  
$EndComp
Connection ~ 7400 6000
Wire Wire Line
	7400 6000 7600 6000
$Comp
L Device:R R25
U 1 1 5ECAEDD6
P 8000 5600
F 0 "R25" V 7793 5600 50  0000 C CNN
F 1 "1k" V 7884 5600 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 7930 5600 50  0001 C CNN
F 3 "~" H 8000 5600 50  0001 C CNN
	1    8000 5600
	0    1    1    0   
$EndComp
Wire Wire Line
	7400 5600 7850 5600
Connection ~ 7400 5600
$Comp
L Device:D_Zener D8
U 1 1 5ECAEDDE
P 8250 5850
F 0 "D8" V 8204 5929 50  0000 L CNN
F 1 "D_Zener" V 8295 5929 50  0000 L CNN
F 2 "Diode_THT:D_DO-35_SOD27_P7.62mm_Horizontal" H 8250 5850 50  0001 C CNN
F 3 "~" H 8250 5850 50  0001 C CNN
	1    8250 5850
	0    1    1    0   
$EndComp
Wire Wire Line
	8150 5600 8250 5600
Wire Wire Line
	8250 5600 8250 5700
$Comp
L power:GNDA #PWR0126
U 1 1 5ECAEDE6
P 8250 6000
F 0 "#PWR0126" H 8250 5750 50  0001 C CNN
F 1 "GNDA" H 8255 5827 50  0000 C CNN
F 2 "" H 8250 6000 50  0001 C CNN
F 3 "" H 8250 6000 50  0001 C CNN
	1    8250 6000
	1    0    0    -1  
$EndComp
Wire Wire Line
	5800 5600 5800 5500
Wire Wire Line
	5800 5500 5950 5500
$Comp
L power:GNDA #PWR0127
U 1 1 5ECAEDEE
P 5550 5600
F 0 "#PWR0127" H 5550 5350 50  0001 C CNN
F 1 "GNDA" H 5555 5427 50  0000 C CNN
F 2 "" H 5550 5600 50  0001 C CNN
F 3 "" H 5550 5600 50  0001 C CNN
	1    5550 5600
	1    0    0    -1  
$EndComp
Wire Wire Line
	5550 5600 5550 5500
Wire Wire Line
	5550 5500 5500 5500
Wire Wire Line
	5250 6150 5150 6150
Connection ~ 5150 6150
Wire Wire Line
	5150 6150 5150 5500
Connection ~ 5950 5850
Wire Wire Line
	5950 5850 5950 6050
$Comp
L Device:R R27
U 1 1 5ECAEDFB
P 5950 6200
F 0 "R27" H 6020 6246 50  0000 L CNN
F 1 "10k" H 6020 6155 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 5880 6200 50  0001 C CNN
F 3 "~" H 5950 6200 50  0001 C CNN
	1    5950 6200
	1    0    0    -1  
$EndComp
Connection ~ 5600 6350
Wire Wire Line
	5600 6350 5150 6350
Wire Wire Line
	5900 6350 5950 6350
Wire Wire Line
	5600 5850 5600 6150
Wire Wire Line
	5600 6150 5550 6150
Wire Wire Line
	5600 5850 5950 5850
Wire Wire Line
	4800 1300 4800 2700
Connection ~ 4800 2700
Wire Wire Line
	4800 2700 4800 4100
Connection ~ 4800 4100
Wire Wire Line
	4800 4100 4800 5500
Wire Wire Line
	4050 1300 4800 1300
Connection ~ 4800 1300
$Comp
L Connector:Conn_01x04_Male J3
U 1 1 5ECC1E8A
P 900 2350
F 0 "J3" H 1000 2700 50  0000 C CNN
F 1 "From PSU" H 1000 2600 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:Molex_KK254_1x04Vertical" H 900 2350 50  0001 C CNN
F 3 "~" H 900 2350 50  0001 C CNN
	1    900  2350
	1    0    0    -1  
$EndComp
$Comp
L power:+15V #PWR0128
U 1 1 5ECCAF38
P 1400 2250
F 0 "#PWR0128" H 1400 2100 50  0001 C CNN
F 1 "+15V" H 1415 2423 50  0000 C CNN
F 2 "" H 1400 2250 50  0001 C CNN
F 3 "" H 1400 2250 50  0001 C CNN
	1    1400 2250
	1    0    0    -1  
$EndComp
$Comp
L power:-15V #PWR0129
U 1 1 5ECCBA65
P 1650 2350
F 0 "#PWR0129" H 1650 2450 50  0001 C CNN
F 1 "-15V" H 1665 2523 50  0000 C CNN
F 2 "" H 1650 2350 50  0001 C CNN
F 3 "" H 1650 2350 50  0001 C CNN
	1    1650 2350
	1    0    0    -1  
$EndComp
NoConn ~ 1100 2450
$Comp
L power:GNDA #PWR0130
U 1 1 5ECD237C
P 1900 2550
F 0 "#PWR0130" H 1900 2300 50  0001 C CNN
F 1 "GNDA" H 1905 2377 50  0000 C CNN
F 2 "" H 1900 2550 50  0001 C CNN
F 3 "" H 1900 2550 50  0001 C CNN
	1    1900 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	1100 2250 1400 2250
Wire Wire Line
	1100 2350 1650 2350
Wire Wire Line
	1900 2550 1100 2550
$Comp
L Connector:Conn_01x04_Female J2
U 1 1 5ECE7B8E
P 10300 1500
F 0 "J2" H 10250 1850 50  0000 L CNN
F 1 "To motherboard" H 9900 1750 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:Molex_KK254_1x04Vertical" H 10300 1500 50  0001 C CNN
F 3 "~" H 10300 1500 50  0001 C CNN
	1    10300 1500
	1    0    0    -1  
$EndComp
Wire Wire Line
	8250 1400 10100 1400
Connection ~ 8250 1400
Wire Wire Line
	10100 1500 9050 1500
Wire Wire Line
	9050 1500 9050 2800
Wire Wire Line
	9050 2800 8250 2800
Connection ~ 8250 2800
Wire Wire Line
	10100 1600 9400 1600
Wire Wire Line
	9400 1600 9400 4200
Wire Wire Line
	9400 4200 8250 4200
Connection ~ 8250 4200
Wire Wire Line
	8250 5600 9750 5600
Wire Wire Line
	9750 5600 9750 1700
Wire Wire Line
	9750 1700 10100 1700
Connection ~ 8250 5600
$EndSCHEMATC
