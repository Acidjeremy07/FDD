LIBRARY ieee;
USE ieee.std_logic_1164.all;

ENTITY compuerta_nor IS
	PORT(a, b, c, d : in std_logic;
		salida : out std_logic
		);
end compuerta_nor;

architecture funcion of compuerta_nor IS
begin

	salida <= not (a or b or c or d);

	end funcion;