EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A3 16535 11693
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
L 74xx:74HC595 U?
U 1 1 5F8632AE
P 2700 3250
F 0 "U?" H 2700 4031 50  0000 C CNN
F 1 "74HC595" H 2700 3940 50  0000 C CNN
F 2 "" H 2700 3250 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74hc595.pdf" H 2700 3250 50  0001 C CNN
	1    2700 3250
	1    0    0    -1  
$EndComp
$Comp
L Display_Character:CC56-12SRWA U?
U 1 1 5F86A3AA
P 14750 4400
F 0 "U?" H 14750 5067 50  0000 C CNN
F 1 "CC56-12SRWA" H 14750 4976 50  0000 C CNN
F 2 "Display_7Segment:CA56-12SRWA" H 14750 3800 50  0001 C CNN
F 3 "http://www.kingbrightusa.com/images/catalog/SPEC/CC56-12SRWA.pdf" H 14320 4430 50  0001 C CNN
	1    14750 4400
	1    0    0    -1  
$EndComp
$Comp
L Display_Character:CC56-12SRWA U?
U 1 1 5F86C3E0
P 12250 3400
F 0 "U?" H 12250 4067 50  0000 C CNN
F 1 "CC56-12SRWA" H 12250 3976 50  0000 C CNN
F 2 "Display_7Segment:CA56-12SRWA" H 12250 2800 50  0001 C CNN
F 3 "http://www.kingbrightusa.com/images/catalog/SPEC/CC56-12SRWA.pdf" H 11820 3430 50  0001 C CNN
	1    12250 3400
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS154 U?
U 1 1 5F878974
P 4300 2950
F 0 "U?" H 4300 4131 50  0000 C CNN
F 1 "74LS154" H 4300 4040 50  0000 C CNN
F 2 "" H 4300 2950 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS154" H 4300 2950 50  0001 C CNN
	1    4300 2950
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC595 U?
U 1 1 5F864439
P 2700 6850
F 0 "U?" H 2700 7631 50  0000 C CNN
F 1 "74HC595" H 2700 7540 50  0000 C CNN
F 2 "" H 2700 6850 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74hc595.pdf" H 2700 6850 50  0001 C CNN
	1    2700 6850
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 9200 1950 9200
Wire Wire Line
	1950 9200 1950 1100
Wire Wire Line
	1950 1100 2300 1100
Wire Wire Line
	3100 2000 3200 2000
Wire Wire Line
	3200 2400 2200 2400
Wire Wire Line
	2200 2400 2200 2850
Wire Wire Line
	2200 2850 2300 2850
Wire Wire Line
	3100 5500 3200 5500
Wire Wire Line
	3200 5500 3200 6000
Wire Wire Line
	3200 6000 2200 6000
Wire Wire Line
	2200 6000 2200 6450
Wire Wire Line
	2200 6450 2300 6450
Wire Wire Line
	2200 9300 1850 9300
Wire Wire Line
	1850 1300 2300 1300
Wire Wire Line
	2200 9400 1750 9400
Wire Wire Line
	1750 9400 1750 4050
Wire Wire Line
	1750 1700 2300 1700
Connection ~ 1750 3450
Wire Wire Line
	1750 3450 1750 1700
Wire Wire Line
	1750 3450 2300 3450
Wire Wire Line
	1850 9300 1850 3050
Wire Wire Line
	1850 3050 1850 1300
Connection ~ 1850 3050
Wire Wire Line
	1850 3050 2300 3050
Wire Wire Line
	2200 9500 1550 9500
Wire Wire Line
	1550 9500 1550 4600
Wire Wire Line
	1550 4600 2300 4600
Wire Wire Line
	2200 9600 1450 9600
Wire Wire Line
	1450 4800 2300 4800
Wire Wire Line
	2200 9700 1350 9700
Wire Wire Line
	1350 9700 1350 7650
Wire Wire Line
	1350 7050 1350 5200
Connection ~ 1350 7050
Wire Wire Line
	1350 7050 2300 7050
Wire Wire Line
	1450 4800 1450 6650
Wire Wire Line
	1450 6650 1450 9600
Connection ~ 1450 6650
Wire Wire Line
	1450 6650 2300 6650
$Comp
L 74xx:74LS154 U?
U 1 1 5F875AF4
P 4300 6550
F 0 "U?" H 4300 7731 50  0000 C CNN
F 1 "74LS154" H 4300 7640 50  0000 C CNN
F 2 "" H 4300 6550 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS154" H 4300 6550 50  0001 C CNN
	1    4300 6550
	1    0    0    -1  
