-- SPDX-License-Identifier: MIT
-- Copyright (c) 2024 Ross K. Snider, Trevor Vannoy.  All rights reserved.
----------------------------------------------------------------------------
-- Description:  Top level VHDL file for the DE10-Nano
----------------------------------------------------------------------------
-- Author:       Ross K. Snider, Trevor Vannoy
-- Company:      Montana State University
-- Create Date:  September 1, 2017
-- Revision:     1.0
-- License: MIT  (opensource.org/licenses/MIT)
----------------------------------------------------------------------------

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

library altera;
use altera.altera_primitives_components.all;

-----------------------------------------------------------
-- Signal Names are defined in the DE10-Nano User Manual
-- http://de10-nano.terasic.com
-----------------------------------------------------------
entity de10nano_top is
  port (
    ----------------------------------------
    --  Clock inputs
    --  See DE10 Nano User Manual page 23
    ----------------------------------------
    --! 50 MHz clock input #1
    fpga_clk1_50 : in    std_logic;
    --! 50 MHz clock input #2
    fpga_clk2_50 : in    std_logic;
    --! 50 MHz clock input #3
    fpga_clk3_50 : in    std_logic;

    ----------------------------------------
    --  Push button inputs (KEY)
    --  See DE10 Nano User Manual page 24
    --  The KEY push button inputs produce a '0'
    --  when pressed (asserted)
    --  and produce a '1' in the rest (non-pushed) state
    ----------------------------------------
    push_button_n : in    std_ulogic_vector(1 downto 0);

    ----------------------------------------
    --  Slide switch inputs (SW)
    --  See DE10 Nano User Manual page 25
    --  The slide switches produce a '0' when
    --  in the down position
    --  (towards the edge of the board)
    ----------------------------------------
    sw : in    std_ulogic_vector(3 downto 0);

    ----------------------------------------
    --  LED outputs
    --  See DE10 Nano User Manual page 26
    --  Setting LED to 1 will turn it on
    ----------------------------------------
    led : out   std_ulogic_vector(7 downto 0);

    ----------------------------------------
    --  GPIO expansion headers (40-pin)
    --  See DE10 Nano User Manual page 27
    --  Pin 11 = 5V supply (1A max)
    --  Pin 29 - 3.3 supply (1.5A max)
    --  Pins 12, 30 GND
    ----------------------------------------
    gpio_0 : inout std_logic_vector(35 downto 0);
    gpio_1 : inout std_logic_vector(35 downto 0);

    ----------------------------------------
    --  Arudino headers
    --  See DE10 Nano User Manual page 30
    ----------------------------------------
    arduino_io      : inout std_logic_vector(15 downto 0);
    arduino_reset_n : inout std_logic
  );
end entity de10nano_top;

architecture de10nano_arch of de10nano_top is

	component led_patterns is
		generic (
      	system_clock_period : time := 20 ns
		); 
		port(
   	  clk             : in  std_ulogic;                         -- system clock
        rst             : in  std_ulogic;                         -- system reset (assume active high, change at top level if needed)
        push_button     : in  std_ulogic;                         -- Pushbutton to change state (assume active high, change at top level if needed)
        switches        : in  std_ulogic_vector(3 downto 0);      -- Switches that determine the next state to be selected
        hps_led_control : in  boolean;                         	-- Software is in control when asserted (=1)
        base_period     : in  unsigned(7 downto 0);      			-- base transition period in seconds, fixed-point data type (W=8, F=4).
        led_reg         : in  std_ulogic_vector(7 downto 0);      -- LED register
        led             : out std_ulogic_vector(7 downto 0)       -- LEDs on the DE10-Nano board
		);   
	end component led_patterns;
	
	constant system_clock_period : time := 20 ns;
	signal hps_led_control		  : boolean := false;
	signal base_period			  : unsigned(7 downto 0) := "00001000";
	signal led_reg					  : std_ulogic_vector(7 downto 0);

begin

  LED_PATTERN_COMPONENT : component led_patterns
		generic map (
			system_clock_period => system_clock_period
		)
		port map (
			clk 					=> fpga_clk1_50,
			rst 					=> not push_button_n(1),
			push_button 		=> not push_button_n(0),
			switches 			=> sw,
			hps_led_control 	=> hps_led_control,
			base_period 		=> base_period,
			led_reg 				=> led_reg,
			led 					=> led
		);

end architecture de10nano_arch;
