LIBRARY ieee;
USE ieee.std_logic_1164.all;

ENTITY mult IS PORT(
	a0,a1,b0,b1:IN  STD_LOGIC;
	p0,p1,p2,p3: OUT STD_LOGIC
	);

END mult;

architecture funcion of mult is
begin
		p3<=(a1 and a0) and (b1 and b0);
		p2<=((a1 and (not a0)) and b1) or ((a1 and b1) and (not b0));
		p1<=(((not a1) and a0) and b1) or ((a1 and (not a0)) and b0) or ((a1 and (not b1)) and b0) or ((a0 and b1) and (not b0));
		p0<=(a0 and b0);

end funcion;