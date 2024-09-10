library ieee;
use ieee.std_logic_1164.all;
use work.print_pkg.all;
use work.assert_pkg.all;
use work.tb_pkg.all;

entity vending_machine is
	port (
		clk : in std_ulogic;
		rst : in std_ulogic;
		nickel : in std_ulogic;
		dime : in std_ulogic;
		dispense : out std_ulogic;
		amount : out natural range 0 to 15
	);
end entity vending_machine;

architecture vending_machine_arch of vending_machine is

	type state_type is (c0, c5, c10, c15);
	signal state : state_type;


begin

	--synchronous
	state_logic : process (clk, rst)
	begin 
		if rst = '1' then
			state <= c0;
		elsif rising_edge(clk) then
			case state is
				when c0 =>
					state <= c10 when dime = '1' else
					c5 when nickel = '1' else
					c0;
				when c5 =>
					state <= c15 when dime = '1' else
					c10 when nickel = '1' else
					c5;
				when c10 =>
					state <= c15 when dime = '1' else
					c15 when nickel = '1' else
					c10;
				when c15 =>
					state <= c0;
				when others =>
					state <= c0;
			end case;
		end if;
	end process state_logic;

	--combinational
	output_logic : process(state, nickel, dime)
	begin
		case state is 
			when c0 =>
				dispense <= '0';
				amount 	 <=  0;
			when c5 =>
				dispense <= '0';
				amount   <=  5;
			when c10 =>
				dispense <= '0';
				amount 	 <=  10;
			when c15 =>
				dispense <= '1';
				amount   <=  15;
			when others =>
				dispense <= '0';
				amount 	 <=  0;
		end case;
	end process output_logic;

end architecture vending_machine_arch;