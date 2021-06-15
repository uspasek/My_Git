create table pracownicy(id_prac int not null, imie_i_nazw char(30), d_ur date, numer_wydz int not null, primary key(id_prac));
create table wydzialy(numer_wydz int not null, nazwa_wydz char(30));

insert into pracownicy(id_prac, imie_i_nazw, d_ur, numer_wydz) values(7513, 'Ewa Nowacka', '1967-05-02', 128);
insert into pracownicy(id_prac, imie_i_nazw, d_ur, numer_wydz) values(9842, 'Bartosz Kowalski', '1957-09-15', 42);
insert into pracownicy(id_prac, imie_i_nazw, d_ur, numer_wydz) values(6651, 'Andrzej Plater', '1978-12-22', 128);
insert into pracownicy(id_prac, imie_i_nazw, d_ur, numer_wydz) values(9006, 'Barbara Cetryk', '1963-09-19', 128);

insert into wydzialy(numer_wydz, nazwa_wydz) values(42, 'Finanse');
insert into wydzialy(numer_wydz, nazwa_wydz) values(128, 'Badania i Rozw');

select * from pracownicy;
select * from wydzialy;

select pracownicy.imie_i_nazw, pracownicy.d_ur from pracownicy where d_ur between '1960-01-01' and '1970-01-01';

select count(id_prac) from pracownicy;

select count(id_prac), numer_wydz from pracownicy group by numer_wydz;

select imie_i_nazw, numer_wydz from pracownicy where numer_wydz = 128;

select pracownicy.imie_i_nazw, wydzialy.numer_wydz, wydzialy.nazwa_wydz from pracownicy inner join wydzialy on pracownicy.numer_wydz = wydzialy.numer_wydz;

select wydzialy.nazwa_wydz, count(pracownicy.numer_wydz) from pracownicy inner join wydzialy on pracownicy.numer_wydz = wydzialy.numer_wydz group by wydzialy.nazwa_wydz;