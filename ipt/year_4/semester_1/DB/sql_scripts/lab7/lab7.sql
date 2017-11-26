USE bookkeeping
GO

IF OBJECT_ID ('SubdivisionAVGPrice', 'P') IS NOT NULL  
    DROP PROC SubdivisionAVGPrice;
GO

CREATE PROCEDURE SubdivisionAVGPrice
  @SubdivisionName nvarchar(50) OUTPUT
AS

SELECT AVG(E.price) avgPrice FROM Equipment E
JOIN MaterialResponsiblePeople MRP ON MRP.id = E.materialResponsiblePerson
JOIN Subdivisions S ON S.id = MRP.subdivision
WHERE S.name = @SubdivisionName

GO

EXEC SubdivisionAVGPrice N'General Managment';
GO

-- True, because: (1000 + 1500 + 2000 + 1000) / 4 = 1375