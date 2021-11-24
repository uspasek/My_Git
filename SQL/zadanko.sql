create table panstwa(id_panstwa int primary key, panstwo char(20));
create table miasta(id_miasta int primary key, miasto char(20), id_panstwa int);

insert into panstwa(id_panstwa, panstwo) values(1, 'Francja');
insert into panstwa(id_panstwa, panstwo) values(2, 'Polska');
insert into panstwa(id_panstwa, panstwo) values(3, 'Czechy');

insert into miasta(id_miasta, miasto, id_panstwa) values(1, 'Warszawa', 2);
insert into miasta(id_miasta, miasto, id_panstwa) values(2, 'Paryz', 1);
insert into miasta(id_miasta, miasto, id_panstwa) values(3, 'Rybnik', 2);

select miasta.id_miasta, miasta.miasto, miasta.id_panstwa, panstwa.id_panstwa, panstwa.panstwo from panstwa, miasta;
select miasta.id_miasta, miasta.miasto, miasta.id_panstwa, panstwa.id_panstwa, panstwa.panstwo from panstwa, miasta where miasta.id_panstwa=panstwa.id_panstwa;
select miasta. miasto, panstwa.panstwo from panstwa, miasta where miasta.id_panstwa=panstwa.id_panstwa;

select miasta.id_miasta, miasta.miasto, miasta.id_panstwa, panstwa.id_panstwa, panstwa.panstwo from panstwa inner join miasta;
select miasta.id_miasta, miasta.miasto, miasta.id_panstwa, panstwa.id_panstwa, panstwa.panstwo from panstwa inner join miasta on miasta.id_panstwa=panstwa.id_panstwa;
select miasta.miasto, panstwa.panstwo from panstwa inner join miasta on miasta.id_panstwa=panstwa.id_panstwa;