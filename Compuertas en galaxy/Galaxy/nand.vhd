LIBRARY ieee;
USE ieee.std_logic_1164.all;

ENTITY compuerta_nand IS
	PORT(a, b, c, d : in std_logic;
		salida : out std_logic
		);
end compuerta_nand;

architecture funcion of compuerta_nand IS
begin

	salida <= not(a and b and c and d);


	end funcion;