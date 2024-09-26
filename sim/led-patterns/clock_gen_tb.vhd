library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity clock_gen_tb is
end entity clock_gen_tb;

architecture clock_gen_tb_arch of clock_gen_tb is

	component clock_gen is
		port (
			clk					: in std_ulogic;
			rst					: in std_ulogic;
			base_period	: in unsigned(7 downto 0);
			clockBase		: out std_ulogic;
			clock0			: out std_ulogic;
			clock1			: out std_ulogic;
			clock2			: out std_ulogic;
			clock3			: out std_ulogic;
			clock4			: out std_ulogic
		);
	end component clock_gen;

  signal clk_tb					 : std_ulogic := '0';
	signal rst_tb					 : std_ulogic := '0';
	signal clockBase			 : std_ulogic := '0';
	signal clock0	 				 : std_ulogic := '0';
	signal clock1	 				 : std_ulogic := '0';
	signal clock2	 				 : std_ulogic := '0';
	signal clock3	 				 : std_ulogic := '0';
	signal clock4	 				 : std_ulogic := '0';
	signal base_period		 : unsigned(7 downto 0);

begin

	CLOCK_GENERATOR : component clock_gen
	port map (
		clk 				=> clk_tb,
		rst 				=> rst_tb,
		base_period => base_period,
		clockBase 	=> clockBase,
		clock0			=> clock0,
		clock1			=> clock1,
		clock2			=> clock2,
		clock3			=> clock3,
		clock4			=> clock4
	);

	clk_tb <= not clk_tb after 10 ns;
	base_period <= "00000001";

end architecture clock_gen_tb_arch;