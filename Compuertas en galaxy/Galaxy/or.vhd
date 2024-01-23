LIBRARY ieee;
USE ieee.std_logic_1164.all;

ENTITY compuerta_or IS
	PORT(a, b, c, d : in std_logic;
		salida : out std_logic
		);
end compuerta_or;

architecture funcion of compuerta_or IS
begin

	salida <= a or b or c or d;

	end funcion;