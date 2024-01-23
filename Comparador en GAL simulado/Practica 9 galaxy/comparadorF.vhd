LIBRARY ieee;
USE IEEE.std_logic_1164.all;

ENTITY comparador IS PORT( 
						X,Y: in std_logic_vector(3 downto 0);
						 A, B: OUT std_logic;
						display: out std_logic_vector(6 downto 0)
						  );
END comparador;

ARCHITECTURE resultado of comparador IS 
BEGIN

		A <= '1' when (X>Y)else '0'; 
		B <= '1' when (X<Y)else '0';  

		PROCESS (A,B)
		BEGIN
				IF(	A = '1' ) THEN
					display <= "1111000";	--MAYOR QUE
				ELSIF ( B = '1' ) THEN
					display <= "1001110";	--MENOR QUE
				ELSE
					display <= "0001001";	--IGUAL 	
				END IF;

		END PROCESS;

END resultado;
