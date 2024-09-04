library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

library altera;
use altera.altera_primitives_components.all;

entity led_patterns is

	generic (
		system_clock_period : time := 20 ns
	);
	
    port(
        clk             : in  std_ulogic;                         -- system clock
        rst           	: in  std_ulogic;                         -- system reset (assume active high, change at top level if needed)
        push_button     : in  std_ulogic;                         -- Pushbutton to change state (assume active high, change at top level if needed)
        switches        : in  std_ulogic_vector(3 downto 0);      -- Switches that determine the next state to be selected
        hps_led_control : in  boolean;                         -- Software is in control when asserted (=1)
        base_period     : in  unsigned(7 downto 0);      -- base transition period in seconds, fixed-point data type (W=8, F=4).
        led_reg         : in  std_ulogic_vector(7 downto 0);      -- LED register
        led             : out std_ulogic_vector(7 downto 0)       -- LEDs on the DE10-Nano board
    );
	 
end entity led_patterns;

architecture my_architecture of led_patterns is

	-- Signal Declarations
	-- Component Declarations

begin
 	
	if (hps_led_control ==1) then
		led <= controlled by software
	else
		led <= controlled by hardware
	end if;
	
end my_architecture;