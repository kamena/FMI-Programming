---------- 2019 -----------
--Да се напише заявка, която да изведе името на най-младата звезда (полът е без значение)--
SELECT NAME
FROM moviestar
WHERE BIRTHDATE IN (SELECT MAX(BIRTHDATE) FROM moviestar)
GROUP BY NAME
