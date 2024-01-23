LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY COMPUERTAS IS 
	PORT (A : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
		  YAND,YOR,YNAND,YNOR,YXOR,YXNOR : OUT STD_LOGIC);

END COMPUERTAS;

ARCHITECTURE CODIGO OF COMPUERTAS IS
BEGIN

		YAND<= (a(0) and a(1)) and (a(2) and a(3));
		YOR <= (a(0) or a(1)) or (a(2) or a(3));
		YNAND<= not((a(0) and a(1)) and (a(2) and a(3)));
		YNOR <= not((a(0) or a(1)) or (a(2) or a(3)));
		YXOR <=	(a(0) xor a(1)) xor (a(2) xor a(3));
		YXNOR<= (a(0) xnor a(1)) xnor (a(2) xnor a(3));

END CODIGO;

