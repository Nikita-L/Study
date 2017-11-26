USE bookkeeping
GO

--IF OBJECT_ID ('MRPDelete', 'TR') IS NOT NULL  
--    DROP TRIGGER MRPDelete;  
--GO

--CREATE TRIGGER MRPDelete
--ON MaterialResponsiblePeople FOR DELETE
--AS
--IF EXISTS (
--	SELECT *
--	FROM DELETED D
--	JOIN Equipment E ON D.id = E.materialResponsiblePerson
--)
--BEGIN
--  RAISERROR('You can not delete MRP when he/she has equipment!', 16, 1)
--  ROLLBACK TRANSACTION
--END;
--GO


--INSERT INTO MaterialResponsiblePeople VALUES (N'Trigger test person', 6);
--DECLARE @insertedID int
--SELECT @insertedID = MRP.id FROM MaterialResponsiblePeople MRP
--WHERE MRP.fullName = N'Trigger test person'
--INSERT INTO Equipment VALUES (N'Trigger test equipment', 2000, 1800, @insertedID);
--GO

--ALTER TABLE Equipment
--NOCHECK CONSTRAINT FK__Equipment__mater__267ABA7A, CK__Equipment__name__25869641;
--GO

--DELETE FROM MaterialResponsiblePeople WHERE fullName = N'Trigger test person'
--GO

--DELETE FROM Equipment WHERE name = N'Trigger test equipment'
--GO
--DELETE FROM MaterialResponsiblePeople WHERE fullName = N'Trigger test person'
--GO


--IF OBJECT_ID ('MRPDelete', 'TR') IS NOT NULL  
--    DROP TRIGGER MRPDelete;  
--GO

--CREATE TRIGGER MRPDelete
--ON MaterialResponsiblePeople FOR DELETE
--AS
--IF EXISTS (
--	SELECT *
--	FROM DELETED D
--	JOIN Equipment E ON D.id = E.materialResponsiblePerson
--)
--BEGIN
--  RAISERROR('You can not delete MRP when he/she has equipment!', 16, 1)
--  ROLLBACK TRANSACTION
--END;
--GO

IF EXISTS(SELECT 1 FROM sys.views WHERE name='Дороге обладнення' AND TYPE='v')
DROP VIEW [Дороге обладнення];
GO

CREATE VIEW [Дороге обладнення] AS
SELECT E.name [Назва], S.name [Підрозділ], E.price [Вартість]
FROM Equipment E
JOIN MaterialResponsiblePeople MRP ON MRP.id = E.materialResponsiblePerson
JOIN Subdivisions S ON S.id = MRP.subdivision
WHERE E.price > 1500
GO

SELECT * FROM [Дороге обладнення]