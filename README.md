# ToneGenerator
DTMF, Blue, and US/UK Red Box tone generator for the Cardputor device in Arduino Sketch

![Screenshot](https://github.com/James-P-D/ToneGenerator/blob/main/screenshot.gif)

## Introduction

A small script for generating DTMF, Blue Box, and US & UK Red box tones.

## Disclaimer

Whilst DTMF is still commonly used in telephony, [blue boxing](https://en.wikipedia.org/wiki/Blue_box) and [red boxing](https://en.wikipedia.org/wiki/Red_box_(phreaking)) were used in the 1970s - late 90s (?) for making fraudulent calls. To the best of my knowledge, neither has working in at least a decade, but just a reminder that attempting to blue/red box is almost certainly illegal in your country.

## Running

After running the program you'll be preseted with the following message:

```
Enter a number or use
'd' for DTMF (default),
'b' for Blue Box,
'r' for US Red Box or
'u' for UK Red Box
```

From here you can press <kbd>d</kbd> to enter DTMF mode and then use `0-9` and `a-d` to generate DTMF tones.

If you press <kbd>b</kbd> you will see:

```
Blue Box Mode:
0 to 9
'k' for KP
's' for ST
```

From here you can press `0-9`, `k` keep pulsing or `s` for start.

If you press <kbd>r</kbd> you will see:

```
US Red Box Mode:
1 for nickle
2 for dime
3 for quarter
4 for dollar
```

From here you can press `1-4`, for nickle, dime, quarter or dollar respectively.

Finally, if you press <kbd>u</kbd> you will see:

```
UK Red Box Mode
1 for 10p
2 for 50p
```

From here you can press `1-2`, for 10 or 20 pence respectively.
