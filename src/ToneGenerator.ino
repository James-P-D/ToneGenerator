#include "M5Cardputer.h"
#include "M5GFX.h"
#define DTMF 0
#define BLUE_BOX 1
#define US_RED_BOX 2
#define UK_RED_BOX 3


M5Canvas canvas(&M5Cardputer.Display);
String prompt = "> ";
int mode = DTMF;

void setup() {
    auto cfg = M5.config();
    M5Cardputer.begin(cfg, true);
    M5Cardputer.Display.setRotation(1);
    M5Cardputer.Display.setTextSize(0.4);
    
    draw_border();
    M5Cardputer.Display.setTextFont(&fonts::FreeMono18pt7b);

    M5Cardputer.Display.fillRect(0, M5Cardputer.Display.height() - 4, M5Cardputer.Display.width(), 4, WHITE);

    canvas.setTextFont(&fonts::FreeMono18pt7b);
    canvas.setTextSize(0.4);
    canvas.createSprite(M5Cardputer.Display.width() - 8, M5Cardputer.Display.height() - 36);
    canvas.setTextScroll(true);
    canvas.println(
      "Enter a number or use\n" 
      "'d' for DTMF (default),\n" 
      "'b' for Blue Box,\n" 
      "'r' for US Red Box or\n"
      "'u' for UK Red Box");
    canvas.pushSprite(4, 4);
    M5Cardputer.Display.drawString(prompt, 4, M5Cardputer.Display.height() - 24);
}

void draw_border() {
    if (mode == BLUE_BOX) {
        M5Cardputer.Display.drawRect(0, 0, M5Cardputer.Display.width(), M5Cardputer.Display.height() - 28, BLUE);
    } else if ((mode == US_RED_BOX) || (mode == UK_RED_BOX)) {
        M5Cardputer.Display.drawRect(0, 0, M5Cardputer.Display.width(), M5Cardputer.Display.height() - 28, RED);
    } else {
        M5Cardputer.Display.drawRect(0, 0, M5Cardputer.Display.width(), M5Cardputer.Display.height() - 28, GREEN);
    }    
}

void play_tone(int tone_1, int tone_2, int duration_ms, int interval_ms) {
    if (tone_1 != -1) {
        M5.Speaker.tone(tone_1, duration_ms);
    }
    if (tone_2 != -1) {   
        M5.Speaker.tone(tone_2, duration_ms);
    }
    delay(duration_ms);
    delay(interval_ms);
}

void process_blue_box(String input) {
    M5.Speaker.begin();
    
    for (auto i : input) {      
        switch(i) {
            case '1' : {
                canvas.print("1 ");
                play_tone(700, 900, 100, 100);                
                break;
            }
            case '2' : {
                canvas.print("2 ");
                play_tone(700, 1100, 100, 100);                
                break;
            }
            case '3' : {
                canvas.print("3 ");
                play_tone(900, 1100, 100, 100);                
                break;
            }
            case '4' : {
                canvas.print("4 ");
                play_tone(700, 1300, 100, 100);                
                break;
            }
            case '5' : {
                canvas.print("5 ");
                play_tone(900, 1300, 100, 100);                
                break;
            }
            case '6' : {
                canvas.print("6 ");
                play_tone(1100, 1300, 100, 100);                
                break;
            }
            case '7' : {
                canvas.print("7 ");
                play_tone(700, 1500, 100, 100);                
                break;
            }
            case '8' : {
                canvas.print("8 ");
                play_tone(900, 1500, 100, 100);                
                break;
            }
            case '9' : {
                canvas.print("9 ");
                play_tone(1100, 1500, 100, 100);                
                break;
            }
            case '0' : {
                canvas.print("0 ");
                play_tone(1300, 1500, 100, 100);                
                break;
            }
            case 'k' : {
                canvas.print("KP ");
                play_tone(1100, 1700, 100, 100);                
                break;
            }
            case 's' : {
                canvas.print("ST ");
                play_tone(1500, 1700, 100, 100);                
                break;
            }
            case ' ' : {
                // Do nothing
                break;      
            }
            default : {
                canvas.print("ERROR: '");
                canvas.print(i);
                canvas.print("' ");
            }
        }
    }
    canvas.println();
    M5.Speaker.end();

}

void process_us_red_box(String input) {
      M5.Speaker.begin();
    
    for (auto i : input) {      
        switch(i) {
            case '1' : {
                canvas.print("Nickle ");
                play_tone(1700, 2200, 66, 100);                
                break;
            }
            case '2' : {
                canvas.print("Dime ");
                play_tone(1700, 2200, 66, 66);
                play_tone(1700, 2200, 66, 100);
                break;
            }
            case '3' : {
                canvas.print("Quarter ");
                play_tone(1700, 2200, 33, 33);
                play_tone(1700, 2200, 33, 33);
                play_tone(1700, 2200, 33, 33);
                play_tone(1700, 2200, 33, 33);
                play_tone(1700, 2200, 33, 100);
                break;
            }
            case '4' : {
                canvas.print("Dollar ");
                play_tone(1700, 2200, 650, 100);
                break;
            }
            case ' ' : {
                // Do nothing
                break;      
            }
            default : {
                canvas.print("ERROR: '");
                canvas.print(i);
                canvas.print("' ");
            }
        }
    }
    canvas.println();
    M5.Speaker.end();
}

