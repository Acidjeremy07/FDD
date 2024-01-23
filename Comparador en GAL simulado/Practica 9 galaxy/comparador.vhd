LIBRARY ieee;
USE IEEE.std_logic_1164.all;

ENTITY comparador IS PORT( 
						X,Y: in std_logic_vector(3 downto 0);
						mayor, menor,igual: out std_logic;
						display: out std_logic_vector(6 downto 0)
						  );
END comparador;

ARCHITECTURE resultado of comparador IS 
BEGIN


		mayor <= '1' when (X(3)>Y(3) or X(2)>Y(2) or X(1)>Y(1) or X(0)>Y(0)) else '0'; 
		menor <= '1' when (X(3)<Y(3) or X(2)<Y(2) or X(1)<Y(1) or X(0)<Y(0)) else '0'; 
		igual <= '1' when (X(3)=Y(3) or X(2)=Y(2) or X(1)=Y(1) or X(0)=Y(0)) else '0';

END resultado;
																																																										  																								  																								  																								  																								  																								  																								  																								  																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																										
