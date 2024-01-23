LIBRARY ieee;
USE ieee.std_logic_1164.all;

ENTITY compuerta_xor IS
	PORT(a, b, c, d : in std_logic;
		salida : out std_logic
		);
end compuerta_xor;

architecture funcion of compuerta_xor IS
begin

	salida <= a xor b xor c xor d;

	end funcion;