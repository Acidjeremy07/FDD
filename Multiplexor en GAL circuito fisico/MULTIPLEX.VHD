LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY MULTIPLEXOR IS 
	PORT (W0,W1,W2,W3 : IN STD_LOGIC;
		  SELEC : IN STD_LOGIC_VECTOR(1 DOWNTO 0);
		  F : OUT STD_LOGIC);

ATTRIBUTE PIN_NUMBERS OF MULTIPLEXOR: ENTITY IS
	" W0:2 W1:3 W2:4 W3:5 "
	& " SELEC(0):6 SELEC(1):7 " 
	& " F:14 "; 

END MULTIPLEXOR;

ARCHITECTURE CODIGO OF MULTIPLEXOR IS
BEGIN
		PROCESS(W0,W1,W2,W3,SELEC)
		BEGIN
			IF SELEC="00" THEN
				F<=W0;
			ELSIF SELEC="01" THEN
				F<=W1;
			ELSIF SELEC="10" THEN
				F<=W2;
			ELSE 
				F<=W3;
			END IF;
		END PROCESS;
END CODIGO;
