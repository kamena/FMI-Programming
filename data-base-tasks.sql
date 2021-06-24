---------- 2019-09 -----------
--1. Б)--
-- Да се огради буквата на заявката, която извежда за всеки продуцент името му и броя на фил-мите му по години.--
-- Продуценти, които нямат нито един филм, НЕ трябва да присъстват в резултатнотомножество. --
SELECT ME.NAME, M.YEAR, COUNT(*) AS CNT
FROM MOVIEEXEC ME
JOIN MOVIE MON ME.CERT# = M.PRODUCERC#
GROUP BY ME.CERT#, ME.NAME, M.YEAR;

--2. Да се напише заявка, която да изведе името на най-младата звезда (полът е без значение)--
SELECT NAME FROM moviestar
WHERE BIRTHDATE IN (SELECT MAX(BIRTHDATE) FROM moviestar)
GROUP BY NAME

---------- 2019-09 -----------
--1. C)--
--Да се огради буквата на заявката, която извежда име на студио и броя на филмите му, за тези студия с по-малко от два филма.--
--Студиата, които нямат нито един филм, НЕтрябва да присъстват в резултата.--
SELECT S.NAME, COUNT(M.TITLE) as CNT
FROM STUDIO S
JOIN MOVIE MON S.NAME = M.STUDIONAME
GROUP BY S.NAMEHAVING COUNT(M.TITLE) < 2;

--2--
--Да се напише заявка, която да изведе имената на всички продуценти с минимален нетен актив.--
SELECT NAME FROM MOVIEEXEC
WHERE NETWORTH IN (SELECT MIN(NETWORTH) FROM MOVIEXEC)
GROUP BY NAME

---------- 2018-09 -----------
--1.--
SELECT s.CLASS, MIN(Year(DATE)) AS FirstBattle, MAX(Year(DATE)) AS LastBattle, COUNT(DISTINCT b.NAME) AS TotalBattles
FROM ships s
LEFT JOIN outcomes o ON s.NAME = o.SHIP
LEFT JOIN battles b ON b.NAME = o.BATTLE
WHERE b.NAME LIKE 'N%'
GROUP BY s.CLASS

--2.--
SELECT o.battle FROM outcomes o
INNER JOIN ships s ON o.SHIP = s.NAME
INNER JOIN classes c ON c.CLASS = s.CLASS
WHERE c.TYPE = 'bb'
GROUP BY o.BATTLE
HAVING COUNT(o.ship) > (
    SELECT COUNT(*) FROM outcomes o2
    INNER JOIN ships s2 ON o2.SHIP = s2.NAME
    INNER JOIN classes c2 ON c2.CLASS = s2.CLASS
    WHERE c2.TYPE = 'bc' AND o.BATTLE = o2.BATTLE
)