void process_uk_red_box(String input) {
      M5.Speaker.begin();
    
    for (auto i : input) {      
        switch(i) {
            case '1' : {
                canvas.print("10p ");
                play_tone(1000, -1, 200, 100);                
                break;
            }
            case '2' : {
                canvas.print("50p ");
                play_tone(1000, -1, 350, 100);
                break;
            }
            case ' ' : {
                // Do nothing
                break;      
            }
            default : {
                canvas.print("ERROR: '");
                canvas.print(i);
                canvas.print("' ");
            }
        }
    }
    canvas.println();
    M5.Speaker.end();  
}

void process_dtmf(String input) {
    M5.Speaker.begin();
    
    for (auto i : input) {      
        switch(i) {
            case '1' : {
                canvas.print("1 ");
                play_tone(1209, 697, 100, 100);                
                break;
            }
            case '2' : {
                canvas.print("2 ");
                play_tone(1336, 697, 100, 100);                
                break;
            }
            case '3' : {
                canvas.print("3 ");
                play_tone(1477, 697, 100, 100);                
                break;
            }
            case 'a' : {
                canvas.print("a ");
                play_tone(1633, 697, 100, 100);                
                break;
            }
            case '4' : {
                canvas.print("4 ");
                play_tone(1209, 770, 100, 100);                
                break;
            }
            case '5' : {
                canvas.print("5 ");
                play_tone(1336, 770, 100, 100);                
                break;
            }
            case '6' : {
                canvas.print("6 ");
                play_tone(1477, 770, 100, 100);                
                break;
            }
            case 'b' : {
                canvas.print("b ");
                play_tone(1633, 770, 100, 100);                
                break;
            }
            case '7' : {
                canvas.print("7 ");
                play_tone(1209, 852, 100, 100);                
                break;
            }
            case '8' : {
                canvas.print("8 ");
                play_tone(1336, 852, 100, 100);                
                break;
            }
            case '9' : {
                canvas.print("9 ");
                play_tone(1477, 852, 100, 100);                
                break;
            }
            case 'c' : {
                canvas.print("c ");
                play_tone(1633, 852, 100, 100);                
                break;
            }
            case '*' : {
                canvas.print("* ");
                play_tone(1209, 941, 100, 100);                
                break;
            }
            case '0' : {
                canvas.print("0 ");
                play_tone(1336, 941, 100, 100);                
                break;
            }
            case '#' : {
                canvas.print("# ");
                play_tone(1477, 941, 100, 100);                
                break;
            }
            case 'd' : {
                canvas.print("d ");
                play_tone(1633, 941, 100, 100);                
                break;
            }
            case ' ' : {
                // Do nothing
                break;      
            }
            default : {
                canvas.print("ERROR: '");
                canvas.print(i);
                canvas.print("' ");
            }
        }
    }
    canvas.println();
    M5.Speaker.end();
}

void loop() {
    M5Cardputer.update();
    if (M5Cardputer.Keyboard.isChange()) {
        if (M5Cardputer.Keyboard.isPressed()) {
            Keyboard_Class::KeysState status = M5Cardputer.Keyboard.keysState();

            for (auto i : status.word) {
                prompt += i;
            }

            if (status.del) {
                prompt.remove(prompt.length() - 1);
            }

            if (status.enter) {                
                prompt.remove(0, 2);

                if ((prompt.length() == 1) && ((prompt == "d") || (prompt == "b") || (prompt == "r") || (prompt == "u"))) {
                    if (prompt == "d") {
                        mode = DTMF;
                        draw_border();
                        canvas.println("\n"
                            "DTMF Mode:\n"
                            "0 to 9"
                            "'a' to 'd'");
                    } else if (prompt == "b") {
                        mode = BLUE_BOX;
                        draw_border();
                        canvas.println("\n"
                            "Blue Box Mode:\n"
                            "0 to 9\n"
                            "'k' for KP\n"
                            "'s' for ST");
                    } else if (prompt == "r") {
                        mode = US_RED_BOX;
                        draw_border();
                        canvas.println("\n"    
                            "US Red Box Mode:\n"
                            "1 for nickle\n"
                            "2 for dime\n"
                            "3 for quarter\n"
                            "4 for dollar\n");
                    } else if (prompt == "u") {
                        mode = UK_RED_BOX;
                        draw_border();
                        canvas.println("\n"
                            "UK Red Box Mode:\n"
                            "1 for 10p\n"
                            "2 for 50p\n");
                    }
                } else {
                    if (mode == BLUE_BOX) {
                        process_blue_box(prompt);
                    } else if (mode == US_RED_BOX) {
                        process_us_red_box(prompt);
                    } else if (mode == UK_RED_BOX) {
                        process_uk_red_box(prompt);
                    } else {
                        process_dtmf(prompt);
                    }
                }
                canvas.pushSprite(4, 4);
                prompt = "> ";
            }

            M5Cardputer.Display.fillRect(0, M5Cardputer.Display.height() - 28, M5Cardputer.Display.width(), 25, BLACK);

            M5Cardputer.Display.drawString(prompt, 4, M5Cardputer.Display.height() - 24);
        }
    }
}
