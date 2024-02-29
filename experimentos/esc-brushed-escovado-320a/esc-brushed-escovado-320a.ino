/**
 * main.cpp
 *
 *  @date Created at:	12/02/2024, 22:58:41
 *	@author:	Pedro Igor B. S.
 *	@email:		pibscontato@gmail.com
 * 	GitHub:		https://github.com/pedro-ibs
 * 	tabSize:	8
 *
 * ########################################################
 * TODO: Licence
 * ########################################################
 *
 * TODO: documentation or resume or Abstract
 *
 */




/* Includes ----------------------------------------------------------------------------------------------------------------------------------------------*/
#include <Arduino.h>
#include <Servo.h>

/* Setings -----------------------------------------------------------------------------------------------------------------------------------------------*/
#define MOTOR_STOP              ( 1500			)
#define MOTOR_CLOCKWISE_MIN     ( 1550      )
#define MOTOR_CLOCKWISE_MAX     ( 1890      )
#define MOTOR_ANTCLOCKWISE_MIN  ( 1450      )
#define MOTOR_ANTCLOCKWISE_MAX  ( 1110      )
#define INTERRUPCAO_PIN         ( 3			    )
#define SERVO_PIN               ( 9			    )
/* Setup -------------------------------------------------------------------------------------------------------------------------------------------------*/
Servo myservo;
static unsigned int uiPwmPeriod		      = MOTOR_STOP;
static unsigned char ucPulsosdoEncoder	= 0;
static uint32_t u32tempoInicial         = 0;
static uint32_t u32tempoFinal           = 0;
/* Function prototype ------------------------------------------------------------------------------------------------------------------------------------*/
/* -------------------------------------------------------------------------------------------------------------------------------------------------------*/


void show_header( void ){
	Serial.print( "tempo"     );
	Serial.print( ','             );
	Serial.print( "pwm"           );
	Serial.print( ','             );
	Serial.print( "periodo"  );
	Serial.print( "\r\n"          );

}


void show_data( void ){
	Serial.print( ( float )millis() / 1000.00	    );
	Serial.print( ','				                      );
	Serial.print( uiPwmPeriod				              );
	Serial.print( ','				                      );
	Serial.print( u32tempoFinal - u32tempoInicial	);
	Serial.print( "\r\n"				                  );
}

void interrupcao( void ){
	if( ucPulsosdoEncoder==0 ){
		u32tempoInicial = micros();
	}

	if(ucPulsosdoEncoder++ >= 20){
		u32tempoFinal		= micros();
		ucPulsosdoEncoder	= 0;
		show_data();

	}
}

void bind( void ){
  myservo.attach( SERVO_PIN );
  myservo.writeMicroseconds( MOTOR_STOP );
	delay( 30 );
}

void test_clockwise( void ){

  // for (uint16_t uPeriod = MOTOR_CLOCKWISE_MIN; uPeriod < MOTOR_CLOCKWISE_MAX; uPeriod++) {
  //   myservo.writeMicroseconds(uPeriod);
  //   Serial.println(uPeriod);
  //   delay( 10 );
  // }
  
  // for (uint16_t uPeriod = MOTOR_CLOCKWISE_MAX; uPeriod > MOTOR_CLOCKWISE_MIN; uPeriod--) {
  //   myservo.writeMicroseconds(uPeriod);
  //   Serial.println(uPeriod);
  //   delay( 10 );
  // }



  // for (uint16_t uPeriod = MOTOR_CLOCKWISE_MIN; uPeriod < MOTOR_CLOCKWISE_MAX; uPeriod++) {
  //   myservo.writeMicroseconds(uPeriod);
  //   Serial.println(uPeriod);
  //   delay( 10 );
  // }
  
  // for (uint16_t uPeriod = MOTOR_CLOCKWISE_MAX; uPeriod > MOTOR_CLOCKWISE_MIN; uPeriod--) {
  //   myservo.writeMicroseconds(uPeriod);
  //   Serial.println(uPeriod);
  //   delay( 10 );
  // }
}

void test_antclockwise( void ){
  // for (uint16_t uPeriod = MOTOR_ANTCLOCKWISE_MIN; uPeriod > MOTOR_ANTCLOCKWISE_MAX; uPeriod--) {
  //   myservo.writeMicroseconds(uPeriod);
  //   Serial.println(uPeriod);
  //   delay( 10 );
  // }

  // for (uint16_t uPeriod = MOTOR_ANTCLOCKWISE_MAX; uPeriod<MOTOR_ANTCLOCKWISE_MIN; uPeriod++) {
  //   myservo.writeMicroseconds(uPeriod);
  //   Serial.println(uPeriod);
  //   delay( 10 );
  // }
}





void setup( void ) {
	Serial.begin( 115200 );
	// attachInterrupt( digitalPinToInterrupt(2), interrupcao, RISING );

  bind();

  // show_header()
	// show_data();
}
void loop() {

  test_antclockwise();

  // myservo.writeMicroseconds( MOTOR_STOP );
  // delay( 500 );


  test_clockwise();

  // myservo.writeMicroseconds( MOTOR_STOP );
  // delay( 500 );



}
