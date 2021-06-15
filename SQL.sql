CREATE TABLE adres (
    id_adresu      INTEGER NOT NULL,
    ulica          VARCHAR(20),
    nr_bloku       INTEGER,
    nr_mieszkania  INTEGER,
    miasto         VARCHAR(20)
);

ALTER TABLE adres ADD CONSTRAINT adres_pk PRIMARY KEY ( id_adresu );

CREATE TABLE cennik (
    cena     INTEGER,
    rozmiar  VARCHAR(3) NOT NULL
);

ALTER TABLE cennik ADD CONSTRAINT cennik_pk PRIMARY KEY ( rozmiar );

CREATE TABLE klient (
    id        INTEGER NOT NULL,
    imie      VARCHAR(20),
    nazwisko  VARCHAR(20)
);

ALTER TABLE klient ADD CONSTRAINT klient_pk PRIMARY KEY ( id );

CREATE TABLE menu (
    id       INTEGER NOT NULL,
    rozmiar  VARCHAR(3),
    nazwa    VARCHAR(20)
);

ALTER TABLE menu ADD CONSTRAINT menu_pk PRIMARY KEY ( id );

CREATE TABLE zamowienie (
    data_zamowienia  DATE,
    id_adresu        INTEGER NOT NULL,
    id_klienta       INTEGER NOT NULL,
    id_pizza         INTEGER NOT NULL
);

ALTER TABLE menu
    ADD CONSTRAINT menu_cennik_fk FOREIGN KEY ( rozmiar )
        REFERENCES cennik ( rozmiar );

ALTER TABLE zamowienie
    ADD CONSTRAINT zamowienie_adres_fk FOREIGN KEY ( id_adresu )
        REFERENCES adres ( id_adresu );

ALTER TABLE zamowienie
    ADD CONSTRAINT zamowienie_klient_fk FOREIGN KEY ( id_klienta )
        REFERENCES klient ( id );

ALTER TABLE zamowienie
    ADD CONSTRAINT zamowienie_menu_fk FOREIGN KEY ( id_pizza )
        REFERENCES menu ( id );




