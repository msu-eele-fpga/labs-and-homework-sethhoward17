library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use work.assert_pkg.all;
use work.print_pkg.all;
use work.tb_pkg.all;


entity one_pulse_tb is
end entity one_pulse_tb;

architecture one_pulse_tb_arch of one_pulse_tb is

  signal clk_tb					: std_ulogic := '0';
	signal rst_tb					: std_ulogic := '0';
	signal input_tb 			: std_ulogic := '0';
	signal pulse_tb 			: std_ulogic := '0';
	signal pulse_expected : std_ulogic;

	component one_pulse is
		port (
			clk : in std_ulogic;
			rst : in std_ulogic;
			input : in std_ulogic;
			pulse : out std_ulogic
		);
	end component one_pulse;

begin

	dut_one_pulse : component one_pulse
		port map (
			clk => clk_tb,
			rst => rst_tb,
			input => input_tb,
			pulse => pulse_tb
		);

	clk_tb <= not clk_tb after CLK_PERIOD / 2;

  -- Create the input signal
  input_stim : process is
  begin

    input_tb <= '0';
    wait for 3.5 * CLK_PERIOD;

    input_tb <= '1';
    wait for 5 * CLK_PERIOD;

    input_tb <= '0';
    wait for 2 * CLK_PERIOD;

		input_tb <= '1';
		wait for 1 * CLK_PERIOD;

		input_tb <= '0';
		wait for 2 * CLK_PERIOD;

    wait;

  end process input_stim;

  -- Create the expected output waveform
  expected_pulse : process is
  begin

    pulse_expected <= 'U';
    wait for CLK_PERIOD / 2;

    pulse_expected <= '0';
    wait for 4 * CLK_PERIOD;

    pulse_expected <= '1';
    wait for 1 * CLK_PERIOD;

    pulse_expected <= '0';
    wait for 4 * CLK_PERIOD;

    pulse_expected <= '0';
    wait for 2 * CLK_PERIOD;

    pulse_expected <= '1';
    wait for 1 * CLK_PERIOD;

    pulse_expected <= '0';
    wait for 2 * CLK_PERIOD;

    wait;

  end process expected_pulse;

  check_output : process is

    variable failed : boolean := false;

  begin

    for i in 0 to 20 loop

      assert pulse_expected = pulse_tb
        report "Error for clock cycle " & to_string(i) & ":" & LF & "pulse = " & to_string(pulse_tb) & " pulse_expected  = " & to_string(pulse_expected)
        severity warning;

      if pulse_expected /= pulse_tb then
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

end architecture one_pulse_tb_arch;