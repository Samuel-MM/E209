int main(void) {
  DDRD = DDRD | 0b11100000; //Pino PD7 definido como saída
  PORTD = PORTD | 0b00000000;
  //PORTD = PORTD & ~(0b11100000);
  for (;;) {
    
    if ((PIND & 0b00000100) != 0 && (PIND & 0b00001000) != 0 && (PIND & 0b00010000) != 0) {
      PORTD = PORTD & ~(0b11000000); //Desliga PD7 e PD6
      PORTD = PORTD | (0b00100000);
     
    }
    else if ((PIND & 0b00001000) != 0 && (PIND & 0b00000100) != 0) {
      PORTD = PORTD & ~(0b01000000); //Desliga PD6
      PORTD = PORTD | (0b00100000);
    }
    
    else if ((PIND & 0b00010000) != 0 && (PIND & 0b00000100) != 0) {
      PORTD = PORTD & ~(0b10000000); //Desliga PD7
      PORTD = PORTD | (0b00100000);
    }
    
    
    else{

      if ((PIND & 0b00010000) != 0) //Botão esquerda
      {
        PORTD |= 0b10000000; //liga a saída PD7 30HP
      }
      if ((PIND & 0b00010000) == 0)
      {
        PORTD = PORTD & ~(0b10000000); //Desliga PD7
      }
      
      
      if ((PIND & 0b00001000) != 0) //Botão meio
      {
        PORTD |= 0b01000000; //liga a saída PD6 50HP
      }
      if ((PIND & 0b00001000) == 0)
      {
        PORTD = PORTD & ~(0b01000000); //Desliga PD6
      }
      
      
      if ((PIND & 0b00000100) != 0) //Botão direita
      {
        PORTD |= 0b00100000; //liga a saída PD5 80HP
      }
      if ((PIND & 0b00000100) == 0)
      {
        PORTD = PORTD & ~(0b00100000); //Desliga PD5
      }
      
    }
  }
}