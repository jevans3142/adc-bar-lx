EESchema Schematic File Version 4
LIBS:psu-board-cache
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
L Regulator_Switching:R-78E12-0.5 U1
U 1 1 5E87E7D0
P 5650 2900
F 0 "U1" H 5650 3142 50  0000 C CNN
F 1 "R-78E12-0.5" H 5650 3051 50  0000 C CNN
F 2 "Converter_DCDC:Converter_DCDC_RECOM_R-78E-0.5_THT" H 5700 2650 50  0001 L CIN
F 3 "https://www.recom-power.com/pdf/Innoline/R-78Exx-0.5.pdf" H 5650 2900 50  0001 C CNN
	1    5650 2900
	1    0    0    -1  
$EndComp
$Comp
L Converter_ACDC:RAC10-15DK_277 PS1
U 1 1 5E884AB8
P 3600 3850
F 0 "PS1" H 3600 4215 50  0000 C CNN
F 1 "RAC10-15DK_277" H 3600 4124 50  0000 C CNN
F 2 "Converter_ACDC:Converter_ACDC_RECOM_RAC10-150K" H 3600 3500 50  0001 C CNN
F 3 "https://www.recom-power.com/pdf/Powerline-AC-DC/RAC04-GB.pdf" H 3500 4150 50  0001 C CNN
	1    3600 3850
	1    0    0    -1  
$EndComp
Wire Wire Line
	5650 3850 5650 3200
Wire Wire Line
	4150 3750 4450 3750
Wire Wire Line
	4150 3950 4450 3950
Wire Wire Line
	4450 3950 4450 4750
Wire Wire Line
	4450 4750 4650 4750
$Comp
L Device:CP C1
U 1 1 5E888497
P 4650 3550
F 0 "C1" H 4768 3596 50  0000 L CNN
F 1 "10uF" H 4768 3505 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D5.0mm_P2.50mm" H 4688 3400 50  0001 C CNN
F 3 "~" H 4650 3550 50  0001 C CNN
	1    4650 3550
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C2
U 1 1 5E888D30
P 4650 4150
F 0 "C2" H 4768 4196 50  0000 L CNN
F 1 "10uF" H 4768 4105 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D5.0mm_P2.50mm" H 4688 4000 50  0001 C CNN
F 3 "~" H 4650 4150 50  0001 C CNN
	1    4650 4150
	1    0    0    -1  
$EndComp
Wire Wire Line
	4650 4000 4650 3850
Wire Wire Line
	4150 3850 4250 3850
Connection ~ 4650 3850
Wire Wire Line
	4650 3850 4650 3700
Wire Wire Line
	4650 4300 4650 4750
Connection ~ 4650 4750
Wire Wire Line
	4650 4750 6900 4750
Wire Wire Line
	5650 3850 6150 3850
Connection ~ 5650 3850
Wire Wire Line
	4450 2050 4650 2050
Wire Wire Line
	4650 3850 5650 3850
$Comp
L Regulator_Switching:R-78E5.0-0.5 U2
U 1 1 5E87D152
P 6150 3400
F 0 "U2" H 6150 3642 50  0000 C CNN
F 1 "R-78E5.0-0.5" H 6150 3551 50  0000 C CNN
F 2 "Converter_DCDC:Converter_DCDC_RECOM_R-78E-0.5_THT" H 6200 3150 50  0001 L CIN
F 3 "https://www.recom-power.com/pdf/Innoline/R-78Exx-0.5.pdf" H 6150 3400 50  0001 C CNN
	1    6150 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	4650 2050 4650 3400
Connection ~ 4650 2050
Wire Wire Line
	4650 2050 5200 2050
Wire Wire Line
	4450 2050 4450 3750
Wire Wire Line
	5350 2900 5200 2900
Wire Wire Line
	5200 2900 5200 2050
Connection ~ 5200 2050
Wire Wire Line
	5200 2050 6900 2050
Wire Wire Line
	5200 2900 5200 3400
Wire Wire Line
	5200 3400 5850 3400
Connection ~ 5200 2900
Wire Wire Line
	6150 3700 6150 3850
Connection ~ 6150 3850
Wire Wire Line
	6150 3850 6900 3850
Wire Wire Line
	5950 2900 6900 2900
Wire Wire Line
	6450 3400 6900 3400
Text Label 6700 2050 0    50   ~ 0
+15V
Text Label 6700 2900 0    50   ~ 0
+12V
Text Label 6750 3400 0    50   ~ 0
+5V
Text Label 6750 3850 0    50   ~ 0
0V
Text Label 6700 4750 0    50   ~ 0
-15V
$Comp
L Connector:Conn_01x04_Female J1
U 1 1 5E90D5DB
P 8450 2400
F 0 "J1" H 8478 2376 50  0000 L CNN
F 1 "Motherboard connector" H 8478 2285 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:Molex_KK254_1x04Vertical" H 8450 2400 50  0001 C CNN
F 3 "~" H 8450 2400 50  0001 C CNN
	1    8450 2400
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x04_Female J3
U 1 1 5E90DC71
P 8450 3650
F 0 "J3" H 8478 3626 50  0000 L CNN
F 1 "Sound To Light connector" H 8478 3535 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:Molex_KK254_1x04Vertical" H 8450 3650 50  0001 C CNN
F 3 "~" H 8450 3650 50  0001 C CNN
	1    8450 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	8250 2400 7950 2400
