LIBRARY ieee;
USE ieee.std_logic_1164.all; 

ENTITY resta IS 
	PORT(a,b:in std_logic;
		resta: out std_logic;
		carry: out std_logic);
END resta;

architecture codigo of resta is
begin

	resta<=(a xor b);
	carry<=((not a) and b);

end codigo;