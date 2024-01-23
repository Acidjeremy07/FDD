LIBRARY ieee;
USE ieee.std_logic_1164.all; 

ENTITY suma IS 
	PORT(a,b,cin :in std_logic;
		suma: out std_logic;
		carry: out std_logic);
END suma;

architecture codigo of suma is
begin

	suma<=(a xor b xor cin);
	carry<=(a and b) or (cin and(b or a));

end codigo;