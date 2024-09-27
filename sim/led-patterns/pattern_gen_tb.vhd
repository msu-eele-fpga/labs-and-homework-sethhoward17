library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity pattern_gen_tb is
end entity pattern_gen_tb;

architecture pattern_gen_tb_arch of pattern_gen_tb is

	component pattern_gen is
		port (
			base_clk	 	: in std_ulogic;
			pat_clk			: in std_ulogic;
			rst  				: in std_ulogic;
			sel 				: in natural;
			led 				: out std_ulogic_vector(7 downto 0)
		);
	end component pattern_gen;

  signal base_clk_tb		 : std_ulogic := '0';
	signal pat_clk_tb			 : std_ulogic := '0';
	signal rst_tb					 : std_ulogic := '0';
	signal led_out				 : std_ulogic_vector(7 downto 0);
	signal sel_tb 			   : natural := 0;

begin

	PATTERN_GENERATOR : component pattern_gen
	port map (
		base_clk 		=> base_clk_tb,
		pat_clk			=> pat_clk_tb,
		rst 				=> rst_tb,
		sel 				=> sel_tb,
		led					=> led_out
	);

	base_clk_tb <= not base_clk_tb after 20 ns;
	pat_clk_tb <= not pat_clk_tb after 5 ns;

	  -- Create the sel signal
  sel_stim : process is
  begin
	
		--assert reset
		wait for 0.5 * 20 ns;
		rst_tb <= '1';
		wait for 1 * 20 ns;
		rst_tb <= '0';
		wait for 1 * 20 ns;

		--set select to 1 for pattern 0
		sel_tb<= 1;
		wait for 100 ns;

		--set select to 2 for pattern 1
		sel_tb<= 2;
		wait for 100 ns;

		--set select to 3 for pattern 2
		sel_tb<= 3;
		wait for 100 ns;

		--set select to 4 for pattern 3
		sel_tb<= 4;
		wait for 100 ns;

		--set select to 5 for pattern 4
		sel_tb<= 5;
		wait for 100 ns;

	end process sel_stim;



end architecture pattern_gen_tb_arch;