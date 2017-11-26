USE bookkeeping
GO
ALTER TABLE Equipment
DROP CONSTRAINT EquipmentCheck;
ALTER TABLE Subdivisions
DROP CONSTRAINT SubdivisionsCheck;
ALTER TABLE MaterialResponsiblePeople
DROP CONSTRAINT MaterialResponsiblePeopleCheck;