$EndComp
$Comp
L MCU_Module:Arduino_UNO_R2 A?
U 1 1 5F85CE3E
P 2700 9600
F 0 "A?" H 2700 10781 50  0000 C CNN
F 1 "Arduino_UNO_R2" H 2700 10690 50  0000 C CNN
F 2 "Module:Arduino_UNO_R2" H 2700 9600 50  0001 C CIN
F 3 "https://www.arduino.cc/en/Main/arduinoBoardUno" H 2700 9600 50  0001 C CNN
	1    2700 9600
	1    0    0    -1  
$EndComp
Wire Wire Line
	2900 8600 2900 8350
Wire Wire Line
	2900 8350 1150 8350
Wire Wire Line
	1150 8350 1150 6250
Wire Wire Line
	1150 900  2700 900 
Connection ~ 1150 2650
Wire Wire Line
	1150 2650 1150 900 
Wire Wire Line
	2700 2650 1150 2650
Wire Wire Line
	2600 10700 2600 10800
Wire Wire Line
	2600 10800 1050 10800
Wire Wire Line
	1050 2200 2700 2200
Connection ~ 1150 4400
Wire Wire Line
	1150 4400 1150 2650
Wire Wire Line
	2700 4400 1150 4400
Connection ~ 1050 7550
Wire Wire Line
	1050 7550 1050 5700
Wire Wire Line
	1050 7550 2700 7550
Connection ~ 1050 5700
Wire Wire Line
	1050 5700 2700 5700
Connection ~ 1050 3950
Wire Wire Line
	1050 3950 1050 2200
Wire Wire Line
	1050 3950 2700 3950
Entry Wire Line
	3100 1600 3200 1500
Entry Wire Line
	3100 1800 3200 1700
Entry Wire Line
	3100 1700 3200 1600
Entry Wire Line
	3100 1500 3200 1400
Entry Wire Line
	3100 1400 3200 1300
Entry Wire Line
	3100 1300 3200 1200
Entry Wire Line
	3100 1200 3200 1100
Entry Wire Line
	3100 1100 3200 1000
$Comp
L Display_Character:CC56-12SRWA U?
U 1 1 5F868915
P 14700 1400
F 0 "U?" H 14700 2067 50  0000 C CNN
F 1 "CC56-12SRWA" H 14700 1976 50  0000 C CNN
F 2 "Display_7Segment:CA56-12SRWA" H 14700 800 50  0001 C CNN
F 3 "http://www.kingbrightusa.com/images/catalog/SPEC/CC56-12SRWA.pdf" H 14270 1430 50  0001 C CNN
	1    14700 1400
	1    0    0    -1  
$EndComp
Connection ~ 1750 4050
Wire Wire Line
	1750 4050 1750 3450
Wire Wire Line
	1750 4050 3700 4050
Wire Wire Line
	3700 4050 3700 2750
Wire Wire Line
	3700 2750 3800 2750
Connection ~ 1350 7650
Wire Wire Line
	1350 7650 1350 7050
Wire Wire Line
	1350 7650 3700 7650
Wire Wire Line
	3700 7650 3700 6350
Wire Wire Line
	3700 6350 3800 6350
Wire Wire Line
	1350 5200 2300 5200
$Comp
L 74xx:74HC595 U?
U 1 1 5F863F62
P 2700 5000
F 0 "U?" H 2700 5781 50  0000 C CNN
F 1 "74HC595" H 2700 5690 50  0000 C CNN
F 2 "" H 2700 5000 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74hc595.pdf" H 2700 5000 50  0001 C CNN
	1    2700 5000
	1    0    0    -1  
$EndComp
$Comp
L Device:R_US R?
U 1 1 5F927420
P 13450 1100
F 0 "R?" V 13245 1100 50  0000 C CNN
F 1 "220" V 13336 1100 50  0000 C CNN
F 2 "" V 13490 1090 50  0001 C CNN
F 3 "~" H 13450 1100 50  0001 C CNN
	1    13450 1100
	0    1    1    0   
$EndComp
$Comp
L Device:R_US R?
U 1 1 5F92FE44
P 13150 1200
F 0 "R?" V 12945 1200 50  0000 C CNN
F 1 "220" V 13036 1200 50  0000 C CNN
F 2 "" V 13190 1190 50  0001 C CNN
F 3 "~" H 13150 1200 50  0001 C CNN
	1    13150 1200
	0    1    1    0   
$EndComp
$Comp
L Device:R_US R?
U 1 1 5F9316F8
P 12800 1300
F 0 "R?" V 12595 1300 50  0000 C CNN
F 1 "220" V 12686 1300 50  0000 C CNN
F 2 "" V 12840 1290 50  0001 C CNN
F 3 "~" H 12800 1300 50  0001 C CNN
	1    12800 1300
	0    1    1    0   
