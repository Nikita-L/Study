USE bookkeeping
GO

SELECT MRP.* FROM MaterialResponsiblePeople MRP
JOIN Subdivisions S ON S.id = MRP.subdivision
JOIN SubdivisionTypes ST on ST.id = S.subdivisionType
WHERE ST.name = N'Managment'

SELECT COUNT(E.id) quantity FROM Equipment E
JOIN MaterialResponsiblePeople MRP ON MRP.id = E.id
JOIN Subdivisions S ON S.id = MRP.subdivision
JOIN SubdivisionTypes ST on ST.id = S.subdivisionType
WHERE ST.name = N'Development'

SELECT SUM(E.price) totalPrice FROM Equipment E
JOIN MaterialResponsiblePeople MRP ON MRP.id = E.id
JOIN Subdivisions S ON S.id = MRP.subdivision
WHERE S.name = N'Blockchain Researching'

SELECT TOP 1 * FROM
(
  SELECT MRP.*, SUM(E.price) sumPrice FROM Equipment E
  JOIN MaterialResponsiblePeople MRP ON MRP.id = E.materialResponsiblePerson
  GROUP BY MRP.id, MRP.fullName, MRP.subdivision
) Total
ORDER BY SumPrice DESC

SELECT S.*, SUM(E.price) sumPrice FROM Equipment E
JOIN MaterialResponsiblePeople MRP ON MRP.id = E.materialResponsiblePerson
JOIN Subdivisions S ON S.id = MRP.subdivision
GROUP BY S.id, S.name, S.subdivisionType
ORDER BY SumPrice DESC

SELECT MRP.fullName, S.name subdivision, E.name equipment, E.price price FROM Equipment E
JOIN MaterialResponsiblePeople MRP ON MRP.id = E.materialResponsiblePerson
JOIN Subdivisions S ON S.id = MRP.subdivision
WHERE E.name LIKE '%Asus%Zenbook%'
GROUP BY MRP.fullName, S.name, E.name, E.price
ORDER BY Price DESC
