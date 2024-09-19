library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

library altera;
use altera.altera_primitives_components.all;

entity clock_gen is
	port (
		clk					: in std_ulogic;
		rst					: in std_ulogic;
		base_period	: in unsigned(7 downto 0);
		clockBase		: out std_ulogic := '0';
		clock0			: out std_ulogic := '0';
		clock1			: out std_ulogic := '0';
		clock2			: out std_ulogic := '0';
		clock3			: out std_ulogic := '0';
		clock4			: out std_ulogic := '0'
	);
end entity clock_gen;

architecture clock_gen_arch of clock_gen is

	signal countBase : natural := 0;
	signal count0		 : natural := 0;
	signal count1		 : natural := 0;
	signal count2		 : natural := 0;
	signal count3		 : natural := 0;
	signal count4		 : natural := 0;


begin

	clock_generator : process (clk, rst) is
	begin
		if rst = '1' then
			clockBase <= '0';
			clock0	  <= '0';
			clock1	  <= '0';
			clock2	  <= '0';
			clock3	  <= '0';
			clock4	  <= '0';
			countBase <= 0;
		elsif rising_edge(clk) then
			if countBase < 4 then--((base_period / system_clock_period) - 1) then
				countBase <= countBase + 1;
			else
				countBase <= 1;
				clockBase <= not clockBase;
			end if;

			if count0 < 4 then --((base_period / system_clock_period) - 1) / 2 then
				count0 <= count0 + 1;
			else
				count0 <= 1;
				clock0 <= not clock0;
			end if;

			if count1 < 4 then --((base_period / system_clock_period) - 1) / 4 then
				count1 <= count1 + 1;
			else
				count1 <= 1;
				clock1 <= not clock1;
			end if;

			if count2 < 4 then --((base_period / system_clock_period) - 1) * 2 then
				count2 <= count2 + 1;
			else
				count2 <= 1;
				clock2 <= not clock2;
			end if;

			if count3 < 4 then --((base_period / system_clock_period) - 1) / 8 then
				count3 <= count3 + 1;
			else
				count3 <= 1;
				clock3 <= not clock3;
			end if;

			if count4 < 4 then --((base_period / system_clock_period) - 1) * 4 then
				count4 <= count4 + 1;
			else
				count4 <= 1;
				clock4 <= not clock4;
			end if;
		end if;
	end process clock_generator;
end architecture clock_gen_arch;