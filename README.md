# DT-Contextual-Challenges-2020-2021
A project to increase awareness of the climate emergency. 

When no action is done, the seven segment displays will show the temperature of major cities now with the global average temperature. 
When the 'pre-industrial era' button is pressed, the board will display temperatures of major cities around the world during that time. When the 'Year 2100' button is pressed, the board will display temperature rises of all the cities based on credible data. The aim is for users that interacted with the display to quickly acknowledge the seriousness of the situation and encourages them to act. Such actions can be taken straight away by learning more about climate emergency through the QR code readily provided. The QR code links to -> <a href="https://kahngjoonkoh.github.io/increase-awareness-of-climate-emergency/">this website</a>

The main powerpoint file is -> <a href="https://github.com/kahngjoonkoh/DT-Contextual-Challenges-2020-2021/blob/master/Contextual%20Challenge%202020-2021%20Kahngjoon%20Koh.pptx">Contextual Challenge 2020-2021 Kahngjoon Koh.pptx</a>

Any other files in this repository are resources that I have used during the iterative design process.

The final design has been documented here. For more details check the powerpoint.
## Table of Contents:
1. [3D Design](#1)
2. [2D Designs](#9)
3. [Materials](#2)
    * [Wood](#6)
    * [Electronics](#7)
    * [Other Materials](#8)
4. [Schematics](#3)
5. [Code](#4)
6. [Result](#5)

## 3D Design <a name="1"/>
Designed with SketchUp

<img width="400" alt="image" src="https://user-images.githubusercontent.com/46638829/180834227-21d4de08-5e0b-410a-801c-8a3391d50d45.png">

-> <a href="https://github.com/kahngjoonkoh/DT-Contextual-Challenges-2020-2021/blob/master/src/model/3D%20Model/Complete%20form%20of%20design.stl">Final Design</a></br>
-> <a href="https://github.com/kahngjoonkoh/DT-Contextual-Challenges-2020-2021/blob/master/src/model/3D%20Model/DT%20final%20design.stl">Exploded View</a>

## 2D Designs <a name="9"/>
Designed with 2D Design

<img width="314" alt="image" src="https://user-images.githubusercontent.com/46638829/180842329-3f2a2d24-4df0-4a03-9e2d-0190c5852529.png">

<img width="187" alt="image" src="https://user-images.githubusercontent.com/46638829/180842353-303e87df-482c-4932-a06e-d10506b2c1bb.png">

<img width="472" alt="image" src="https://user-images.githubusercontent.com/46638829/180842466-8ed1f1a4-f7dc-4722-8354-06ef671b2fde.png">

<img width="436" alt="image" src="https://user-images.githubusercontent.com/46638829/180842533-6ff1219e-87ba-4039-83be-f91e457f5949.png">

-> <a href="https://github.com/kahngjoonkoh/DT-Contextual-Challenges-2020-2021/tree/master/src/model">src</a>

## Materials <a name="2"/>
### Wood <a name="6"/>
* Birch-veneered plywood (4 x 440 x 440mm)
* Birch-veneered plywood (4 x 250 x 440mm)
* Oak x2 (40 x 30 x 660mm)
* Oak x 2 (40 x 30 x 460mm)
* MDF (4 x 420 x 620mm)

### Electronics <a name="7"/>
* 6V 1A AC/DC power supplier
* Arduino or Arduino Uno
* Sn74hc595 Shift Register x 10
* DIP 16 socket x 10
* CD4514 Demultiplexer x 6
* DIP 24 socket x 6
* Seven Segment Displays x 24 (50.3 x 19 x 8mm with a 0.56 inch digit size; Red; common cathode; 10561k)
* Seven Segment Displays x 1 (71.6 x 25.8 x 7.4mm with a 0.8 inch digit size; Red; common cathode; 10561k)
* Push Buttons x 2
* 2N2222A Transistors x 100
* 100Ω, 200Ω, 1kΩ Resistors

### Other Materials <a name="8"/>
* Acrylic (5 x 400 x 600mm)
* Epoxy Resin and hardener
* PVA glue
* Mounting brackets x 2
* Screws x 8 
* Water-based varnish (matt)


## Schematics <a name="3"/>
Designed with KiCad

<img width="400" alt="image" src="https://user-images.githubusercontent.com/46638829/180834596-66634f06-9d96-4990-80f5-9d4bd66250c9.png">

-> <a href="https://github.com/kahngjoonkoh/DT-Contextual-Challenges-2020-2021/tree/master/src/Schematic">src</a>

## Code <a name="4"/>
Code for Arduino
-> <a href="https://github.com/kahngjoonkoh/DT-Contextual-Challenges-2020-2021/blob/master/src/Arduino/main/main.ino">main.ino</a>

The Arudino has a pin limit. However, there are 25 seven segments displays that require signals. Instead of sending signals to all of the displays simultaneously, 6 displays will be displayed at a time. The time between frames was made short using 
<pre><code>#define portOfPin(P) (((P)>=0&&(P)<8)?&PORTD:(((P)>7&&(P)<14)?&PORTB:&PORTC))
#define ddrOfPin(P) (((P)>=0&&(P)<8)?&DDRD:(((P)>7&&(P)<14)?&DDRB:&DDRC))
#define pinOfPin(P) (((P)>=0&&(P)<8)?&PIND:(((P)>7&&(P)<14)?&PINB:&PINC))

#define pinIndex(P)((uint8_t)(P>13?P-14:P&7))
#define pinMask(P)((uint8_t)(1<<pinIndex(P)))

#define digitalLow(P) *(portOfPin(P))&=~pinMask(P)
#define digitalHigh(P) *(portOfPin(P))|=pinMask(P)
#define isHigh(P)((*(pinOfPin(P))& pinMask(P))>0)
</code></pre>

This sped up `digitalRead` by 60 times and `digitalWrite` by 28 times. (<a href="http://masteringarduino.blogspot.com/2013/10/fastest-and-smallest-digitalread-and.html">Credit</a>)


## Result <a name="5"/>
<img width="522" alt="image" src="https://user-images.githubusercontent.com/46638829/180839173-5c1d4da6-a2a1-4089-a81d-ecb4a469ce88.png">

## License
[![CC BY-NC-SA 4.0][cc-by-nc-sa-shield]][cc-by-nc-sa]

[cc-by-nc-sa]: http://creativecommons.org/licenses/by-nc-sa/4.0/
[cc-by-nc-sa-image]: https://licensebuttons.net/l/by-nc-sa/4.0/88x31.png
[cc-by-nc-sa-shield]: https://img.shields.io/badge/License-CC%20BY--NC--SA%204.0-lightgrey.svg
