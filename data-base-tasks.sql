---------- 2019-09 -----------
--1. Б)--
-- Да се огради буквата на заявката, която извежда за всеки продуцент името му и броя на фил-мите му по години.--
-- Продуценти, които нямат нито един филм, НЕ трябва да присъстват в резултатнотомножество. --
SELECT ME.NAME, M.YEAR, COUNT(*) AS CNT
FROM MOVIEEXEC ME
JOIN MOVIE MON ME.CERT# = M.PRODUCERC#
GROUP BY ME.CERT#, ME.NAME, M.YEAR;

--2. Да се напише заявка, която да изведе името на най-младата звезда (полът е без значение)--
SELECT NAME
FROM moviestar
WHERE BIRTHDATE IN (SELECT MAX(BIRTHDATE) FROM moviestar)
GROUP BY NAME

---------- 2019-09 -----------
--1. C--
--Да се огради буквата на заявката, която извежда име на студио и броя на филмите му, за тези студия с по-малко от два филма.--
--Студиата, които нямат нито един филм, НЕтрябва да присъстват в резултата.--
SELECT S.NAME, COUNT(M.TITLE) as CNT
FROM STUDIO S
JOIN MOVIE MON S.NAME = M.STUDIONAME
GROUP BY S.NAMEHAVING COUNT(M.TITLE) < 2;
