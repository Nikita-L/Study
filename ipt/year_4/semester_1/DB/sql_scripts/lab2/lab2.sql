USE bookkeeping
GO


--ALTER TABLE SubdivisionTypes
--  DROP CONSTRAINT SubdivisionTypesLenCheck;
----ALTER TABLE SubdivisionTypes -- TEMP
----  DROP CONSTRAINT SubdivisionTypesCheck;
--ALTER TABLE SubdivisionTypes
--  ADD CONSTRAINT SubdivisionTypesCheck
--	CHECK (Len(RTrim(name)) > 1);

--ALTER TABLE Subdivisions
--  DROP CONSTRAINT subdivisionsLenCheck;
--ALTER TABLE Subdivisions
--  DROP CONSTRAINT subdivisionTypeFK;
----ALTER TABLE Subdivisions -- TEMP
----  DROP CONSTRAINT SubdivisionsCheck;
--ALTER TABLE Subdivisions
--  ADD CONSTRAINT SubdivisionsCheck
--	CHECK (Len(RTrim(name)) > 1),
--	FOREIGN KEY (subdivisionType)
--	  REFERENCES subdivisionTypes (id)
--	  ON UPDATE CASCADE  -- CASCADE
--	  ON DELETE CASCADE; -- CASCADE

--ALTER TABLE MaterialResponsiblePeople
--  DROP CONSTRAINT MaterialResponsiblePeopleLenCheck;
--ALTER TABLE MaterialResponsiblePeople
--  DROP CONSTRAINT subdivisionFK;
--ALTER TABLE MaterialResponsiblePeople -- TEMP
--  DROP CONSTRAINT MaterialResponsiblePeopleCheck;
ALTER TABLE MaterialResponsiblePeople
  ADD CONSTRAINT MaterialResponsiblePeopleCheck
	CHECK (Len(RTrim(fullName)) > 5),
	FOREIGN KEY (subdivision)
      REFERENCES Subdivisions (id)
	  ON UPDATE CASCADE  -- CASCADE
	  ON DELETE CASCADE; -- CASCADE

--ALTER TABLE Equipment
--  DROP CONSTRAINT EquipmentLenCheck;
--ALTER TABLE Equipment
--  DROP CONSTRAINT EquipmentPriceCheck;
--ALTER TABLE Equipment
--  DROP CONSTRAINT MaterialResponsiblePersonFK;
----ALTER TABLE Equipment -- TEMP
----  DROP CONSTRAINT EquipmentCheck;
--ALTER TABLE Equipment
--  ADD CONSTRAINT EquipmentCheck
--    CHECK (price>=residualValue and price >= 0 and residualValue >= 0),
--	CHECK (Len(RTrim(name)) > 1),
--	FOREIGN KEY (materialResponsiblePerson)
--	  REFERENCES MaterialResponsiblePeople (id)
--	  ON UPDATE CASCADE  -- CASCADE
--	  ON DELETE NO ACTION;


--ALTER TABLE  Subdivisions
--  NOCHECK CONSTRAINT SubdivisionsCheck;
--INSERT INTO Subdivisions (name, subdivisionType)
--  VALUES (N'Nikita', 999);
--ALTER TABLE  Subdivisions
--  WITH CHECK
--	   CHECK CONSTRAINT SubdivisionsCheck;


--DELETE FROM Subdivisions;
--ALTER TABLE Subdivisions
--   WITH CHECK
--      CHECK CONSTRAINT SubdivisionsCheck;


--ALTER TABLE Subdivisions
--   NOCHECK CONSTRAINT SubdivisionsCheck;

--INSERT INTO Subdivisions (name, subdivisionType)
--   VALUES (N'', null);

--Update Subdivisions 
--   set name = isnull(name, 'Unknown')
--UPDATE Subdivisions
--   SET name = 
--      CASE WHEN Len(RTrim(name)) < 1 THEN N'Alternative name'
--      END

--ALTER TABLE Subdivisions
--  WITH CHECK
--    CHECK CONSTRAINT SubdivisionsCheck;


--ALTER TABLE MaterialResponsiblePeople
--  ADD Single  VARCHAR(3) DEFAULT 'так';

---- Dropping constraints => column drop avaliable
--DECLARE @ConstraintName nvarchar(200);
--SELECT @ConstraintName = Name FROM SYS.DEFAULT_CONSTRAINTS
--   WHERE PARENT_OBJECT_ID = OBJECT_ID('MaterialResponsiblePeople')
--      AND PARENT_COLUMN_ID = (SELECT column_id FROM sys.columns
--         WHERE NAME = N'Single'
--            AND object_id = OBJECT_ID(N'MaterialResponsiblePeople'));
--IF @ConstraintName IS NOT NULL
--   EXEC('ALTER TABLE MaterialResponsiblePeople DROP CONSTRAINT ' + @ConstraintName);

--ALTER TABLE MaterialResponsiblePeople
--  DROP COLUMN Single;


--EXEC SP_RENAME  'MaterialResponsiblePeople', 'MRP';


--EXEC SP_RENAME  'MRP', 'MaterialResponsiblePeople';