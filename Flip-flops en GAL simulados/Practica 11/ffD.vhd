library IEEE;
use IEEE.STD_LOGIC_1164.all;

entity flipflop is
port(
	Q:out std_logic;
	clock,D:in std_logic
);
end flipflop;

architecture codigo of flipflop is
	begin
	process(clock)
		begin
		if clock'EVENT AND clock='1' then Q<=D;
		end if;
	end process;
end codigo;
