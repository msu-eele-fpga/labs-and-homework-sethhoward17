library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity timed_counter is
	generic (
		clk_period : time;
		count_time : time
	);
	port (
		clk	: in std_ulogic;
		enable	: in boolean;
		done	: out boolean
	);
end entity timed_counter;

architecture timed_counter_arch of timed_counter is

	constant COUNTER_LIMIT	: natural := ((count_time/clk_period)) ;
	signal	 counter	: natural range 0 to COUNTER_LIMIT := 0;

begin

	timed_counter : process(clk) is
	begin

		if rising_edge(clk) then
			if enable then
				if counter < COUNTER_LIMIT then
					counter <= counter + 1;
					done <= false;
				else
					counter <= 1;
					done <= true;
				end if;

			else
				counter <= 0;
				done <= false;
			end if;
		end if;

	end process timed_counter;

	

-- count_time / clk_period = clk cycles before done


end architecture;