$EndComp
$Comp
L Device:R_US R?
U 1 1 5F932ECE
P 12500 1400
F 0 "R?" V 12295 1400 50  0000 C CNN
F 1 "220" V 12386 1400 50  0000 C CNN
F 2 "" V 12540 1390 50  0001 C CNN
F 3 "~" H 12500 1400 50  0001 C CNN
	1    12500 1400
	0    1    1    0   
$EndComp
$Comp
L Device:R_US R?
U 1 1 5F934835
P 13450 1500
F 0 "R?" V 13245 1500 50  0000 C CNN
F 1 "220" V 13336 1500 50  0000 C CNN
F 2 "" V 13490 1490 50  0001 C CNN
F 3 "~" H 13450 1500 50  0001 C CNN
	1    13450 1500
	0    1    1    0   
$EndComp
$Comp
L Device:R_US R?
U 1 1 5F936213
P 13150 1600
F 0 "R?" V 12945 1600 50  0000 C CNN
F 1 "220" V 13036 1600 50  0000 C CNN
F 2 "" V 13190 1590 50  0001 C CNN
F 3 "~" H 13150 1600 50  0001 C CNN
	1    13150 1600
	0    1    1    0   
$EndComp
$Comp
L Device:R_US R?
U 1 1 5F937A7F
P 12850 1700
F 0 "R?" V 12645 1700 50  0000 C CNN
F 1 "220" V 12736 1700 50  0000 C CNN
F 2 "" V 12890 1690 50  0001 C CNN
F 3 "~" H 12850 1700 50  0001 C CNN
	1    12850 1700
	0    1    1    0   
$EndComp
$Comp
L Device:R_US R?
U 1 1 5F93944F
P 12500 1800
F 0 "R?" V 12295 1800 50  0000 C CNN
F 1 "220" V 12386 1800 50  0000 C CNN
F 2 "" V 12540 1790 50  0001 C CNN
F 3 "~" H 12500 1800 50  0001 C CNN
	1    12500 1800
	0    1    1    0   
$EndComp
Wire Wire Line
	13600 1200 13300 1200
Wire Wire Line
	13600 1300 12950 1300
Wire Wire Line
	13600 1400 12650 1400
Wire Wire Line
	13600 1600 13300 1600
Wire Wire Line
	13600 1700 13000 1700
Wire Wire Line
	13600 1800 12650 1800
Wire Wire Line
	13300 1500 12350 1500
Wire Wire Line
	13000 1600 12350 1600
Wire Wire Line
	12700 1700 12350 1700
Wire Wire Line
	12650 1300 12350 1300
Wire Wire Line
	13000 1200 12350 1200
Wire Wire Line
	13300 1100 12350 1100
Entry Wire Line
	12250 1000 12350 1100
Entry Wire Line
	12250 1100 12350 1200
Entry Wire Line
	12250 1200 12350 1300
Entry Wire Line
	12250 1300 12350 1400
Entry Wire Line
	12250 1400 12350 1500
Entry Wire Line
	12250 1500 12350 1600
Entry Wire Line
	12250 1600 12350 1700
Entry Wire Line
	12250 1700 12350 1800
Wire Wire Line
	3200 2000 3200 2400
$Comp
L 74xx:74HC595 U?
U 1 1 5F8625CD
P 2700 1500
F 0 "U?" H 2700 2281 50  0000 C CNN
F 1 "74HC595" H 2700 2190 50  0000 C CNN
F 2 "" H 2700 1500 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74hc595.pdf" H 2700 1500 50  0001 C CNN
	1    2700 1500
	1    0    0    -1  
$EndComp
Wire Bus Line
	3200 900  12250 900 
Connection ~ 2700 2650
Wire Wire Line
	4300 1950 3300 1950
Wire Wire Line
	3300 1950 3300 2650
Wire Wire Line
	3300 2650 2700 2650
Wire Wire Line
	1050 5700 1050 4150
Wire Wire Line
	4300 4050 4300 4150
Wire Wire Line
	4300 4150 1050 4150
Connection ~ 1050 4150
Wire Wire Line
	1050 4150 1050 3950
Wire Wire Line
	4300 7650 4300 7750
Wire Wire Line
	4300 7750 1050 7750
Connection ~ 1050 7750
Wire Wire Line
	1050 7750 1050 7550
Wire Wire Line
	2700 6250 1150 6250
Connection ~ 1150 6250
Wire Wire Line
	1150 6250 1150 4400
