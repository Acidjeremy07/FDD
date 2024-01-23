LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY DECO IS
	PORT(
			A,B,C,D,E,F,G : OUT STD_LOGIC;
			X3,X2,X1,X0	  : IN STD_LOGIC);

	ATTRIBUTE PIN_NUMBERS OF DECO: ENTITY IS
		" X3:2 X2:3 X2:4 X1:5 X0:6 "
		& " A:14 B:15 C:16 D:17 E:18 F:19 G:20 ";

END  DECO;

ARCHITECTURE CODIGO OF DECO IS

SIGNAL var_out : std_logic_vector(6 downto 0);
SIGNAL var_in  : std_logic_vector(3 downto 0);

BEGIN
	PROCESS(X3,X2,X1,X0)
	BEGIN
		var_in(3)<=X3;
		var_in(2)<=X2;
		var_in(1)<=X1;
		var_in(0)<=X0;

			IF var_in="0000" THEN var_out<="1111110";--0
			ELSIF var_in="0001" THEN var_out<="0110000";--1
			ELSIF var_in="0010" THEN var_out<="1101101";--2
			ELSIF var_in="0011" THEN var_out<="1111000";--3
			ELSIF var_in="0100" THEN var_out<="1110011";--4
			ELSIF var_in="0101" THEN var_out<="1011011";--5
			ELSIF var_in="0110" THEN var_out<="1011111";--6
			ELSIF var_in="0111" THEN var_out<="1110000";--7
			ELSIF var_in="1000" THEN var_out<="1111111";--8
			ELSIF var_in="1001" THEN var_out<="1110011";--9
			ELSE var_out<="0000000";
		END IF;

   		A<=var_out(6);
		B<=var_out(5);
		C<=var_out(4);
		D<=var_out(3);
		E<=var_out(2);
		F<=var_out(1);
		G<=var_out(0);

	END PROCESS;
END CODIGO;
