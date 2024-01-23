LIBRARY ieee;
USE ieee.std_logic_1164.all; 

ENTITY suma IS 
	PORT(a,b:in std_logic;
		suma: out std_logic;
		carry: out std_logic);
END suma;

architecture codigo of suma is
begin

	suma<=(a xor b);
	carry<=(a and b);

end codigo;