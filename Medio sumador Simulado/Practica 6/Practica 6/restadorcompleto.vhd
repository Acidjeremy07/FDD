library IEEE;
use IEEE.std_logic_1164.all;

entity resta is
    port (
        resta, cout : out std_logic;
        a, b, cin : in std_logic
    );
end entity;

architecture codigo of resta is
begin

    resta <= (cin and (not a) and (not b))
        or ((not cin) and (not a) and b)
        or (cin and a and b)
        or ((not cin) and a and (not b));

    cout <= (cin and (not a))
        or (cin and b)
        or ((not a) and b);

end codigo;