Wire Wire Line
	8250 2300 7950 2300
Wire Wire Line
	8250 2500 7950 2500
Wire Wire Line
	8250 2600 7950 2600
Wire Wire Line
	8250 3550 7950 3550
Wire Wire Line
	8250 3650 7950 3650
Wire Wire Line
	8250 3750 7950 3750
Wire Wire Line
	8250 3850 7950 3850
Text Label 7950 3550 0    50   ~ 0
+15V
Text Label 7950 3650 0    50   ~ 0
-15V
Text Label 8050 3850 0    50   ~ 0
0V
Text Label 7950 2400 0    50   ~ 0
+12V
Text Label 7950 2300 0    50   ~ 0
+15V
Text Label 8000 2500 0    50   ~ 0
+5V
Text Label 8050 2600 0    50   ~ 0
0V
Text Label 8000 3750 0    50   ~ 0
+5V
Wire Wire Line
	2600 3750 3050 3750
Wire Wire Line
	3050 3950 2600 3950
$Comp
L Connector:Conn_01x01_Male J5
U 1 1 5E9124DB
P 2400 3750
F 0 "J5" H 2508 3931 50  0000 C CNN
F 1 "Live In" H 2508 3840 50  0000 C CNN
F 2 "Connector_Pin:Pin_D1.3mm_L11.0mm" H 2400 3750 50  0001 C CNN
F 3 "~" H 2400 3750 50  0001 C CNN
	1    2400 3750
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Male J6
U 1 1 5E912A57
P 2400 3950
F 0 "J6" H 2500 3900 50  0000 C CNN
F 1 "Neutral In" H 2500 3800 50  0000 C CNN
F 2 "Connector_Pin:Pin_D1.3mm_L11.0mm" H 2400 3950 50  0001 C CNN
F 3 "~" H 2400 3950 50  0001 C CNN
	1    2400 3950
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Male J7
U 1 1 5E91DB0C
P 2400 4750
F 0 "J7" H 2500 4700 50  0000 C CNN
F 1 "Earth" H 2500 4600 50  0000 C CNN
F 2 "Connector_Pin:Pin_D1.3mm_L11.0mm" H 2400 4750 50  0001 C CNN
F 3 "~" H 2400 4750 50  0001 C CNN
	1    2400 4750
	1    0    0    -1  
$EndComp
Connection ~ 4250 3850
Wire Wire Line
	4250 3850 4650 3850
$Comp
L Device:Jumper JP1
U 1 1 5E91EE7C
P 3450 4750
F 0 "JP1" H 3450 5014 50  0000 C CNN
F 1 "Earth Link" H 3450 4923 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 3450 4750 50  0001 C CNN
F 3 "~" H 3450 4750 50  0001 C CNN
	1    3450 4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	2600 4750 3150 4750
Wire Wire Line
	3750 4750 4250 4750
Wire Wire Line
	4250 3850 4250 4750
$Comp
L Connector:Conn_01x04_Female J2
U 1 1 5E927E94
P 8450 3000
F 0 "J2" H 8478 2976 50  0000 L CNN
F 1 "Aux 1" H 8478 2885 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:Molex_KK254_1x04Vertical" H 8450 3000 50  0001 C CNN
F 3 "~" H 8450 3000 50  0001 C CNN
	1    8450 3000
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x04_Female J4
U 1 1 5E927E9A
P 8450 4400
F 0 "J4" H 8478 4376 50  0000 L CNN
F 1 "Aux 2" H 8478 4285 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:Molex_KK254_1x04Vertical" H 8450 4400 50  0001 C CNN
F 3 "~" H 8450 4400 50  0001 C CNN
	1    8450 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	8250 3000 7950 3000
Wire Wire Line
	8250 2900 7950 2900
Wire Wire Line
	8250 3100 7950 3100
Wire Wire Line
	8250 3200 7950 3200
Wire Wire Line
	8250 4300 7950 4300
Wire Wire Line
	8250 4400 7950 4400
Wire Wire Line
	8250 4500 7950 4500
Wire Wire Line
	8250 4600 7950 4600
Text Label 7950 4300 0    50   ~ 0
+15V
Text Label 7950 4400 0    50   ~ 0
-15V
Text Label 8050 4600 0    50   ~ 0
0V
Text Label 7950 3000 0    50   ~ 0
+12V
Text Label 7950 2900 0    50   ~ 0
+15V
Text Label 8000 3100 0    50   ~ 0
+5V
Text Label 8050 3200 0    50   ~ 0
0V
Text Label 8000 4500 0    50   ~ 0
+5V
$EndSCHEMATC
