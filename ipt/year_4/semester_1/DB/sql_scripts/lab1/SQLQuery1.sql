 CREATE DATABASE bookkeeping;
CREATE TABLE Equipment (
	id bigint PRIMARY KEY,
    name nvarchar UNIQUE CHECK (Len(RTrim(name)) > 5),
    price money,
    residualValue money,
	CHECK (price>=residualValue), -- residualValue <= price
);
CREATE TABLE Subdivisions (
	id int PRIMARY KEY,
    name nvarchar UNIQUE CHECK (Len(RTrim(name)) > 5),
    subdivisionType nvarchar(255),
);
CREATE TABLE MaterialResponsiblePersons (
	id int PRIMARY KEY,
    fullName nvarchar(255) UNIQUE CHECK (Len(RTrim(fullName)) > 5),
    subdivision int FOREIGN KEY REFERENCES Subdivisions(id),
	equipment bigint FOREIGN KEY REFERENCES Equipment(id) ON DELETE NO ACTION,
);
