int timerD = 0;
int timerC = 0;
int i = 0;
int tensD = 0, onesD = 0;
int tensC = 0, onesC = 0;

void main() {
    ADCON1 = 0x06;

    TRISA = 0xFF;
    TRISB = 0x00;
    TRISC = 0x00;
    TRISD = 0x00;

    PORTB = 0x00;
    PORTC = 0x00;
    PORTD = 0x00;

    while(1) {
        if(PORTA.F0 == 1) {

            PORTB.F0 = 0; PORTB.F1 = 0; PORTB.F2 = 1;
            PORTB.F3 = 1; PORTB.F4 = 0; PORTB.F5 = 0;

            for(timerD = 12, timerC = 15; timerC >= 3; timerD--, timerC--) {
            if(PORTA.F0 == 0) break;
                tensD = timerD / 10; onesD = timerD % 10;
                tensC = timerC / 10; onesC = timerC % 10;

                for(i = 0; i < 25; i++) {
                    PORTD = (tensD & 0x0F) | 0x20;
                    PORTC = (tensC & 0x0F) | 0x20;
                    delay_ms(10);

                    PORTD = (onesD & 0x0F) | 0x10;
                    PORTC = (onesC & 0x0F) | 0x10;
                    delay_ms(10);
                }
            }


            PORTB.F0 = 0; PORTB.F1 = 1; PORTB.F2 = 0;
            PORTB.F3 = 1; PORTB.F4 = 0; PORTB.F5 = 0;

            for(timerD = 3, timerC = 3; timerC >= 1; timerD--, timerC--) {
            if(PORTA.F0 == 0) break;
                tensD = timerD / 10; onesD = timerD % 10;
                tensC = timerC / 10; onesC = timerC % 10;

                for(i = 0; i < 25; i++) {
                    PORTD = (tensD & 0x0F) | 0x20;
                    PORTC = (tensC & 0x0F) | 0x20;
                    delay_ms(10);

                    PORTD = (onesD & 0x0F) | 0x10;
                    PORTC = (onesC & 0x0F) | 0x10;
                    delay_ms(10);
                }
            }
              PORTB.F0 = 1; PORTB.F1 = 0; PORTB.F2 = 0;
            PORTB.F3 = 0; PORTB.F4 = 0; PORTB.F5 = 1;

            for(timerD = 23, timerC = 20; timerD >= 3; timerD--, timerC--) {
            if(PORTA.F0 == 0) break;
                tensD = timerD / 10; onesD = timerD % 10;
                tensC = timerC / 10; onesC = timerC % 10;

                for(i = 0; i < 25; i++) {
                    PORTD = (tensD & 0x0F) | 0x20;
                    PORTC = (tensC & 0x0F) | 0x20;
                    delay_ms(10);

                    PORTD = (onesD & 0x0F) | 0x10;
                    PORTC = (onesC & 0x0F) | 0x10;
                    delay_ms(10);
                }
            }

            PORTB.F0 = 1; PORTB.F1 = 0; PORTB.F2 = 0;
            PORTB.F3 = 0; PORTB.F4 = 1; PORTB.F5 = 0;

            for(timerD = 3, timerC = 3; timerC >= 1; timerD--, timerC--) {
            if(PORTA.F0 == 0) break;
                tensD = timerD / 10; onesD = timerD % 10;
                tensC = timerC / 10; onesC = timerC % 10;

                for(i = 0; i < 25; i++) {
                    PORTD = (tensD & 0x0F) | 0x20;
                    PORTC = (tensC & 0x0F) | 0x20;
                    delay_ms(10);

                    PORTD = (onesD & 0x0F) | 0x10;
                    PORTC = (onesC & 0x0F) | 0x10;
                    delay_ms(10);
                }
            }

        }
        else {
         PORTD=0; PORTC=0;
            if(PORTA.F1 == 0) {
                  PORTB = 0x00;
               PORTB.F1 = 1;
               delay_ms(3000);
                PORTB.F0 = 1; PORTB.F1 = 0; PORTB.F2 = 0;
                PORTB.F3 = 0; PORTB.F4 = 0; PORTB.F5 = 1;
                while(PORTA.F0 == 0 && PORTA.F1 == 0);

            }
            else {
                 PORTB = 0x00;
               PORTB.F4 = 1;
               delay_ms(3000);
                PORTB.F0 = 0; PORTB.F1 = 0; PORTB.F2 = 1;
                PORTB.F3 = 1; PORTB.F4 = 0; PORTB.F5 = 0;
                while(PORTA.F0 == 0 && PORTA.F1 == 1);

            }
        }
    }
}