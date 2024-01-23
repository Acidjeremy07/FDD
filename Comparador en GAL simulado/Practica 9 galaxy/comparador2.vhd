LIBRARY ieee;
USE IEEE.std_logic_1164.all;

ENTITY comparador IS PORT( 
						X,Y: in std_logic_vector(3 downto 0);
						signal mayor, menor,igual: std_logic;
						display: out std_logic_vector(6 downto 0)
						  );
END comparador;

ARCHITECTURE resultado of comparador IS 
BEGIN

		mayor <= '1' when (X(3)>Y(3) and X(2)>Y(2) and X(1)>Y(1) and X(0)>Y(0)) else '0'; 
		menor <= '1' when (X(3)<Y(3) and X(2)<Y(2) and X(1)<Y(1) and X(0)<Y(0)) else '0'; 
		igual <= '1' when (X(3)=Y(3) and X(2)=Y(2) and X(1)=Y(1) and X(0)=Y(0)) else '0';

		PROCESS ( mayor, menor)
		BEGIN
				IF(	mayor = '1' ) THEN
					display <= "1111000";	--MAYOR QUE
				ELSIF ( menor = '1' ) THEN
					display <= "1001110";	--MENOR QUE
				ELSE
					display <= "0001001";	--IGUAL 	
				END IF;

		END PROCESS;

END resultado;