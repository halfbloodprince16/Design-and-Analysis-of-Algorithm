START 200
MOVER AREG B
MOVEM BREG '=2'
MOVEM BREG '=5'
LTORG
LOOP ADD CREG A
SUB CREG '=1'
LTORG
ORIGIN LOOP+5
BACK EQU LOOP
MOVEM BREG '=6'
MOVER AREG '=3'
B DS  3
A DC  5
END
