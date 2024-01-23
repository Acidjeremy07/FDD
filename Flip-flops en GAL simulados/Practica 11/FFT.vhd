library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
 
entity FFT
is
	port( T: in std_logic;
	Clock: in std_logic;
	Q: out std_logic);
end FFT;
 
architecture codigo of FFT is

	signal tmp: std_logic;
	begin
		process (Clock)
		begin
		if Clock'event and Clock='1' then
			if T='0' then
			tmp <= tmp;
			elsif T='1' then
			tmp <= not (tmp);
			end if;
		end if;
		end process;
	Q <= tmp;

end codigo;
