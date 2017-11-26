USE bookkeeping
GO

--SELECT * FROM Subdivisions;

--SELECT
--   CASE
--      WHEN Len(RTrim(name)) < 1 THEN REPLACE(name, N'', N'Alternative name')
--   END
--FROM Subdivisions;

--UPDATE Subdivisions
--   SET name = 
--      CASE WHEN Len(RTrim(name)) < 1 THEN N'Alternative name'
--      END
--EXEC SP_HELP Subdivisions;

--ALTER TABLE MaterialResponsiblePeople
--  ADD Single  VARCHAR(3) DEFAULT 'так';

--DECLARE @ConstraintName nvarchar(200)
--SELECT @ConstraintName = Name FROM SYS.DEFAULT_CONSTRAINTS
--WHERE PARENT_OBJECT_ID = OBJECT_ID('MaterialResponsiblePeople')
--AND PARENT_COLUMN_ID = (SELECT column_id FROM sys.columns
--                        WHERE NAME = N'Single'
--                        AND object_id = OBJECT_ID(N'MaterialResponsiblePeople'))
--IF @ConstraintName IS NOT NULL
--EXEC('ALTER TABLE MaterialResponsiblePeople DROP CONSTRAINT ' + @ConstraintName)

--ALTER TABLE MaterialResponsiblePeople
--  DROP COLUMN Single;

-- DELETE FROM SubdivisionTypes;

--SELECT * FROM SubdivisionTypes;
--SELECT * FROM Subdivisions;
--SELECT * FROM MaterialResponsiblePeople;
SELECT * FROM Equipment;
--DELETE FROM Subdivisions;