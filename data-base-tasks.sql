---------- 2019 -----------
SELECT NAME
FROM moviestar
WHERE BIRTHDATE IN (SELECT MAX(BIRTHDATE) FROM moviestar)
GROUP BY NAME
