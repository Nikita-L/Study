USE bookkeeping
GO


SELECT Total.* FROM
(
  SELECT MRP.fullName, S.name subdivision, ST.name subdivisionType, SUM(E.price) sumPrice
  FROM Equipment E
  JOIN MaterialResponsiblePeople MRP ON MRP.id = E.materialResponsiblePerson
  JOIN Subdivisions S ON S.id = MRP.subdivision
  JOIN SubdivisionTypes ST on ST.id = S.subdivisionType
  GROUP BY MRP.fullName, S.name, ST.name
) Total
WHERE
(
   SELECT AVG(sumPrice) avgSumPrice
   FROM
   (
      SELECT MRP.id , SUM(E.price) sumPrice FROM Equipment E
	  JOIN MaterialResponsiblePeople MRP ON MRP.id = E.materialResponsiblePerson
	  JOIN Subdivisions S ON S.id = MRP.subdivision
	  JOIN SubdivisionTypes ST on ST.id = S.subdivisionType
	  WHERE ST.name = N'Development'
	  GROUP BY MRP.id
   ) sums
) < Total.sumPrice

SELECT TOP 1 * FROM
(
  SELECT ST.*, SUM(E.price) sumPrice FROM Equipment E
  JOIN MaterialResponsiblePeople MRP ON MRP.id = E.materialResponsiblePerson
  JOIN Subdivisions S ON S.id = MRP.subdivision
  JOIN SubdivisionTypes ST on ST.id = S.subdivisionType
  GROUP BY ST.id, ST.name
) Total
ORDER BY SumPrice DESC
SELECT TOP 1 * FROM
(
  SELECT ST.*, SUM(E.price) sumPrice FROM Equipment E
  JOIN MaterialResponsiblePeople MRP ON MRP.id = E.materialResponsiblePerson
  JOIN Subdivisions S ON S.id = MRP.subdivision
  JOIN SubdivisionTypes ST on ST.id = S.subdivisionType
  GROUP BY ST.id, ST.name
) Total
ORDER BY SumPrice

SELECT MRP.fullName, S.name subdivision, ST.name subdivisionType, E.name eqName, E.price eqPrice, Result.sumPrice
FROM
(
	SELECT Total.* FROM
	(
		SELECT MRP.id, SUM(E.price) sumPrice
		FROM Equipment E
		JOIN MaterialResponsiblePeople MRP ON MRP.id = E.materialResponsiblePerson
		JOIN Subdivisions S ON S.id = MRP.subdivision
		JOIN SubdivisionTypes ST on ST.id = S.subdivisionType
		GROUP BY MRP.id
	) Total
	WHERE
	(
		SELECT AVG(sumPrice) avgSumPrice
		FROM
		(
			SELECT MRP.id , SUM(E.price) sumPrice FROM Equipment E
			JOIN MaterialResponsiblePeople MRP ON MRP.id = E.materialResponsiblePerson
			JOIN Subdivisions S ON S.id = MRP.subdivision
			JOIN SubdivisionTypes ST on ST.id = S.subdivisionType
			GROUP BY MRP.id
		) sums
	) < Total.sumPrice
) Result
JOIN MaterialResponsiblePeople MRP ON MRP.id = Result.id
JOIN Subdivisions S ON S.id = MRP.subdivision
JOIN SubdivisionTypes ST on ST.id = S.subdivisionType
JOIN Equipment E ON MRP.id = E.materialResponsiblePerson