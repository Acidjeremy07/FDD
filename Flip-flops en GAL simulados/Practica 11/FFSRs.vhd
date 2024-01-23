library ieee;
use ieee.std_logic_1164.all;

entity flipflopSRs is
	port(clk, rst, S, R: in std_logic;
	Q: out std_logic);

end flipflopSRs;

architecture codigo of flipflopSRs is
begin
	process(clk, rst)
	begin
		if rst = '1' then
		Q <= '0';
		elsif rising_edge(clk) then
			if S = '1' then
			Q <= '1';
			elsif R = '1' then
			Q <= '0';
			end if;
		end if;
	end process;
end codigo;
