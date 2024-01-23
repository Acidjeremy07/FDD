LIBRARY ieee;
USE ieee.std_logic_1164.all;

ENTITY compuertas is
	PORT(
		a, b, c, d : in std_logic;
		andx, orx, nandx, norx, xorx, xnorx : out std_logic);

end compuertas;

architecture codigo of compuertas is 
begin	
	
		andx	<= 	a and b and c and d;
		orx		<= 	a or  b or  c or  d;
		nandx	<= 	not (a and b and c and d);
		norx	<= 	not (a or  b or  c or  d);
		xorx	<=	a xor b xor c xor d;
		xnorx	<= 	not(a xor b xor c xor d);

end codigo;
