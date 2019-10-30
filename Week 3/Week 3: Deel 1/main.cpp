//Constexpr clock homework Week 3
//Written by: Mike Hoogendoorn
//Date of last edit: 30-10-2019

#include "hwlib.hpp"

//math function.
constexpr double pow( double g, int n ){
   double result = 1;
   while( n > 0 ){
       result *= g;
       n--;
   }
   return result;
}

//Math function.
constexpr double fac( int n ){
   double result = 1;
   while( n > 0 ){
       result *= n;
       n--;
   }
   return result;
}

//Math funtion that returns the sine of A.
constexpr double sin( double a ){
   return 
      a 
      - pow( a, 3 ) / fac( 3 ) 
      + pow( a, 5 ) / fac( 5 ) 
      - pow( a, 7 ) / fac( 7 )
      + pow( a, 9 ) / fac( 9 ) 
      - pow( a, 11 ) / fac( 11 ) 
      + pow( a, 13 ) / fac( 13 )
	  - pow( a, 15 ) / fac( 15 )
	  + pow( a, 17 ) / fac( 17 )
	  - pow( a, 19 ) / fac( 19 );
}

//Math function that returns the cosine of A.
constexpr double cos( double a ){
   return 
      1 
      - pow( a, 2 ) / fac( 2 ) 
      + pow( a, 4 ) / fac( 4 ) 
      - pow( a, 6 ) / fac( 6 )
      + pow( a, 8 ) / fac( 8 ) 
      - pow( a, 10 ) / fac( 10 ) 
      + pow( a, 12 ) / fac( 12 )
	  - pow( a, 14 ) / fac( 14 )
	  + pow( a, 16 ) / fac( 16 )
	  - pow( a, 18 ) / fac( 18 );
}

//Class for the constexpr lookup table.
class lookup {
private:    
   std::array< hwlib::xy, 60 > minutes;
   std::array< hwlib::xy, 12 > hours;
public: 

	constexpr lookup():
		minutes{}
	{   
		for( int i = 0; i < 60; i++ ){
			minutes[i].y = 32 + 27 * sin(6.28 * (i * 6) / 360);
			minutes[i].x = 64 + 27 * cos(6.28 * (i * 6) / 360);
		}
		
		for( int i = 0; i < 12; i++ ){
			hours[i].y = 32 + 20 * sin(6.28 * (i * 30) / 360);
			hours[i].x = 64 + 20 * cos(6.28 * (i * 30) / 360);
		}
	}

	//Function to pull from the minutes lookup table.
	constexpr hwlib::xy get_minutes( int n ) const {
		return minutes[n];
	}
   
	//Function to pull from the hours lookup table.
	constexpr hwlib::xy get_hours( int n ) const {
		return hours[n];
	}
};


//Main function.
int main( void ){
	
	//Create the lookup table.
	constexpr lookup lookup_table;
	
	//Create the I2C bus from the scl & sda pins.
	auto scl = hwlib::target::pin_oc( hwlib::target::pins::scl );
	auto sda = hwlib::target::pin_oc( hwlib::target::pins::sda );
	auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda( scl,sda );
   
	//Create the display object using the I2C bus and the oleds address.
	auto display = hwlib::glcd_oled( i2c_bus, 0x3c );

	//Create the buttons to read from.
	auto minutes_button = hwlib::target::pin_in( hwlib::target::pins::d5 );
	auto hour_button = hwlib::target::pin_in( hwlib::target::pins::d6 );

	//Clear the display just in case something got left on it.
	display.clear();

	//Create the required timing variables.
	uint8_t seconds = 0;
	uint8_t minutes = 0;
	uint8_t hours = 0;
	auto time_start = hwlib::now_us() / 1000000;
	auto time_now = hwlib::now_us() / 1000000;

	//Loop forever.
	for(;;){

		//Create the lines to draw using the time variables.
		auto seconds_line = hwlib::line(hwlib::xy(64, 32), lookup_table.get_minutes(seconds));
		auto minutes_line = hwlib::line(hwlib::xy(64, 32), lookup_table.get_minutes(minutes));
		auto hours_line = hwlib::line(hwlib::xy(64, 32), lookup_table.get_hours(hours));
		
		//Draw the lines.
		minutes_line.draw(display); seconds_line.draw(display); hours_line.draw(display);
		
		//Create and draw the 12 hour circles.
		for(auto i = 0; i < 12; i++){
			auto circle = hwlib::circle(lookup_table.get_minutes(i * 5), 3);
			circle.draw(display);
		}
		
		//Flush the display to show our drawable objects on screen.
		display.flush();
		
		//Get the new time.
		time_now = hwlib::now_us() / 1000000;
		
		//Compare timings and increment seconds as needed.
		if(time_start < time_now){
			seconds += (time_now - time_start);
			display.clear();
			time_start = time_now;
		}
		
		//Increase minutes on button press.
		if(minutes_button.read()){
			minutes++;
		}
		
		//Increase hours on button press.
		if(hour_button.read()){
			hours++;
		}

		//Make sure seconds never goes higher then 60 values.
		if(seconds > 59){
			seconds = 0;
			minutes++;
		}
		
		//Make sure minutes never goes higher then 60 values.
		if(minutes > 59){
			minutes = 0;
			hours++;
		}

		//Make sure hours never goes higher then 12 values.
		if(hours > 11){
			hours = 0;
		}
	}
}