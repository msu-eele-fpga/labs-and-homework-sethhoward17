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
        rst             : in  std_ulogic;                         -- system reset (assume active high, change at top level if needed)
        push_button     : in  std_ulogic;                         -- Pushbutton to change state (assume active high, change at top level if needed)
        switches        : in  std_ulogic_vector(3 downto 0);      -- Switches that determine the next state to be selected
        hps_led_control : in  boolean;                         	-- Software is in control when asserted (=1)
        base_period     : in  unsigned(7 downto 0);      			-- base transition period in seconds, fixed-point data type (W=8, F=4).
        led_reg         : in  std_ulogic_vector(7 downto 0);      -- LED register
        led             : out std_ulogic_vector(7 downto 0)       -- LEDs on the DE10-Nano board
    );
    
end entity led_patterns;

architecture my_architecture of led_patterns is

	component async_conditioner is
  	port (
			clk   : in std_ulogic;
      rst   : in std_ulogic;
     	async : in std_ulogic;
      sync  : out std_ulogic
      );
	end component async_conditioner;

	component pattern_gen is
		port (
			clk	 : in std_ulogic;
			rst  : in std_ulogic;
			sel  : in std_ulogic_vector(2 downto 0);
			led : out std_ulogic_vector(7 downto 0)
		);
	end component;
	
	--clock signals for each pattern
	signal clockBase : std_ulogic;
	signal clock0		 : std_ulogic;
	signal clock1		 : std_ulogic;	
	signal clock2		 : std_ulogic;	
	signal clock3		 : std_ulogic;	
	signal clock4		 : std_ulogic;	

	signal sel 			 : std_ulogic_vector(2 downto 0);		--select line for the pattern generator
	signal pb				 : std_ulogic := '0';								--conditioned push button signal
	signal PrevState : natural;													--keep track of previous state for when switches > 5

	type state_type is (idle, DisplaySW, State0, State1, State2, State3, State4);
	signal state : state_type;

begin

	ASYNC_COND : component async_conditioner
		port map (
			clk   => clk,
      rst   => rst,
      async => not push_button,
      sync  => pb
     );

	PATTERN_GENERATOR : component pattern_gen
	port map (
		clk => clk,
		rst => rst,
		sel => sel,
		led	=> led
	);
   
	state_logic : process(clk, rst)
	begin
		--if hps_led_control = false then
			if rst = '1' then
				state <= idle;
			elsif rising_edge(clk) then
				case state is
					when idle =>
						state <= DisplaySW when push_button = '1' else
						idle;					
					when DisplaySW =>
						state <= State0 when switches = "0000" else
									State1 when switches = "0001" else
									State2 when switches = "0010" else
									State3 when switches = "0011" else
									State4 when switches = "0100" else
									State0 when PrevState = 0 else
									State1 when PrevState = 1 else
									State2 when PrevState = 2 else
									State3 when PrevState = 3 else
									State4 when PrevState = 4 else
									DisplaySW;
												
					when State0 =>
						state <=  DisplaySW when push_button = '1' else
						State0;
					when State1 =>
						state <=  DisplaySW when push_button = '1' else
						State1;
					when State2 =>
						state <=  DisplaySW when push_button = '1' else
						State2;
					when State3 =>
						state <=  DisplaySW when push_button = '1' else
						State3;
					when State4 =>
						state <=  DisplaySW when push_button = '1' else
						State4;
					when others =>
						state <= DisplaySW;				
				end case;	
			end if;
		--else
      --led <= controlled by hardware
		--end if;
	end process state_logic;
	
	output_logic : process (state, push_button)
	begin
		case state is
					when idle =>
					
					when DisplaySW =>
				
					when State0 =>
						PrevState <= 0;
					
					when State1 =>
						PrevState <= 1;
				
					when State2 =>
						PrevState <= 2;
					
					when State3 =>
						PrevState <= 3;
					
					when State4 =>
						PrevState <= 4;
					
					when others =>
					
				end case;
			end process output_logic;
   
end my_architecture;