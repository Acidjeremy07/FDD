LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY comparador IS PORT( 
						X,Y: in std_logic_vector(3 downto 0);
						signal Z:  std_logic_vector(3 downto 0);
						display: out std_logic_vector(6 downto 0)
						  );
END comparador;

ARCHITECTURE resultado of comparador IS 
BEGIN

		Z<= X when (X(3)>Y(3) or X(2)>Y(2) or X(1)>Y(1) or X(0)>Y(0)) else
			Y when (X(3)<Y(3) or X(2)<Y(2) or X(1)<Y(1) or X(0)<Y(0)) else
			"0000";

		PROCESS (X,Y,Z)
		BEGIN
			
				IF( Z = X ) THEN
					display <= "1111000";	--MAYOR QUE
				ELSIF ( Z = Y) THEN
					display <= "1001110";	--MENOR QUE
				ELSE
					display <= "0001001";	--IGUAL 	
				END IF;
		END PROCESS;

END resultado;
