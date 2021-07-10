---------- 2020-09 -----------
--1--
SELECT s.name, s.address
FROM studio s JOIN movie m ON m.STUDIONAME = s.NAME
WHERE m.INCOLOR = 'Y'
GROUP BY s.name, s.ADDRESS
HAVING s.name IN (SELECT studioname FROM movie WHERE incolor = 'N')

--2--
SELECT s.name, s.address, AVG(m.length), COUNT(m.title)
FROM Studio s 
LEFT JOIN movie m ON m.STUDIONAME = s.NAME
GROUP BY s.name, s.ADDRESS
HAVING COUNT(*) <= 3

---------- 2020-08 -----------
--1--
SELECT name, birthdate, m.incolor FROM moviestar
JOIN starsin st ON st.STARNAME = NAME
JOIN movie m ON m.title = st.MOVIETITLE
WHERE name NOT LIKE "%Jr.%"
GROUP BY name, birthdate, m.INCOLOR
HAVING m.INCOLOR = 'Y'
ORDER BY BIRTHDATE DESC

--2--
SELECT name, YEAR(birthdate), COUNT(m.studioname) FROM moviestar
LEFT JOIN starsin st ON st.STARNAME = name
LEFT JOIN movie m ON m.title = st.movietitle
WHERE GENDER = 'F'
GROUP BY name, YEAR(birthdate)
HAVING COUNT(m.title) <= 6

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
GROUP BY S.NAME
HAVING COUNT(M.TITLE) < 2;

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
WHERE s.CLASS LIKE 'N%'
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

---------- 2018-07 -----------
--1--
SELECT s.name, MIN(m.year) AS FirstMovie, MAX(m.year) AS LastMovie, COUNT(m.title)
FROM studio s 
JOIN movie m ON m.STUDIONAME = s.NAME
WHERE s.name LIKE 'M%'
GROUP BY s.name

--2--
SELECT s.starname, MAX(s3.TotalMovies) FROM starsin s 
JOIN (
    SELECT s1.starname as starname, COUNT(s1.movietitle) as TotalMovies FROM starsin s1
    JOIN moviestar m ON m.NAME = s1.STARNAME
    WHERE m.GENDER = 'F'
    GROUP BY STARNAME
) s3 ON s3.starname = s.STARNAME

--OR--
SELECT starname, COUNT(st.MOVIETITLE) FROM moviestar ms
JOIN starsin st ON ms.name = st.STARNAME
WHERE ms.GENDER = 'F'
GROUP BY starname
HAVING COUNT(st.MOVIETITLE) >= ALL (SELECT COUNT(MOVIETITLE)
                                    FROM moviestar
                                    JOIN starsin ON name = STARNAME
				    WHERE GENDER = 'F'
                                    GROUP BY starname)


---------- 2017-09-----------
--1--
SELECT DISTINCT s.name, c.country
FROM ships s 
JOIN Classes c ON c.CLASS = s.CLASS
LEFT JOIN outcomes o ON o.SHIP = s.NAME
WHERE o.RESULT <> 'sunk' OR o.RESULT IS NULL

--2--
SELECT s.name, c.displacement, c.numguns FROM classes c
JOIN ships s ON s.CLASS = c.CLASS
WHERE displacement = (SELECT MIN(displacement) FROM classes) AND
      numguns = (SELECT MAX(numguns) FROM classes c1 WHERE c1.class = c.class)

--3--
SELECT battle, ship FROM outcomes o1
WHERE NOT EXISTS (
    SELECT * FROM outcomes o2
    WHERE o2.battle = o1.BATTLE AND o1.ship <> o2.ship
)

--4--
SELECT class, COUNT(DISTINCT name)
FROM ships s 
JOIN outcomes o ON s.name=o.ship
WHERE result='sunk' AND class IN (SELECT c.class
                                  FROM classes c 
                                  JOIN ships s ON c.class=s.class
                                  GROUP BY c.class
                                  HAVING COUNT(name)>5)
GROUP BY class

--my 4--
SELECT class, COUNT(DISTINCT name)
FROM ships s 
JOIN outcomes o ON s.name=o.ship
WHERE result='sunk'
GROUP BY class
HAVING class IN (SELECT class FROM ships GROUP BY class HAVING COUNT(name) > 5)

---------- 2017-07-----------
--1--
SELECT m.studioname, m.title, m.year
FROM movie m
WHERE year = (SELECT MAX(year) FROM movie WHERE m.STUDIONAME = STUDIONAME)

--2--
SELECT me.name, SUM(m.length) FROM movieexec me 
JOIN movie m ON m.`PRODUCERC#` = me.`CERT#`
WHERE m.`PRODUCERC#` IN (SELECT `PRODUCERC#` FROM movie WHERE YEAR < 1980)
GROUP BY me.name

SELECT me.name, SUM(m.length) FROM movieexec me
JOIN movie m ON m.`PRODUCERC#` = me.`CERT#`
GROUP BY me.name
HAVING MIN(m.year) < 1980

--3--
SELECT st.starname, st.movietitle, name, networth 
FROM starsin st
JOIN movie m ON st.MOVIETITLE = m.TITLE AND st.MOVIEYEAR = m.YEAR
JOIN (SELECT `CERT#`, name, NETWORTH
      FROM movieexec
      WHERE NETWORTH = (SELECT MAX(NETWORTH) FROM movieexec me2)) t
      ON m.`PRODUCERC#` = t.`CERT#`

--my 3--
SELECT st.STARNAME, m.title, me.name, me.networth
FROM starsin st
JOIN movie m ON m.TITLE = st.MOVIETITLE
JOIN movieexec me ON me.`CERT#` = m.`PRODUCERC#`
WHERE me.NETWORTH IN (SELECT MAX(NETWORTH) FROM movieexec)

--4 B) --
SELECT name, title, year
FROM movie JOIN movieexec ON `producerc#`=`cert#`
WHERE `cert#` = ANY (SELECT `producerc#`
                     FROM movie
                     WHERE title='Terms of Endearment')
		
---------- 2016-09-----------
--1--
SELECT DISTINCT c.country, (SELECT COUNT(o.result)
                            FROM classes c1
                            JOIN ships s ON c1.class=s.class
                            JOIN outcomes o ON s.name=o.ship
                            WHERE result='sunk' AND c1.country=c.country)
FROM classes c

--my 1--
SELECT DISTINCT c.country, COUNT(t.numSunk)
FROM classes c
LEFT JOIN ( 
    SELECT c1.COUNTRY, COUNT(o.result) as numSunk
    FROM classes c1
    JOIN ships s ON c1.class=s.class
    JOIN outcomes o ON s.name=o.ship
    WHERE result='sunk') t ON t.Country = c.COUNTRY
GROUP BY COUNTRY

--my 2--
SELECT battle, ship FROM outcomes o
GROUP BY BATTLE
HAVING COUNT(ship) > (SELECT COUNT(ship) FROM outcomes WHERE battle="North Cape")

