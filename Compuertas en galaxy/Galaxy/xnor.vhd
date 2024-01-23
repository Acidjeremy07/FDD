LIBRARY ieee;
USE ieee.std_logic_1164.all;

ENTITY compuerta_xnor IS
	PORT(a, b, c, d : in std_logic;
		salida : out std_logic
		);
end compuerta_xnor;

architecture funcion of compuerta_xnor IS
begin

	salida <= not(a xor b xor c xor d);

	end funcion;