Connection ~ 2700 6250
Wire Wire Line
	4300 5550 3300 5550
Wire Wire Line
	3300 5550 3300 6250
Wire Wire Line
	3300 6250 2700 6250
$Comp
L CustomMade:ESP8266_WiFi_Module U?
U 1 1 5F97BDB9
P 4300 10250
F 0 "U?" H 4300 10881 50  0000 C CNN
F 1 "ESP8266_WiFi_Module" H 4300 10790 50  0000 C CNN
F 2 "" H 4150 10800 50  0001 C CNN
F 3 "" H 4150 10800 50  0001 C CNN
	1    4300 10250
	1    0    0    -1  
$EndComp
Connection ~ 2600 10800
Wire Wire Line
	2600 10800 4300 10800
Wire Wire Line
	4300 10800 4300 10700
Wire Wire Line
	2800 8600 2800 8450
Wire Wire Line
	2800 8450 3700 8450
Wire Wire Line
	4300 8450 4300 9800
$Comp
L Switch:SW_Push SW?
U 1 1 5F98A804
P 1550 10050
F 0 "SW?" H 1550 10335 50  0000 C CNN
F 1 "SW_Push" H 1550 10244 50  0000 C CNN
F 2 "" H 1550 10250 50  0001 C CNN
F 3 "~" H 1550 10250 50  0001 C CNN
	1    1550 10050
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW?
U 1 1 5F98EFCA
P 1550 10450
F 0 "SW?" H 1550 10735 50  0000 C CNN
F 1 "SW_Push" H 1550 10644 50  0000 C CNN
F 2 "" H 1550 10650 50  0001 C CNN
F 3 "~" H 1550 10650 50  0001 C CNN
	1    1550 10450
	1    0    0    -1  
$EndComp
Wire Wire Line
	1050 10800 1050 7750
Wire Wire Line
	1150 8350 1150 10050
Wire Wire Line
	1150 10050 1350 10050
Connection ~ 1150 8350
Wire Wire Line
	1150 10050 1150 10450
Wire Wire Line
	1150 10450 1350 10450
Connection ~ 1150 10050
Wire Wire Line
	1750 10050 2100 10050
Wire Wire Line
	2100 10050 2100 10200
Wire Wire Line
	2100 10200 2200 10200
Wire Wire Line
	1750 10450 2100 10450
Wire Wire Line
	2100 10450 2100 10300
Wire Wire Line
	2100 10300 2200 10300
Wire Wire Line
	2200 9000 2150 9000
Wire Wire Line
	2150 9000 2150 8250
Wire Wire Line
	2150 8250 3800 8250
Wire Wire Line
	3800 8250 3800 10250
Wire Wire Line
	3800 10250 3900 10250
Wire Wire Line
	2150 9100 2050 9100
Wire Wire Line
	2050 9100 2050 8150
Wire Wire Line
	2050 8150 4800 8150
Wire Wire Line
	4800 8150 4800 10150
Wire Wire Line
	4800 10150 4700 10150
Wire Wire Line
	3100 3550 3650 3550
Wire Wire Line
	3650 3550 3650 2550
Wire Wire Line
	3650 2550 3800 2550
Wire Wire Line
	3800 2450 3600 2450
Wire Wire Line
	3600 2450 3600 3450
Wire Wire Line
	3600 3450 3100 3450
Wire Wire Line
	3100 3350 3550 3350
Wire Wire Line
	3550 3350 3550 2350
Wire Wire Line
	3550 2350 3800 2350
Wire Wire Line
	3100 3250 3500 3250
Wire Wire Line
	3500 3250 3500 2250
Wire Wire Line
	3500 2250 3800 2250
Wire Wire Line
	3100 7150 3650 7150
Wire Wire Line
	3650 7150 3650 6150
Wire Wire Line
	3650 6150 3800 6150
Wire Wire Line
	3100 7050 3600 7050
Wire Wire Line
	3600 7050 3600 6050
Wire Wire Line
	3600 6050 3800 6050
Wire Wire Line
	3100 6950 3550 6950
Wire Wire Line
	3550 6950 3550 5950
Wire Wire Line
	3550 5950 3800 5950
Wire Wire Line
	3100 6850 3500 6850
Wire Wire Line
	3500 6850 3500 5850
Wire Wire Line
	3500 5850 3800 5850
Wire Wire Line
	3900 10350 3700 10350
Wire Wire Line
	3700 10350 3700 8450
Connection ~ 3700 8450
Wire Wire Line
	3700 8450 4300 8450
Wire Bus Line
	12250 900  12250 1700
Wire Bus Line
	3200 900  3200 1700
$EndSCHEMATC
