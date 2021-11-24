
Create table ksiazki (
	id_ksiazki Int not null,
	tytul  char(20),
	autor char(20),
	Primary Key (id_ksiazki)) ENGINE = InnoDB;

Create table wypozyczenia (
	id_wypozyczenia  Int NOT Null,
	id_ksiazki Int not null,
	id_osoby Int not null,
	data_wypozyczenia Date,
Primary Key (id_wypozyczenia)) Engine = InnoDB;

Create table osoby(
	id_osoby Int not null,
	nazwisko Char(10),
	imie Char(10),
	adres Char(30),
Primary Key (id_osoby)) Engine = InnoDB;

Alter table wypozyczenia add Foreign Key (id_ksiazki)
References ksiazki (id_ksiazki) on delete restrict on update restrict;
Alter table wypozyczenia add Foreign Key (id_osoby)
References osoby (id_osoby) on delete restrict on update restrict;
INSERT INTO ksiazki (id_ksiazki, tytul, autor)
VALUES(1, 'Analiza matematyczna', 'Kowalski Jan');
INSERT INTO ksiazki (id_ksiazki, tytul, autor)
VALUES(2, 'Rachunek prawdopod.', 'Batko Lukasz');
INSERT INTO ksiazki (id_ksiazki, tytul, autor)
VALUES(3, 'Fizyka dla inz.', 'Batko Lukasz');
INSERT INTO ksiazki (id_ksiazki, tytul, autor)
VALUES(4, 'C++ wprowadzenie', 'Balcerzak Jozef');
INSERT INTO ksiazki (id_ksiazki, tytul, autor)
VALUES(5, 'Bazy danych:wprow', 'Wasiak Jan');
INSERT INTO osoby (id_osoby, nazwisko, imie, adres)
VALUES(1, 'Oleksy ', 'Pawel', 'Krakow, al. Mickiewicza 11/6');
INSERT INTO osoby (id_osoby, nazwisko, imie, adres)
VALUES(2, 'Debowski ', 'Piotr', 'Krakow, ul. Zielona 11/6');
INSERT INTO osoby (id_osoby, nazwisko, imie, adres)
VALUES(3, 'Kulik ', 'Eugeniusz', 'Wieliczka, ul. Krakowska 7');
INSERT INTO osoby (id_osoby, nazwisko, imie, adres)
VALUES(4, 'Sikora ', 'Jan', 'Krakow, ul. Tatrzanska 7/9');
INSERT INTO wypozyczenia (id_wypozyczenia, id_ksiazki, id_osoby, data_wypozyczenia)
Values(1, 1, 1, '2007-11-07');
INSERT INTO wypozyczenia (id_wypozyczenia, id_ksiazki, id_osoby, data_wypozyczenia)
Values(2, 2, 2, '2007-12-09');
INSERT INTO wypozyczenia (id_wypozyczenia, id_ksiazki, id_osoby, data_wypozyczenia)
Values(3, 3, 3, '2007-12-10');
INSERT INTO wypozyczenia (id_wypozyczenia, id_ksiazki, id_osoby, data_wypozyczenia)
Values(4, 4, 4, '2008-01-04');
INSERT INTO wypozyczenia (id_wypozyczenia, id_ksiazki, id_osoby, data_wypozyczenia)
Values(5, 3, 2, '2008-01-07');

Select ksiazki.tytul, ksiazki.autor, wypozyczenia.data_wypozyczenia,
osoby.nazwisko, osoby.imie, osoby.adres
From ksiazki, wypozyczenia, osoby
Where ksiazki.id_ksiazki=wypozyczenia.id_ksiazki AND
osoby.id_osoby=wypozyczenia.id_osoby;

INSERT INTO Wypozyczenia (id_wypozyczenia,id_ksiazki,id_osoby,data_wypozyczenia)
VALUES (7,4,7, '2021-04-11');
SELECT * FROM Wypozyczenia;
Alter table wypozyczenia add Foreign Key (id_ksiazki)
references ksiazki (id_ksiazki) on delete restrict on update restrict;
Alter table wypozyczenia add Foreign Key (id_osoby)
references ksiazki (id_osoby) on delete restrict on update restrict;

select wypozyczenia.id_wypozyczenia, ksiazki.tytul, ksiazki.autor, osoby.nazwisko, osoby.imie, wypozyczenia.data_wypozyczenia from osoby inner join (ksiazki inner join wypozyczenia on ksiazki.id_ksiazki = wypozyczenia.id_ksiazki) on osoby.id_osoby = wypozyczenia.id_osoby; 
select osoby.nazwisko, osoby.imie, count(wypozyczenia.id_wypozyczenia) as Policz_id_wypozyczenia from osoby inner join (ksiazki inner join wypozyczenia on ksiazki.id_ksiazki = wypozyczenia.id_ksiazki) on osoby.id_osoby = wypozyczenia.id_osoby group by osoby.nazwisko, osoby.imie;
select ksiazki.tytul, count(wypozyczenia.id_wypozyczenia) as Ile_razy_wypozyczona from ksiazki inner join (osoby inner join wypozyczenia on osoby.id_osoby = wypozyczenia.id_osoby) on ksiazki.id_ksiazki = wypozyczenia.id_ksiazki group by ksiazki.tytul;


