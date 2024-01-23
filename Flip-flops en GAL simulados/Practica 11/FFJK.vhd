library ieee;
use ieee.std_logic_1164.all;

entity fFJK is
	port(clk, rst, J, K: in std_logic;
	Q: out std_logic);

end FFJK;

architecture codigo of FFJK is
	
	signal JK: std_logic_vector(1 downto 0);
	signal Q_aux: std_logic;
	begin
	JK <= J&K;
	process(clk, rst)
	begin
		if rst = '1' then
		Q_aux <= '0';
		elsif rising_edge(clk) then
			case JK is
			when "00" => Q_aux <= Q_aux;
			when "01" => Q_aux <= '0';
			when "10" => Q_aux <= '1';
			when others => Q_aux <= not Q_aux;
			end case;
		end if;
	end process;
	Q <= Q_aux;

end codigo;
