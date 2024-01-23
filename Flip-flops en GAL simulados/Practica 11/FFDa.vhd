library IEEE;
use IEEE.STD_LOGIC_1164.all;

entity flipflop is
port(
	q:out std_logic;
	clk,rst,D:in std_logic
);
end flipflop;

architecture codigo of flipflop is
	begin	
	process (clk,rst)
	begin
		if rst='1' then
		q <= '0';
		elsif clk'event and clk='1' then
		q <= d;
		end if;
	end process;
end codigo;
