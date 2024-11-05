library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity pwm_controller_tb is
end entity pwm_controller_tb;

architecture pwm_controller_tb_arch of pwm_controller_tb is

	component pwm_controller is
		generic (
			CLK_PERIOD : time := 20 ns
		);
		port (
			clk : in std_logic;
			rst : in std_logic;
			-- PWM repetition period in milliseconds;
			-- datatype (W.F) is individually assigned
			period : in unsigned(33 - 1 downto 0);
			-- PWM duty cycle between [0 1]; out-of-range values are hard-limited
			-- datatype (W.F) is individually assigned
			duty_cycle : in std_logic_vector(20 - 1 downto 0);
			output : out std_logic
		);
	end component pwm_controller;

	signal clk_tb 				: std_logic := '0';
	signal rst_tb 				: std_logic := '0';
	signal period_tb 			: unsigned(32 downto 0);
	signal duty_cycle_tb 	: std_logic_vector(19 downto 0);
	signal output_tb			: std_logic;

begin

	PWM_CONTROL : component pwm_controller
	port map(
		clk 				=> clk_tb,
		rst 				=> rst_tb,
		period 			=> period_tb,
		duty_cycle 	=> duty_cycle_tb,
		output		 	=> output_tb
	);

	clk_tb <= not clk_tb after 10 ns;

	DUTY_CYCLE : process
	begin
		rst_tb <= '1';
		wait for 1 us;
		rst_tb <= '0';
		wait for 1 us;

		period_tb <= "000001000000000000000000000000000"; --1 ms
		duty_cycle_tb <= "01000000000000000000";					--50% duty cycle
		wait for 3 ms;

		period_tb <= "000001000000000000000000000000000"; --1 ms
		duty_cycle_tb <= "00100000000000000000";					--25% duty cycle
		wait for 3 ms;

		period_tb <= "000001000000000000000000000000000"; --1 ms
		duty_cycle_tb <= "01100000000000000000";					--75% duty cycle
		wait for 3 ms;
	end process;

end architecture;