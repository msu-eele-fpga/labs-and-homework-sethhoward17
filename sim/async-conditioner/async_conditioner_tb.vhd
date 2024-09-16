library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use work.assert_pkg.all;
use work.print_pkg.all;
use work.tb_pkg.all;

entity async_conditioner_tb is
end entity async_conditioner_tb;

architecture async_conditioner_tb_arch of async_conditioner_tb is

	component async_conditioner is
		port (
			clk 	: in std_ulogic;
			rst 	: in std_ulogic;
			async : in std_ulogic;
			sync 	: out std_ulogic
		);
	end component async_conditioner;

  signal clk_tb					 : std_ulogic := '0';
	signal rst_tb					 : std_ulogic := '0';
	signal input_tb 			 : std_ulogic := '0';
	signal signal_tb 			 : std_ulogic := '0';
	signal signal_expected : std_ulogic;

begin

	dut_async_conditioner : entity work.async_conditioner
		port map (
			clk 	=> clk_tb,
			rst 	=> rst_tb,
			async => input_tb,
			sync 	=> signal_tb
		);

	clk_tb <= not clk_tb after CLK_PERIOD / 2;

	  -- Create the input signal
  input_stim : process is
  begin
	
		wait for 0.5 * CLK_PERIOD;
		rst_tb <= '1';
		wait for 1 *CLK_PERIOD;
		rst_tb <= '0';

    input_tb <= '0';
    wait for 1.7 * CLK_PERIOD;

    input_tb <= '1';
    wait for 1 * CLK_PERIOD;

    input_tb <= '0';
    wait for 0.3 * CLK_PERIOD;

		input_tb <= '1';
		wait for 0.3 * CLK_PERIOD;

		input_tb <= '0';
		wait for 0.4 * CLK_PERIOD;

		input_tb <= '1';
		wait for 0.4 * CLK_PERIOD;

		input_tb <= '0';
		wait for 0.3* CLK_PERIOD;

		input_tb <= '1';
		wait for 0.3 * CLK_PERIOD;

		input_tb <= '0';
		wait for 0.2 * CLK_PERIOD;

    input_tb <= '1';
    wait for 5 * CLK_PERIOD;

    input_tb <= '0';
    wait for 0.3 * CLK_PERIOD;

		input_tb <= '1';
		wait for 0.3 * CLK_PERIOD;

		input_tb <= '0';
		wait for 0.4 * CLK_PERIOD;

		input_tb <= '1';
		wait for 0.4 * CLK_PERIOD;

		input_tb <= '0';
		wait for 0.3* CLK_PERIOD;

		input_tb <= '1';
		wait for 0.3 * CLK_PERIOD;

		input_tb <= '0';
		wait for 0.2 * CLK_PERIOD;

    input_tb <= '0';
    wait for 5 * CLK_PERIOD;

    wait;

  end process input_stim;

  -- Create the expected output waveform
  expected_signal : process is
  begin

    signal_expected <= 'U';
    wait for CLK_PERIOD;

    signal_expected <= '0';
    wait for 5.5 * CLK_PERIOD;

    signal_expected <= '1';
    wait for 1 * CLK_PERIOD;

    signal_expected <= '0';
    wait for 10 * CLK_PERIOD;

    wait;

  end process expected_signal;

  check_output : process is

    variable failed : boolean := false;

  begin

    for i in 0 to 20 loop

      assert signal_expected = signal_tb
        report "Error for clock cycle " & to_string(i) & ":" & LF & "signal = " & to_string(signal_tb) & " signal_expected  = " & to_string(signal_expected)
        severity warning;

      if signal_expected /= signal_tb then
        failed := true;
      end if;

      wait for CLK_PERIOD;

    end loop;

    if failed then
      report "tests failed!"
        severity failure;
    else
      report "all tests passed!";
    end if;

    std.env.finish;

  end process check_output;

end architecture async_conditioner_tb_arch;