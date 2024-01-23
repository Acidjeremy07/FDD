LIBRARY ieee;
USE ieee.std_logic_1164.all; 

ENTITY suma IS 
	PORT(x,y:in std_logic;
		s: out std_logic;
		a: out std_logic);
END suma;

architecture codigo of suma is
begin

	s<=(x xor y);
	a<=(x and y);

end codigo;