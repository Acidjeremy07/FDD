LIBRARY ieee;
USE ieee.std_logic_1164.all;

ENTITY compuerta_and IS
	PORT(a, b, c, d : in std_logic;
		salida : out std_logic
		);
end compuerta_and;

architecture funcion of compuerta_and IS
begin

	salida <= a and b and c and d;

	end funcion;