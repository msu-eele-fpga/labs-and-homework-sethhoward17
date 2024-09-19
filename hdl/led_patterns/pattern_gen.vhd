library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

library altera;
use altera.altera_primitives_components.all;

entity pattern_gen is
	port (
		clk	 : in std_ulogic;
		rst  : in std_ulogic;
		sel  : in std_ulogic_vector(2 downto 0);
		led : out std_ulogic_vector(7 downto 0)
	);
end entity pattern_gen;;