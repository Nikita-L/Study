USE master;
GO
CREATE DATABASE bookkeeping
GO
USE bookkeeping
GO

CREATE TABLE SubdivisionTypes (
	id int IDENTITY PRIMARY KEY,
    name nvarchar(50) UNIQUE NOT NULL,

	CONSTRAINT SubdivisionTypesLenCheck CHECK (Len(RTrim(name)) > 1),
);
CREATE TABLE Subdivisions (
	id int IDENTITY PRIMARY KEY,
    name nvarchar(50) UNIQUE NOT NULL,
    subdivisionType int,

	CONSTRAINT SubdivisionsLenCheck CHECK (Len(RTrim(name)) > 1),
	CONSTRAINT subdivisionTypeFK FOREIGN KEY (subdivisionType)
		REFERENCES subdivisionTypes(id)
		ON UPDATE CASCADE
		ON DELETE SET NULL,
);
CREATE TABLE MaterialResponsiblePeople (
	id int IDENTITY PRIMARY KEY,
    fullName nvarchar(255) UNIQUE NOT NULL,
	subdivision int,

	CONSTRAINT MaterialResponsiblePeopleLenCheck CHECK (Len(RTrim(fullName)) > 5),
	CONSTRAINT subdivisionFK FOREIGN KEY (subdivision)
		REFERENCES Subdivisions(id)
		ON UPDATE CASCADE
		ON DELETE SET NULL,
);
CREATE TABLE Equipment (
	id bigint IDENTITY PRIMARY KEY,
    name nvarchar(50) NOT NULL,
    price decimal(19, 2),
    residualValue decimal(19, 2),
	materialResponsiblePerson int,

	CONSTRAINT EquipmentLenCheck CHECK (Len(RTrim(name)) > 1),
	CONSTRAINT EquipmentPriceCheck CHECK (price>=residualValue and price>=0),
	CONSTRAINT MaterialResponsiblePersonFK FOREIGN KEY (materialResponsiblePerson)
		REFERENCES MaterialResponsiblePeople(id)
		ON UPDATE CASCADE
		ON DELETE SET NULL,
);

USE bookkeeping
GO
EXEC dbo.sp_changedbowner @loginame = N'sa', @map = false
GO